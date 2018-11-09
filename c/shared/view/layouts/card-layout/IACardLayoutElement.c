//
//  IACardLayoutElement.c
//

#include "IALibrary.h"
#include "IACardLayoutElement.h"

#define CLASSNAME "IACardLayoutElement"


void IACardLayoutElement_init(IACardLayoutElement * this, const IACardLayoutElementAttributes * attr){
	*this = (IACardLayoutElement){
		.base = IAObject_make(this),
		.content = IACardLayoutElementAttributes_getContent(attr),
		.marginLeft = IACardLayoutElementAttributes_getMarginLeft(attr),
		.marginTop = IACardLayoutElementAttributes_getMarginTop(attr),
		.marginRight = IACardLayoutElementAttributes_getMarginRight(attr),
		.marginBottom = IACardLayoutElementAttributes_getMarginBottom(attr),
		.marginLeftRelative = IACardLayoutElementAttributes_getMarginLeftRelative(attr),
		.marginTopRelative = IACardLayoutElementAttributes_getMarginTopRelative(attr),
		.marginRightRelative = IACardLayoutElementAttributes_getMarginRightRelative(attr),
		.marginBottomRelative = IACardLayoutElementAttributes_getMarginBottomRelative(attr)
	};
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IACardLayoutElement_initWithContent(IACardLayoutElement * this, IADrawableRect * content){
	IACardLayoutElementAttributes attr;
	IACardLayoutElementAttributes_make(&attr, content);
	IACardLayoutElement_init(this, &attr);
}

void IACardLayoutElement_initCopy(IACardLayoutElement * this, const IACardLayoutElement * toCopy) {
	*this = *toCopy;
	this->base = IAObject_make(this);
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IACardLayoutElement_deinit(IACardLayoutElement * this){
	IADrawableRect_release(this->content);
	IA_decrementInitCount();
}
