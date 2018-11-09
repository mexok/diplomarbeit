//
//  AppManager.c
//

#include "IALibrary.h"
#include "IAViewHolder.h"
#include "IACurrentFrame.h"
#include "AppManager.h"
#include "HomeState.h"
#include "Presenter.h"
#include "MainView.h"

#define CLASSNAME "AppManager"

static IAViewHolder * viewHolder;
static HomeState * homeState;
static MainView * mainView;
static Presenter * presenter;

void AppManager_commence(){
	viewHolder = IAViewHolder_new();
	mainView = MainView_new();
	homeState = HomeState_new(22.0f, 22.0f);
	presenter = Presenter_new(homeState, mainView);
	IAViewHolder_start(viewHolder, (IAView *) mainView, IACurrentFrame_getTime(), NULL);
}

void AppManager_draw() {
	HomeState_updateTime(homeState, IACurrentFrame_getDeltaTimeSinceLastFrame());
	IAViewHolder_draw(viewHolder, IACurrentFrame_getTime());
}

