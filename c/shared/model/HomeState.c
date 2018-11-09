//
//  HomeState.c
//

#include <math.h>

#include "IALibrary.h"
#include "HomeState.h"

#define CLASSNAME "HomeState"


void HomeState_init(HomeState * this, float currentRoomTemperature, float targetRoomTemperature) {
	*this = (HomeState){
		.base = IAObject_make(this),
		.currentRoomTemperature = currentRoomTemperature,
		.targetRoomTemperature = targetRoomTemperature
	};
	IANotificationEvent_init(&this->onTemperatureChanged);
	IA_incrementInitCount();
}

void HomeState_updateTime(HomeState * this, uint64_t timeDiff){
	float temperatureDiff = 0.0005f * timeDiff;
	float oldTemperature = this->currentRoomTemperature;
	if (temperatureDiff >= fabsf(this->currentRoomTemperature - this->targetRoomTemperature)){
		this->currentRoomTemperature = this->targetRoomTemperature;
	}else{
		if (this->targetRoomTemperature > this->currentRoomTemperature){
			this->currentRoomTemperature += temperatureDiff;
		}else{
			this->currentRoomTemperature -= temperatureDiff;
		}
	}
	if (this->currentRoomTemperature != oldTemperature){
		IANotificationEvent_notify(&this->onTemperatureChanged);
	}
}

void HomeState_deinit(HomeState * this) {
	IANotificationEvent_deinit(&this->onTemperatureChanged);
	IA_decrementInitCount();
}
