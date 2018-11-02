//
//  IAFlowLayoutElement.c
//

#include "IALibrary.h"
#include "IAFlowLayoutElement.h"

#define CLASSNAME "IAFlowLayoutElement"


void IAFlowLayoutElement_init(IAFlowLayoutElement * this, const IAFlowLayoutElementAttributes * attr){
	this->base = IAObject_make(this);
	this->content = IAFlowLayoutElementAttributes_getContent(attr);
	this->fixedLength = IAFlowLayoutElementAttributes_getFixedLength(attr);
	this->hasFixedLength = IAFlowLayoutElementAttributes_hasFixedLength(attr);
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAFlowLayoutElement_initWithContent(IAFlowLayoutElement * this, IADrawableRect * content){
	IAFlowLayoutElementAttributes attr;
	IAFlowLayoutElementAttributes_make(&attr, content);
	IAFlowLayoutElement_init(this, &attr);
}

void IAFlowLayoutElement_initCopy(IAFlowLayoutElement * this, const IAFlowLayoutElement * toCopy) {
	this->base = IAObject_make(this);
	this->content = toCopy->content;
	this->fixedLength = toCopy->fixedLength;
	this->hasFixedLength = toCopy->hasFixedLength;
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAFlowLayoutElement_deinit(IAFlowLayoutElement * this){
	IADrawableRect_release(this->content);
	IA_decrementInitCount();
}
