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

void IAFlowLayoutElementAttributes_setRelativeLength(IAFlowLayoutElementAttributes *this, float relativeLength){
	this->relativeLength = relativeLength;
	this->hasRelativeLength = true;
}

void IAFlowLayoutElementAttributes_setFixedProportion(IAFlowLayoutElementAttributes *this, float fixedProportion){
	this->fixedProportion = fixedProportion;
	this->hasFixedProportion = true;
}
