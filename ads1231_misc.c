#include <stdint.h>
#include "ads1231_misc.h"

static const uint32_t T_STANDBY_MS = 100;
static const uint32_t T_DATA_READY_MS = 402;
static const uint8_t DATA_BITS = 24;

void initBus(void) {
    setSckAsOutput();
    setDataOutAsInput();
    setSckLow();
}

void enterStandByMode(void) {
    setSckHigh();
    delay_ms(T_STANDBY_MS);
}

void leaveStandByMode(void) {
    setSckLow();
    delay_ms(T_DATA_READY_MS);
}

uint32_t getBits(void) {
    uint32_t tmp = 0x00000000;
    
    setSckLow();
    for (uint8_t i = 0; i < DATA_BITS; ++i) {
        setSckHigh();
        uint8_t dataBit;
        dataBit = getDataOut();

    }
    //TODO add implementation
}

int32_t convertTwosToOnesComplement(uint32_t data) {
    //TODO add implementation
}

void setSckHigh(void) {
    //TODO add implementation
}

void setSckLow(void) {
    //TODO add implementation
}

uint8_t getDataOut(void) {
    //TODO add implementation
}

void delay_ms(uint32_t ms) {
    //TODO add implementation
}

void setSckAsOutput(void) {
    //TODO add implementation
}

void setDataOutAsInput(void) {
    //TODO add implementation
}
