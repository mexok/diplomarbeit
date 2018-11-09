//
//  OnOffSwitchDelegate.h
//

#ifndef OnOffSwitchDelegate_h
#define OnOffSwitchDelegate_h

#include <stdbool.h>

typedef struct OnOffSwitch OnOffSwitch;

//@event
typedef struct {
	void * correspondingObject;
	//@exe
	void (*onStateChanged)(void * correspondingObject, bool isOn, OnOffSwitch * onOffSwitch);
} OnOffSwitchDelegate;

#include "OnOffSwitchDelegate+Generated.h"

#endif
