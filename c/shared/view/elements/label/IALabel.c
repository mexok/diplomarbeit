//
//  IALabel.c
//

#include "IALibrary.h"
#include "IALabel.h"
#include "IADrawingBounds.h"

#define CLASSNAME "IALabel"


static void draw(IALabel *);

void IALabel_init(IALabel * this, const IALabelAttributes * attr) {
	*this = (IALabel){
		.font = IALabelAttributes_getFont(attr),
		.textAlignment = IALabelAttributes_getTextAlignment(attr),
		.fontSize = IALabelAttributes_getFontSize(attr),
		.fontColor = IALabelAttributes_getFontColor(attr)
    };
	IADrawableRect_make((IADrawableRect *) this, (IADrawable_drawFunction) draw, NULL);
	IAString_init(&this->text, IALabelAttributes_getText(attr));
	IAColorableFontAtlas_retain(this->font);
	IA_incrementInitCount();
}

static void draw(IALabel * this){
	IARect rect = IALabel_getRect(this);
	IAPoint point = IARect_getCenterPoint(rect);
	switch (this->textAlignment){
		case IATextAlignment_left:
			point.x = rect.origin.x;
			break;
		case IATextAlignment_right:
			point.x = rect.origin.x + rect.size.width;
			break;
		default:
			break;
	}
	IAColorableFontAtlas_setColor(this->font, this->fontColor);
	IAColorableFontAtlas_setCurrentFontSize(this->font, this->fontSize);
	IAColorableFontAtlas_drawTextRelativelyAtMiddleline(this->font, IALabel_getText(this), point, this->textAlignment);
}

void IALabel_deinit(IALabel *this) {
	IAString_deinit(&this->text);
	IAColorableFontAtlas_release(this->font);
	IA_decrementInitCount();
}
