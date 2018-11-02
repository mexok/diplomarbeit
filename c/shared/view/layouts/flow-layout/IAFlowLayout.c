//
//  IAFlowLayout.c
//

#include "IALibrary.h"
#include "IAFlowLayout.h"
#include "IADrawingBounds.h"

#define CLASSNAME "IAFlowLayout"


static void draw(const IAFlowLayout * this);
static void setRect(IAFlowLayout * this, IARect rect);


void IAFlowLayout_init(IAFlowLayout * this, const IAFlowLayoutAttributes * attr){
	IALayout_init(
			(IALayout *) this,
			(void (*)(const IADrawable *)) draw,
			(void (*)(IADrawableRect *, IARect)) setRect,
			(const IALayoutAttributes *) attr);
	size_t elementCount = IAFlowLayoutAttributes_getElementCount(attr);
	if (elementCount == 0){
		this->elements = IAArrayList_new(10);
	}else{
		this->elements = IAArrayList_new(elementCount);
	}
	const IAFlowLayoutElement * attrElements = IAFlowLayoutAttributes_getElements(attr);
	for (size_t i = 0; i < elementCount; i++) {
		IAFlowLayoutElement * element = IAFlowLayoutElement_copy(attrElements + i);
		IAArrayList_add(this->elements, element);
	}
	this->spacing = IAFlowLayoutAttributes_getSpacing(attr);
	this->isVertical = IAFlowLayoutAttributes_isVertical(attr);
	IA_incrementInitCount();
}

static void draw(const IAFlowLayout * this) {
	for (size_t i = 0; i < IAArrayList_getCurrentSize(this->elements); ++i) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		IADrawableRect * content = IAFlowLayoutElement_getContent(element);
		IADrawableRect_draw(content);
	}
}

static float getLengthPerVariableElement(IAFlowLayout * this, float totalLength){
	size_t elementCount = IAArrayList_getCurrentSize(this->elements);
	size_t numberOfSpaces = (elementCount - 1);
	size_t numberOfFixedElements = 0;
	float spaceLeft = totalLength - (numberOfSpaces * this->spacing);

	for (size_t i = 0; i < elementCount; i++) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		if (IAFlowLayoutElement_hasFixedLength(element)){
			spaceLeft -= IAFlowLayoutElement_getFixedLength(element);
			numberOfFixedElements++;
		}
	}

	float variableLength = 0.0f;
	if (spaceLeft > 0.0f && elementCount > numberOfFixedElements){
		variableLength = spaceLeft / (elementCount - numberOfFixedElements);
	}
	return variableLength;
}

static void setRect(IAFlowLayout * this, IARect rect) {
	size_t elementCount = IAArrayList_getCurrentSize(this->elements);
	if (elementCount == 0){
		return;
	}

	float totalLength = this->isVertical ? rect.size.height : rect.size.width;
	float lengthPerVariableElement = getLengthPerVariableElement(this, totalLength);

	float offset = 0.0f;
	for (size_t i = 0; i < elementCount; i++) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		IADrawableRect * content = IAFlowLayoutElement_getContent(element);

		float widthOfElement = IAFlowLayoutElement_hasFixedLength(element) ? IAFlowLayoutElement_getFixedLength(element) : lengthPerVariableElement;

		IARect contentRect = {
				.origin = {
						.x = this->isVertical ? rect.origin.x : rect.origin.x + offset,
						.y = this->isVertical ? rect.origin.y + offset : rect.origin.y,
				},
				.size = {
						.width = this->isVertical ? rect.size.width : widthOfElement,
						.height = this->isVertical ? widthOfElement : rect.size.height,
				}
		};
		IADrawableRect_setRect(content, contentRect);
		offset += this->isVertical ? contentRect.size.height : contentRect.size.width;
		offset += this->spacing;
	}
}

void IAFlowLayout_addElement(IAFlowLayout * this, IAFlowLayoutElement * element){
	IAArrayList_add(this->elements, element);
}

void IAFlowLayout_insertElementAtIndex(IAFlowLayout * this, size_t index, IAFlowLayoutElement * element){
	IAArrayList_insertAtIndex(this->elements, index, element);
}

IAFlowLayoutElement * IAFlowLayout_removeLastElement(IAFlowLayout * this){
	return (IAFlowLayoutElement *) IAArrayList_removeLast(this->elements);
}

IAFlowLayoutElement * IAFlowLayout_removeElementAtIndex(IAFlowLayout * this, size_t index){
	return (IAFlowLayoutElement *) IAArrayList_removeAtIndex(this->elements, index);
}

void IAFlowLayout_deinit(IAFlowLayout * this){
	IAArrayList_release(this->elements);
	IA_decrementInitCount();
	IALayout_deinit((IALayout *) this);
}
