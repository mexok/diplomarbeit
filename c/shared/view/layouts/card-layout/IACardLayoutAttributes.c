//
//  IACardLayoutAttributes.c
//

#include "IALibrary.h"
#include "IACardLayoutAttributes.h"

#define CLASSNAME "IACardLayoutAttributes"


void IACardLayoutAttributes_make(IACardLayoutAttributes * this){
	*this = (IACardLayoutAttributes){
	};
	IALayoutAttributes_make((IALayoutAttributes *) this);
}

void IACardLayoutAttributes_setElements(IACardLayoutAttributes * this, size_t elementCount, IACardLayoutElement elements[elementCount]) {
	this->elementCount = elementCount;
	this->elements = elements;
}
