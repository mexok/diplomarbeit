//
//  SmallTileAttributes.c
//

#include "IALibrary.h"
#include "SmallTileAttributes.h"
#include "Resources.h"

#define CLASSNAME "SmallTileAttributes"


void SmallTileAttributes_init(SmallTileAttributes * this) {
	*this = (SmallTileAttributes){
		.base = IAObject_make(this)
    };
	IAString_init(&this->title, "");
	IAString_init(&this->subtitleActive, "");
	IAString_init(&this->subtitleInactive, "");
	IA_incrementInitCount();
}

void SmallTileAttributes_setSubtitle(SmallTileAttributes * this, const char * subtitle){
	IAString_set(&this->subtitleActive, subtitle);
	IAString_set(&this->subtitleInactive, subtitle);
}

void SmallTileAttributes_setImageSet(SmallTileAttributes * this, SmallTileImageSet imageSet){
	IAImage * image;
	switch (imageSet){
		case SmallTileImageSet_home:
			image = Resources_getImage("tile_home");
			this->iconActive = IAImage_copy(image);
			break;
		case SmallTileImageSet_lock:
			image = Resources_getImage("tile_door_open");
			this->iconActive = IAImage_copy(image);
			image = Resources_getImage("tile_door_closed");
			this->iconInactive = IAImage_copy(image);
			break;
		case SmallTileImageSet_plus:
			image = Resources_getImage("tile_add-favo");
			this->iconActive = IAImage_copy(image);
			break;
		case SmallTileImageSet_tv:
			image = Resources_getImage("tile_TV_on");
			this->iconActive = IAImage_copy(image);
			image = Resources_getImage("tile_TV_off");
			this->iconInactive = IAImage_copy(image);
			break;
		default:
			break;
	}
	if (imageSet == SmallTileImageSet_home || imageSet == SmallTileImageSet_plus){
		this->backgroundActive = Resources_getImage("tile_small_on_untouched");
		this->backgroundActive = IAImage_copy(this->backgroundActive);
		this->backgroundActiveTouched = Resources_getImage("tile_small_on_touched");
		this->backgroundActiveTouched = IAImage_copy(this->backgroundActiveTouched);
		this->backgroundInactive = this->backgroundActive;
		this->backgroundInactiveTouched = this->backgroundActiveTouched;
	}else{
		this->backgroundActive = Resources_getImage("tile_small_on_untouched");
		this->backgroundActive = IAImage_copy(this->backgroundActive);
		this->backgroundActiveTouched = Resources_getImage("tile_small_on_touched");
		this->backgroundActiveTouched = IAImage_copy(this->backgroundActiveTouched);
		this->backgroundInactive = Resources_getImage("tile_small_off_untouched");
		this->backgroundInactive = IAImage_copy(this->backgroundInactive);
		this->backgroundInactiveTouched = Resources_getImage("tile_small_off_touched");
		this->backgroundInactiveTouched = IAImage_copy(this->backgroundInactiveTouched);
	}
}

void SmallTileAttributes_deinit(SmallTileAttributes * this){
	IAString_deinit(&this->title);
	IAString_deinit(&this->subtitleActive);
	IAString_deinit(&this->subtitleInactive);
	IA_decrementInitCount();
}
