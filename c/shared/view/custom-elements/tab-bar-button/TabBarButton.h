//
//  TabBarButton.h
//

#ifndef TabBarButton_h
#define TabBarButton_h

#include "IADrawableRect.h"
#include "IAButton.h"
#include "TabBarButtonAttributes.h"
#include "TabBarButtonEvent.h"

typedef struct TabBarButton TabBarButton;

struct TabBarButton{
	//@extend
	IADrawableRect rect;
	IAButton * buttonForStateOn;
	IAButtonDelegate buttonForStateOnDelegate;
	IAButton * buttonForStateOff;
	IAButtonDelegate buttonForStateOffDelegate;
	//@get
	bool isOn;
	//@get
	bool isClickable;

	//@get
	int tag;

	//@register
	TabBarButtonEvent events;
};


void TabBarButton_init(TabBarButton *, const TabBarButtonAttributes * attr);

void TabBarButton_setIsOn(TabBarButton *, bool isOn);
void TabBarButton_setIsClickable(TabBarButton *, bool isClickable);

void TabBarButton_deinit(TabBarButton *);

#include "TabBarButton+Generated.h"

#endif
