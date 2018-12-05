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
	//@get
	float relativeLength;
	//@get
	bool hasRelativeLength;
	//@get
	float fixedProportion;
	//@get
	bool hasFixedProportion;
} IAFlowLayoutElementAttributes;


void IAFlowLayoutElementAttributes_make(IAFlowLayoutElementAttributes *, IADrawableRect * content);

void IAFlowLayoutElementAttributes_setFixedLength(IAFlowLayoutElementAttributes *, float fixedLength);
void IAFlowLayoutElementAttributes_setRelativeLength(IAFlowLayoutElementAttributes *, float relativeLength);
void IAFlowLayoutElementAttributes_setFixedProportion(IAFlowLayoutElementAttributes *, float fixedProportion);

#include "IAFlowLayoutElementAttributes+Generated.h"

#endif
