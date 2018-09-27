//
//  Resources.c
//

#include "IALibrary.h"
#include "Resources.h"

#define CLASSNAME "Resources"


void Resources_commence() {

}

IAImage * Resources_getImage(const char * name){
	return IAString_new(name);
}

void Resources_terminate() {

}
