//
//  IACardLayoutElementAttributes.c
//

#include "IALibrary.h"
#include "IACardLayoutElementAttributes.h"

#define CLASSNAME "IACardLayoutElementAttributes"


void IACardLayoutElementAttributes_make(IACardLayoutElementAttributes *this, IADrawableRect * content) {
	*this = (IACardLayoutElementAttributes){
		.base = IAObject_make(this),
		.content = content
	};
}

void IACardLayoutElementAttributes_setMargins(IACardLayoutElementAttributes * this, float margins){
	this->marginLeft = margins;
	this->marginTop = margins;
	this->marginRight = margins;
	this->marginBottom = margins;
}

void IACardLayoutElementAttributes_setMarginsRelative(IACardLayoutElementAttributes * this, float marginsRelative){
	this->marginLeftRelative = marginsRelative;
	this->marginTopRelative = marginsRelative;
	this->marginRightRelative = marginsRelative;
	this->marginBottomRelative = marginsRelative;
}
