#include <stdint.h>
#include "registers.h"

volatile int send_trigger = 0;
volatile int measure_trigger = 0;

volatile uint32_t temperature = 0;
volatile int16_t voltage = 0;

#define MESSAGE_TEMP_OFFSET 19
#define MESSAGE_VOLT_OFFSET 25

uint8_t radio_frequency_whiteniv[] =  {55,1,37,3,0,5,1,7,2,9,3,11,4,13,5,15,6,17,7,19,8,21,9,23,10,25,38,27,11,29,12,31,13,33,14,35,15,37,16,39,17,41,18,43,19,45,20,47,21,49,22,51,23,53,24,55,25,57,26,59,27,61,28,63,29,65,30,67,31,69,32,71,33,73,34,75,35,77,36,79,39,81,40,83,41};
uint8_t radio_channel_frequency[] =  {4,6,8,10,12,14,16,18,20,22,24,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,2,26,80,82,84};


// TX Packet Buffer
unsigned char tx_packet[100] = {
        0x42,  
        0x1B,  //packet length 27 bytes (not including first 3 header bytes). 30 bytes total
        0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,  //radio address 
        0x02, //Length of next data segment (1 data type byte + 1 byte data) = 2 bytes
        0x01, 0x06,  //AD type, advertise only flag 
        0x02, //next segment is 2 bytes...
        0x0A, 0x04, //Tx Power +4
        0x05, //5 bytes...
        0x16, 0x6E, 0x2A, 0x00, 0x00, //Temperature in celcius 00.00
        0x04, //4 bytes...
        0x16, 0x0f, 0x18, 0x00,  //Battery Level in percentage  
        0x03, //3 bytes...
        0x09, 0x48, 0x49  //short name, "HI"
    };

void start_hf_clock()
{
    /* Start 32 MHz crystal oscillator */
    NRF_CLOCK_HFCLKSTARTED = 0;
    NRF_CLOCK_HFCLKSTART = 1;

    /* Wait for the HF external oscillator to start up */
    while(NRF_CLOCK_HFCLKSTARTED == 0);
}

void stop_hf_clock()
{
    NRF_CLOCK_HFCLKSTOP = 1;
}

void start_lf_clock() {

    // Start low frequency clock (32.768 kHz)

    //Set the source 
    //0: Built in Resistor-Capacitor Oscillator
    //1: External Crystal  
    NRF_CLOCK_LFCLKSRC = 0;  //set the source to onboard RC
    NRF_CLOCK_CTIV = 8;  // 2 secs calibration timer

    NRF_CLOCK_LFCLKSTARTED = 0;
    NRF_CLOCK_TASKS_LFCLKSTART = 1;

    // Wait for the LF clock to start up
    while(NRF_CLOCK_LFCLKSTARTED == 0);

    //reset calibration finished flag
    NRF_CLOCK_EVENTS_DONE = 0;

    //start calibration
    NRF_CLOCK_TASKS_CAL = 1;
    //wait for calibration to finish
    while(NRF_CLOCK_EVENTS_DONE == 0);

    //reset to avoid issue with some variants
    NRF_RTC0_TASKS_STOP = 1;
}

void setup_timer() {

    //setup RTC0 for transmit timer

    NRF_RTC0_PRESCALER = 0;

    NRF_RTC0_CC = 0x4000; //500 ms interval

    // Enable RTC0 EVENTS_COMPARE[0 - 2] generation
    NRF_RTC0_EVTEN = (1 << 16) | (1 << 17);
    NRF_RTC0_EVTENSET = (1 << 16) | (1 << 17);
    // Enable RTC0 IRQ on EVENTS_COMPARE[0 - 2]
    NRF_RTC0_INTENSET = (1 << 16) | (1 << 17);

    //Enable IRQ for rtc 0
    NVIC_INTSET = 1 << 11;

    NRF_RTC0_TASKS_START = 1;

    //Setup rtc 1 for measuring voltage and temperature

    // 32kHz timer period
    NRF_RTC1_PRESCALER = 32;

    NRF_RTC1_CC = 0xEB28; //~60.2 seconds

    // Enable RTC0 EVENTS_COMPARE[0 - 2] generation
    NRF_RTC1_EVTEN = (1 << 16);
    NRF_RTC1_EVTENSET = (1 << 16);
    // Enable RTC0 IRQ on EVENTS_COMPARE[0 - 2]
    NRF_RTC1_INTENSET = (1 << 16);

    //Enable IRQ for rtc 1
    NVIC_INTSET = (1 << 17);

    NRF_RTC1_TASKS_START = 1;
}

void radio_set_frequency(uint8_t channel) {
    //set the frequency
    uint8_t frequency = radio_channel_frequency[channel];
    NRF_RADIO_FREQUENCY = frequency;
    //data whitening
    NRF_RADIO_DATAWHITEIV = radio_frequency_whiteniv[frequency];  
}

void setup_radio() {

    // Configure radio with Ble 1Mbit
    NRF_RADIO_MODE = 0x03;

    // Configure packet
    NRF_RADIO_PCNF0 =   (6 << 0) | //LF Len in bits
                        (1 << 8) |  //S0 Len in bytes
                        (2 << 16);// | //S1 Len in bits

    NRF_RADIO_PCNF1 =   (255 << 0) |  //Max Length
                        (0 << 8) |  // Static Length
                        (3 << 16) |  //Base Address Length
                        (0 << 24) |  //Little Endian
                        (1 << 25);  //Enable Whitening


    // Configure address Prefix0 + Base0 - 0x8E89BED6 broadcast address
    NRF_RADIO_PREFIX0 = 0x8e;
    NRF_RADIO_BASE0 = 0x89bed600;

    // Use logical address 0 (BASE0 + PREFIX0 byte 0)
    NRF_RADIO_TXADDRESS = 0;

    //Enable address 0
    NRF_RADIO_RXADDRESSES = 1;

    // Initialize CRC (three bytes), skip address
    NRF_RADIO_CRCCNF = (3 << 0) | //CRC Length = 3
                       (1 << 8);  //Skip addr

    NRF_RADIO_CRCPOLY = 0x00065b;
    NRF_RADIO_CRCINIT = 0x555555;                
                    
    // +4dBm output power
    NRF_RADIO_TXPOWER = 4;

    // Configure shortcuts to start as soon as READY event is received, and disable radio as soon as packet is sent.
    NRF_RADIO_SHORTS =  (0 << 0) | //Ready to Tx/Rx -> Start
                        (0 << 1);  //Send/Rec Packet End -> Disable

    //set packet pointer to tx buffer address
    NRF_RADIO_PACKETPTR = (uint32_t)&tx_packet[0];
}

void init_tx_packet() {

    //copy the address from factory registers
    tx_packet[3] = (NRF_FICR_DEVICEADDR1      ) & 0xFF;
    tx_packet[4] = (NRF_FICR_DEVICEADDR1 >>  8) & 0xFF;
    tx_packet[5] = (NRF_FICR_DEVICEADDR1 >> 16) & 0xFF;
    tx_packet[6] = (NRF_FICR_DEVICEADDR1 >> 24)       ;
    tx_packet[7] = (NRF_FICR_DEVICEADDR2      ) & 0xFF;
    tx_packet[8] = (NRF_FICR_DEVICEADDR2 >>  8) & 0xFF;
}

void radio_transmit() {
   
    //transmit advertisement on selected frequency
    NRF_RADIO_EVENTS_READY = 0;
    NRF_RADIO_TASKS_TXEN = 1;
    while (NRF_RADIO_EVENTS_READY == 0);  

    NRF_RADIO_EVENTS_END = 0;
    NRF_RADIO_TASKS_START = 1;
    while (NRF_RADIO_EVENTS_END == 0);  

    NRF_RADIO_EVENTS_DISABLED = 0;
    NRF_RADIO_TASKS_DISABLE = 1;
    while(NRF_RADIO_EVENTS_DISABLED == 0);
}

void send_packet() {

    //set values for temperature and battery voltage in tx packet buffer
    tx_packet[MESSAGE_TEMP_OFFSET] = (temperature & 0xFF);
    tx_packet[MESSAGE_TEMP_OFFSET + 1] = (temperature >> 8) & 0xFF;
    tx_packet[MESSAGE_VOLT_OFFSET] = (uint8_t)(((voltage - 17) * 100) / 13);

    //transmit on all 3 broadcast frequencies
    radio_set_frequency(37);
    radio_transmit();

    radio_set_frequency(38);
    radio_transmit();

    radio_set_frequency(39);
    radio_transmit();
    
    //disable radio
    NRF_RADIO_EVENTS_DISABLED = 0;
    NRF_RADIO_TASKS_DISABLE = 1;
    while(NRF_RADIO_EVENTS_DISABLED == 0);
}

void measure_temperature() {

    //read SoC temperature
    NRF_TEMP_DATARDY = 0;
    NRF_TEMP_TASKS_START = 1;
    while(NRF_TEMP_DATARDY == 0) {};

    temperature = ((NRF_TEMP_TEMP * 100)/ 4);
}

void init_adc(void) {

    //setup adc to read voltage
    NRF_ADC_EVENTS_END = 0;
    NRF_ADC_EVENTS_STARTED = 0;

    NRF_ADC_CH1_PSELP = 9; //VDD
    NRF_ADC_CH1_CONFIG = 0; //defaults
}

void sample_adc(void) {

    //read adc and calculate voltage

    volatile int16_t buffer[2];
    uint32_t timeout = 100000;  

    NRF_ADC_RESULT_PTR = (uint32_t)buffer; //&voltage;
    NRF_ADC_RESULT_MAXCNT = 1; //?
    NRF_ADC_ENABLE = 1;

    NRF_ADC_EVENTS_END = 0;
    NRF_ADC_TASKS_START = 1;
    NRF_ADC_TASKS_SAMPLE = 1; 

    while(NRF_ADC_EVENTS_END == 0 && timeout > 0) { timeout--; };

    voltage = buffer[0] / 28; 

    NRF_ADC_TASKS_STOP = 1;

    NRF_ADC_ENABLE = 0;
}

int main()
{
    //enable dc/dc regulator if LC Filter components are populated (more efficient)
    //NRF_POWER_DCDC = 1;

    //start the High Frequency Clock
    start_hf_clock();

    //Start the low frequency clock
    start_lf_clock();

    //init radio
    setup_radio();

    //copy ble address to tx memory buffer
    init_tx_packet();

    //setup Real-Time Clocks and interrupts
    setup_timer();
    
    //measure the temperature
    measure_temperature();

    //setup ADC to measure battery voltage
    init_adc();
    sample_adc();

    //shut down High Frequency Clock
    stop_hf_clock();

    while(1)
    {
        //check to see if an interrupt has set any task flags

        //This is triggered once every 500ms
        if(send_trigger == 1) {
            //reset flag
            send_trigger = 0;
            
            //start/stop the HF clock before and after advertising
            start_hf_clock();
            send_packet();
            stop_hf_clock();
        }

        //read temp and voltage every minute
        if(measure_trigger == 1) {
            measure_trigger = 0;

            start_hf_clock();
            measure_temperature(); 
            sample_adc();  
            stop_hf_clock();
        }

        //enter low power mode (WFE = Wait For Event)
        __asm ("wfe");
    }
    return 0;
}

//Transmit Interrupt handler
void RTC0_IRQHandler(void)
{
    if(NRF_RTC0_EVENTS_COMPARE)
    {
        NRF_RTC0_EVENTS_COMPARE = 0;

        //set the send trigger flag to notify the main loop it is time to transmit
        send_trigger = 1;
       
        NRF_RTC0_TASKS_CLEAR = 1;        
    } 
}

//measure temp/voltage interrupt handler
void RTC1_IRQHandler(void) {
    if(NRF_RTC1_EVENTS_COMPARE) {
        NRF_RTC1_EVENTS_COMPARE = 0;

        //set the measure flag
        measure_trigger = 1;
       
        NRF_RTC1_TASKS_CLEAR = 1;    
    }
}