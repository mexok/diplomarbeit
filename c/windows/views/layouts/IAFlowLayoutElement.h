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


void IAFlowLayoutElement_make(IAFlowLayoutElement *, IADrawableRect * content);
void IAFlowLayoutElement_makeCopy(IAFlowLayoutElement *, const IAFlowLayoutElement * toCopy);

#include "IAFlowLayoutElement+Generated.h"

#endif
