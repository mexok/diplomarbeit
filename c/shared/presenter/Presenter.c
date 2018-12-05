//
//  Presenter.c
//

#include "IALibrary.h"
#include "Presenter.h"
#include "Resources.h"

#define CLASSNAME "Presenter"


static float convertTemperatureToSliderValue(float temperature);
static float convertSliderValueToTemperature(float value);

static void onLeavingHomeClicked(Presenter * this, SmallTile * tile);
static void onTvLivingRoomClicked(Presenter * this, SmallTile * tile);
static void onLeftKitchenWindowClicked(Presenter * this, SmallTile * tile);
static void onTvKitchenClicked(Presenter * this, SmallTile * tile);
static void onAlarmSystemClicked(Presenter * this, SmallTile * tile);
static void onDinnerClicked(Presenter * this, SmallTile * tile);
static void onAddFavoritesClicked(Presenter * this, SmallTile * tile);

static void onLivingRoomLampColorClicked(Presenter * this, IAButton * button);
static void onLivingRoomLampDimmedPercentageChanged(Presenter * this, float value, IASlider * slider);

static void onViewTemperatureChanged(Presenter * this, float value, IASlider * slider);
static void onModelTemperatureChanged(Presenter * this);


static void setupMainViewWithHomeState(Presenter * this){
	float targetRoomTemperature = HomeState_getTargetRoomTemperature(this->homeState);
	float temperatureSliderValue =  convertTemperatureToSliderValue(targetRoomTemperature);
	IASlider * temperatureSlider = MainView_getTemperatureSlider(this->mainView);
	IASlider_setValue(temperatureSlider, temperatureSliderValue);

	float realRoomTemperature = HomeState_getTargetRoomTemperature(this->homeState);
	MainView_setRealTemperature(this->mainView, realRoomTemperature);

	int livingRoomLampColorIndex = HomeState_getLivingRoomLampColorIndex(this->homeState);
	IAImage * image = Resources_getLampColorImage(livingRoomLampColorIndex);
	MainView_setLampColorImage(this->mainView, image);

	float livingRoomLampDimmedPercentage = HomeState_getLivingRoomLampDimmedPercentage(this->homeState);
	IASlider * lampSlider = MainView_getLampSlider(this->mainView);
	IASlider_setValue(lampSlider, livingRoomLampDimmedPercentage);
	MainView_setLampDimmedPercentage(this->mainView, livingRoomLampDimmedPercentage);
}

static void setupDelegates(Presenter * this){
	this->leavingHomeDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onLeavingHomeClicked
	};
	this->tvLivingRoomDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onTvLivingRoomClicked
	};
	this->leftKitchenWindowDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onLeftKitchenWindowClicked
	};
	this->tvKitchenDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onTvKitchenClicked
	};
	this->alarmSystemDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onAlarmSystemClicked
	};
	this->dinnerDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onDinnerClicked
	};
	this->addFavoritesDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onAddFavoritesClicked
	};

	this->livingRoomLampColorDelegate = (IAButtonDelegate){
			.correspondingObject = this,
			.onClick = (void (*)(void *, IAButton *)) onLivingRoomLampColorClicked
	};
	this->livingRoomLampDimmedPercentageChangedDelegate = (IASliderDelegate) {
			.correspondingObject = this,
			.onValueChanged = (void (*)(void *, float, IASlider *)) onLivingRoomLampDimmedPercentageChanged
	};

	this->onViewTemperatureChangedDelegate = (IASliderDelegate) {
			.correspondingObject = this,
			.onValueChanged = (void (*)(void *, float, IASlider *)) onViewTemperatureChanged
	};
	this->onModelTemperatureChangedDelegate = (IANotificationDelegate) {
			.correspondingObject = this,
			.notify = (void (*)(void *)) onModelTemperatureChanged
	};
}

void Presenter_init(Presenter * this, HomeState * homeState, MainView * mainView) {
	*this = (Presenter){
		.base = IAObject_make(this),
		.homeState = homeState,
		.mainView = mainView
	};
	MainView_retain(this->mainView);
	HomeState_retain(this->homeState);

	setupMainViewWithHomeState(this);
	setupDelegates(this);

	SmallTile * tile = MainView_getScenarioHome(mainView);
	SmallTile_registerForTouchEvents(tile, &this->leavingHomeDelegate);
	tile = MainView_getTvLivingRoom(mainView);
	SmallTile_registerForTouchEvents(tile, &this->tvLivingRoomDelegate);
	tile = MainView_getLeftKitchenWindow(mainView);
	SmallTile_registerForTouchEvents(tile, &this->leftKitchenWindowDelegate);
	tile = MainView_getTvKitchen(mainView);
	SmallTile_registerForTouchEvents(tile, &this->tvKitchenDelegate);
	tile = MainView_getAlarmService(mainView);
	SmallTile_registerForTouchEvents(tile, &this->alarmSystemDelegate);
	tile = MainView_getDinner(mainView);
	SmallTile_registerForTouchEvents(tile, &this->dinnerDelegate);
	tile = MainView_getAddFavorites(mainView);
	SmallTile_registerForTouchEvents(tile, &this->addFavoritesDelegate);

	for (int i = 0; i < 7; ++i) {
		IAButton * lampColorButton = MainView_getLampColorButton(mainView, i);
		IAButton_registerForTouchEvents(lampColorButton, &this->livingRoomLampColorDelegate);
	}

	IASlider * lampSlider = MainView_getLampSlider(mainView);
	IASlider_registerForSliderEvents(lampSlider, &this->livingRoomLampDimmedPercentageChangedDelegate);

	IASlider * temperatureSlider = MainView_getTemperatureSlider(mainView);
	IASlider_registerForSliderEvents(temperatureSlider, &this->onViewTemperatureChangedDelegate);
	HomeState_registerForOnTemperatureChanged(this->homeState, &this->onModelTemperatureChangedDelegate);
	IA_incrementInitCount();
}

static void onLeavingHomeClicked(Presenter * this, SmallTile * tile){
	logInfo("Leaving home scenario started");
}

static void onTvLivingRoomClicked(Presenter * this, SmallTile * tile){
	bool isActive = SmallTile_isActive(tile);
	HomeState_setIsTvLivingRoomOn(this->homeState, isActive);
}

static void onLeftKitchenWindowClicked(Presenter * this, SmallTile * tile){
	bool isActive = SmallTile_isActive(tile);
	HomeState_setIsLeftKitchenWindowOpen(this->homeState, isActive);
}

static void onTvKitchenClicked(Presenter * this, SmallTile * tile){
	bool isActive = SmallTile_isActive(tile);
	HomeState_setIsTvKitchenOn(this->homeState, isActive);
}

static void onAlarmSystemClicked(Presenter * this, SmallTile * tile){
	bool isActive = SmallTile_isActive(tile);
	HomeState_setIsAlarmSystemOn(this->homeState, isActive);
}

static void onDinnerClicked(Presenter * this, SmallTile * tile){
	logInfo("Dinner scenario started");
}

static void onAddFavoritesClicked(Presenter * this, SmallTile * tile){
	logInfo("Add to favorites clicked");
}

static void onLivingRoomLampColorClicked(Presenter * this, IAButton * button){
	int tag = IAButton_getTag(button);
	IAImage * image = Resources_getLampColorImage(tag);
	MainView_setLampColorImage(this->mainView, image);
	HomeState_setLivingRoomLampColorIndex(this->homeState, tag);
}

static void onLivingRoomLampDimmedPercentageChanged(Presenter * this, float value, IASlider * slider){
	MainView_setLampDimmedPercentage(this->mainView, value);
	HomeState_setLivingRoomLampDimmedPercentage(this->homeState, value);
}

static float convertTemperatureToSliderValue(float temperature){
	return (temperature - 17.0f) / 12.0f;
}

static float convertSliderValueToTemperature(float value){
	return 17.0f + 12.0f * value;
}

static void onViewTemperatureChanged(Presenter * this, float value, IASlider * slider){
	float temperature = convertSliderValueToTemperature(value);
	HomeState_setTargetRoomTemperature(this->homeState, temperature);
}

static void onModelTemperatureChanged(Presenter * this){
	float temperature = HomeState_getCurrentRoomTemperature(this->homeState);
	MainView_setRealTemperature(this->mainView, temperature);
}

void Presenter_deinit(Presenter * this) {
	HomeState_release(this->homeState);
	MainView_release(this->mainView);
	IA_decrementInitCount();
}
