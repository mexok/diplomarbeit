//
//  Resources.h
//

#ifndef Resources_h
#define Resources_h

#include "IAImage.h"
#include "IAColorableFontAtlas.h"

void Resources_commence(void);

//@resourceProvider(Image)
IAImage * Resources_getImage(const char * name);

// index has to be between 0 and 6 (inclusive)
IAColor Resources_getLampColor(int index);
IAImage * Resources_getLampColorImage(int index);

//@resourceProvider(RegularFont30)
IAColorableFontAtlas * Resources_getRegularFont30Atlas(void);

//@resourceProvider(RegularFont70)
IAColorableFontAtlas * Resources_getRegularFont70Atlas(void);


#endif
