//
//  IAFlowLayoutAttributes.h
//

#ifndef IAFlowLayoutAttributes_h
#define IAFlowLayoutAttributes_h


#include "IAFlowLayoutElement.h"

typedef struct{
	//@get
	size_t elementCount;
	//@getAsConst
	IAFlowLayoutElement * elements;
	//@set+get
	float spacing;
	//@set+get
	bool isVertical;
} IAFlowLayoutAttributes;


void IAFlowLayoutAttributes_make(IAFlowLayoutAttributes *);

void IAFlowLayoutAttributes_setElements(IAFlowLayoutAttributes *, size_t elementCount, IAFlowLayoutElement elements[elementCount]);

#include "IAFlowLayoutAttributes+Generated.h"

#endif
