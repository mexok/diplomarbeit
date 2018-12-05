//
//  TabBarButtonAttributes.h
//

#ifndef TabBarButtonAttributes_h
#define TabBarButtonAttributes_h

#include "IADrawableRect.h"

typedef struct TabBarButton TabBarButton;

typedef struct {
	//@set+get
	IADrawableRect * stateOnNormal;
	//@set+get
	IADrawableRect * stateOnTouched;
	//@set+get
	IADrawableRect * stateOffNormal;
	//@set+get
	IADrawableRect * stateOffTouched;
	//@set+get
	bool initialIsOn;
	//@set+get
	int tag;
} TabBarButtonAttributes;


void TabBarButtonAttributes_make(TabBarButtonAttributes *);

#include "TabBarButtonAttributes+Generated.h"

#endif
