//
//  IALayoutAttributes.c
//

#include "IALibrary.h"
#include "IALayoutAttributes.h"

#define CLASSNAME "IALayoutAttributes"


void IALayoutAttributes_make(IALayoutAttributes * this) {
	*this = (IALayoutAttributes){
		.base = IAObject_make(this)
	};
}

void IALayoutAttributes_setBackgroundColor(IALayoutAttributes * this, IAColor backgroundColor){
	this->backgroundColor = backgroundColor;
	this->hasBackgroundColor = true;
}

void IALayoutAttributes_setPadding(IALayoutAttributes * this, float padding){
	this->paddingLeft = padding;
	this->paddingTop = padding;
	this->paddingRight = padding;
	this->paddingBottom = padding;
}
