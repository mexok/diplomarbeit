//
//  IALabelAttributes.c
//

#include "IALibrary.h"
#include "IALabelAttributes.h"

#define CLASSNAME "IALabelAttributes"


void IALabelAttributes_make(IALabelAttributes *this) {
	this->base = IAObject_make(this);
}
