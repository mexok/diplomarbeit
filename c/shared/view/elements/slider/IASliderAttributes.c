//
//  IASliderAttributes.c
//

#include "IALibrary.h"
#include "IASliderAttributes.h"

#define CLASSNAME "IASliderAttributes"


void IASliderAttributes_make(IASliderAttributes * this) {
	*this = (IASliderAttributes){
		.base = IAObject_make(this),
		.lengthOfHandle = 20.0f
    };
}
