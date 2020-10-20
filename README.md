### Description
The purpose of this repo is to interface 24-bit ADC for bridge sensors 
`ADS1231` IC with `nRF52811` SoC. \
The data from `ADS1231` will be readed in single shots by `nRF52811`.

###### Schematics
Below are schematics showing how `ADS1231` is interfaced with `nRF52811`:

From `ADS1231` side:

![ADS1231\_side](docs/ADS1231.png)

From `nRF52811` side:

![nRF52811\_side](docs/nRF52811.png)

##### ADS1231 features

###### ADS1231 data rate
The `ADS1231` data rate is set by the `SPEED` pin(4). When the `SPEED` is low,
the data rate is nominally 10SPS. But if it is high then data rate is 80SPS.

###### ADS1231 data format
The `ADS1231` outputs 24 bits of data in binary two's complement format. The
LSB has weight of (0.5V\_ref/128)(2^23 - 1). The positive full scale input
produces an output code of `0x7fffff` and negative full-scale input produces
an output code of `0x800000`. The output clips at these codes for signals
exceeding full-scale.
| Input signal Vin         | Ideal output |
|:------------------------:|:------------:|
| >= +0.5Vref/128          | 0x7fffff     |
| (+0.5vref/128)(2^23 - 1) | 0x000001     |
| 0                        | 0x000000     |
| (-0.5vref/128)(2^23 - 1) | 0xffffff     |
| <= -0.5Vref/128          | 0x800000     |

