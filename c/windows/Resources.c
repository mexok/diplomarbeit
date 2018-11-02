//
//  Resources.c
//

#include "IALibrary.h"
#include "Resources.h"
#include "IAColorRect.h"
#include "IAImageContext.h"
#include "IABitmapManagerSingleton.h"

#define CLASSNAME "Resources"

static IAImageContext * context;

void Resources_commence() {
	IABitmapManager * bitmapManager = IABitmapManagerSingleton_getDefaultBitmapManager();
	context = IAImageContext_new(bitmapManager);
	IAImageContext_addImage(context, "Koala", "C:/diplomarbeit/assets/Koala.jpg");
	IAImage * img = IAImageContext_getImage(context, "Koala");
	IASize s = IAImage_getOriginalSize(img);
	int x = 0;
}

IAImage * Resources_getImage(const char * name){
	return IAImageContext_getImage(context, name);
}
