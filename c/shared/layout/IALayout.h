//
//  IALayout.h
//  yaml
//
//  Created by Konstantin Merker on 02.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef IALayout_h
#define IALayout_h

#include "IAObject.h"

typedef struct{
    //@extend
    IAObject base;
    
} IALayout;


void IALayout_init(IALayout * this);



void IALayout_deinit(IALayout * this);

#include "IALayout+Generated.h"

#endif
