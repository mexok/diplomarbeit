#ifndef IAScrollLayoutAttributes_h
#define IAScrollLayoutAttributes_h


#include <stdint.h>
#include "IARect.h"
#include "IAOverscrollingBehavior.h"
#include "IADrawableRect.h"
#include "IALayoutAttributes.h"

typedef struct IAScrollLayout IAScrollLayout;


typedef struct{
	//@extend
	IALayoutAttributes layoutAttributes;
	//@get
	IADrawableRect * content;
	//@set+get
	float contentLength;
	//@set+get
	bool isHorizontal;

	//@set+get
	float decelerationForScrollingInPixelPerTimeUnitSquared;
	//@get
	IAOverscrollingBehavior overscrollingBehavior;

	//@set+get
	float thresholdInPixelForOnScrollBeginCall;
	//@set+get
	uint64_t(*getTime)();
	//@set+get
	int zOrder;
} IAScrollLayoutAttributes;


void IAScrollLayoutAttributes_make(IAScrollLayoutAttributes * this, IADrawableRect * content);

#include "IAScrollLayoutAttributes+Generated.h"

#endif
