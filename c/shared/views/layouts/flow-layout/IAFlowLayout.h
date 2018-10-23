//
//  IAFlowLayout.h
//

#ifndef IAFlowLayout_h
#define IAFlowLayout_h

#include "IADrawableRect.h"
#include "IAFlowLayoutAttributes.h"

typedef struct{
	//@extend
	IADrawableRect drawableRect;
	size_t elementCount;
	IAFlowLayoutElement * elements;
	float spacing;
	bool isVertical;
} IAFlowLayout;


void IAFlowLayout_init(IAFlowLayout *, const IAFlowLayoutAttributes * attr);



void IAFlowLayout_deinit(IAFlowLayout *);

#include "IAFlowLayout+Generated.h"

#endif
