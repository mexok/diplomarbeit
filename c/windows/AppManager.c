//
//  AppManager.c
//

#include "IALibrary.h"
#include "IAViewHolder.h"
#include "IACurrentFrame.h"
#include "AppManager.h"
#include "MainView.h"

#define CLASSNAME "AppManager"

static IAViewHolder * viewHolder;
static MainView * mainView;

void AppManager_commence(){
	viewHolder = IAViewHolder_new();
	mainView = MainView_new();
	IAViewHolder_start(viewHolder, (IAView *) mainView, IACurrentFrame_getTime(), NULL);
}

void AppManager_draw() {
	IAViewHolder_draw(viewHolder, IACurrentFrame_getTime());
}

