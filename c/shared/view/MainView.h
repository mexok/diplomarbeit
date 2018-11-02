//
//  MainView.h
//

#ifndef MainView_h
#define MainView_h

#include "IAObject.h"
#include "OverlayLayout.h"
#include "IAView.h"
#include "IAButton.h"
#include "IAScrollLayout.h"

typedef struct {
	//@extend
	IAView view;
	IAFlowLayout * overlay;
	IAFlowLayout * content;
	IAScrollLayout * contentFavorites;
	IAButton * tabs[3];
} MainView;


void MainView_init(MainView *);


void MainView_deinit(MainView *);

#include "MainView+Generated.h"

#endif
