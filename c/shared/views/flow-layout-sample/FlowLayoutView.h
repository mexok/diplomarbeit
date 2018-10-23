//
//  FlowLayoutView.h
//

#ifndef FlowLayoutView_h
#define FlowLayoutView_h

#include "IAObject.h"
#include "IAView.h"
#include "IAColorRect.h"

typedef struct{
	//@extend
	IAObject base;
	//@getAsConstRef
	IAView view;
	IAColorRect * rect;
	int posx;
} FlowLayoutView;


void FlowLayoutView_init(FlowLayoutView *);

void FlowLayoutView_setArgs(const FlowLayoutView *, const void * args);

void FlowLayoutView_onFadeInStart(FlowLayoutView *, uint64_t startTime, uint64_t duration);
void FlowLayoutView_drawFadeIn(FlowLayoutView *, uint64_t startTime, uint64_t duration, uint64_t currentTime);
void FlowLayoutView_onFadeInFinished(FlowLayoutView *, uint64_t startTime, uint64_t duration, uint64_t endTime);
void FlowLayoutView_draw(FlowLayoutView *, uint64_t currentTime);
void FlowLayoutView_onFadeOutStart(FlowLayoutView *, uint64_t startTime, uint64_t duration);
void FlowLayoutView_drawFadeOut(FlowLayoutView *, uint64_t startTime, uint64_t duration, uint64_t currentTime);
void FlowLayoutView_onFadeOutFinished(FlowLayoutView *, uint64_t startTime, uint64_t duration, uint64_t endTime);

void FlowLayoutView_deinit(FlowLayoutView *);

#include "FlowLayoutView+Generated.h"

#endif
