//
//  IAGridLayoutElement.h
//

#ifndef IAGridLayoutElement_h
#define IAGridLayoutElement_h

#include "IAGridLayoutElementAttributes.h"

typedef struct {
	//@get
	IADrawableRect * content;
	//@get
	size_t offsetX;
	//@get
	size_t offsetY;
	//@get
	size_t width;
	//@get
	size_t height;
} IAGridLayoutElement;


void IAGridLayoutElement_init(IAGridLayoutElement *, const IAGridLayoutElementAttributes * attr);
void IAGridLayoutElement_initCopy(IAGridLayoutElement *, const IAGridLayoutElement * toCopy);

void IAGridLayoutElement_deinit(IAGridLayoutElement *);

#include "IAGridLayoutElement+Generated.h"

#endif
