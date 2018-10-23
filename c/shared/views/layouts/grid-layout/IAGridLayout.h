//
//  IAGridLayout.h
//

#ifndef IAGridLayout_h
#define IAGridLayout_h

#include "IADrawableRect.h"
#include "IAGridLayoutAttributes.h"

typedef struct {
	//@extend
	IADrawableRect drawableRect;
	size_t elementCount;
	IAGridLayoutElement * elements;
	size_t gridWidth;
	size_t gridHeight;
	//@get
	float spacing;
} IAGridLayout;


void IAGridLayout_init(IAGridLayout *, const IAGridLayoutAttributes * attr);


void IAGridLayout_deinit(IAGridLayout *);

#include "IAGridLayout+Generated.h"

#endif
