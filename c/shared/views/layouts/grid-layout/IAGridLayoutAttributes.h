//
//  IAGridLayoutAttributes.h
//

#ifndef IAGridLayoutAttributes_h
#define IAGridLayoutAttributes_h

#include <stdint.h>
#include "IAGridLayoutElement.h"

typedef struct {
	//@get
	size_t elementCount;
	//@getAsConst
	IAGridLayoutElement * elements;
	//@set+get
	size_t gridWidth;
	//@set+get
	size_t gridHeight;
	//@set+get
	float spacing;
} IAGridLayoutAttributes;


void IAGridLayoutAttributes_make(IAGridLayoutAttributes *);

void IAGridLayoutAttributes_setElements(IAGridLayoutAttributes *, size_t elementCount, IAGridLayoutElement elements[elementCount]);

#include "IAGridLayoutAttributes+Generated.h"

#endif
