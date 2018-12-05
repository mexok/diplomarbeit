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

void HomeState_setTargetRoomTemperature(HomeState * this, float targetRoomTemperature){
	this->targetRoomTemperature = targetRoomTemperature;
	logInfo("TargetRoomTemperature has been set to %.2f", targetRoomTemperature);
}

void HomeState_setLivingRoomLampColor(HomeState * this, IAColor livingRoomLampColor){
	this->livingRoomLampColor = livingRoomLampColor;
	logInfo("LivingRoomLampColor has been set. Red: %d, Green: %d, Blue %d", livingRoomLampColor.red, livingRoomLampColor.green, livingRoomLampColor.blue);
}

void HomeState_setLivingRoomLampDimmedPercentage(HomeState * this, float livingRoomLampDimmedPercentage){
	this->livingRoomLampDimmedPercentage = livingRoomLampDimmedPercentage;
	logInfo("LivingRoomLampDimmedPercentage percentage has been set to %.4f", livingRoomLampDimmedPercentage);
}

void HomeState_setIsTvLivingRoomOn(HomeState * this, bool isTvLivingRoomOn){
	this->isTvLivingRoomOn = isTvLivingRoomOn;
	logInfo("IsTvLivingRoomOn has been set to %d", isTvLivingRoomOn);
}

void HomeState_setIsTvKitchenOn(HomeState * this, bool isTvKitchenOn){
	this->isTvKitchenOn = isTvKitchenOn;
	logInfo("IsTvKitchenOn has been set to %d", isTvKitchenOn);
}

void HomeState_setIsLeftKitchenWindowOpen(HomeState * this, bool isLeftKitchenWindowOpen){
	this->isLeftKitchenWindowOpen = isLeftKitchenWindowOpen;
	logInfo("IsLeftKitchenWindowOpen has been set to %d", isLeftKitchenWindowOpen);
}

void HomeState_setIsAlarmSystemOn(HomeState * this, bool isAlarmSystemOn){
	this->isAlarmSystemOn = isAlarmSystemOn;
	logInfo("IsAlarmSystemOn has been set to %d", isAlarmSystemOn);
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
