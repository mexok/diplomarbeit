#include "IALibrary.h"
#include "IAScrollLayoutAttributes.h"
#include "IAViewPort.h"
#include "IATime.h"

#define CLASSNAME "IAScrollLayoutAttributes"


void IAScrollLayoutAttributes_make(IAScrollLayoutAttributes * this, void * correspondingObject, IADrawableRect * content){
	*this = (IAScrollLayoutAttributes) {
			.correspondingObject = correspondingObject,
			.content = content,
			.getTime = IATime_getTimeInMilliseconds
	};
	IALayoutAttributes_make((IALayoutAttributes *) this);
	this->decelerationForScrollingInPixelPerTimeUnitSquared = 0.003f;
	this->overscrollingBehavior = (IAOverscrollingBehavior) {
			.maximumOverscrollingInPixel = 120.0f,
			.dragLengthToReachMaximumOverscrolling = 300.0f,
			.decelerationInPixelPerTimeUnitSquared = 0.004f
	};

}
