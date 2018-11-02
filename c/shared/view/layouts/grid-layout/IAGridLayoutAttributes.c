//
//  IAGridLayoutAttributes.c
//

#include "IALibrary.h"
#include "IAGridLayoutAttributes.h"

#define CLASSNAME "IAGridLayoutAttributes"


void IAGridLayoutAttributes_make(IAGridLayoutAttributes * this){
	*this = (IAGridLayoutAttributes){
		.gridWidth = 1,
		.gridHeight = 1
    };
	IALayoutAttributes_make((IALayoutAttributes *) this);
}

void IAGridLayoutAttributes_setElements(IAGridLayoutAttributes * this, size_t elementCount, IAGridLayoutElement elements[elementCount]){
	this->elementCount = elementCount;
	this->elements = elements;
}
