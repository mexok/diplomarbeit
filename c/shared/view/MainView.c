//
//  MainView.c
//

#include "IALibrary.h"
#include "MainView.h"
#include "IAViewPort.h"
#include "IABackgroundColor.h"
#include "ContentFavorites.h"
#include "IACurrentFrame.h"

#define CLASSNAME "MainView"


static void onFadeInStart(MainView *, uint64_t startTime, uint64_t duration);
static void draw(MainView *);


static void onClickMyButton(MainView *this, IAButton *button){
	logInfo("My button clicked!");
}

static void onInjectMyButton(MainView *this, IAButtonAttributes * attr){
	IAButtonAttributes_setOnClickFunction(attr, (void(*)(void *, IAButton *)) onClickMyButton);
}

void MainView_init(MainView *this) {
	IAViewAttributes viewAttr;
	IAViewAttributes_make(&viewAttr, this);
	IAViewAttributes_setOnFadeInStartFunction(&viewAttr, (IAViewAttributes_onFadeInStart) onFadeInStart);
	IAViewAttributes_setDrawFunction(&viewAttr, (IAViewAttributes_drawFunction) draw);
	IAView_make((IAView *) this, "main-view", &viewAttr);

	OverlayLayoutAttributes attr;
	OverlayLayoutAttributes_make(&attr, this);
	OverlayLayoutAttributes_setContentRef(&attr, &this->content);
	this->overlay = OverlayLayout_newFromYaml(&attr);

	ContentFavoritesAttributes favoritesAttr;
	ContentFavoritesAttributes_make(&favoritesAttr, this);
	this->contentFavorites = ContentFavorites_newFromYaml(&favoritesAttr);

	IAFlowLayoutElement * element = IAFlowLayoutElement_withContent((IADrawableRect *) this->contentFavorites);
	IAFlowLayout_addElement(this->content, element);
	IA_incrementInitCount();
}

static void onFadeInStart(MainView * this, uint64_t startTime, uint64_t duration){
	IAScrollLayout_enableScrolling(this->contentFavorites, startTime);
}

static void draw(MainView * this){
	uint64_t time = IACurrentFrame_getTime();
	IAScrollLayout_updateTime(this->contentFavorites, time);
	IABackgroundColor_draw(IAColor_black);
	IARect rect = {
			.origin = IAPoint_zero,
			.size = IAViewPort_getSize()
	};
	IAFlowLayout_setRect(this->overlay, rect);
	IAFlowLayout_draw(this->overlay);
};

void MainView_deinit(MainView *this) {
	IA_release(this->overlay);
	IA_release(this->contentFavorites);
	IA_decrementInitCount();
}
