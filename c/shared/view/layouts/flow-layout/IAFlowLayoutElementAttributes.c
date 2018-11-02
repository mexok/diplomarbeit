//
//  IAFlowLayoutElementAttributes.c
//

#include "IALibrary.h"
#include "IAFlowLayoutElementAttributes.h"

#define CLASSNAME "IAFlowLayoutElementAttributes"


void IAFlowLayoutElementAttributes_make(IAFlowLayoutElementAttributes *this, IADrawableRect * content) {
	*this = (IAFlowLayoutElementAttributes){
		.base = IAObject_make(this),
		.content = content
	};
}

void IAFlowLayoutElementAttributes_setFixedLength(IAFlowLayoutElementAttributes *this, float fixedLength){
	this->fixedLength = fixedLength;
	this->hasFixedLength = true;
}