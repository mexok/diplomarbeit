//
//  SampleView.c
//

#include "IALibrary.h"
#include "SampleView.h"
#include "IAViewPort.h"
#include "IABackgroundColor.h"

#define CLASSNAME "SampleView"


static void onFadeInStart(SampleView *, uint64_t startTime, uint64_t duration);
static void draw(SampleView *);


static void onClickMyButton(SampleView *this, IAButton *button){
	logInfo("My button clicked!");
}

static void onInjectMyButton(SampleView *this, IAButtonAttributes * attr){
	IAButtonAttributes_setOnClickFunction(attr, (void(*)(void *, IAButton *)) onClickMyButton);
}

void SampleView_init(SampleView *this) {
	this->base = IAObject_make(this);
	SampleLayoutAttributes attr;
	SampleLayoutAttributes_make(&attr, this);
	SampleLayoutAttributes_setOnInjectMyButtonFunction(&attr, (void (*)(void *, IAButtonAttributes *)) onInjectMyButton);
	SampleLayoutAttributes_setMyButtonRef(&attr, &this->myButton);
	this->sampleLayout = SampleLayout_newFromYaml(&attr);
	IAViewAttributes viewAttr;
	IAViewAttributes_make(&viewAttr, this);
	IAViewAttributes_setOnFadeInStartFunction(&viewAttr, (IAViewAttributes_onFadeInStart) onFadeInStart);
	IAViewAttributes_setDrawFunction(&viewAttr, (IAViewAttributes_drawFunction) draw);
	IAView_make(&this->view, "sample-view", &viewAttr);
	IA_incrementInitCount();
}

static void onFadeInStart(SampleView * this, uint64_t startTime, uint64_t duration){
	IAButton_setIsClickable(this->myButton, true);
}

static void draw(SampleView * this){
	IABackgroundColor_draw(IAColor_black);
	IARect rect = {
			.origin = IAPoint_zero,
			.size = IAViewPort_getSize()
	};
	IAFlowLayout_setRect(this->sampleLayout, rect);
	IAFlowLayout_draw(this->sampleLayout);
};

void SampleView_deinit(SampleView *this) {
	IAFlowLayout_release(this->sampleLayout);
	IA_decrementInitCount();
}
