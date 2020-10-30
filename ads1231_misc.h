#ifndef ADS1231_MISC_H
#define ADS1231_MISC_H

#include <stdint.h>
#include <stdbool.h>

void initBus(void);
void enterStandByMode(void);
void leaveStandByMode(void);
uint32_t getBits(void);
int32_t convertTwosToOnesComplement(uint32_t data);
void delay_ms(uint32_t ms);

#endif  // ADS1231_MISC_H
