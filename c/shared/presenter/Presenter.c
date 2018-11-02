//
//  Presenter.c
//

#include "IALibrary.h"
#include "Presenter.h"

#define CLASSNAME "Presenter"


static void onTemperatureChanged(Presenter * this){

}

void Presenter_init(Presenter * this, HomeState * homeState, MainView * mainView) {
	*this = (Presenter){
		.base = IAObject_make(this),
		.homeState = homeState,
		.mainView = mainView
	};
	HomeState_retain(this->homeState);
	this->onTemperatureChangedDelegate = (IANotificationDelegate) {
		.correspondingObject = this,
		.notify = (void (*)(void *)) onTemperatureChanged
	};
	IA_incrementInitCount();
}

void Presenter_registerDelegates(Presenter * this){
	HomeState_registerForOnTemperatureChanged(this->homeState, &this->onTemperatureChangedDelegate);
}

void Presenter_unregisterDelegates(Presenter * this){
	HomeState_unregisterFromOnTemperatureChanged(this->homeState, &this->onTemperatureChangedDelegate);
}

void Presenter_deinit(Presenter * this) {
	HomeState_release(this->homeState);
	IA_decrementInitCount();
}
