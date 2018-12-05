//
//  IAFlowLayoutAttributes.c
//

#include "IALibrary.h"
#include "IAFlowLayoutAttributes.h"

#define CLASSNAME "IAFlowLayoutAttributes"


void IAFlowLayoutAttributes_make(IAFlowLayoutAttributes * this){
	*this = (IAFlowLayoutAttributes){
		.alignment = IAFlowLayoutAlignment_front
	};
	IALayoutAttributes_make((IALayoutAttributes *) this);
}

void IAFlowLayoutAttributes_setElements(IAFlowLayoutAttributes * this, size_t elementCount, IAFlowLayoutElement elements[elementCount]) {
	this->elementCount = elementCount;
	this->elements = elements;
}
