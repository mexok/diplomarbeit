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
	debugAssert((IALayoutAttributes_hasBackgroundColor(attr) == false || IALayoutAttributes_hasBackgroundDrawable(attr) == false) && "a layout cannot have both: background color and drawable");
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
	this->hasBackgroundDrawable = IALayoutAttributes_hasBackgroundDrawable(attr);
	this->backgroundDrawable = IALayoutAttributes_getBackgroundDrawable(attr);
	if (this->hasBackgroundDrawable){
		IADrawableRect_retain(this->backgroundDrawable);
	}
	this->paddingLeft = IALayoutAttributes_getPaddingLeft(attr);
	this->paddingTop = IALayoutAttributes_getPaddingTop(attr);
	this->paddingRight = IALayoutAttributes_getPaddingRight(attr);
	this->paddingBottom = IALayoutAttributes_getPaddingBottom(attr);

	this->paddingLeftRelative = IALayoutAttributes_getPaddingLeftRelative(attr);
	this->paddingTopRelative = IALayoutAttributes_getPaddingTopRelative(attr);
	this->paddingRightRelative = IALayoutAttributes_getPaddingRightRelative(attr);
	this->paddingBottomRelative = IALayoutAttributes_getPaddingBottomRelative(attr);
	IA_incrementInitCount();
}

static void staticDrawFn(IALayout * this){
	if (this->hasBackgroundColor){
		IAColorRect_draw(this->backgroundColorRect);
	}
	if (this->hasBackgroundDrawable){
		IADrawableRect_draw(this->backgroundDrawable);
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
	if (this->hasBackgroundDrawable){
		IADrawableRect_setRect(this->backgroundDrawable, rect);
	}
	IASize originalSize = rect.size;
	float totalPaddingLeft = this->paddingLeft + originalSize.width * this->paddingLeftRelative;
	float totalPaddingTop = this->paddingTop + originalSize.height * this->paddingTopRelative;
	float totalPaddingRight = this->paddingRight + originalSize.width * this->paddingRightRelative;
	float totalPaddingBottom = this->paddingBottom + originalSize.height * this->paddingBottomRelative;
	rect.origin.x += totalPaddingLeft;
	rect.origin.y += totalPaddingTop;
	rect.size.width -= totalPaddingLeft + totalPaddingRight;
	rect.size.height -= totalPaddingTop + totalPaddingBottom;
	this->overwrittenSetRectFn((IADrawableRect *) this, rect);
}

void IALayout_deinit(IALayout * this) {
	if (this->backgroundColorRect != NULL){
		IAColorRect_release(this->backgroundColorRect);
	}
	if (this->hasBackgroundDrawable){
		IADrawableRect_release(this->backgroundDrawable);
	}
	IA_decrementInitCount();
}
