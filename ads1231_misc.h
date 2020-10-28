#ifndef ADS1231_MISC_H
#define ADS1231_MISC_H

#include <stdint.h>
#include <stdbool.h>

void initBus(void);
void enterStandByMode(void);
void leaveStandByMode(void);
uint32_t getBits(void);
int32_t convertTwosToOnesComplement(uint32_t data);
void setSckHigh(void);
void setSckLow(void);
uint8_t getDataOut(void);
void delay_ms(uint32_t ms);
void setSckAsOutput(void);
void setDataOutAsInput(void);
bool isTwosComplementNegative(uint32_t data, uint8_t dataBits);
uint32_t inverseTwosComplement(uint32_t data, uint8_t dataBits);

#endif  // ADS1231_MISC_H
