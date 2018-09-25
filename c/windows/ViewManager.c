//
//  ViewManager.c
//

#include "IALibrary.h"
#include "IAViewHolder.h"
#include "IACurrentFrame.h"
#include "ViewManager.h"
#include "FlowLayoutView.h"
#include "SampleView.h"

#define CLASSNAME "ViewManager"

static IAViewHolder * viewHolder;
static FlowLayoutView * flowLayoutView;
static SampleView * sampleView;

void ViewManager_commence(){
	flowLayoutView = FlowLayoutView_new();
	viewHolder = IAViewHolder_new();
	sampleView = SampleView_new();
	IAViewHolder_start(viewHolder, SampleView_getView(sampleView), IACurrentFrame_getTime(), NULL);
}

void ViewManager_draw() {
	IAViewHolder_draw(viewHolder, IACurrentFrame_getTime());
}

