//
//  IACardLayoutAttributes.h
//

#ifndef IACardLayoutAttributes_h
#define IACardLayoutAttributes_h


#include "IALayoutAttributes.h"
#include "IACardLayoutElement.h"

typedef struct{
	//@extend
	IALayoutAttributes attributes;
	//@get
	size_t elementCount;
	//@getAsConst
	IACardLayoutElement * elements;
} IACardLayoutAttributes;


void IACardLayoutAttributes_make(IACardLayoutAttributes *);

void IACardLayoutAttributes_setElements(IACardLayoutAttributes *, size_t elementCount, IACardLayoutElement elements[elementCount]);

#include "IACardLayoutAttributes+Generated.h"

#endif
