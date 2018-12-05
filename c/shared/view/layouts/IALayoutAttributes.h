//
//  IALayoutAttributes.h
//

#ifndef IALayoutAttributes_h
#define IALayoutAttributes_h

#include "IAObject.h"
#include "IAColor.h"
#include "IADrawableRect.h"

typedef struct {
	//@extend
	IAObject base;
	//@get
	IADrawableRect * backgroundDrawable;
	//@get
	bool hasBackgroundDrawable;
	//@get
	IAColor backgroundColor;
	//@get
	bool hasBackgroundColor;
	//@set+get
	float paddingLeft;
	//@set+get
	float paddingTop;
	//@set+get
	float paddingRight;
	//@set+get
	float paddingBottom;
} IALayoutAttributes;


void IALayoutAttributes_make(IALayoutAttributes *);

void IALayoutAttributes_setBackgroundDrawable(IALayoutAttributes *, IADrawableRect * backgroundDrawable);
void IALayoutAttributes_setBackgroundColor(IALayoutAttributes *, IAColor backgroundColor);
void IALayoutAttributes_setPadding(IALayoutAttributes *, float padding);

#include "IALayoutAttributes+Generated.h"

#endif
