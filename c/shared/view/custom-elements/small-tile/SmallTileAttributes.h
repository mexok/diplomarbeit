//
//  SmallTileAttributes.h
//

#ifndef SmallTileAttributes_h
#define SmallTileAttributes_h

#include "IAObject.h"
#include "IAString.h"
#include "IAImage.h"
#include "SmallTileImageSet.h"

typedef struct {
	//@extend
	IAObject base;

	//@setAsCharArray+getAsCharArray
	IAString title;
	//@setAsCharArray+getAsCharArray
	IAString subtitleActive;
	//@setAsCharArray+getAsCharArray
	IAString subtitleInactive;

	//@set+get
	IAImage * iconActive;
	//@set+get
	IAImage * iconInactive;
	//@set+get
	IAImage * backgroundActive;
	//@set+get
	IAImage * backgroundActiveTouched;
	//@set+get
	IAImage * backgroundInactive;
	//@set+get
	IAImage * backgroundInactiveTouched;
	//@set+get
	bool isPermanentActive;
} SmallTileAttributes;


void SmallTileAttributes_init(SmallTileAttributes *);

void SmallTileAttributes_setSubtitle(SmallTileAttributes *, const char * subtitle);
void SmallTileAttributes_setImageSet(SmallTileAttributes *, SmallTileImageSet imageSet);

void SmallTileAttributes_deinit(SmallTileAttributes *);

#include "SmallTileAttributes+Generated.h"

#endif
