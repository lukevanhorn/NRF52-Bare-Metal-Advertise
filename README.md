# nRF52-Bare-Metal-Advertise

Example bare-metal code to advertise on the nRF52x BLE SoC Series

This measures the die temperature and supply voltage / battery level once a minute. Sample data is included in the advertisement.

Tested on nRF52832 and nRF52810

Requires gcc,make, and nrfjprog command line tool to flash

### Build
``` 
make all
flash
```
