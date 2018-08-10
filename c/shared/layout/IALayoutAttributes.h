//
//  IALayoutAttributes.h
//  yaml
//
//  Created by Konstantin Merker on 02.08.18.
//Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef IALayoutAttributes_h
#define IALayoutAttributes_h

#include "IASize.h"
#include "IALayoutScaling.h"
#include "IAArray.h"

typedef struct{
    IAArray(IALayoutElement) * elements;
} IALayoutAttributes;


void IALayoutAttributes_make(IALayoutAttributes * this, size_t elementCount, IALayoutElement * elements[elementCount]);




#include "IALayoutAttributes+Generated.h"

#endif
