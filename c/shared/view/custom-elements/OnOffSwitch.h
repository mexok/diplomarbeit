//
//  OnOffSwitch.h
//

#ifndef OnOffSwitch_h
#define OnOffSwitch_h

#include "IADrawableRect.h"
#include "IAButton.h"
#include "OnOffSwitchAttributes.h"
#include "OnOffSwitchEvent.h"

typedef struct OnOffSwitch OnOffSwitch;

struct OnOffSwitch{
	//@extend
	IADrawableRect rect;
	IAButton * buttonForStateOn;
	IAButtonDelegate buttonForStateOnDelegate;
	IAButton * buttonForStateOff;
	IAButtonDelegate buttonForStateOffDelegate;
	//@get
	bool isOn;
	//@get
	bool isClickable;

	//@register
	OnOffSwitchEvent events;
};


void OnOffSwitch_init(OnOffSwitch *, const OnOffSwitchAttributes * attr);

void OnOffSwitch_setIsClickable(OnOffSwitch *, bool isClickable);

void OnOffSwitch_deinit(OnOffSwitch *);

#include "OnOffSwitch+Generated.h"

#endif
