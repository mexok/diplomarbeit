//
//  IAGridLayoutElement.c
//

#include "IALibrary.h"
#include "IAGridLayoutElement.h"

#define CLASSNAME "IAGridLayoutElement"


void IAGridLayoutElement_init(IAGridLayoutElement * this, const IAGridLayoutElementAttributes * attr) {
	*this = (IAGridLayoutElement) {
			.content = IAGridLayoutElementAttributes_getContent(attr),
			.offsetX = IAGridLayoutElementAttributes_getOffsetX(attr),
			.offsetY = IAGridLayoutElementAttributes_getOffsetY(attr),
			.width = IAGridLayoutElementAttributes_getWidth(attr),
			.height = IAGridLayoutElementAttributes_getHeight(attr)
	};
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAGridLayoutElement_initCopy(IAGridLayoutElement * this, const IAGridLayoutElement * toCopy){
	*this = *toCopy;
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAGridLayoutElement_deinit(IAGridLayoutElement * this){
	IADrawableRect_release(this->content);
	IA_decrementInitCount();
}
