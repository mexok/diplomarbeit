//
//  MainApp.c
//  yaml
//
//  Created by Konstantin Merker on 30.07.18.
//  Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#include "MainApp.h"
#include "IAColorRect.h"
#include "IABackgroundColor.h"
#include "View.h"

#define CLASSNAME "MainApp"

static IAColorRect * colorRect;

static void commence(void * null){
    colorRect = IAColorRect_new(IAColor_make(255, 0, 255, 255));
}

static void onRender(void * null){
    IABackgroundColor_draw(IAColor_make(255, 255, 0, 255));
    IAColorRect_setLeftTopRightBottom(colorRect, 100.0f, 100.0f, 500.0f, 200.0f);
    IAColorRect_draw(colorRect);
    logInfo("%ld", sizeof(View));
}

void MainApp_onAppStart(IAAppAttributes * attr){
    IAAppAttributes_setCommenceFunction(attr, commence);
    IAAppAttributes_setOnRenderFunction(attr, onRender);
}
