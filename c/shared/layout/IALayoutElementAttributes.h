//
//  IALayoutElementAttributes.h
//  yaml
//
//  Created by Konstantin Merker on 02.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef IALayoutElementAttributes_h
#define IALayoutElementAttributes_h

#include "IADrawableRect.h"

typedef struct{
    IADrawableRect * correspondingDrawableRect;
    IAPoint centerPoint;
    IAPoint leftTopPoint;
    IASize size;
    IARect rect;
    bool isCenterPoint;
} IALayoutElementAttributes;


void IALayoutElementAttributes_make(IALayoutElementAttributes * this);

#include "IALayoutElementAttributes+Generated.h"

#endif
