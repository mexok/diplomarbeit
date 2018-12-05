//
//  IALabelAttributes.c
//

#include "IALibrary.h"
#include "IALabelAttributes.h"

#define CLASSNAME "IALabelAttributes"


void IALabelAttributes_init(IALabelAttributes *this, const char * text, IAColorableFontAtlas * font){
	*this = (IALabelAttributes){
		.base = IAObject_make(this),
		.font = font,
		.textAlignment = IATextAlignment_left,
		.fontColor = IAColor_black
	};
	IAString_init(&this->text, text);
	IA_incrementInitCount();
}

void IALabelAttributes_deinit(IALabelAttributes *this){
	IAString_deinit(&this->text);
	IA_decrementInitCount();
}