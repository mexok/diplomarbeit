//
//  MainView.c
//

#include "IALibrary.h"
#include "MainView.h"
#include "IAViewPort.h"
#include "IABackgroundColor.h"
#include "ContentFavorites.h"
#include "IACurrentFrame.h"
#include "ContentHome.h"

#define CLASSNAME "MainView"


static void onFadeInStart(MainView *, uint64_t startTime, uint64_t duration);
static void draw(MainView *);

static void onClickFavoritesButton(MainView *this, IAButton *button);
static void onClickHomeButton(MainView *this, IAButton *button);
static void onClickAlertsButton(MainView *this, IAButton *button);

void MainView_init(MainView *this) {
	IAViewAttributes viewAttr;
	IAViewAttributes_make(&viewAttr, this);
	IAViewAttributes_setOnFadeInStartFunction(&viewAttr, (IAViewAttributes_onFadeInStart) onFadeInStart);
	IAViewAttributes_setDrawFunction(&viewAttr, (IAViewAttributes_drawFunction) draw);
	IAView_make((IAView *) this, "main-view", &viewAttr);

	OverlayLayoutAttributes attr;
	OverlayLayoutAttributes_make(&attr, this);
	OverlayLayoutAttributes_setContentRef(&attr, &this->content);
	OverlayLayoutAttributes_setFavoritesButtonRef(&attr, &this->tabs[0]);
	OverlayLayoutAttributes_setHomeButtonRef(&attr, &this->tabs[1]);
	OverlayLayoutAttributes_setAlertsButtonRef(&attr, &this->tabs[2]);
	this->overlay = OverlayLayout_newFromYaml(&attr);

	this->tabDelegates[0] = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onClickFavoritesButton
	};
	this->tabDelegates[1] = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onClickHomeButton
	};
	this->tabDelegates[2] = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onClickAlertsButton
	};
	for (size_t i = 0; i < 3; i++){
		IAButton_registerForTouchEvents(this->tabs[i], &this->tabDelegates[i]);
	}

	ContentFavoritesAttributes favoritesAttr;
	ContentFavoritesAttributes_make(&favoritesAttr, this);
	ContentFavoritesAttributes_setTemperatureSliderRef(&favoritesAttr, &this->temperatureSlider);
	ContentFavoritesAttributes_setRightKitchenWindowRef(&favoritesAttr, &this->rightKitchenWindow);
	this->contentFavorites = ContentFavorites_newFromYaml(&favoritesAttr);
	this->contentHome = ContentHome_newFromYaml();

	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->contentFavorites);
	IACardLayout_addElement(this->content, element);
	IA_incrementInitCount();
}

void MainView_setRealTemperature(MainView * this, float temperature){
	logInfo("Real Temperature: %f", temperature);
}

static void onFadeInStart(MainView * this, uint64_t startTime, uint64_t duration){
	IAScrollLayout_enableScrolling(this->contentFavorites, startTime);
	for (size_t i = 0; i < 3; i++) {
		IAButton_setIsClickable(this->tabs[i], true);
	}
	IASlider_setIsClickable(this->temperatureSlider, true);
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

static void onClickFavoritesButton(MainView *this, IAButton *button){
	if (IACardLayout_hasElements(this->content) == false){
		IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->contentFavorites);
		IACardLayout_addElement(this->content, element);
	}
}

static void onClickHomeButton(MainView *this, IAButton *button){
	IACardLayout_removeLastElement(this->content);
	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->contentHome);
	IACardLayout_addElement(this->content, element);
}

static void onClickAlertsButton(MainView *this, IAButton *button){
	IACardLayout_removeLastElement(this->content);
}

void MainView_deinit(MainView *this) {
	IA_release(this->overlay);
	IA_release(this->contentFavorites);
	IA_decrementInitCount();
}
