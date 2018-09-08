//
//  IAFlowLayout.c
//

#include "IALibrary.h"
#include "IAFlowLayout.h"

#define CLASSNAME "IAFlowLayout"


static void draw(IAFlowLayout * this);
static void setRect(IAFlowLayout * this, IARect rect);
static IASize getMinSizeNeeded(IAFlowLayout * this);

void IAFlowLayout_init(IAFlowLayout * this, const IAFlowLayoutAttributes * attr){
	IADrawableRect_make(this, (void (*)(IADrawable *)) draw, (void (*)(IADrawableRect *, IARect)) setRect, (IASize (*)(IADrawableRect *)) getMinSizeNeeded);
	this->elementCount = IAFlowLayoutAttributes_getElementCount(attr);
	const IAFlowLayoutElement * elements = IAFlowLayoutAttributes_getElements(attr);
	this->elements = IA_malloc(sizeof(IAFlowLayoutElement) * this->elementCount);
	for (size_t i = 0; i < this->elementCount; i++) {
		IAFlowLayoutElement_makeCopy(this->elements + i, elements + i);
	}
	IA_incrementInitCount();
}

static void draw(IAFlowLayout * this) {

}

static void setRect(IAFlowLayout * this, IARect rect) {

}

static IASize getMinSizeNeeded(IAFlowLayout * this) {

}

void IAFlowLayout_deinit(IAFlowLayout * this){
	IA_free(this->elements);
	IA_decrementInitCount();
}
