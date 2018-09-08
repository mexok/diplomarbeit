//
//  IAFlowLayoutElement.c
//

#include "IALibrary.h"
#include "IAFlowLayoutElement.h"

#define CLASSNAME "IAFlowLayoutElement"


void IAFlowLayoutElement_make(IAFlowLayoutElement * this, IADrawableRect * content){
	this->content = content;
}

void IAFlowLayoutElement_makeCopy(IAFlowLayoutElement * this, const IAFlowLayoutElement * toCopy) {
	this->content = toCopy->content;
}
