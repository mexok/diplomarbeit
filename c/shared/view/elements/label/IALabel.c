//
//  IALabel.c
//

#include "IALibrary.h"
#include "IALabel.h"

#define CLASSNAME "IALabel"


void IALabel_init(IALabel *this) {
	this->base = IAObject_make(this);
	IA_incrementInitCount();
}

void IALabel_deinit(IALabel *this) {
	IA_decrementInitCount();
}
