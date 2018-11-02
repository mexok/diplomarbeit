//
//  MainViewArgs.c
//

#include "IALibrary.h"
#include "MainViewArgs.h"

#define CLASSNAME "MainViewArgs"


void MainViewArgs_init(MainViewArgs *this) {
	this->base = IAObject_make(this);
	IA_incrementInitCount();
}

void MainViewArgs_deinit(MainViewArgs *this) {
	IA_decrementInitCount();
}
