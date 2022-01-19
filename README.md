# nRF52-Bare-Metal-Advertise

Example bare-metal code to advertise on the nRF52x BLE SoC Series

This project walks through how to initialize the low and high frequency clocks, BLE radio, A/D, and RTC interrupts. The project is self contained, with minimal lines of code to create a working bluetooth beacon with custom data. This example measures the chip temperature and battery level once a minute and defaults to a 500ms advertisement interval.

Tested on nRF52832 and nRF52810

Requires gcc,make, and nrfjprog command line tool to flash

### Build
``` 
make all
flash
```
