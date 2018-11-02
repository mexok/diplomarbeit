//
//  IAFlowLayout.h
//

#ifndef IAFlowLayout_h
#define IAFlowLayout_h

#include "IALayout.h"
#include "IAFlowLayoutAttributes.h"
#include "IAArrayList.h"


typedef struct{
	//@extend
	IALayout layout;
	IAArrayList * elements;
	float spacing;
	bool isVertical;
} IAFlowLayout;


void IAFlowLayout_init(IAFlowLayout *, const IAFlowLayoutAttributes * attr);

void IAFlowLayout_addElement(IAFlowLayout *, IAFlowLayoutElement * element);
void IAFlowLayout_insertElementAtIndex(IAFlowLayout *, size_t index, IAFlowLayoutElement * element);
IAFlowLayoutElement * IAFlowLayout_removeLastElement(IAFlowLayout *);
IAFlowLayoutElement * IAFlowLayout_removeElementAtIndex(IAFlowLayout *, size_t index);

void IAFlowLayout_deinit(IAFlowLayout *);

#include "IAFlowLayout+Generated.h"

#endif
