//
//  OnOffSwitchAttributes.c
//

#include "IALibrary.h"
#include "OnOffSwitchAttributes.h"

#define CLASSNAME "OnOffSwitchAttributes"


void OnOffSwitchAttributes_make(OnOffSwitchAttributes * this, void * correspondingObject) {
	*this = (OnOffSwitchAttributes){
		.correspondingObject = correspondingObject
	};
}
