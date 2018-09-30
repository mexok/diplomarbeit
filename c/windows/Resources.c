//
//  Resources.c
//

#include "IALibrary.h"
#include "Resources.h"
#include "IAColorRect.h"

#define CLASSNAME "Resources"


void Resources_commence() {

}

IAImage * Resources_getImage(const char * name){
	return IAColorRect_new(IAColor_cyan);
}

void Resources_terminate() {

}
