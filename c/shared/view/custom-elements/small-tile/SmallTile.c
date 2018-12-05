//
//  SmallTile.c
//

#include "IALibrary.h"
#include "SmallTile.h"
#include "Resources.h"

#define CLASSNAME "SmallTile"


static void onClick(SmallTile * this, IAButton * button);
static void setupActive(SmallTile * this);
static void setupInactive(SmallTile * this);


void SmallTile_init(SmallTile *this, const SmallTileAttributes * attr) {
	debugAssert(SmallTileAttributes_getIconActive(attr) != NULL);
	*this = (SmallTile){
		.iconActive = SmallTileAttributes_getIconActive(attr),
		.iconInactive = SmallTileAttributes_getIconInactive(attr),
		.backgroundActive = SmallTileAttributes_getBackgroundActive(attr),
		.backgroundActiveTouched = SmallTileAttributes_getBackgroundActiveTouched(attr),
		.backgroundInactive = SmallTileAttributes_getBackgroundInactive(attr),
		.backgroundInactiveTouched = SmallTileAttributes_getBackgroundInactiveTouched(attr),
		.isActive = true
    };

	this->iconActive = IAImage_newCopy(this->iconActive);
	if (this->iconInactive == NULL){
		this->iconInactive = IAImage_newCopy(this->iconActive);
	}else{
		this->iconInactive = IAImage_newCopy(this->iconInactive);
	}

	IAString_init(&this->title, SmallTileAttributes_getTitle(attr));
	IAString_init(&this->subtitleActive, SmallTileAttributes_getSubtitleActive(attr));
	IAString_init(&this->subtitleInactive, SmallTileAttributes_getSubtitleInactive(attr));

	IAImage_retain(this->backgroundActive);
	IAImage_retain(this->backgroundActiveTouched);
	IAImage_retain(this->backgroundInactive);
	IAImage_retain(this->backgroundInactiveTouched);

	SmallTileLayoutAttributes tileAttr;
	SmallTileLayoutAttributes_make(&tileAttr, this);
	SmallTileLayoutAttributes_setImageHolderRef(&tileAttr, &this->imageHolder);
	SmallTileLayoutAttributes_setTitleRef(&tileAttr, &this->titleLabel);
	SmallTileLayoutAttributes_setSubtitleRef(&tileAttr, &this->subtitleLabel);
	this->tile = SmallTileLayout_newFromYaml(&tileAttr);

	SmallTileLayoutAttributes_setImageHolderRef(&tileAttr, &this->imageHolderTouched);
	SmallTileLayoutAttributes_setTitleRef(&tileAttr, &this->titleLabelTouched);
	SmallTileLayoutAttributes_setSubtitleRef(&tileAttr, &this->subtitleLabelTouched);
	this->tileTouched = SmallTileLayout_newFromYaml(&tileAttr);

	IALabel_setFontColor(this->titleLabel, IAColor_makeWithHex("#7a7a7a"));
	IALabel_setFontColor(this->titleLabelTouched, IAColor_makeWithHex("#7a7a7a"));
	IALabel_setFontColor(this->subtitleLabel, IAColor_makeWithHex("#7a7a7a"));
	IALabel_setFontColor(this->subtitleLabelTouched, IAColor_makeWithHex("#7a7a7a"));

	IAButtonAttributes buttonAttributes;
	IAButtonAttributes_make(&buttonAttributes);
	IAButtonAttributes_setNormal(&buttonAttributes, (IADrawableRect *) this->tile);
	IAButtonAttributes_setTouched(&buttonAttributes, (IADrawableRect *) this->tileTouched);
	IAButton_init((IAButton *) this, &buttonAttributes);

	this->buttonDelegate = (IAButtonDelegate){
		.correspondingObject = this,
		.onClick = (void (*)(void *, IAButton* )) onClick
	};
	IAButton_registerForTouchEvents((IAButton *) this, &this->buttonDelegate);
	setupActive(this);
	IA_incrementInitCount();
}

static void onClick(SmallTile * this, IAButton * button){
	IACardLayout_removeElementAtIndex(this->tile, 0);
	IACardLayout_removeElementAtIndex(this->tileTouched, 0);
	IACardLayout_removeLastElement(this->imageHolder);
	IACardLayout_removeLastElement(this->imageHolderTouched);
	if (this->isActive){
		this->isActive = false;
		setupInactive(this);
	}else{
		this->isActive = true;
		setupActive(this);
	}
}

static void setupActive(SmallTile * this){
	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->backgroundActive);
	IACardLayout_insertElementAtIndex(this->tile, 0, element);
	element = IACardLayoutElement_withContent((IADrawableRect *) this->backgroundActiveTouched);
	IACardLayout_insertElementAtIndex(this->tileTouched, 0, element);

	element = IACardLayoutElement_withContent((IADrawableRect *) this->iconActive);
	IACardLayout_insertElementAtIndex(this->imageHolder, 0, element);
	IACardLayout_insertElementAtIndex(this->imageHolderTouched, 0, element);

	IALabel_setText(this->titleLabel, IAString_toCharArray(&this->title));
	IALabel_setText(this->subtitleLabel, IAString_toCharArray(&this->subtitleActive));
	IALabel_setText(this->titleLabelTouched, IAString_toCharArray(&this->title));
	IALabel_setText(this->subtitleLabelTouched, IAString_toCharArray(&this->subtitleActive));
}

static void setupInactive(SmallTile * this){
	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->backgroundInactive);
	IACardLayout_insertElementAtIndex(this->tile, 0, element);
	element = IACardLayoutElement_withContent((IADrawableRect *)this->backgroundInactiveTouched);
	IACardLayout_insertElementAtIndex(this->tileTouched, 0, element);

	element = IACardLayoutElement_withContent((IADrawableRect *) this->iconInactive);
	IACardLayout_insertElementAtIndex(this->imageHolder, 0, element);
	IACardLayout_insertElementAtIndex(this->imageHolderTouched, 0, element);

	IALabel_setText(this->titleLabel, IAString_toCharArray(&this->title));
	IALabel_setText(this->subtitleLabel, IAString_toCharArray(&this->subtitleInactive));
	IALabel_setText(this->titleLabelTouched, IAString_toCharArray(&this->title));
	IALabel_setText(this->subtitleLabelTouched, IAString_toCharArray(&this->subtitleInactive));
}

void SmallTile_deinit(SmallTile *this) {
	IAString_deinit(&this->title);
	IAString_deinit(&this->subtitleActive);
	IAString_deinit(&this->subtitleInactive);

	IAImage_release(this->iconActive);
	IAImage_release(this->iconInactive);

	IAImage_release(this->backgroundActive);
	IAImage_release(this->backgroundActiveTouched);
	IAImage_release(this->backgroundInactive);
	IAImage_release(this->backgroundInactiveTouched);

	IACardLayout_release(this->tile);
	IACardLayout_release(this->tileTouched);

	IAButton_unregisterFromTouchEvents((IAButton *) this, &this->buttonDelegate);
	IAButton_deinit((IAButton *) this);
	IA_decrementInitCount();
}
