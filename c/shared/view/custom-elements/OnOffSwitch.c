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
}

static void onButtonStateOffClicked(OnOffSwitch * this, IAButton * button){
	this->isOn = true;
	OnOffSwitch_updateButtons(this);
}

void OnOffSwitch_init(OnOffSwitch * this, const OnOffSwitchAttributes * attr) {
	*this = (OnOffSwitch){
		.correspondingObject = OnOffSwitchAttributes_getCorrespondingObject(attr),
		.onStateChange = OnOffSwitchAttributes_getOnStateChangeFunction(attr)
    };
	IADrawableRect_make((IADrawableRect *) this, (IADrawable_drawFunction) draw, (IADrawableRect_setRectFunction) setRect);

	IAButtonAttributes buttonAttributes;
	IAButtonAttributes_make(&buttonAttributes, this);
	IAButtonAttributes_setNormal(&buttonAttributes, OnOffSwitchAttributes_getStateOnNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, OnOffSwitchAttributes_getStateOnTouched(attr));
	IAButtonAttributes_setOnClickFunction(&buttonAttributes, (void (*)(void *, IAButton *)) onButtonStateOnClicked);
	this->buttonForStateOn = IAButton_new(&buttonAttributes);
	IAButtonAttributes_setNormal(&buttonAttributes, OnOffSwitchAttributes_getStateOffNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, OnOffSwitchAttributes_getStateOffTouched(attr));
	IAButtonAttributes_setOnClickFunction(&buttonAttributes, (void (*)(void *, IAButton *)) onButtonStateOffClicked);
	this->buttonForStateOff = IAButton_new(&buttonAttributes);

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
	IAButton_release(this->buttonForStateOn);
	IAButton_release(this->buttonForStateOff);
	IA_decrementInitCount();
}
