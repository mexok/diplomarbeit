//
//  OnOffSwitch.h
//

#ifndef OnOffSwitch_h
#define OnOffSwitch_h

#include "IADrawableRect.h"
#include "IAButton.h"
#include "OnOffSwitchAttributes.h"

typedef struct OnOffSwitch OnOffSwitch;

struct OnOffSwitch{
	//@extend
	IADrawableRect rect;
	IAButton * buttonForStateOn;
	IAButton * buttonForStateOff;
	//@get
	bool isOn;
	//@get
	bool isClickable;

	void * correspondingObject;
	void (*onStateChange)(void * correspondingObject, OnOffSwitch *);
};


void OnOffSwitch_init(OnOffSwitch *, const OnOffSwitchAttributes * attr);

void OnOffSwitch_setIsClickable(OnOffSwitch *, bool isClickable);

void OnOffSwitch_deinit(OnOffSwitch *);

#include "OnOffSwitch+Generated.h"

#endif
