//
//  Resources.h
//

#ifndef Resources_h
#define Resources_h

#include "IAImage.h"

void Resources_commence(void);

//@resourceProvider(Image)
IAImage * Resources_getImage(const char * name);

#endif
