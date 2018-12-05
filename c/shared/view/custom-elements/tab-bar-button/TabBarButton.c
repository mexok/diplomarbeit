//
//  TabBarButton.c
//

#include "IALibrary.h"
#include "TabBarButton.h"

#define CLASSNAME "TabBarButton"


static void TabBarButton_updateButtons(TabBarButton * this);

static void setRect(TabBarButton * this, IARect rect){
	IAButton_setRect(this->buttonForStateOn, rect);
	IAButton_setRect(this->buttonForStateOff, rect);
}

static void draw(TabBarButton * this){
	if (this->isOn){
		IAButton_draw(this->buttonForStateOn);
	}else{
		IAButton_draw(this->buttonForStateOff);
	}
}

static void onButtonStateOnClicked(TabBarButton * this, IAButton * button){
	this->isOn = false;
	TabBarButton_updateButtons(this);
	TabBarButtonEvent_onStateChanged(&this->events, this->isOn, this);
}

static void onButtonStateOffClicked(TabBarButton * this, IAButton * button){
	this->isOn = true;
	TabBarButton_updateButtons(this);
	TabBarButtonEvent_onStateChanged(&this->events, this->isOn, this);
}

void TabBarButton_init(TabBarButton * this, const TabBarButtonAttributes * attr) {
	*this = (TabBarButton){
		.tag = TabBarButtonAttributes_getTag(attr)
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
	IAButtonAttributes_setNormal(&buttonAttributes, TabBarButtonAttributes_getStateOnNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, TabBarButtonAttributes_getStateOnTouched(attr));
	this->buttonForStateOn = IAButton_new(&buttonAttributes);
	IAButton_registerForTouchEvents(this->buttonForStateOn, &this->buttonForStateOffDelegate);
	IAButtonAttributes_setNormal(&buttonAttributes, TabBarButtonAttributes_getStateOffNormal(attr));
	IAButtonAttributes_setTouched(&buttonAttributes, TabBarButtonAttributes_getStateOffTouched(attr));
	this->buttonForStateOff = IAButton_new(&buttonAttributes);
	IAButton_registerForTouchEvents(this->buttonForStateOff, &this->buttonForStateOffDelegate);

	TabBarButtonEvent_init(&this->events);

	IA_incrementInitCount();
}

void TabBarButton_setIsOn(TabBarButton *this, bool isOn){
	if (this->isOn != isOn){
		this->isOn = isOn;
		TabBarButton_updateButtons(this);
		//We do not want to throw a state change event in this case
	}
}

void TabBarButton_setIsClickable(TabBarButton * this, bool isClickable){
	if (this->isClickable != isClickable){
		this->isClickable = isClickable;
		TabBarButton_updateButtons(this);
	}
}

static void TabBarButton_updateButtons(TabBarButton * this){
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

void TabBarButton_deinit(TabBarButton * this) {
	TabBarButtonEvent_deinit(&this->events);
	IAButton_release(this->buttonForStateOn);
	IAButton_release(this->buttonForStateOff);
	IA_decrementInitCount();
}
