//
//  IAFlowLayout.c
//

#include "IALibrary.h"
#include "IAFlowLayout.h"

#define CLASSNAME "IAFlowLayout"


static void draw(const IAFlowLayout * this);
static void setRect(IAFlowLayout * this, IARect rect);
static IASize getMinSizeNeeded(IAFlowLayout * this);



void IAFlowLayout_init(IAFlowLayout * this, const IAFlowLayoutAttributes * attr){
	IADrawableRect_make((IADrawableRect *) this, (void (*)(const IADrawable *)) draw, (void (*)(IADrawableRect *, IARect)) setRect, (IASize (*)(const IADrawableRect *)) getMinSizeNeeded);
	this->elementCount = IAFlowLayoutAttributes_getElementCount(attr);
	const IAFlowLayoutElement * elements = IAFlowLayoutAttributes_getElements(attr);
	this->elements = IA_malloc(sizeof(IAFlowLayoutElement) * this->elementCount);
	for (size_t i = 0; i < this->elementCount; i++) {
		IAFlowLayoutElement_initCopy(this->elements + i, elements + i);
	}
	this->spacing = IAFlowLayoutAttributes_getSpacing(attr);
	this->isVertical = IAFlowLayoutAttributes_isVertical(attr);
	IA_incrementInitCount();
}

static void draw(const IAFlowLayout * this) {
	for (size_t i = 0; i < this->elementCount; ++i) {
		IADrawableRect * content = IAFlowLayoutElement_getContent(&this->elements[i]);
		IADrawableRect_draw(content);
	}
}

static void getMinLengthAndMaxOtherLength(IAFlowLayout * this, float * minLengthOut, float * maxOtherLengthOut){
	float minLength = 0.0f;
	float maxOtherLength = 0.0f;
	for (size_t i = 0; i < this->elementCount; ++i) {
		IADrawableRect * content = IAFlowLayoutElement_getContent(&this->elements[i]);
		IASize minSizeOfContent = IADrawableRect_getMinSizeNeeded(content);
		float minLengthOfContent = this->isVertical ? minSizeOfContent.height : minSizeOfContent.width;
		float maxOtherLengthOfContent = this->isVertical ? minSizeOfContent.width : minSizeOfContent.height;
		minLength += minLengthOfContent;
		if (maxOtherLengthOfContent > maxOtherLength) {
			maxOtherLength = maxOtherLengthOfContent;
		}
	}
	*minLengthOut = minLength;
	*maxOtherLengthOut = maxOtherLength;
}

static void getScaleFactorAndSpacing(IAFlowLayout * this, float totalLength, float * scaleFactorOut, float * additionalLengthOut, float * spacingOut){
	float minLength, maxOtherLength;
	getMinLengthAndMaxOtherLength(this, &minLength, &maxOtherLength);
	size_t numberOfSpaces = (this->elementCount - 1);

	float scaleFactor;
	float additionalLength;
	float spacing;
	if (totalLength < minLength){
		scaleFactor = totalLength / minLength;
		spacing = 0.0f;
		additionalLength = 0.0f;
	}else{
		float totalSpacing = numberOfSpaces * this->spacing;
		if (totalLength < totalSpacing){
			scaleFactor = 0.0f;
			spacing = totalLength / numberOfSpaces;
			additionalLength = 0.0f;
		}else{
			scaleFactor = 1.0f;
			spacing = this->spacing;
			additionalLength = (totalLength - totalSpacing - minLength) / this->elementCount;
		}
	}
	*scaleFactorOut = scaleFactor;
	*additionalLengthOut = additionalLength;
	*spacingOut = spacing;
}

static void setRect(IAFlowLayout * this, IARect rect) {
	if (this->elementCount == 0){
		return;
	}

	float totalLength = this->isVertical ? rect.size.height : rect.size.width;

	float scaleFactor, additionalLength, spacing;
	getScaleFactorAndSpacing(this, totalLength, &scaleFactor, &additionalLength, &spacing);

	float offset = 0.0f;
	for (size_t i = 0; i < this->elementCount; ++i) {
		IADrawableRect * content = IAFlowLayoutElement_getContent(&this->elements[i]);
		IASize size = IADrawableRect_getMinSizeNeeded(content);
		IARect contentRect = {
				.origin = {
						.x = this->isVertical ? rect.origin.x : rect.origin.x + offset,
						.y = this->isVertical ? rect.origin.y + offset : rect.origin.y,
				},
				.size = {
						.width = this->isVertical ? rect.size.width : size.width * scaleFactor + additionalLength,
						.height = this->isVertical ? size.height * scaleFactor + additionalLength : rect.size.height,
				}
		};
		IADrawableRect_setRect(content, contentRect);
		offset += this->isVertical ? contentRect.size.height : contentRect.size.width;
		offset += spacing;
	}
}

static IASize getMinSizeNeeded(IAFlowLayout * this) {
	if (this->elementCount == 0){
		return IASize_ZERO;
	}
	float minLength, maxOtherLength;
	getMinLengthAndMaxOtherLength(this, &minLength, &maxOtherLength);
	minLength += (this->elementCount - 1) * this->spacing;
	if (this->isVertical){
		return IASize_make(maxOtherLength, minLength);
	}else{
		return IASize_make(minLength, maxOtherLength);
	}
}

void IAFlowLayout_deinit(IAFlowLayout * this){
	for (size_t i = 0; i < this->elementCount; i++) {
		IAFlowLayoutElement_deinit(this->elements + i);
	}
	IA_free(this->elements);
	IA_decrementInitCount();
}
