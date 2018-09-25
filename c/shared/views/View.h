//
//  View.h
//  yaml
//
//  Created by Konstantin Merker on 01.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef View_h
#define View_h

typedef struct{
    //@extend
    IAObject base;

} View;


void View_init(View * this);



void View_deinit(View * this);

#endif
