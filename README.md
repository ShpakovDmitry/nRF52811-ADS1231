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
