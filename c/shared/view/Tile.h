//
//  Tile.h
//

#ifndef Tile_h
#define Tile_h

#include "IAObject.h"

typedef struct {
	//@extend
	IAObject base;


} Tile;


void Tile_init(Tile *);


void Tile_deinit(Tile *);

#include "Tile+Generated.h"

#endif
