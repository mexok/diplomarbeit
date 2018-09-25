//
//  SampleView.c
//

#include "IALibrary.h"
#include "SampleView.h"
#include "IAViewPort.h"

#define CLASSNAME "SampleView"


static void draw(SampleView *);

void SampleView_init(SampleView *this) {
	this->base = IAObject_make(this);
	SampleLayoutAttributes attr;
	SampleLayoutRef ref;
	this->sampleLayout = SampleLayout_newIAFlowLayoutFromYaml(&attr, &ref);
	IAViewAttributes viewAttr;
	IAViewAttributes_make(&viewAttr, this);
	IAViewAttributes_setDrawFunction(&viewAttr, (IAViewAttributes_drawFunction) draw);
	IAView_make(&this->view, "sample-view", &viewAttr);
	IA_incrementInitCount();
}

static void draw(SampleView * this){
	IARect rect = {
			.origin = IAPoint_ZERO,
			.size = IAViewPort_getSize()
	};
	IAFlowLayout_setRect(this->sampleLayout, rect);
	IAFlowLayout_draw(this->sampleLayout);
};

void SampleView_deinit(SampleView *this) {
	IAFlowLayout_release(this->sampleLayout);
	IA_decrementInitCount();
}
