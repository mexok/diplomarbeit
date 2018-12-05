//
//  SmallTile.h
//

#ifndef SmallTile_h
#define SmallTile_h

#include "IAButton.h"
#include "SmallTileAttributes.h"
#include "SmallTileLayout.h"

typedef struct {
	//@extend
	IAButton button;

	IACardLayout * tile;
	IACardLayout * imageHolder;
	IALabel * titleLabel;
	IALabel * subtitleLabel;

	IACardLayout * tileTouched;
	IACardLayout * imageHolderTouched;
	IALabel * titleLabelTouched;
	IALabel * subtitleLabelTouched;

	IAString title;
	IAString subtitleActive;
	IAString subtitleInactive;
	IAImage * iconActive;
	IAImage * iconInactive;

	IAImage * backgroundActive;
	IAImage * backgroundActiveTouched;
	IAImage * backgroundInactive;
	IAImage * backgroundInactiveTouched;

	//@get
	bool isActive;

	IAButtonDelegate buttonDelegate;
} SmallTile;


void SmallTile_init(SmallTile *, const SmallTileAttributes * attr);


void SmallTile_deinit(SmallTile *);

#include "SmallTile+Generated.h"

#endif
