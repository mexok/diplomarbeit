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
	void * correspondingObject;
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
	void(*onScrollBegin)(void * correspondingObject, IAScrollLayout * scrollView);
	//@set+get
	void(*onScrollEnd)(void * correspondingObject, IAScrollLayout * scrollView);
	//@set+get
	uint64_t(*getTime)();
	//@set+get
	int zOrder;
} IAScrollLayoutAttributes;


void IAScrollLayoutAttributes_make(IAScrollLayoutAttributes * this, void * correspondingObject, IADrawableRect * content);

#include "IAScrollLayoutAttributes+Generated.h"

#endif
