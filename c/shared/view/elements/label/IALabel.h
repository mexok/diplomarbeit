//
//  IALabel.h
//

#ifndef IALabel_h
#define IALabel_h

#include "IAObject.h"

typedef struct {
	//@extend
	IAObject base;


} IALabel;


void IALabel_init(IALabel *);


void IALabel_deinit(IALabel *);

#include "IALabel+Generated.h"

#endif
