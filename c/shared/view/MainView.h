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
	IALabel * title;
	IACardLayout * content;
	IAScrollLayout * contentFavorites;
	IAGridLayout * contentGrid;
	TabBarButton * tabs[3];
	TabBarButtonDelegate tabDelegate;

	//@get
	SmallTile * scenarioHome;
	//@get
	SmallTile * tvLivingRoom;
	//@get
	SmallTile * leftKitchenWindow;
	//@get
	SmallTile * tvKitchen;
	//@get
	SmallTile * alarmService;
	//@get
	SmallTile * dinner;
	//@get
	SmallTile * addFavorites;

	//@get
	IASlider * temperatureSlider;
	IALabel * temperatureLabel;

	//@get
	IASlider * lampSlider;
	IALabel * lampLabel;
	IAFlowLayout * lampColorButtonsLayout;
	IAButton * lampColorButtons[7];
	IACardLayout * lampColorImageHolder;
} MainView;


void MainView_init(MainView *);

IAButton * MainView_getLampColorButton(MainView *, int index);

void MainView_setRealTemperature(MainView *, float temperature);
void MainView_setLampColorImage(MainView *, IAImage * image);
void MainView_setLampDimmedPercentage(MainView *, float percentage);

void MainView_deinit(MainView *);

#include "MainView+Generated.h"

#endif
