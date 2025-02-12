//
//  IALayout.h
//

#ifndef IALayout_h
#define IALayout_h

#include "IADrawableRect.h"
#include "IAColorRect.h"
#include "IALayoutAttributes.h"

typedef struct {
	//@extend
	IADrawableRect drawableRect;
	IADrawable_drawFunction overwrittenDrawFn;
	IADrawableRect_setRectFunction overwrittenSetRectFn;
	//@get
	IAColor backgroundColor;
	//@get
	bool hasBackgroundColor;
	IAColorRect * backgroundColorRect;

	//@get
	bool hasBackgroundDrawable;
	IADrawableRect * backgroundDrawable;

	//@get
	float paddingLeft;
	//@get
	float paddingTop;
	//@get
	float paddingRight;
	//@get
	float paddingBottom;

	//@get
	float paddingLeftRelative;
	//@get
	float paddingTopRelative;
	//@get
	float paddingRightRelative;
	//@get
	float paddingBottomRelative;
} IALayout;


void IALayout_init(IALayout *, IADrawable_drawFunction draw, IADrawableRect_setRectFunction setRect, const IALayoutAttributes * attr);


void IALayout_deinit(IALayout *);

#include "IALayout+Generated.h"

#endif
