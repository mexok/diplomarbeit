//
//  IAGridLayoutElementAttributes.c
//

#include "IALibrary.h"
#include "IAGridLayoutElementAttributes.h"

#define CLASSNAME "IAGridLayoutElementAttributes"


void IAGridLayoutElementAttributes_make(IAGridLayoutElementAttributes * this, IADrawableRect * content) {
	*this = (IAGridLayoutElementAttributes){
		.content = content,
		.width = 1,
		.height = 1
    };
}
