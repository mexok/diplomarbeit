//
//  Presenter.h
//

#ifndef Presenter_h
#define Presenter_h

#include "IAObject.h"
#include "HomeState.h"
#include "MainView.h"

typedef struct {
	//@extend
	IAObject base;
	HomeState * homeState;
	MainView * mainView;
	OnOffSwitchDelegate rightKitchenWindowDelegate;
	IASliderDelegate onViewTemperatureChangedDelegate;
	IANotificationDelegate onModelTemperatureChangedDelegate;
} Presenter;


void Presenter_init(Presenter *, HomeState * homeState, MainView * mainView);

void Presenter_deinit(Presenter *);

#include "Presenter+Generated.h"

#endif
