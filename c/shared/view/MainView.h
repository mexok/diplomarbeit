//
//  MainView.h
//

#ifndef MainView_h
#define MainView_h

#include "IAObject.h"
#include "OverlayLayout.h"
#include "ContentFavorites.h"
#include "IAView.h"
#include "IAScrollLayout.h"

typedef struct {
	//@extend
	IAView view;
	IAFlowLayout * overlay;
	IACardLayout * content;
	IAScrollLayout * contentFavorites;
	IACardLayout * contentHome;
	IAButton * tabs[3];
	IAButtonDelegate tabDelegates[3];
	//@get
	IASlider * temperatureSlider;
	//@get
	OnOffSwitch * rightKitchenWindow;
} MainView;


void MainView_init(MainView *);

void MainView_setRealTemperature(MainView *, float temperature);

void MainView_deinit(MainView *);

#include "MainView+Generated.h"

#endif
