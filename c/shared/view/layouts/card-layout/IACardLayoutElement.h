//
//  IACardLayoutElement.h
//

#ifndef IACardLayoutElement_h
#define IACardLayoutElement_h

#include "IADrawableRect.h"
#include "IACardLayoutElementAttributes.h"

typedef struct{
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
} IACardLayoutElement;


void IACardLayoutElement_init(IACardLayoutElement *, const IACardLayoutElementAttributes * attr);
void IACardLayoutElement_initWithContent(IACardLayoutElement *, IADrawableRect * content);
void IACardLayoutElement_initCopy(IACardLayoutElement *, const IACardLayoutElement * toCopy);

void IACardLayoutElement_deinit(IACardLayoutElement *);

#include "IACardLayoutElement+Generated.h"

#endif
