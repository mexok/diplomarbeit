//
//  Presenter.c
//

#include "IALibrary.h"
#include "Presenter.h"

#define CLASSNAME "Presenter"


static void onRightKitchenWindowChanged(Presenter * this, bool isOn, OnOffSwitch * onOffSwitch);
static void onViewTemperatureChanged(Presenter * this, float value, IASlider * slider);
static void onModelTemperatureChanged(Presenter * this);

void Presenter_init(Presenter * this, HomeState * homeState, MainView * mainView) {
	*this = (Presenter){
		.base = IAObject_make(this),
		.homeState = homeState,
		.mainView = mainView
	};
	MainView_retain(this->mainView);
	HomeState_retain(this->homeState);

	this->rightKitchenWindowDelegate = (OnOffSwitchDelegate){
		.correspondingObject = this,
		.onStateChanged = (void (*)(void *, bool, OnOffSwitch *)) onRightKitchenWindowChanged
	};
	this->onViewTemperatureChangedDelegate = (IASliderDelegate) {
			.correspondingObject = this,
			.onValueChanged = (void (*)(void *, float, IASlider *)) onViewTemperatureChanged
	};
	this->onModelTemperatureChangedDelegate = (IANotificationDelegate) {
			.correspondingObject = this,
			.notify = (void (*)(void *)) onModelTemperatureChanged
	};

	OnOffSwitch * rightKitchenWindow = MainView_getRightKitchenWindow(mainView);
	OnOffSwitch_registerForEvents(rightKitchenWindow, &this->rightKitchenWindowDelegate);
	IASlider * temperatureSlider = MainView_getTemperatureSlider(mainView);
	IASlider_registerForSliderEvents(temperatureSlider, &this->onViewTemperatureChangedDelegate);
	HomeState_registerForOnTemperatureChanged(this->homeState, &this->onModelTemperatureChangedDelegate);
	IA_incrementInitCount();
}


static void onRightKitchenWindowChanged(Presenter * this, bool isOn, OnOffSwitch * onOffSwitch){
	HomeState_setIsRightWindowOpen(this->homeState, isOn);
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
