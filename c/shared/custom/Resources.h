//
//  Resources.h
//  yaml
//
//  Created by Konstantin Merker on 08.08.18.
//  Copyright © 2018 Konstantin Merker, Paul Wallrabe und Martin Krautschick GbR (Imps Apps). All rights reserved.
//

#ifndef Resources_h
#define Resources_h

#include "IAImage.h"
#include "IAImageContext.h"

//@provider(IAFrameAnimation:imageContext)
IAImageContext * Resources_getImageContext(void);

//@provider(IALayout:content -> image, IAButton:imageNormal, IAButton:imageTouched)
IAImage * Resources_get(const char * name);

//@provider(guiString)
IAString * Resources_get(const char * name);


#endif
