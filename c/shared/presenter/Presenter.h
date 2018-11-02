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
	IANotificationDelegate onTemperatureChangedDelegate;
} Presenter;


void Presenter_init(Presenter *, HomeState * homeState, MainView * mainView);

void Presenter_registerDelegates(Presenter *);
void Presenter_unregisterDelegates(Presenter *);

void Presenter_deinit(Presenter *);

#include "Presenter+Generated.h"

#endif
