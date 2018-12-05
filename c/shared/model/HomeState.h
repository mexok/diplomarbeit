//
//  HomeState.h
//

#ifndef HomeState_h
#define HomeState_h

#include "IAObject.h"
#include "IANotificationEvent.h"
#include "IAColor.h"

typedef struct {
	//@extend
	IAObject base;
	//@get
	float currentRoomTemperature;
	//@get
	float targetRoomTemperature;

	//@get
	IAColor livingRoomLampColor;
	//@get
	float livingRoomLampDimmedPercentage;

	//@get
	bool isTvLivingRoomOn;
	//@get
	bool isTvKitchenOn;

	//@get
	bool isLeftKitchenWindowOpen;
	//@get
	bool isAlarmSystemOn;

	//@register
	IANotificationEvent onTemperatureChanged;
} HomeState;


void HomeState_init(HomeState *, float currentRoomTemperature, float targetRoomTemperature);

void HomeState_setTargetRoomTemperature(HomeState *, float targetRoomTemperature);
void HomeState_setLivingRoomLampColor(HomeState *, IAColor livingRoomLampColor);
void HomeState_setLivingRoomLampDimmedPercentage(HomeState *, float livingRoomLampDimmedPercentage);
void HomeState_setIsTvLivingRoomOn(HomeState *, bool isTvLivingRoomOn);
void HomeState_setIsTvKitchenOn(HomeState *, bool isTvKitchenOn);
void HomeState_setIsLeftKitchenWindowOpen(HomeState *, bool isLeftKitchenWindowOpen);
void HomeState_setIsAlarmSystemOn(HomeState *, bool isAlarmSystemOn);

void HomeState_updateTime(HomeState *, uint64_t timeDiff);

void HomeState_deinit(HomeState *);

#include "HomeState+Generated.h"

#endif
