//
//  IACardLayout.c
//

#include "IALibrary.h"
#include "IACardLayout.h"
#include "IADrawingBounds.h"

#define CLASSNAME "IACardLayout"


static void draw(const IACardLayout * this);
static void setRect(IACardLayout * this, IARect rect);


void IACardLayout_init(IACardLayout * this, const IACardLayoutAttributes * attr){
	IALayout_init(
			(IALayout *) this,
			(void (*)(const IADrawable *)) draw,
			(void (*)(IADrawableRect *, IARect)) setRect,
			(const IALayoutAttributes *) attr);
	size_t elementCount = IACardLayoutAttributes_getElementCount(attr);
	if (elementCount == 0){
		this->elements = IAArrayList_new(10);
	}else{
		this->elements = IAArrayList_new(elementCount);
	}
	const IACardLayoutElement * attrElements = IACardLayoutAttributes_getElements(attr);
	for (size_t i = 0; i < elementCount; i++) {
		IACardLayoutElement * element = IACardLayoutElement_copy(attrElements + i);
		IAArrayList_add(this->elements, element);
	}
	IA_incrementInitCount();
}

static void draw(const IACardLayout * this) {
	for (size_t i = 0; i < IAArrayList_getCurrentSize(this->elements); i++) {
		IACardLayoutElement * element = IAArrayList_get(this->elements, i);
		IADrawableRect * content = IACardLayoutElement_getContent(element);
		IARect contentRect = IADrawableRect_getRect(content);
		if (contentRect.size.width > 0.0f && contentRect.size.height > 0.0f){
			IADrawableRect_draw(content);
		}
	}
}

static void setRect(IACardLayout * this, IARect rect) {
	for (size_t i = 0; i < IAArrayList_getCurrentSize(this->elements); i++) {
		IACardLayoutElement * element = IAArrayList_get(this->elements, i);
		float left = rect.origin.x + IACardLayoutElement_getMarginLeft(element);
		left += IACardLayoutElement_getMarginLeftRelative(element) * rect.size.width;
		float top = rect.origin.y + IACardLayoutElement_getMarginTop(element);
		top += IACardLayoutElement_getMarginTopRelative(element) * rect.size.height;
		float right = rect.origin.x + rect.size.width - IACardLayoutElement_getMarginRight(element);
		right -= IACardLayoutElement_getMarginRightRelative(element) * rect.size.width;
		float bottom = rect.origin.y + rect.size.height - IACardLayoutElement_getMarginBottom(element);
		bottom -= IACardLayoutElement_getMarginBottomRelative(element) * rect.size.height;
		IARect contentRect = IARect_makeWithLeftTopRightBottom(left, top, right, bottom);
		IADrawableRect * content = IACardLayoutElement_getContent(element);
		IADrawableRect_setRect(content, contentRect);
	}
}

void IACardLayout_addElement(IACardLayout * this, IACardLayoutElement * element){
	IAArrayList_add(this->elements, element);
}

void IACardLayout_insertElementAtIndex(IACardLayout * this, size_t index, IACardLayoutElement * element){
	IAArrayList_insertAtIndex(this->elements, index, element);
}

IACardLayoutElement * IACardLayout_removeLastElement(IACardLayout * this){
	return (IACardLayoutElement *) IAArrayList_removeLast(this->elements);
}

IACardLayoutElement * IACardLayout_removeElementAtIndex(IACardLayout * this, size_t index){
	return (IACardLayoutElement *) IAArrayList_removeAtIndex(this->elements, index);
}

size_t IACardLayout_getElementCount(IACardLayout * this){
	return IAArrayList_getCurrentSize(this->elements);
}

bool IACardLayout_hasElements(IACardLayout * this){
	return !IAArrayList_isEmpty(this->elements);
}

void IACardLayout_deinit(IACardLayout * this){
	IAArrayList_release(this->elements);
	IA_decrementInitCount();
	IALayout_deinit((IALayout *) this);
}
