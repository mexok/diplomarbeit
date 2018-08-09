//
//  IALayoutElement.h
//  yaml
//
//  Created by Konstantin Merker on 02.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef IALayoutElement_h
#define IALayoutElement_h

typedef struct{
    IADrawableRect * correspondingDrawableRect;
} IALayoutElement;


void IALayoutElement_init(IALayoutElement * this);



void IALayoutElement_deinit(IALayoutElement * this);

#include "IALayoutElement+Generated.h"

#endif
