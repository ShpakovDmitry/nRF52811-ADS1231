#include <stdint.h>
#include <stdbool.h>
#include "ads1231_misc.h"

static const uint32_t T_STANDBY_MS = 100;
static const uint32_t T_DATA_READY_MS = 402;
static const uint8_t DATA_BITS = 24;
static const uint32_t GPIO_PORT_0_BASE_ADDRESS 0x50000000u
static const uint8_t DOUT_PIN = 11;
static const uint8_t SCK_PIN = 12;

typedef volatile struct __attribute__((packed)) {
    uint32_t reserved0[321];    /* 0x000 - 0x500 reserved */
    uint32_t OUT;               /* 0x504 Write GPIO port */
    uint32_t OUTSET;            /* 0x508 Set individual bits in GPIO port */
    uint32_t OUTCLR;            /* 0x50C Clear individual bit in GPIO port */
    uint32_t IN;                /* 0x510 Read GPIO port */
    uint32_t DIR;               /* 0x514 Direction of GPIO port */
    uint32_t DIRSET;            /* 0x518 DIR set register */
    uint32_t DIRCLR;            /* 0x51C DIR clear register */
    uint32_t LATCH;             /* 0x520 Latch register */
    uint32_t DETECTMODE;        /* 0x524 Mode select */
    uint32_t reserved1[118];    /* 0x528 - 0x6FC reserved */
    uint32_t PIN_CNF[32];       /* 0x700 - 0x77C Configuration of GPIO pins*/
} GPIO_Registers;

static GPIO_Registers* gpio0 = (GPIO_Registers* ) GPIO_PORT_0_BASE_ADDRESS;

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
        tmp |= getDataOut();
        tmp <<= 1;
        setSckLow();
    }
    return tmp;
}

int32_t convertTwosToOnesComplement(uint32_t data) {
    bool isNegative = false;
    int32_t tmp = 0;

    isNegative = isTwosComplementNegative(data, DATA_BITS);
    if (isNegative == true) {
        data = inverseTwosComplement(data, DATA_BITS);
    }
    tmp = (int32_t) data;
    if (isNegative == true) {
        tmp *= -1;
    }
    return tmp;
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

bool isTwosComplementNegative(uint32_t data, uint8_t dataBits) {
    return (data & (1 << dataBits)) ? true : false;
}

uint32_t inverseTwosComplement(uint32_t data, uint8_t dataBits) {
    if (data == (1 << (dataBits - 1))) {    // proper handle of the edge case
        data--;                             // when data is equal to max. neg.
    }                                       // value.
    data = ~data;
    data++;
}
