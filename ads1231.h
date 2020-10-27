#ifndef ADS1231_H
#define ADS1231_H

#include <stdint.h>

void ADS1231_init(void);        // must be called prior to any other
int32_t ADS1231_getData(void);  // value in range -8388608 <= x <= 8388607

#endif  // ADS1231_H
