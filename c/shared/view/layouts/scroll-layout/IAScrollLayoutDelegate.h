//
//  IAScrollLayoutDelegate.h
//

#ifndef IAScrollLayoutDelegate_h
#define IAScrollLayoutDelegate_h

//@event
typedef struct {
	void * correspondingObject;
	//@exe
	void(*onScrollBegin)(void * correspondingObject, IAScrollLayout * scrollView);
	//@exe
	void(*onScrollEnd)(void * correspondingObject, IAScrollLayout * scrollView);
} IAScrollLayoutDelegate;

#include "IAScrollLayoutDelegate+Generated.h"

#endif
