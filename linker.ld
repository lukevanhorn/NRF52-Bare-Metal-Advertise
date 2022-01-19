/* details on syntax can be found in GCC linker manual */

MEMORY {
  FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x80000  /* total length of flash. Set to 0x80000 (524k) for NRF52832, 0x2F000 (192k) for NRF52810 */
  RAM (rwx) :  ORIGIN = 0x20000000, LENGTH = 0x10000 /* total length of RAM. Set to 0x10000 (64k) for NRF52832, 0x2F000 (24k) for NRF52810 */
}

SECTIONS {
        .isr_vector : {
                . = ALIGN(4);
                KEEP(*(.isr_vector))    /* vector table */
                . = ALIGN(4);
        } >FLASH

        .text : {
                . = ALIGN(4);
                *(.text)                /* Program code */
                *(.text.*)
                *(.rodata)              /* read only data */
                *(.rodata*)
                . = ALIGN(4);
                _etext = .;             /* _etext is end of program code */
        } >FLASH                        /* this section is code, hence gos to FLASH */

        .data : AT ( _etext ) {         /* AT specifies the LMA (load memory address) */
                . = ALIGN(4);           /* also, this section is for initialized
                                             global/static variables */
                _sdata = .;
                *(.data)
                *(.data.*)
                . = ALIGN(4);
                _edata = .;
        } >RAM                          /* this section go into this RAM */

        .bss : {                        /* this section is for uninitialized global/static
                                        variables, which we set to zero */
                . = ALIGN(4);
                _sbss = .;              /* the . sets the symbol to value of current counter */
                *(.bss)
                *(COMMON)
                . = ALIGN(4);
                _ebss = .;
        } >RAM
}