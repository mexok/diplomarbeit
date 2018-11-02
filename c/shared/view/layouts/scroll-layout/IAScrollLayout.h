#ifndef IAScrollLayout_h
#define IAScrollLayout_h

#include <stdint.h>
#include "IARect.h"
#include "IATouchDelegate.h"
#include "IAScrollLayoutAttributes.h"
#include "IAScrollingData.h"
#include "IAOverscrollingHandler.h"
#include "IALayout.h"


typedef struct IAScrollLayout IAScrollLayout;

struct IAScrollLayout{
	//@extend
	IALayout base;
	void * correspondingObject;
	IADrawableRect * content;
	float contentLength;
	bool isHorizontal;

	IATouchDelegate touchDelegate;

	uint64_t currentTime;

	IAPoint last;
	uint64_t startTime;
	float startScrollPos;
	//@get
	float currentScrollPos;

	IAScrollingData * scrollingData;
	IAOverscrollingHandler * overscrollingHandler;

	float thresholdInPixelForOnScrollBeginCall;
	bool onScrollBeginCalled;
	void(*onScrollBegin)(void * correspondingObject, IAScrollLayout * scrollView);
	void(*onScrollEnd)(void * correspondingObject, IAScrollLayout * scrollView);
	uint64_t(*getTime)();
};


void IAScrollLayout_init(IAScrollLayout *, const IAScrollLayoutAttributes * attr);

bool IAScrollLayout_isScrollable(const IAScrollLayout *);
bool IAScrollLayout_isScrolling(const IAScrollLayout *);

void IAScrollLayout_enableScrolling(IAScrollLayout *, uint64_t currentTime);
void IAScrollLayout_updateTime(IAScrollLayout *, uint64_t currentTime);
void IAScrollLayout_disableScrolling(IAScrollLayout *, uint64_t currentTime);

float IAScrollLayout_getOverscrolling(IAScrollLayout *);

void IAScrollLayout_deinit(IAScrollLayout *);

#include "IAScrollLayout+Generated.h"

#endif
