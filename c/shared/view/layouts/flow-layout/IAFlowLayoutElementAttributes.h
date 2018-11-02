//
//  IAFlowLayoutElementAttributes.h
//

#ifndef IAFlowLayoutElementAttributes_h
#define IAFlowLayoutElementAttributes_h

#include "IAObject.h"
#include "IADrawableRect.h"

typedef struct {
	//@extend
	IAObject base;
	//@get
	IADrawableRect * content;
	//@get
	float fixedLength;
	//@get
	bool hasFixedLength;
} IAFlowLayoutElementAttributes;


void IAFlowLayoutElementAttributes_make(IAFlowLayoutElementAttributes *, IADrawableRect * content);

void IAFlowLayoutElementAttributes_setFixedLength(IAFlowLayoutElementAttributes *, float fixedLength);

#include "IAFlowLayoutElementAttributes+Generated.h"

#endif
