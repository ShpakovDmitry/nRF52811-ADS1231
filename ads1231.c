#include <stdint.h>
#include "ads1231.h"
#include "ads1231_misc.h"

void ADS1231_init(void) {
    ADS1231_initBus();
    ADS1231_enterStandByMode();
}

int32_t ADS1231_getData(void) {
    ADS1231_leaveStandByMode();
    uint32_t data;
    data = ADS1231_getBits();
    ADS1231_enterStandByMode();
    return convertTwosToOnesComplement(data);
}

