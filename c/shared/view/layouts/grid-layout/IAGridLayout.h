//
//  IAGridLayout.h
//

#ifndef IAGridLayout_h
#define IAGridLayout_h

#include "IALayout.h"
#include "IAGridLayoutAttributes.h"

typedef struct {
	//@extend
	IALayout layout;
	size_t elementCount;
	IAGridLayoutElement * elements;
	size_t gridWidth;
	size_t gridHeight;
	//@get
	float spacing;
} IAGridLayout;


void IAGridLayout_init(IAGridLayout *, const IAGridLayoutAttributes * attr);

float IAGridLayout_getNeededHeight(IAGridLayout *, float width, float heightToWidthProportionOfSingleCell);

void IAGridLayout_deinit(IAGridLayout *);

#include "IAGridLayout+Generated.h"

#endif
