#include <stdint.h>

#define NRF_FICR_BASE 0x10000000
#define NRF_FICR_DEVICEADDR1        (*((uint32_t*) (NRF_FICR_BASE + 0x0A4)))
#define NRF_FICR_DEVICEADDR2        (*((uint32_t*) (NRF_FICR_BASE + 0x0A8)))

#define NRF_ICR_BASE 0x10001000
#define NRF_ICR_CUSTOMER0           (*((uint32_t*) (NRF_ICR_BASE + 0x080)))
#define NRF_ICR_CUSTOMER1           (*((uint32_t*) (NRF_ICR_BASE + 0x084)))
#define NRF_ICR_CUSTOMER2           (*((uint32_t*) (NRF_ICR_BASE + 0x088)))
#define NRF_ICR_CUSTOMER3           (*((uint32_t*) (NRF_ICR_BASE + 0x08C)))
#define NRF_ICR_CUSTOMER4           (*((uint32_t*) (NRF_ICR_BASE + 0x090)))
#define NRF_ICR_CUSTOMER5           (*((uint32_t*) (NRF_ICR_BASE + 0x094)))
#define NRF_ICR_CUSTOMER6           (*((uint32_t*) (NRF_ICR_BASE + 0x098)))
#define NRF_ICR_CUSTOMER7           (*((uint32_t*) (NRF_ICR_BASE + 0x09C)))
#define NRF_ICR_CUSTOMER8           (*((uint32_t*) (NRF_ICR_BASE + 0x0A0)))
#define NRF_ICR_CUSTOMER9           (*((uint32_t*) (NRF_ICR_BASE + 0x0A4)))
#define NRF_ICR_CUSTOMER10          (*((uint32_t*) (NRF_ICR_BASE + 0x0A8)))
#define NRF_ICR_CUSTOMER11          (*((uint32_t*) (NRF_ICR_BASE + 0x0AC)))

#define NRF_APP_OFFSET_1            0x10000
#define NRF_APP_OFFSET_2            0x40000
#define NRF_ICR_APP_ADDRESS         (*((uint32_t*) (NRF_ICR_BASE + 0x0B0)))
#define NRF_ICR_APP_LENGTH          (*((uint32_t*) (NRF_ICR_BASE + 0x0B4)))
#define NRF_ICR_UPDATE_ADDRESS      (*((uint32_t*) (NRF_ICR_BASE + 0x0B8)))
#define NRF_ICR_UPDATE_LENGTH       (*((uint32_t*) (NRF_ICR_BASE + 0x0BC)))

#define NRF_CLOCK_BASE 0x40000000
#define NRF_CLOCK_HFCLKSTART        (*((uint32_t*) NRF_CLOCK_BASE))
#define NRF_CLOCK_HFCLKSTOP         (*((uint32_t*) (NRF_CLOCK_BASE + 0x004)))
#define NRF_CLOCK_TASKS_LFCLKSTART  (*((uint32_t*) (NRF_CLOCK_BASE + 0x008)))
#define NRF_CLOCK_TASKS_LFCLKSTOP   (*((uint32_t*) (NRF_CLOCK_BASE + 0x00C)))
#define NRF_CLOCK_TASKS_CAL         (*((uint32_t*) (NRF_CLOCK_BASE + 0x010)))
#define NRF_CLOCK_TASKS_CTSTART     (*((uint32_t*) (NRF_CLOCK_BASE + 0x014)))
#define NRF_CLOCK_TASKS_CTSTOP      (*((uint32_t*) (NRF_CLOCK_BASE + 0x018)))
#define NRF_CLOCK_HFCLKSTARTED      (*((uint32_t*) (NRF_CLOCK_BASE + 0x100)))
#define NRF_CLOCK_LFCLKSTARTED      (*((uint32_t*) (NRF_CLOCK_BASE + 0x104)))
#define NRF_CLOCK_EVENTS_DONE       (*((uint32_t*) (NRF_CLOCK_BASE + 0x10C)))
#define NRF_CLOCK_EVENTS_CTTO       (*((uint32_t*) (NRF_CLOCK_BASE + 0x110)))
#define NRF_CLOCK_LFCLKSRC          (*((uint32_t*) (NRF_CLOCK_BASE + 0x518)))
#define NRF_CLOCK_CTIV              (*((uint32_t*) (NRF_CLOCK_BASE + 0x538)))
#define NRF_CLOCK_XTALFREQ          (*((uint32_t*) (NRF_CLOCK_BASE + 0x550)))  //0xFF = 16, 0x00 = 32

#define NRF_TASKS_CONST_LATENCY     (*((uint32_t*) 0x40000078))
#define NRF_TASKS_LOWPWR            (*((uint32_t*) 0x4000007C))
#define NRF_POWER_DCDC              (*((uint32_t*) 0x40000578))

#define NRF_RADIO_BASE 0x40001000
#define NRF_RADIO_TASKS_TXEN        (*((uint32_t*) (NRF_RADIO_BASE)))
#define NRF_RADIO_TASKS_RXEN        (*((uint32_t*) (NRF_RADIO_BASE + 0x004)))
#define NRF_RADIO_TASKS_START       (*((uint32_t*) (NRF_RADIO_BASE + 0x008)))
#define NRF_RADIO_TASKS_STOP        (*((uint32_t*) (NRF_RADIO_BASE + 0x00C)))
#define NRF_RADIO_TASKS_DISABLE     (*((uint32_t*) (NRF_RADIO_BASE + 0x010)))
#define NRF_RADIO_EVENTS_READY      (*((uint32_t*) (NRF_RADIO_BASE + 0x100)))
#define NRF_RADIO_EVENTS_END        (*((uint32_t*) (NRF_RADIO_BASE + 0x10C)))
#define NRF_RADIO_EVENTS_DISABLED   (*((uint32_t*) (NRF_RADIO_BASE + 0x110)))
#define NRF_RADIO_EVENTS_CRCOK      (*((uint32_t*) (NRF_RADIO_BASE + 0x130)))
#define NRF_RADIO_SHORTS            (*((uint32_t*) (NRF_RADIO_BASE + 0x200)))
#define NRF_RADIO_INTENSET          (*((uint32_t*) (NRF_RADIO_BASE + 0x304)))
#define NRF_RADIO_INTENCLR          (*((uint32_t*) (NRF_RADIO_BASE + 0x308)))
#define NRF_RADIO_STATUS_CRCOK      (*((uint32_t*) (NRF_RADIO_BASE + 0x400)))
#define NRF_RADIO_PACKETPTR         (*((uint32_t*) (NRF_RADIO_BASE + 0x504)))
#define NRF_RADIO_FREQUENCY         (*((uint32_t*) (NRF_RADIO_BASE + 0x508)))
#define NRF_RADIO_TXPOWER           (*((uint32_t*) (NRF_RADIO_BASE + 0x50C)))
#define NRF_RADIO_MODE              (*((uint32_t*) (NRF_RADIO_BASE + 0x510)))
#define NRF_RADIO_PCNF0             (*((uint32_t*) (NRF_RADIO_BASE + 0x514)))
#define NRF_RADIO_PCNF1             (*((uint32_t*) (NRF_RADIO_BASE + 0x518)))
#define NRF_RADIO_BASE0             (*((uint32_t*) (NRF_RADIO_BASE + 0x51C)))
#define NRF_RADIO_PREFIX0           (*((uint32_t*) (NRF_RADIO_BASE + 0x524)))
#define NRF_RADIO_TXADDRESS         (*((uint32_t*) (NRF_RADIO_BASE + 0x52C)))
#define NRF_RADIO_RXADDRESSES       (*((uint32_t*) (NRF_RADIO_BASE + 0x530)))
#define NRF_RADIO_CRCCNF            (*((uint32_t*) (NRF_RADIO_BASE + 0x534)))
#define NRF_RADIO_CRCPOLY           (*((uint32_t*) (NRF_RADIO_BASE + 0x538)))
#define NRF_RADIO_CRCINIT           (*((uint32_t*) (NRF_RADIO_BASE + 0x53C)))
#define NRF_RADIO_TIFS              (*((uint32_t*) (NRF_RADIO_BASE + 0x544)))
#define NRF_RADIO_RSSISAMPLE        (*((uint32_t*) (NRF_RADIO_BASE + 0x548)))
#define NRF_RADIO_STATE             (*((uint32_t*) (NRF_RADIO_BASE + 0x550)))
#define NRF_RADIO_DATAWHITEIV       (*((uint32_t*) (NRF_RADIO_BASE + 0x554)))
#define NRF_RADIO_MODECNF0          (*((uint32_t*) (NRF_RADIO_BASE + 0x650)))
#define NRF_RADIO_POWER             (*((uint32_t*) (NRF_RADIO_BASE + 0xFFC)))

#define NRF_UART0_BASE 0x40002000
#define NRF_UART0_TASKS_STARTRX     (*((uint32_t*) (NRF_UART0_BASE + 0x000)))
#define NRF_UART0_TASKS_STOPRX      (*((uint32_t*) (NRF_UART0_BASE + 0x004)))
#define NRF_UART0_TASKS_STARTTX     (*((uint32_t*) (NRF_UART0_BASE + 0x008)))
#define NRF_UART0_TASKS_STOPTX      (*((uint32_t*) (NRF_UART0_BASE + 0x00C)))
#define NRF_UART0_TASKS_SUSPEND     (*((uint32_t*) (NRF_UART0_BASE + 0x01C)))
#define NRF_UART0_EVENTS_RXRDY      (*((uint32_t*) (NRF_UART0_BASE + 0x108)))
#define NRF_UART0_EVENTS_TXRDY      (*((uint32_t*) (NRF_UART0_BASE + 0x11C)))
#define NRF_UART0_EVENTS_ENDTX      (*((uint32_t*) (NRF_UART0_BASE + 0x120)))
#define NRF_UART0_EVENTS_TXSTOPPED  (*((uint32_t*) (NRF_UART0_BASE + 0x158)))
#define NRF_UART0_INTENSET          (*((uint32_t*) (NRF_UART0_BASE + 0x304)))
#define NRF_UART0_ENABLE            (*((uint32_t*) (NRF_UART0_BASE + 0x500)))
#define NRF_UART0_PSEL_TXD          (*((uint32_t*) (NRF_UART0_BASE + 0x50C)))
#define NRF_UART0_PSEL_RXD          (*((uint32_t*) (NRF_UART0_BASE + 0x514)))
#define NRF_UART0_RXD               (*((uint32_t*) (NRF_UART0_BASE + 0x518)))
#define NRF_UART0_TXD               (*((uint32_t*) (NRF_UART0_BASE + 0x51C)))
#define NRF_UART0_BAUDRATE          (*((uint32_t*) (NRF_UART0_BASE + 0x524)))
#define NRF_UARTE0_TXD_PTR          (*((uint32_t*) (NRF_UART0_BASE + 0x544)))
#define NRF_UARTE0_TXD_MAXCNT       (*((uint32_t*) (NRF_UART0_BASE + 0x548)))
#define NRF_UART0_CONFIG            (*((uint32_t*) (NRF_UART0_BASE + 0x56C)))

/* SPIM */
#define NRF_SPIM0_BASE 0x40004000
#define NRF_SPIM0_TASKS_START     (*((uint32_t*) (NRF_SPIM0_BASE + 0x010)))
#define NRF_SPIM0_TASKS_STOP      (*((uint32_t*) (NRF_SPIM0_BASE + 0x014)))
#define NRF_SPIM0_TASKS_SUSPEND   (*((uint32_t*) (NRF_SPIM0_BASE + 0x01C)))
#define NRF_SPIM0_TASKS_RESUME    (*((uint32_t*) (NRF_SPIM0_BASE + 0x020)))
#define NRF_SPIM0_EVENTS_STOPPED  (*((uint32_t*) (NRF_SPIM0_BASE + 0x104)))
#define NRF_SPIM0_EVENTS_RDY      (*((uint32_t*) (NRF_SPIM0_BASE + 0x108)))
#define NRF_SPIM0_EVENTS_ENDRX    (*((uint32_t*) (NRF_SPIM0_BASE + 0x110)))
#define NRF_SPIM0_EVENTS_END      (*((uint32_t*) (NRF_SPIM0_BASE + 0x118)))
#define NRF_SPIM0_EVENTS_ENDTX    (*((uint32_t*) (NRF_SPIM0_BASE + 0x120)))
#define NRF_SPIM0_EVENTS_STARTED  (*((uint32_t*) (NRF_SPIM0_BASE + 0x14C)))
#define NRF_SPIM0_SHORTS          (*((uint32_t*) (NRF_SPIM0_BASE + 0x200)))
#define NRF_SPIM0_INTENSET        (*((uint32_t*) (NRF_SPIM0_BASE + 0x304)))
#define NRF_SPIM0_INTCLR          (*((uint32_t*) (NRF_SPIM0_BASE + 0x308)))
#define NRF_SPIM0_ENABLE          (*((uint32_t*) (NRF_SPIM0_BASE + 0x500)))
#define NRF_SPIM0_PSEL_SCK        (*((uint32_t*) (NRF_SPIM0_BASE + 0x508)))
#define NRF_SPIM0_PSEL_MOSI       (*((uint32_t*) (NRF_SPIM0_BASE + 0x50C)))
#define NRF_SPIM0_PSEL_MISO       (*((uint32_t*) (NRF_SPIM0_BASE + 0x510)))
#define NRF_SPIM0_RXD             (*((uint32_t*) (NRF_SPIM0_BASE + 0x518)))
#define NRF_SPIM0_TXD             (*((uint32_t*) (NRF_SPIM0_BASE + 0x51C)))
#define NRF_SPIM0_FREQUENCY       (*((uint32_t*) (NRF_SPIM0_BASE + 0x524)))
#define NRF_SPIM0_RXD_PTR         (*((uint32_t*) (NRF_SPIM0_BASE + 0x534)))
#define NRF_SPIM0_RXD_MAXCNT      (*((uint32_t*) (NRF_SPIM0_BASE + 0x538)))
#define NRF_SPIM0_RXD_AMOUNT      (*((uint32_t*) (NRF_SPIM0_BASE + 0x53C)))
#define NRF_SPIM0_RXD_LIST        (*((uint32_t*) (NRF_SPIM0_BASE + 0x540)))
#define NRF_SPIM0_TXD_PTR         (*((uint32_t*) (NRF_SPIM0_BASE + 0x544)))
#define NRF_SPIM0_TXD_MAXCNT      (*((uint32_t*) (NRF_SPIM0_BASE + 0x548)))
#define NRF_SPIM0_TXD_AMOUNT      (*((uint32_t*) (NRF_SPIM0_BASE + 0x54C)))
#define NRF_SPIM0_TXD_LIST        (*((uint32_t*) (NRF_SPIM0_BASE + 0x550)))
#define NRF_SPIM0_CONFIG          (*((uint32_t*) (NRF_SPIM0_BASE + 0x554)))
#define NRF_SPIM0_ORC             (*((uint32_t*) (NRF_SPIM0_BASE + 0x5C0)))

/* ADC */
#define NRF_ADC_BASE 0x40007000
#define NRF_ADC_TASKS_START         (*((uint32_t*) (NRF_ADC_BASE)))
#define NRF_ADC_TASKS_SAMPLE        (*((uint32_t*) (NRF_ADC_BASE + 0x004)))
#define NRF_ADC_TASKS_STOP          (*((uint32_t*) (NRF_ADC_BASE + 0x008)))
#define NRF_ADC_EVENTS_STARTED      (*((uint32_t*) (NRF_ADC_BASE + 0x100)))
#define NRF_ADC_EVENTS_END          (*((uint32_t*) (NRF_ADC_BASE + 0x104)))
#define NRF_ADC_EVENTS_DONE         (*((uint32_t*) (NRF_ADC_BASE + 0x108)))
#define NRF_ADC_ENABLE              (*((uint32_t*) (NRF_ADC_BASE + 0x500)))
#define NRF_ADC_CH0_PSELP           (*((uint32_t*) (NRF_ADC_BASE + 0x510)))
#define NRF_ADC_CH0_PSELN           (*((uint32_t*) (NRF_ADC_BASE + 0x514)))
#define NRF_ADC_CH0_CONFIG          (*((uint32_t*) (NRF_ADC_BASE + 0x518)))
#define NRF_ADC_CH0_LIMIT           (*((uint32_t*) (NRF_ADC_BASE + 0x51C)))
#define NRF_ADC_CH1_PSELP           (*((uint32_t*) (NRF_ADC_BASE + 0x520)))
#define NRF_ADC_CH1_CONFIG          (*((uint32_t*) (NRF_ADC_BASE + 0x528)))
#define NRF_ADC_RESULT_PTR          (*((uint32_t*) (NRF_ADC_BASE + 0x62C)))
#define NRF_ADC_RESULT_MAXCNT       (*((uint32_t*) (NRF_ADC_BASE + 0x630)))
#define NRF_ADC_INT                 (*((uint32_t*) (NRF_ADC_BASE + 0x300)))
#define NRF_ADC_INT_SET             (*((uint32_t*) (NRF_ADC_BASE + 0x304)))
#define NRF_ADC_INT_CLR             (*((uint32_t*) (NRF_ADC_BASE + 0x308)))


/* TIMER1 */
#define NRF_TIMER1_BASE 0x40009000
#define NRF_TIMER1_TASKS_START      (*((uint32_t*) (NRF_TIMER1_BASE)))
#define NRF_TIMER1_TASKS_STOP       (*((uint32_t*) (NRF_TIMER1_BASE + 0x004)))
#define NRF_TIMER1_TASKS_COUNT      (*((uint32_t*) (NRF_TIMER1_BASE + 0x008)))
#define NRF_TIMER1_TASKS_CLEAR      (*((uint32_t*) (NRF_TIMER1_BASE + 0x00C)))
#define NRF_TIMER1_TASKS_CAPTURE0   (*((uint32_t*) (NRF_TIMER1_BASE + 0x040)))
#define NRF_TIMER1_TASKS_CAPTURE1   (*((uint32_t*) (NRF_TIMER1_BASE + 0x044)))
#define NRF_TIMER1_TASKS_CAPTURE2   (*((uint32_t*) (NRF_TIMER1_BASE + 0x048)))
#define NRF_TIMER1_TASKS_CAPTURE3   (*((uint32_t*) (NRF_TIMER1_BASE + 0x04C)))
#define NRF_TIMER1_TASKS_CAPTURE4   (*((uint32_t*) (NRF_TIMER1_BASE + 0x054)))
#define NRF_TIMER1_TASKS_CAPTURE5   (*((uint32_t*) (NRF_TIMER1_BASE + 0x058)))
#define NRF_TIMER1_EVENTS_COMPARE0  (*((uint32_t*) (NRF_TIMER1_BASE + 0x140)))
#define NRF_TIMER1_EVENTS_COMPARE1  (*((uint32_t*) (NRF_TIMER1_BASE + 0x148)))
#define NRF_TIMER1_SHORTS           (*((uint32_t*) (NRF_TIMER1_BASE + 0x200)))
#define NRF_TIMER1_INTENSET         (*((uint32_t*) (NRF_TIMER1_BASE + 0x304)))
#define NRF_TIMER1_INTENCLR         (*((uint32_t*) (NRF_TIMER1_BASE + 0x308)))
#define NRF_TIMER1_BITMODE          (*((uint32_t*) (NRF_TIMER1_BASE + 0x508)))
#define NRF_TIMER1_PRESCALER        (*((uint32_t*) (NRF_TIMER1_BASE + 0x510)))
#define NRF_TIMER1_CC               (*((uint32_t*) (NRF_TIMER1_BASE + 0x540)))
#define NRF_TIMER1_CC1              (*((uint32_t*) (NRF_TIMER1_BASE + 0x544)))

#define NRF_RTC0_BASE 0x4000B000
#define NRF_RTC0_TASKS_START        (*((uint32_t*) (NRF_RTC0_BASE)))
#define NRF_RTC0_TASKS_STOP         (*((uint32_t*) (NRF_RTC0_BASE + 0x004)))
#define NRF_RTC0_TASKS_CLEAR        (*((uint32_t*) (NRF_RTC0_BASE + 0x008)))
#define NRF_RTC0_EVENTS_COMPARE     (*((uint32_t*) (NRF_RTC0_BASE + 0x140)))
#define NRF_RTC0_EVENTS_COMPARE1    (*((uint32_t*) (NRF_RTC0_BASE + 0x144)))
#define NRF_RTC0_EVENTS_COMPARE2    (*((uint32_t*) (NRF_RTC0_BASE + 0x148)))
#define NRF_RTC0_INTENSET           (*((uint32_t*) (NRF_RTC0_BASE + 0x304)))
#define NRF_RTC0_EVTEN              (*((uint32_t*) (NRF_RTC0_BASE + 0x340)))
#define NRF_RTC0_EVTENSET           (*((uint32_t*) (NRF_RTC0_BASE + 0x344)))
#define NRF_RTC0_COUNTER            (*((uint32_t*) (NRF_RTC0_BASE + 0x504)))
#define NRF_RTC0_PRESCALER          (*((uint32_t*) (NRF_RTC0_BASE + 0x508)))
#define NRF_RTC0_CC                 (*((uint32_t*) (NRF_RTC0_BASE + 0x540)))
#define NRF_RTC0_CC1                (*((uint32_t*) (NRF_RTC0_BASE + 0x544)))
#define NRF_RTC0_CC2                (*((uint32_t*) (NRF_RTC0_BASE + 0x548)))

/* TEMP */
#define NRF_TEMP_BASE 0x4000C000
#define NRF_TEMP_TASKS_START        (*((uint32_t*) (NRF_TEMP_BASE)))
#define NRF_TEMP_TASKS_STOP         (*((uint32_t*) (NRF_TEMP_BASE + 0x004)))
#define NRF_TEMP_DATARDY            (*((uint32_t*) (NRF_TEMP_BASE + 0x100)))
#define NRF_TEMP_TEMP               (*((uint32_t*) (NRF_TEMP_BASE + 0x508)))

/* RNG */
#define NRF_RNG_BASE 0x4000D000
#define NRF_RNG_TASKS_START         (*((uint32_t*) (NRF_RNG_BASE)))
#define NRF_RNG_TASKS_STOP          (*((uint32_t*) (NRF_RNG_BASE + 0x004)))
#define NRF_RNG_EVENTS_VALRDY       (*((uint32_t*) (NRF_RNG_BASE + 0x100)))
#define NRF_RNG_SHORTS              (*((uint32_t*) (NRF_RNG_BASE + 0x200)))
#define NRF_RNG_VALUE               (*((uint32_t*) (NRF_RNG_BASE + 0x508)))

/* WDT */
#define NRF_WDT_BASE 0x40010000
#define NRF_WDT_TASKS_START         (*((uint32_t*) (NRF_WDT_BASE)))
#define NRF_WDT_CRV                 (*((uint32_t*) (NRF_WDT_BASE + 0x504)))
#define NRF_WDT_RR0EN               (*((uint32_t*) (NRF_WDT_BASE + 0x508)))
#define NRF_WDT_RR0                 (*((uint32_t*) (NRF_WDT_BASE + 0x600)))

/* RTC1 */
#define NRF_RTC1_BASE 0x40011000
#define NRF_RTC1_TASKS_START        (*((uint32_t*) (NRF_RTC1_BASE)))
#define NRF_RTC1_TASKS_STOP         (*((uint32_t*) (NRF_RTC1_BASE + 0x004)))
#define NRF_RTC1_TASKS_CLEAR        (*((uint32_t*) (NRF_RTC1_BASE + 0x008)))
#define NRF_RTC1_EVENTS_COMPARE     (*((uint32_t*) (NRF_RTC1_BASE + 0x140)))
#define NRF_RTC1_EVENTS_COMPARE1    (*((uint32_t*) (NRF_RTC1_BASE + 0x144)))
#define NRF_RTC1_EVENTS_COMPARE2    (*((uint32_t*) (NRF_RTC1_BASE + 0x148)))
#define NRF_RTC1_INTENSET           (*((uint32_t*) (NRF_RTC1_BASE + 0x304)))
#define NRF_RTC1_EVTEN              (*((uint32_t*) (NRF_RTC1_BASE + 0x340)))
#define NRF_RTC1_EVTENSET           (*((uint32_t*) (NRF_RTC1_BASE + 0x344)))
#define NRF_RTC1_COUNTER            (*((uint32_t*) (NRF_RTC1_BASE + 0x504)))
#define NRF_RTC1_PRESCALER          (*((uint32_t*) (NRF_RTC1_BASE + 0x508)))
#define NRF_RTC1_CC                 (*((uint32_t*) (NRF_RTC1_BASE + 0x540)))
#define NRF_RTC1_CC1                (*((uint32_t*) (NRF_RTC1_BASE + 0x544)))
#define NRF_RTC1_CC2                (*((uint32_t*) (NRF_RTC1_BASE + 0x548)))
#define NRF_RTC1_CC3                (*((uint32_t*) (NRF_RTC1_BASE + 0x54C)))

/* COMP */
#define NRF_COMP_BASE 0x40013000
#define NRF_COMP_TASKS_START        (*((uint32_t*) (NRF_COMP_BASE)))
#define NRF_COMP_TASKS_STOP         (*((uint32_t*) (NRF_COMP_BASE + 0x004)))
#define NRF_COMP_TASKS_SAMPLE       (*((uint32_t*) (NRF_COMP_BASE + 0x008)))
#define NRF_COMP_EVENTS_DOWN        (*((uint32_t*) (NRF_COMP_BASE + 0x104)))
#define NRF_COMP_EVENTS_UP          (*((uint32_t*) (NRF_COMP_BASE + 0x108)))
#define NRF_COMP_SHORTS             (*((uint32_t*) (NRF_COMP_BASE + 0x200)))
#define NRF_COMP_INTEN              (*((uint32_t*) (NRF_COMP_BASE + 0x300)))
#define NRF_COMP_INTENSET           (*((uint32_t*) (NRF_COMP_BASE + 0x304)))
#define NRF_COMP_INTENCLR           (*((uint32_t*) (NRF_COMP_BASE + 0x308)))
#define NRF_COMP_ENABLE             (*((uint32_t*) (NRF_COMP_BASE + 0x500)))
#define NRF_COMP_PSEL               (*((uint32_t*) (NRF_COMP_BASE + 0x504)))
#define NRF_COMP_REFSEL             (*((uint32_t*) (NRF_COMP_BASE + 0x508)))
#define NRF_COMP_TH                 (*((uint32_t*) (NRF_COMP_BASE + 0x530)))
#define NRF_COMP_MODE               (*((uint32_t*) (NRF_COMP_BASE + 0x534)))
#define NRF_COMP_HYST               (*((uint32_t*) (NRF_COMP_BASE + 0x538)))
#define NRF_COMP_ISOURCE            (*((uint32_t*) (NRF_COMP_BASE + 0x53C)))

/* flash */
#define NRF_NVIC_BASE 0x4001E000
#define NRF_NVIC_READY              (*((uint32_t*) (NRF_NVIC_BASE + 0x400)))
#define NRF_NVIC_CONFIG             (*((uint32_t*) (NRF_NVIC_BASE + 0x504)))
#define NRF_NVIC_ERASEPAGE          (*((uint32_t*) (NRF_NVIC_BASE + 0x508)))
#define NRF_NVIC_ERASEUICR          (*((uint32_t*) (NRF_NVIC_BASE + 0x514)))

/* PPI */
#define NRF_PPI_BASE 0x4001F000
#define NRF_PPI_CHENSET             (*((uint32_t*) (NRF_PPI_BASE + 0x504)))
#define NRF_PPI_CH0_EVENT           (*((uint32_t*) (NRF_PPI_BASE + 0x510)))
#define NRF_PPI_CH0_TASK            (*((uint32_t*) (NRF_PPI_BASE + 0x514)))
#define NRF_PPI_CH1_EVENT           (*((uint32_t*) (NRF_PPI_BASE + 0x518)))
#define NRF_PPI_CH1_TASK            (*((uint32_t*) (NRF_PPI_BASE + 0x51C)))
#define NRF_PPI_CH0_FORK            (*((uint32_t*) (NRF_PPI_BASE + 0x910)))
#define NRF_PPI_CH1_FORK            (*((uint32_t*) (NRF_PPI_BASE + 0x914)))


/* RTC2 */
#define NRF_RTC2_BASE 0x40024000
#define NRF_RTC2_TASKS_START        (*((uint32_t*) (NRF_RTC2_BASE)))
#define NRF_RTC2_TASKS_STOP         (*((uint32_t*) (NRF_RTC2_BASE + 0x004)))
#define NRF_RTC2_TASKS_CLEAR        (*((uint32_t*) (NRF_RTC2_BASE + 0x008)))
#define NRF_RTC2_EVENTS_COMPARE     (*((uint32_t*) (NRF_RTC2_BASE + 0x140)))
#define NRF_RTC2_EVENTS_COMPARE1    (*((uint32_t*) (NRF_RTC2_BASE + 0x144)))
#define NRF_RTC2_EVENTS_COMPARE2    (*((uint32_t*) (NRF_RTC2_BASE + 0x148)))
#define NRF_RTC2_INTENSET           (*((uint32_t*) (NRF_RTC2_BASE + 0x304)))
#define NRF_RTC2_EVTEN              (*((uint32_t*) (NRF_RTC2_BASE + 0x340)))
#define NRF_RTC2_EVTENSET           (*((uint32_t*) (NRF_RTC2_BASE + 0x344)))
#define NRF_RTC2_COUNTER            (*((uint32_t*) (NRF_RTC2_BASE + 0x504)))
#define NRF_RTC2_PRESCALER          (*((uint32_t*) (NRF_RTC2_BASE + 0x508)))
#define NRF_RTC2_CC                 (*((uint32_t*) (NRF_RTC2_BASE + 0x540)))
#define NRF_RTC2_CC1                (*((uint32_t*) (NRF_RTC2_BASE + 0x544)))
#define NRF_RTC2_CC2                (*((uint32_t*) (NRF_RTC2_BASE + 0x548)))
#define NRF_RTC2_CC3                (*((uint32_t*) (NRF_RTC2_BASE + 0x54C)))

#define NRF_NVMC_BASE 0x4001E000
#define NRF_NVMC_READY              (*((uint32_t*) (NRF_NVMC_BASE + 0x400)))
#define NRF_NVMC_CONFIG             (*((uint32_t*) (NRF_NVMC_BASE + 0x504)))
#define NRF_NVMC_ERASEPAGE          (*((uint32_t*) (NRF_NVMC_BASE + 0x508)))
#define NRF_NVMC_ERASEUICR          (*((uint32_t*) (NRF_NVMC_BASE + 0x514)))

#define GPIO_BASE   0x50000000
#define GPIO_OUTSET                 (*((uint32_t*) (GPIO_BASE + 0x508)))
#define GPIO_OUTCLR                 (*((uint32_t*) (GPIO_BASE + 0x50C)))
#define GPIO_PIN_IN                 (*((uint32_t*) (GPIO_BASE + 0x510)))
#define GPIO_PIN_CNF(pin)           (*((uint32_t*) (GPIO_BASE + 0x700 + pin * 4)))
#define GPIO_PIN_CFG_DIR            0x01
#define GPIO_PIN_CFG_BUF            0x02
#define GPIO_PIN_CFG_PULL           0x04
#define GPIO_PIN_CFG_DRIVE          0x100
#define GPIO_PIN_CFG_SENSE          0x10000

#define NRF_SCB_BASE 0xE000ED00
#define NRF_SCB_VTOR                (*((uint32_t*) (NRF_SCB_BASE + 0x008)))
#define NRF_SCB_AIRCR               (*((uint32_t*) (NRF_SCB_BASE + 0x00C)))
#define NRF_SCB_SCR                 (*((uint32_t*) (NRF_SCB_BASE + 0x010)))

#define NVIC_INTSET (*((uint32_t*) 0xE000E100)) 
#define NVIC_INTCLR (*((uint32_t*) 0xE000E180)) 

#define RADIO_IRQ 0x1
#define TIMER0_IRQn 0x8
    
static inline void Reset(void) { NRF_SCB_AIRCR = (0x05FA << 16) | (1 << 2); }

/**
  \brief   Enable External Interrupt
  \details Enables a device-specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
inline void NVIC_EnableIRQ(unsigned int IRQn)
{
    NVIC_INTSET = 1 << (IRQn & 0x1F);
}

/**
  \brief   Disable External Interrupt
  \details Disables a device-specific interrupt in the NVIC interrupt controller.
  \param [in]      IRQn  External interrupt number. Value cannot be negative.
 */
inline void NVIC_DisableIRQ(unsigned int IRQn)
{
    NVIC_INTCLR = 1 << (IRQn & 0x1F);
}

//wait for nvmc to be ready
static inline void nvmc_wait_until_ready(void)
{
	while (NRF_NVMC_READY != 1);
}

static inline void NRF_Start_WDT(uint32_t timeout) {
    NRF_WDT_CRV = timeout; //0x27FFF;  //5s = (163839 + 1) / 32768;
    NRF_WDT_TASKS_START = 1;
}

static inline void NRF_Reset_WDT(void) {
    NRF_WDT_RR0 = 0x6E524635;
}
