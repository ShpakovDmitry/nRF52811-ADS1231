### Description
The purpose of this repo is to interface 24-bit ADC for bridge sensors 
`ADS1231` IC with `nRF52811` SoC. \
The data from `ADS1231` will be readed in single shots by `nRF52811`.

###### Schematics
Below are schematics showing how `ADS1231` is interfaced with `nRF52811`:

```
+-----------------+           +------------------+
|                 |  ADS_OUT  |                  |
|           P0.11 |-----<-----|#DRDY/DOUT        |
|                 |  ADS_SCK  |                  |
|           P0.12 |----->-----|SCLK              |
|nRF52811         |           |           ADS1231|
+-----------------+           +------------------+
```

* [Schematics](docs/schematics.md)
* [ADS1231 features](/docs/ADS1231_features.md)

###### Usage
Simply put source files in your project. And it is done.

Before any data could be fetched from `ADS1231` IC, `init()` routine should be
called:
```c
/* 
 * IMPORTANT!!!
 * init() must be called prior to any other routine related with `ADS1231`
 * This routine is blocking for ~100 ms
 * After executing `ADS1231` module is pushed in STANDBY mode
 */
void ADS1231_init(void);
```

After that data fetch routine could be called:
```c
/*
 * This routine is blocking for more than ~500 ms
 * This time includes:
 *  - pushing `ADS1231` out of STANDBY mode
 *  - internal `ADS1231` data conversion time
 *  - data fetch from `ADS1231`
 *  - pushing `ADS1231` in STANDBY mode
 * NOTE:
 *  If RTOS is used timings in delay loop may be inacurate
 *  thus higher delay may occur.
 * 
 * Data is returned in signed integer.
 */
int32_t ADS1231_getData(void);  // value in range -8388608 <= x <= 8388607

```

> :warning: **after data readout**, `ADS1231` IC is pushed in **STANDBY** mode.

> :warning: As for proper timings, time delays are needed and no hardware timer
is used, delay loop is used. 

