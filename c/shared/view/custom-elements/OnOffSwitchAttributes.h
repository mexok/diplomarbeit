//
//  OnOffSwitchAttributes.h
//

#ifndef OnOffSwitchAttributes_h
#define OnOffSwitchAttributes_h

#include "IADrawableRect.h"

typedef struct OnOffSwitch OnOffSwitch;

typedef struct {
	//@get
	void * correspondingObject;
	//@set+get
	IADrawableRect * stateOnNormal;
	//@set+get
	IADrawableRect * stateOnTouched;
	//@set+get
	IADrawableRect * stateOffNormal;
	//@set+get
	IADrawableRect * stateOffTouched;
	//@set+get
	void (*onStateChange)(void * correspondingObject, OnOffSwitch *);
	//@set+get
	bool initialIsOn;
} OnOffSwitchAttributes;


void OnOffSwitchAttributes_make(OnOffSwitchAttributes *, void * correspondingObject);

#include "OnOffSwitchAttributes+Generated.h"

#endif
