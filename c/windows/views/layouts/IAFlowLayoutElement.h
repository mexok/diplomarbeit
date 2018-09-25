//
//  IAFlowLayoutElement.h
//

#ifndef IAFlowLayoutElement_h
#define IAFlowLayoutElement_h

#include "IADrawableRect.h"

typedef struct{
	//@get
	IADrawableRect * content;
} IAFlowLayoutElement;


void IAFlowLayoutElement_init(IAFlowLayoutElement *, IADrawableRect * content);
void IAFlowLayoutElement_initCopy(IAFlowLayoutElement *, const IAFlowLayoutElement * toCopy);

void IAFlowLayoutElement_deinit(IAFlowLayoutElement *);

#include "IAFlowLayoutElement+Generated.h"

#endif
