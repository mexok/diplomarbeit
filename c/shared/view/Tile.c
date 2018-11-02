//
//  Tile.c
//

#include "IALibrary.h"
#include "Tile.h"

#define CLASSNAME "Tile"


void Tile_init(Tile *this) {
	this->base = IAObject_make(this);
	IA_incrementInitCount();
}

void Tile_deinit(Tile *this) {
	IA_decrementInitCount();
}
