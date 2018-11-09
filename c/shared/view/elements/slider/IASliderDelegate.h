//
//  IASliderDelegate.h
//

#ifndef IASliderDelegate_h
#define IASliderDelegate_h

typedef struct IASlider IASlider;

//@event
typedef struct {
	void * correspondingObject;
	//@exe
	void (*onValueChanged)(void * correspondingObject, float value, IASlider * slider);
} IASliderDelegate;

#include "IASliderDelegate+Generated.h"

#endif
