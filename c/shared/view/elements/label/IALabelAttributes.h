//
//  IALabelAttributes.h
//

#ifndef IALabelAttributes_h
#define IALabelAttributes_h

#include "IAObject.h"
#include "IAColorableFontAtlas.h"

typedef struct {
	//@extend
	IAObject base;
	//@setAsCharArray+getAsCharArray
	IAString text;
	//@get
	IAColorableFontAtlas * font;
	//@set+get
	IATextAlignment textAlignment;
	//@set+get
	float fontSize;
	//@set+get
	IAColor fontColor;
} IALabelAttributes;


void IALabelAttributes_init(IALabelAttributes *, const char * text, IAColorableFontAtlas * font);

void IALabelAttributes_deinit(IALabelAttributes *);

#include "IALabelAttributes+Generated.h"

#endif
