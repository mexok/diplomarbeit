//
//  IASlider.c
//


#include <math.h>

#include "IALibrary.h"
#include "IASlider.h"
#include "IATouchManager.h"
#include "IAAcceleration.h"

#define CLASSNAME "IASlider"

static bool wantToUseTouch(IASlider *, IATouch);
static void onTouchBegan(IASlider *, size_t numTouches, IATouch touches[numTouches]);
static void onTouchMoved(IASlider *, size_t numTouches, IATouch touches[numTouches]);
static void onTouchEnded(IASlider *, size_t numTouches, IATouch touches[numTouches]);
static void onTouchCanceled(IASlider *);

static void setRect(IASlider *, IARect rect);
static void draw(IASlider *);

void IASlider_init(IASlider * this, const IASliderAttributes * attr) {
	*this = (IASlider){
		.background = IASliderAttributes_getBackground(attr),
		.handle = IASliderAttributes_getHandle(attr),
		.lengthOfHandle = IASliderAttributes_getLengthOfHandle(attr),
	};
	IADrawableRect_make((IADrawableRect *) this, (IADrawable_drawFunction) draw, (IADrawableRect_setRectFunction) setRect);

	IATouchDelegateAttributes touchDelegateAttr;
	IATouchDelegateAttributes_make(&touchDelegateAttr, this);
	IATouchDelegateAttributes_setWantToUseTouchFunction(&touchDelegateAttr, (bool (*)(void *, IATouch)) wantToUseTouch);
	IATouchDelegateAttributes_setAlwaysWantToConsumeTouch(&touchDelegateAttr, true);
	IATouchDelegateAttributes_setOnTouchBeganFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch touches[])) onTouchBegan);
	IATouchDelegateAttributes_setOnTouchMovedFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch touches[])) onTouchMoved);
	IATouchDelegateAttributes_setOnTouchEndedFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch touches[])) onTouchEnded);
	IATouchDelegateAttributes_setOnTouchCanceledFunction(&touchDelegateAttr, (void(*)(void *)) onTouchCanceled);
	IATouchDelegateAttributes_setZOrder(&touchDelegateAttr, IASliderAttributes_getZOrder(attr));
	IATouchDelegate_init(&this->touchDelegate, &touchDelegateAttr);

	if (this->background != NULL){
		IADrawableRect_retain(this->background);
	}
	if (this->handle != NULL){
		IADrawableRect_retain(this->handle);
	}
	IASliderEvent_init(&this->sliderEvents);
	IA_incrementInitCount();
}

float IASlider_getValue(IASlider * this){
	float value = this->artificialHandlePosition;
	value = fminf(value, 1.0f);
	value = fmaxf(value, 0.0f);
	return value;
}

void IASlider_setValue(IASlider * this, float value){
	this->artificialHandlePosition = value;
}

static float IASlider_getSlidingLength(IASlider * this){
	IARect total = IASlider_getRect(this);
	float slidingLength = total.size.width - this->lengthOfHandle;
	slidingLength = fmaxf(slidingLength, 0.0f);
	return slidingLength;
}

static IARect IASlider_getRectOfHandle(IASlider * this){
	IARect begin = IASlider_getRect(this);
	begin.size.width = this->lengthOfHandle;
	IARect end = begin;
	end.origin.x += IASlider_getSlidingLength(this);
	float value = IASlider_getValue(this);
	IARect current = IAAcceleration_calculateCurrentRect(begin, end, value, IAAcceleration_linearMovementFunction);
	return current;
}

static bool wantToUseTouch(IASlider * this, IATouch touch){
	if (this->isCurrentTouch){
		return false;
	}
	IARect current = IASlider_getRectOfHandle(this);
	if (IARect_isPointWithin(current, touch.location)){
		return true;
	}else{
		return false;
	}
}

static void onTouchBegan(IASlider * this, size_t numTouches, IATouch touches[numTouches]){
	IARect handleRect = IASlider_getRectOfHandle(this);
	for (size_t i = 0; i < numTouches; i++) {
		if (this->isCurrentTouch == false){
			if (IARect_isPointWithin(handleRect, touches[i].location)){
				this->currentTouch = touches[i];
				this->isCurrentTouch = true;
			}
		}
	}
}

static void onTouchMoved(IASlider * this, size_t numTouches, IATouch touches[numTouches]){
	if (this->isCurrentTouch) {
		float slidingLength = IASlider_getSlidingLength(this);
		if(slidingLength > 0.0f){
			float oldValue = IASlider_getValue(this);
			for (size_t i = 0; i < numTouches; i++) {
				if (IATouch_hasSameIdentifier(this->currentTouch, touches[i])) {
					float diff = (touches[i].location.x - this->currentTouch.location.x) / slidingLength;
					this->artificialHandlePosition += diff;
					this->currentTouch = touches[i];
				}
			}
			float newValue = IASlider_getValue(this);
			if (newValue != oldValue){
				IASliderEvent_onValueChanged(&this->sliderEvents, newValue, this);
			}
		}
	}
}

static void onTouchEnded(IASlider * this, size_t numTouches, IATouch touches[numTouches]){
	if (this->isCurrentTouch) {
		for (size_t i = 0; i < numTouches; i++) {
			if (IATouch_hasSameIdentifier(this->currentTouch, touches[i])) {
				this->isCurrentTouch = false;
				this->artificialHandlePosition = fminf(this->artificialHandlePosition, 1.0f);
				this->artificialHandlePosition = fmaxf(this->artificialHandlePosition, 0.0f);
			}
		}
	}
}

static void onTouchCanceled(IASlider * this){
	this->isCurrentTouch = false;
	this->artificialHandlePosition = fminf(this->artificialHandlePosition, 1.0f);
	this->artificialHandlePosition = fmaxf(this->artificialHandlePosition, 0.0f);
}

static void setRect(IASlider * this, IARect rect){
	if (this->background != NULL){
		IADrawableRect_setRect(this->background, rect);
	}
	IARect handleRect = IASlider_getRectOfHandle(this);
	if (this->handle != NULL){
		IADrawableRect_setRect(this->handle, handleRect);
	}
}

static void draw(IASlider * this){
	if (this->background != NULL){
		IADrawableRect_draw(this->background);
	}
	if (this->handle != NULL){
		IADrawableRect_draw(this->handle);
	}
}

void IASlider_setIsClickable(IASlider * this, bool isClickable){
	if (this->isClickable != isClickable){
		this->isClickable = isClickable;
		if (this->isClickable) {
			IATouchManager_registerTouchDelegate(&this->touchDelegate);
		}else{
			IATouchManager_unregisterTouchDelegate(&this->touchDelegate);
			this->isCurrentTouch = false;
		}
	}
}

void IASlider_deinit(IASlider * this) {
	if (this->background != NULL){
		IADrawableRect_release(this->background);
	}
	if (this->handle != NULL){
		IADrawableRect_release(this->handle);
	}
	IASliderEvent_deinit(&this->sliderEvents);
	IATouchDelegate_deinit(&this->touchDelegate);
	IA_decrementInitCount();
}
