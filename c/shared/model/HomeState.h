//
//  HomeState.h
//

#ifndef HomeState_h
#define HomeState_h

#include "IAObject.h"
#include "IANotificationEvent.h"

typedef struct {
	//@extend
	IAObject base;
	//@get
	float currentRoomTemperature;
	//@set+get
	float targetRoomTemperature;
	//@register
	IANotificationEvent onTemperatureChanged;
} HomeState;


void HomeState_init(HomeState *, float currentRoomTemperature, float targetRoomTemperature);

void HomeState_updateTime(HomeState *, uint64_t timeDiff);

void HomeState_deinit(HomeState *);

#include "HomeState+Generated.h"

#endif
