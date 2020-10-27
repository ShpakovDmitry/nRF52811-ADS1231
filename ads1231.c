#include <stdint.h>
#include "ads1231.h"
#include "ads1231_misc.h"

void ADS1231_init(void) {
    initBus();
    enterStandByMode();
}

int32_t ADS1231_getData(void) {
    leaveStandByMode();
    uint32_t data;
    data = getBits();
    enterStandByMode();
    return convertTwosToOnesComplement(data);
}

