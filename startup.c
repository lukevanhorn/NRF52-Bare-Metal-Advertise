#define STACK_TOP (void *)0x20004000

extern unsigned long _stext;
extern unsigned long _sbss;
extern unsigned long _sdata;
extern unsigned long _etext;
extern unsigned long _ebss;
extern unsigned long _edata;

void c_startup(void);
void d_h(void);
void RADIO_IRQHandler(void);
void UARTE0_UART0_IRQHandler(void);
void SPI0_IRQHandler(void);
void TIMER1_IRQHandler(void);
void RTC0_IRQHandler(void);
void RTC1_IRQHandler(void);
void COMP_LPCOMP_IRQHandler(void);
void RTC2_IRQHandler(void);

int main();

__attribute__((section(".isr_vector")))
void (*vectors[])(void) = {
        STACK_TOP,
        c_startup,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        RADIO_IRQHandler,
        UARTE0_UART0_IRQHandler,
        d_h,
        SPI0_IRQHandler,
        d_h,
        d_h,
        d_h,
        d_h,
        TIMER1_IRQHandler,
        d_h,
        RTC0_IRQHandler,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        RTC1_IRQHandler,
        d_h,
        COMP_LPCOMP_IRQHandler,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        d_h,
        0,       
        0,
        d_h,
        d_h,
        d_h,
        d_h,
        RTC2_IRQHandler
};

void d_h(void)
{
        while(1) {}
}

__attribute__((weak)) void RADIO_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void UARTE0_UART0_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void SPI0_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void TIMER1_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void RTC0_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void RTC1_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void COMP_LPCOMP_IRQHandler(void) { 
        while(1) {}
}

__attribute__((weak)) void RTC2_IRQHandler(void) { 
        while(1) {}
}

void c_startup(void)
{
        unsigned long *src, *dst;
        
        src = &_etext;
        dst = &_sdata;
        while(dst < &_edata) 
                *(dst++) = *(src++);
        
        src = &_sbss;
        while(src < &_ebss) 
                *(src++) = 0;

        main();
}