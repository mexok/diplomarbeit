//
//  IAFlowLayoutElement.c
//

#include "IALibrary.h"
#include "IAFlowLayoutElement.h"

#define CLASSNAME "IAFlowLayoutElement"


void IAFlowLayoutElement_init(IAFlowLayoutElement * this, IADrawableRect * content){
	this->content = content;
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAFlowLayoutElement_initCopy(IAFlowLayoutElement * this, const IAFlowLayoutElement * toCopy) {
	this->content = toCopy->content;
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

void IAFlowLayoutElement_deinit(IAFlowLayoutElement * this){
	IADrawableRect_release(this->content);
	IA_decrementInitCount();
}
