//
//  View.c
//  yaml
//
//  Created by Konstantin Merker on 01.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#include "IALibrary.h"
#include "View.h"

#define CLASSNAME "View"


void View_init(View * this){
    View_generated_initAttributes(this);
}

void View_render(View * this){
    View_generated_refresh(this);
}

void View_deinit(View * this){
    View_generated_deinitAttributes(this);
}

