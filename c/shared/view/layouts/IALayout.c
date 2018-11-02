//
//  IALayout.c
//

#include "IALibrary.h"
#include "IALayout.h"
#include "IADrawingBounds.h"

#define CLASSNAME "IALayout"



static void staticDrawFn(IALayout *);
static void staticSetRectFn(IALayout *, IARect rect);

void IALayout_init(
		IALayout * this,
		IADrawable_drawFunction draw,
		IADrawableRect_setRectFunction setRect,
		const IALayoutAttributes * attr) {
	IADrawableRect_make((IADrawableRect *) this, (IADrawable_drawFunction) staticDrawFn, (IADrawableRect_setRectFunction) staticSetRectFn);
	this->overwrittenDrawFn = draw;
	this->overwrittenSetRectFn = setRect;
	this->hasBackgroundColor = IALayoutAttributes_hasBackgroundColor(attr);
	this->backgroundColor = IALayoutAttributes_getBackgroundColor(attr);
	if (this->hasBackgroundColor){
		this->backgroundColorRect = IAColorRect_new(this->backgroundColor);
	}else{
		this->backgroundColorRect = NULL;
	}
	this->paddingLeft = IALayoutAttributes_getPaddingLeft(attr);
	this->paddingTop = IALayoutAttributes_getPaddingTop(attr);
	this->paddingRight = IALayoutAttributes_getPaddingRight(attr);
	this->paddingBottom = IALayoutAttributes_getPaddingBottom(attr);
	IA_incrementInitCount();
}

static void staticDrawFn(IALayout * this){
	if (this->hasBackgroundColor){
		IAColorRect_draw(this->backgroundColorRect);
	}
	IARect drawingArea = IALayout_getRect(this);
	IADrawingBounds_pushBounds(drawingArea);
	this->overwrittenDrawFn((IADrawable *) this);
	IADrawingBounds_popBounds();
}

static void staticSetRectFn(IALayout * this, IARect rect){
	if (this->hasBackgroundColor){
		IAColorRect_setRect(this->backgroundColorRect, rect);
	}
	rect.origin.x += this->paddingLeft;
	rect.origin.y += this->paddingTop;
	rect.size.width -= this->paddingLeft + this->paddingRight;
	rect.size.height -= this->paddingTop + this->paddingBottom;
	this->overwrittenSetRectFn((IADrawableRect *) this, rect);
}

void IALayout_deinit(IALayout * this) {
	if (this->backgroundColorRect != NULL){
		IAColorRect_release(this->backgroundColorRect);
	}
	IA_decrementInitCount();
}
