//
//  OnOffSwitch.c
//

#include "IALibrary.h"
#include "OnOffSwitch.h"

#define CLASSNAME "OnOffSwitch"


static void OnOffSwitch_updateButtons(OnOffSwitch * this);

static void setRect(OnOffSwitch * this, IARect rect){
	IAButton_setRect(this->buttonForStateOn, rect);
	IAButton_setRect(this->buttonForStateOff, rect);
}

static void draw(OnOffSwitch * this){
	if (this->isOn){
		IAButton_draw(this->buttonForStateOn);
	}else{
		IAButton_draw(this->buttonForStateOff);
	}
}

static void onButtonStateOnClicked(OnOffSwitch * this, IAButton * button){
	this->isOn = false;
	OnOffSwitch_updateButtons(this);
	OnOffSwitchEvent_onStateChanged(&this->events, this->isOn, this);
}

static void onButtonStateOffClicked(OnOffSwitch * this, IAButton * button){
	this->isOn = true;
	OnOffSwitch_updateButtons(this);
	OnOffSwitchEvent_onStateChanged(&this->events, this->isOn, this);
}

void OnOffSwitch_init(OnOffSwitch * this, const OnOffSwitchAttributes * attr) {
	*this = (OnOffSwitch){
    };
	IADrawableRect_make((IADrawableRect *) this, (IADrawable_drawFunction) draw, (IADrawableRect_setRectFunction) setRect);

	this->buttonForStateOnDelegate = (IAButtonDelegate){
		.correspondingObject = this,
		.onClick = (void (*)(void *, IAButton *)) onButtonStateOnClicked
	};
	this->buttonForStateOffDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onButtonStateOffClicked
	};

	IAButtonAttributes buttonAttributes;
	IAButtonAttributes_make(&buttonAttributes);
	IAButtonAttributes_setNormal(&buttonAttributes, OnOffSwitchAttributes_getStateOnNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, OnOffSwitchAttributes_getStateOnTouched(attr));
	this->buttonForStateOn = IAButton_new(&buttonAttributes);
	IAButton_registerForTouchEvents(this->buttonForStateOn, &this->buttonForStateOffDelegate);
	IAButtonAttributes_setNormal(&buttonAttributes, OnOffSwitchAttributes_getStateOffNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, OnOffSwitchAttributes_getStateOffTouched(attr));
	this->buttonForStateOff = IAButton_new(&buttonAttributes);
	IAButton_registerForTouchEvents(this->buttonForStateOff, &this->buttonForStateOffDelegate);

	OnOffSwitchEvent_init(&this->events);

	IA_incrementInitCount();
}

void OnOffSwitch_setIsClickable(OnOffSwitch * this, bool isClickable){
	if (this->isClickable != isClickable){
		this->isClickable = isClickable;
		OnOffSwitch_updateButtons(this);
	}
}

static void OnOffSwitch_updateButtons(OnOffSwitch * this){
	if (this->isClickable){
		if (this->isOn){
			IAButton_setIsClickable(this->buttonForStateOn, true);
			IAButton_setIsClickable(this->buttonForStateOff, false);
		}else{
			IAButton_setIsClickable(this->buttonForStateOn, false);
			IAButton_setIsClickable(this->buttonForStateOff, true);
		}
	}else{
		IAButton_setIsClickable(this->buttonForStateOn, false);
		IAButton_setIsClickable(this->buttonForStateOff, false);
	}
}

void OnOffSwitch_deinit(OnOffSwitch * this) {
	OnOffSwitchEvent_deinit(&this->events);
	IAButton_release(this->buttonForStateOn);
	IAButton_release(this->buttonForStateOff);
	IA_decrementInitCount();
}
