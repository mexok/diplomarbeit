//
//  ViewManager.c
//

#include "IALibrary.h"
#include "IAViewHolder.h"
#include "IACurrentFrame.h"
#include "ViewManager.h"
#include "FlowLayoutView.h"

#define CLASSNAME "ViewManager"

static IAViewHolder * viewHolder;
static FlowLayoutView * flowLayoutView;

void ViewManager_commence(){
	flowLayoutView = FlowLayoutView_new();
	viewHolder = IAViewHolder_new();
	IAViewHolder_start(viewHolder, FlowLayoutView_getView(flowLayoutView), IACurrentFrame_getTime(), NULL);
}

void ViewManager_draw() {
	IAViewHolder_draw(viewHolder, IACurrentFrame_getTime());
}

