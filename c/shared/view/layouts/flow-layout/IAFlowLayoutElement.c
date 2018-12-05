//
//  IAFlowLayoutElement.c
//

#include "IALibrary.h"
#include "IAFlowLayoutElement.h"

#define CLASSNAME "IAFlowLayoutElement"


void IAFlowLayoutElement_init(IAFlowLayoutElement * this, const IAFlowLayoutElementAttributes * attr){
#ifdef DEBUG
	int definedLengthCount = 0;
	if (IAFlowLayoutElementAttributes_hasFixedLength(attr)){
		definedLengthCount++;
	}
	if (IAFlowLayoutElementAttributes_hasRelativeLength(attr)){
		definedLengthCount++;
	}
	if (IAFlowLayoutElementAttributes_hasFixedProportion(attr)){
		definedLengthCount++;
	}
	assert(definedLengthCount <= 1 && "A flow layout element length can only be defined once.");
#endif

	this->base = IAObject_make(this);
	this->content = IAFlowLayoutElementAttributes_getContent(attr);
	this->fixedLength = IAFlowLayoutElementAttributes_getFixedLength(attr);
	this->hasFixedLength = IAFlowLayoutElementAttributes_hasFixedLength(attr);
	this->relativeLength = IAFlowLayoutElementAttributes_getRelativeLength(attr);
	this->hasRelativeLength = IAFlowLayoutElementAttributes_hasRelativeLength(attr);
	this->fixedProportion = IAFlowLayoutElementAttributes_getFixedProportion(attr);
	this->hasFixedProportion = IAFlowLayoutElementAttributes_hasFixedProportion(attr);
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
	this->relativeLength = toCopy->relativeLength;
	this->hasRelativeLength = toCopy->hasRelativeLength;
	this->fixedProportion = toCopy->fixedProportion;
	this->hasFixedProportion = toCopy->hasFixedProportion;
	IADrawableRect_retain(this->content);
	IA_incrementInitCount();
}

bool IAFlowLayoutElement_hasDefinedLength(IAFlowLayoutElement * this){
	if (this->hasFixedLength == true
	    || this->hasRelativeLength == true
        || this->hasFixedProportion == true){
		return true;
	}else{
		return false;
	}
}

float IAFlowLayoutElement_getDefinedLength(IAFlowLayoutElement * this, float totalLength, float otherLength){
	if (this->hasFixedLength){
		return this->fixedLength;
	}else if (this->hasRelativeLength){
		return this->relativeLength * totalLength;
	}else if (this->hasFixedProportion){
		return otherLength * this->fixedProportion;
	}else{
		logError("IAFlowLayoutElement_getDefinedLength called but objekt has not a defined length.");
		assert(0);
		return 0.0f;
	}
}

void IAFlowLayoutElement_deinit(IAFlowLayoutElement * this){
	IADrawableRect_release(this->content);
	IA_decrementInitCount();
}
