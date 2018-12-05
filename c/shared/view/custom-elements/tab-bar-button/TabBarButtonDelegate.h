//
//  TabBarButtonDelegate.h
//

#ifndef TabBarButtonDelegate_h
#define TabBarButtonDelegate_h

#include <stdbool.h>

typedef struct TabBarButton TabBarButton;

//@event
typedef struct {
	void * correspondingObject;
	//@exe
	void (*onStateChanged)(void * correspondingObject, bool isOn, TabBarButton * TabBarButton);
} TabBarButtonDelegate;

#include "TabBarButtonDelegate+Generated.h"

#endif
