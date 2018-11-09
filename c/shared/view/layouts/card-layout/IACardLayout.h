//
//  IACardLayout.h
//

#ifndef IACardLayout_h
#define IACardLayout_h

#include "IALayout.h"
#include "IACardLayoutAttributes.h"
#include "IAArrayList.h"


typedef struct{
	//@extend
	IALayout layout;
	IAArrayList * elements;
} IACardLayout;


void IACardLayout_init(IACardLayout *, const IACardLayoutAttributes * attr);

void IACardLayout_addElement(IACardLayout *, IACardLayoutElement * element);
void IACardLayout_insertElementAtIndex(IACardLayout *, size_t index, IACardLayoutElement * element);
IACardLayoutElement * IACardLayout_removeLastElement(IACardLayout *);
IACardLayoutElement * IACardLayout_removeElementAtIndex(IACardLayout *, size_t index);
size_t IACardLayout_getElementCount(IACardLayout *);
bool IACardLayout_hasElements(IACardLayout *);

void IACardLayout_deinit(IACardLayout *);

#include "IACardLayout+Generated.h"

#endif
