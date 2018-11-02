#pragma once

#include "IAOpenGLWinMappings.h"

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CSrc_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CSrc_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

//@disableFunctionNameCheck

void createResources(int frameBufferWidth, int frameBufferHeight);

void updateFramebufferSize(int frameBufferWidth, int frameBufferHeight);

void render(void);

void acquireApplicationLock();
void releaseApplicationLock();
