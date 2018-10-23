//
//  IAGridLayoutElementAttributes.h
//

#ifndef IAGridLayoutElementAttributes_h
#define IAGridLayoutElementAttributes_h

#include <stdint.h>
#include "IADrawableRect.h"

typedef struct {
	//@get
	IADrawableRect * content;
	//@set+get
	size_t offsetX;
	//@set+get
	size_t offsetY;
	//@set+get
	size_t width;
	//@set+get
	size_t height;
} IAGridLayoutElementAttributes;


void IAGridLayoutElementAttributes_make(IAGridLayoutElementAttributes *, IADrawableRect * content);

#include "IAGridLayoutElementAttributes+Generated.h"

#endif
