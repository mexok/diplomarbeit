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
	//@get
	float fixedLength;
	//@get
	bool hasFixedLength;
} IAFlowLayoutElement;


void IAFlowLayoutElement_init(IAFlowLayoutElement *, const IAFlowLayoutElementAttributes * attr);
void IAFlowLayoutElement_initWithContent(IAFlowLayoutElement *, IADrawableRect * content);
void IAFlowLayoutElement_initCopy(IAFlowLayoutElement *, const IAFlowLayoutElement * toCopy);

void IAFlowLayoutElement_deinit(IAFlowLayoutElement *);

#include "IAFlowLayoutElement+Generated.h"

#endif
