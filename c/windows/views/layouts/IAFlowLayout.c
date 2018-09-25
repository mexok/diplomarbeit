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
	IADrawableRect_make((IADrawableRect *) this, (void (*)(const IADrawable *)) draw, (void (*)(IADrawableRect *, IARect)) setRect, (IASize (*)(IADrawableRect *)) getMinSizeNeeded);
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

static void getScaleFactorAndSpacing(IAFlowLayout * this, float totalLength, float * scaleFactorOut, float * spacingOut){
	float minLength, maxOtherLength;
	getMinLengthAndMaxOtherLength(this, &minLength, &maxOtherLength);

	float scaleFactor = 1.0f;
	float spacing = 0.0f;
	if (totalLength < minLength){
		scaleFactor = totalLength / minLength;
	}else{
		float totalSpacing = (this->elementCount - 1) * this->spacing;
		if (totalLength < minLength - totalSpacing){
			scaleFactor = (minLength - totalSpacing) / totalLength;
		}else{
			assert(this->elementCount > 1);
			spacing = (minLength - totalLength) / (this->elementCount - 1);
		}
	}
	*scaleFactorOut = scaleFactor;
	*spacingOut = spacing;
}

static void setRect(IAFlowLayout * this, IARect rect) {
	if (this->elementCount == 0){
		return;
	}

	float totalLength = this->isVertical ? rect.size.height : rect.size.width;

	float scaleFactor, spacing;
	getScaleFactorAndSpacing(this, totalLength, &scaleFactor, &spacing);

	float offset = 0.0f;
	for (size_t i = 0; i < this->elementCount; ++i) {
		IADrawableRect * content = IAFlowLayoutElement_getContent(&this->elements[i]);
		IARect contentRect = {
				.origin = {
						.x = this->isVertical ? rect.origin.x + offset : rect.origin.x,
						.y = this->isVertical ? rect.origin.y : rect.origin.y + offset,
				},
				.size = {
						.width = this->isVertical ? rect.size.width : rect.size.width * scaleFactor,
						.height = this->isVertical ? rect.size.height * scaleFactor : rect.size.height,
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
