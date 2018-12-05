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
	this->alignment = IAFlowLayoutAttributes_getAlignment(attr);
	IA_incrementInitCount();
}

static void draw(const IAFlowLayout * this) {
	for (size_t i = 0; i < IAArrayList_getCurrentSize(this->elements); ++i) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		IADrawableRect * content = IAFlowLayoutElement_getContent(element);
		IADrawableRect_draw(content);
	}
}

static bool areOnlyDefinedElementsInLayout(IAFlowLayout * this){
	for (int i = 0; i < IAArrayList_getCurrentSize(this->elements); ++i) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		if (IAFlowLayoutElement_hasDefinedLength(element) == false){
			return false;
		}
	}
	return true;
}

static float getLengthPerVariableElement(IAFlowLayout * this, float totalLength, float otherLength){
	size_t elementCount = IAArrayList_getCurrentSize(this->elements);
	size_t numberOfSpaces = (elementCount - 1);
	size_t numberOfDefinedElements = 0;
	float spaceLeft = totalLength - (numberOfSpaces * this->spacing);

	for (size_t i = 0; i < elementCount; i++) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		if (IAFlowLayoutElement_hasDefinedLength(element)){
			spaceLeft -= IAFlowLayoutElement_getDefinedLength(element, totalLength, otherLength);
			numberOfDefinedElements++;
		}
	}

	float variableLength = 0.0f;
	if (spaceLeft > 0.0f && elementCount > numberOfDefinedElements){
		variableLength = spaceLeft / (elementCount - numberOfDefinedElements);
	}
	return variableLength;
}

static void setRect(IAFlowLayout * this, IARect rect) {
	size_t elementCount = IAArrayList_getCurrentSize(this->elements);
	if (elementCount == 0){
		return;
	}

	float totalLength = this->isVertical ? rect.size.height : rect.size.width;
	float otherLength = this->isVertical ? rect.size.width : rect.size.height;
	float lengthPerVariableElement = getLengthPerVariableElement(this, totalLength, otherLength);
	float offset = 0.0f;
	float spacing = this->spacing;

	if (areOnlyDefinedElementsInLayout(this)){
		float lengthOfDefinedElements = 0.0f;
		for (size_t i = 0; i < IAArrayList_getCurrentSize(this->elements); ++i) {
			IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
			lengthOfDefinedElements += IAFlowLayoutElement_getDefinedLength(element, totalLength, otherLength);
		}
		if (this->alignment == IAFlowLayoutAlignment_stretched){
			spacing = totalLength - lengthOfDefinedElements;
			if (elementCount > 1){
				spacing /= (elementCount - 1);
			}
		}else{
			float totalLengthOfContent = lengthOfDefinedElements;
			if (elementCount > 1){
				totalLengthOfContent += (elementCount - 1) * spacing;
			}
			if (this->alignment == IAFlowLayoutAlignment_rear){
				offset = offset + totalLength - totalLengthOfContent;
			}else if (this->alignment == IAFlowLayoutAlignment_centered){
				offset = offset + totalLength - totalLengthOfContent;
				offset /= 2.0f;
			}
		}
	}

	for (size_t i = 0; i < elementCount; i++) {
		IAFlowLayoutElement * element = IAArrayList_get(this->elements, i);
		IADrawableRect * content = IAFlowLayoutElement_getContent(element);

		float widthOfElement = IAFlowLayoutElement_hasDefinedLength(element) ? IAFlowLayoutElement_getDefinedLength(element, totalLength, otherLength) : lengthPerVariableElement;

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
		offset += spacing;
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
