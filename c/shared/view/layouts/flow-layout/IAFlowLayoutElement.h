//
//  IAFlowLayoutElement.h
//

#ifndef IAFlowLayoutElement_h
#define IAFlowLayoutElement_h

#include "IADrawableRect.h"
#include "IAFlowLayoutElementAttributes.h"

typedef struct{
	//@extend
	IAObject base;
	//@get
	IADrawableRect * content;
	float fixedLength;
	bool hasFixedLength;
	float relativeLength;
	bool hasRelativeLength;
} IAFlowLayoutElement;


void IAFlowLayoutElement_init(IAFlowLayoutElement *, const IAFlowLayoutElementAttributes * attr);
void IAFlowLayoutElement_initWithContent(IAFlowLayoutElement *, IADrawableRect * content);
void IAFlowLayoutElement_initCopy(IAFlowLayoutElement *, const IAFlowLayoutElement * toCopy);

bool IAFlowLayoutElement_hasDefinedLength(IAFlowLayoutElement *);
float IAFlowLayoutElement_getDefinedLength(IAFlowLayoutElement *, float totalLength);

void IAFlowLayoutElement_deinit(IAFlowLayoutElement *);

#include "IAFlowLayoutElement+Generated.h"

#endif
