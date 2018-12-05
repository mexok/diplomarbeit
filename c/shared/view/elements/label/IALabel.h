//
//  IALabel.h
//

#ifndef IALabel_h
#define IALabel_h

#include "IADrawableRect.h"
#include "IALabelAttributes.h"

typedef struct {
	//@extend
	IADrawableRect base;
	//@setAsCharArray+getAsCharArray
	IAString text;
	IAColorableFontAtlas * font;
	//@set+get
	IATextAlignment textAlignment;
	//@set+get
	float fontSize;
	//@set+get
	IAColor fontColor;
} IALabel;


void IALabel_init(IALabel *, const IALabelAttributes * attr);


void IALabel_deinit(IALabel *);

#include "IALabel+Generated.h"

#endif
