//
//  IASliderAttributes.h
//

#ifndef IASliderAttributes_h
#define IASliderAttributes_h

#include "IADrawableRect.h"

typedef struct {
	//@extend
	IAObject base;
	//@set+get
	IADrawableRect * background;
	//@set+get
	IADrawableRect * handle;
	//@set+get
	float lengthOfHandle;
	//@set+get
	int zOrder;
} IASliderAttributes;


void IASliderAttributes_make(IASliderAttributes *);

#include "IASliderAttributes+Generated.h"

#endif
