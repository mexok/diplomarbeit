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

static void onTabStateChanged(MainView * correspondingObject, bool isOn, TabBarButton * TabBarButton);

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
	OverlayLayoutAttributes_setProfileButtonRef(&attr, &this->tabs[1]);
	OverlayLayoutAttributes_setNotificationsButtonRef(&attr, &this->tabs[2]);
	OverlayLayoutAttributes_setTitleRef(&attr, &this->title);
	this->overlay = OverlayLayout_newFromYaml(&attr);

	this->tabDelegate = (TabBarButtonDelegate){
			.correspondingObject = this,
			.onStateChanged = (void (*)(void *, bool, TabBarButton *)) onTabStateChanged
	};
	for (size_t i = 0; i < 3; i++){
		TabBarButton_registerForEvents(this->tabs[i], &this->tabDelegate);
	}

	ContentFavoritesAttributes favoritesAttr;
	ContentFavoritesAttributes_make(&favoritesAttr, this);
	ContentFavoritesAttributes_setContentGridRef(&favoritesAttr, &this->contentGrid);

	ContentFavoritesAttributes_setScenarioHomeRef(&favoritesAttr, &this->scenarioHome);
	ContentFavoritesAttributes_setTvLivingRoomRef(&favoritesAttr, &this->tvLivingRoom);
	ContentFavoritesAttributes_setLeftKitchenWindowRef(&favoritesAttr, &this->leftKitchenWindow);
	ContentFavoritesAttributes_setTvKitchenRef(&favoritesAttr, &this->tvKitchen);
	ContentFavoritesAttributes_setAlarmServiceRef(&favoritesAttr, &this->alarmService);
	ContentFavoritesAttributes_setDinnerRef(&favoritesAttr, &this->dinner);
	ContentFavoritesAttributes_setAddFavoritesRef(&favoritesAttr, &this->addFavorites);

	ContentFavoritesAttributes_setTemperatureSliderRef(&favoritesAttr, &this->temperatureSlider);
	ContentFavoritesAttributes_setTemperatureLabelRef(&favoritesAttr, &this->temperatureLabel);

	ContentFavoritesAttributes_setLampSliderRef(&favoritesAttr, &this->lampSlider);
	ContentFavoritesAttributes_setLampLabelRef(&favoritesAttr, &this->lampLabel);
	ContentFavoritesAttributes_setLampColorButtonsLayoutRef(&favoritesAttr, &this->lampColorButtonsLayout);
	ContentFavoritesAttributes_setLampColorImageHolderRef(&favoritesAttr, &this->lampColorImageHolder);

	this->contentFavorites = ContentFavorites_newFromYaml(&favoritesAttr);

	for (int i = 0; i < 7; i++) {
		IAButtonAttributes lampColorButtonAttr;
		IAButtonAttributes_make(&lampColorButtonAttr);
		IAImage * normal = Resources_getLampColorImage(i);
		IAButtonAttributes_setNormal(&lampColorButtonAttr, (IADrawableRect *) IAImage_copy(normal));
		this->lampColorButtons[i] = IAButton_new(&lampColorButtonAttr);
		IAFlowLayoutElement * element = IAFlowLayoutElement_newWithContent((IADrawableRect *) this->lampColorButtons[i]);
		IAFlowLayout_addElement(this->lampColorButtonsLayout, element);
	}

	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->contentFavorites);
	IACardLayout_addElement(this->content, element);
	IA_incrementInitCount();
}

void MainView_setRealTemperature(MainView * this, float temperature){
	char text[30];
	sprintf(text, "%.1f %c%cC", temperature, 0xC2, 0xB0);
	IALabel_setText(this->temperatureLabel, text);
}

void MainView_setLampColorImage(MainView * this, IAImage * image){
	IACardLayout_removeLastElement(this->lampColorImageHolder);
	IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) image);
	IACardLayout_addElement(this->lampColorImageHolder, element);
}

static void onFadeInStart(MainView * this, uint64_t startTime, uint64_t duration){
	IAScrollLayout_enableScrolling(this->contentFavorites, startTime);
	for (size_t i = 0; i < 3; i++) {
		TabBarButton_setIsClickable(this->tabs[i], true);
		TabBarButton_setIsOn(this->tabs[i], false);
	}
	TabBarButton_setIsClickable(this->tabs[0], false);
	TabBarButton_setIsOn(this->tabs[0], true);

	SmallTile_setIsClickable(this->scenarioHome, true);
	SmallTile_setIsClickable(this->tvLivingRoom, true);
	SmallTile_setIsClickable(this->leftKitchenWindow, true);
	SmallTile_setIsClickable(this->tvKitchen, true);
	SmallTile_setIsClickable(this->alarmService, true);
	SmallTile_setIsClickable(this->dinner, true);
	SmallTile_setIsClickable(this->addFavorites, true);

	for (int i = 0; i < 7; i++) {
		IAButton_setIsClickable(this->lampColorButtons[i], true);
	}

	IASlider_setIsClickable(this->temperatureSlider, true);
	IASlider_setIsClickable(this->lampSlider, true);
}

static void draw(MainView * this){
	uint64_t time = IACurrentFrame_getTime();
	IAScrollLayout_updateTime(this->contentFavorites, time);
	IABackgroundColor_draw(IAColor_black);
	IARect rect = {
			.origin = IAPoint_zero,
			.size = IAViewPort_getSize()
	};
	float scrollViewContentLength = IAGridLayout_getNeededHeight(this->contentGrid, rect.size.width - 120.0f, 1.0f);
	IAScrollLayout_updateContentLength(this->contentFavorites, scrollViewContentLength);

	IAFlowLayout_setRect(this->overlay, rect);
	IAFlowLayout_draw(this->overlay);
};

static void onTabStateChanged(MainView * this, bool isOn, TabBarButton * tabBarButton){
	debugAssert(isOn && "tabs should not be deactivateable");
	IACardLayout_removeLastElement(this->content);

	for (size_t i = 0; i < 3; i++) {
		TabBarButton_setIsClickable(this->tabs[i], true);
		TabBarButton_setIsOn(this->tabs[i], false);
	}
	TabBarButton_setIsClickable(tabBarButton, false);
	TabBarButton_setIsOn(tabBarButton, true);

	if (tabBarButton == this->tabs[0]){
		IACardLayoutElement * element = IACardLayoutElement_withContent((IADrawableRect *) this->contentFavorites);
		IACardLayout_addElement(this->content, element);
		IALabel_setText(this->title, "Favorites");
	}else if (tabBarButton == this->tabs[1]){
		IALabel_setText(this->title, "Profile");
	}else{
		IALabel_setText(this->title, "Notifications");
	}
}

void MainView_deinit(MainView *this) {
	IA_release(this->overlay);
	IA_release(this->contentFavorites);
	IA_decrementInitCount();
}
