//
//  IASlider.h
//

#ifndef IASlider_h
#define IASlider_h

#include "IADrawableRect.h"
#include "IASliderAttributes.h"
#include "IATouchDelegate.h"
#include "IASliderEvent.h"

typedef struct IASlider IASlider;

struct IASlider{
	//@extend
	IADrawableRect rect;
	IADrawableRect * background;
	IADrawableRect * handle;
	float lengthOfHandle;
	float artificialHandlePosition;

	IATouch currentTouch;
	bool isCurrentTouch;

	bool isClickable;
	IATouchDelegate touchDelegate;

	//@register
	IASliderEvent sliderEvents;
} ;


void IASlider_init(IASlider *, const IASliderAttributes * attr);

float IASlider_getValue(IASlider *);
void IASlider_setValue(IASlider *, float value);

void IASlider_setIsClickable(IASlider *, bool isClickable);

void IASlider_deinit(IASlider *);

#include "IASlider+Generated.h"

#endif
