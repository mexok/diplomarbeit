//
//  IACardLayoutElementAttributes.h
//

#ifndef IACardLayoutElementAttributes_h
#define IACardLayoutElementAttributes_h

#include "IAObject.h"
#include "IADrawableRect.h"

typedef struct {
	//@extend
	IAObject base;
	//@get
	IADrawableRect * content;
	//@set+get
	float marginLeft;
	//@set+get
	float marginTop;
	//@set+get
	float marginRight;
	//@set+get
	float marginBottom;
	//@set+get
	float marginLeftRelative;
	//@set+get
	float marginTopRelative;
	//@set+get
	float marginRightRelative;
	//@set+get
	float marginBottomRelative;
} IACardLayoutElementAttributes;


void IACardLayoutElementAttributes_make(IACardLayoutElementAttributes *, IADrawableRect * content);

void IACardLayoutElementAttributes_setMargins(IACardLayoutElementAttributes *, float margins);
void IACardLayoutElementAttributes_setMarginsRelative(IACardLayoutElementAttributes *, float marginsRelative);

#include "IACardLayoutElementAttributes+Generated.h"

#endif
