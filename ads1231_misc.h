#ifndef ADS1231_MISC_H
#define ADS1231_MISC_H

#include <stdint.h>
#include <stdbool.h>

void ADS1231_initBus(void);
void ADS1231_enterStandByMode(void);
void ADS1231_leaveStandByMode(void);
uint32_t ADS1231_getBits(void);
int32_t convertTwosToOnesComplement(uint32_t data);
void ADS1231_delay_ms(uint32_t ms);

#endif  // ADS1231_MISC_H
