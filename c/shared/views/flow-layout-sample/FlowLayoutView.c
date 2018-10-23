//
//  FlowLayoutView.c
//

#include "IALibrary.h"
#include "FlowLayoutView.h"
#include "IAViewPort.h"
#include "IACurrentFrame.h"

#define CLASSNAME "FlowLayoutView"


void FlowLayoutView_init(FlowLayoutView * this) {
	this->base = IAObject_make(this);
	IAViewAttributes attr;
	IAViewAttributes_make(&attr, this);
	IAViewAttributes_setSetArgsFunction(&attr, FlowLayoutView_setArgs);
	IAViewAttributes_setOnFadeInStartFunction(&attr, FlowLayoutView_onFadeInStart);
	IAViewAttributes_setDrawFadeInFunction(&attr, FlowLayoutView_drawFadeIn);
	IAViewAttributes_setOnFadeInFinishedFunction(&attr, FlowLayoutView_onFadeInFinished);
	IAViewAttributes_setDrawFunction(&attr, FlowLayoutView_draw);
	IAViewAttributes_setOnFadeOutStartFunction(&attr, FlowLayoutView_onFadeOutStart);
	IAViewAttributes_setDrawFadeOutFunction(&attr, FlowLayoutView_drawFadeOut);
	IAViewAttributes_setOnFadeOutFinishedFunction(&attr, FlowLayoutView_onFadeOutFinished);
	IAView_make(&this->view, "flow layout view", &attr);
	this->rect = IAColorRect_new(IAColor_red);
	this->posx = 0;
	IA_incrementInitCount();
}

void FlowLayoutView_setArgs(const FlowLayoutView * this, const void * args) {

}

void FlowLayoutView_onFadeInStart(FlowLayoutView * this, uint64_t startTime, uint64_t duration) {

}

void FlowLayoutView_drawFadeIn(FlowLayoutView * this, uint64_t startTime, uint64_t duration, uint64_t currentTime) {

}

void FlowLayoutView_onFadeInFinished(FlowLayoutView * this, uint64_t startTime, uint64_t duration, uint64_t endTime) {

}

void FlowLayoutView_draw(FlowLayoutView * this, uint64_t currentTime) {
	this->posx += IACurrentFrame_getDeltaTimeSinceLastFrame();
	IAColorRect_setRect(this->rect, IARect_make(/*this->posx % 500*/ 1, 1, 200, 200));
	IAColorRect_draw(this->rect);
}

void FlowLayoutView_onFadeOutStart(FlowLayoutView * this, uint64_t startTime, uint64_t duration) {

}

void FlowLayoutView_drawFadeOut(FlowLayoutView * this, uint64_t startTime, uint64_t duration, uint64_t currentTime) {

}

void FlowLayoutView_onFadeOutFinished(FlowLayoutView * this, uint64_t startTime, uint64_t duration, uint64_t endTime) {

}

void FlowLayoutView_deinit(FlowLayoutView * this) {
	IA_decrementInitCount();
}
