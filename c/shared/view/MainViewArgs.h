//
// Created by Konstantin on 25.10.2018.
//

#ifndef MainViewArgs_h
#define MainViewArgs_h

typedef struct{
	//@extend
	IAObject object;
	void * data;
	void (*onTabSwitch)(void * data, int tabIndex);
	IAArray * tiles;
} MainViewArgs;


void MainViewArgs_init(MainViewArgs *);
void MainViewArgs_deinit(MainViewArgs *);

#endif
