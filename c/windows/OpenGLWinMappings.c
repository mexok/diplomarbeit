//
//  OpenGLWinMappings.c
//


//#include <opencv2/core/core.hpp>
/*
extern "C" {
#include "IALibrary.h"
#include "IAOpenGLWinMappings.h"
}

#include "OpenGLWinMappings.h"*/

#include <stdio.h>

#define CLASSNAME "OpenGLWinMappings"

//using namespace cv;

static void * nativeCreateRefFromAsset(const char * assetName);
static void * nativeCreateRefFromScreen(int x, int y, int width, int height);
//static IASize nativeGetSourceSize(void * bitmapRef);
static void nativeBind(void * bitmapRef);
static void nativeDestroyBitmapRef(void * bitmapRef);

void OpenGLWinMappings_setMappings() {
	/*IAOpenGLWinMappings mappings = {
			.IABitmap_nativeCreateRefFromAsset = nativeCreateRefFromAsset,
			.IABitmap_nativeCreateRefFromScreen = nativeCreateRefFromScreen,
			.IABitmap_nativeGetSourceSize = nativeGetSourceSize,
			.IABitmap_nativeBind = nativeBind,
			.IABitmap_nativeDestroyBitmapRef = nativeDestroyBitmapRef
	};
	IAOpenGLWinMappings_setMappings(mappings);*/
}

static void * nativeCreateRefFromAsset(const char * assetName){
//	Mat image;
	//image = imread(assetName, CV_LOAD_IMAGE_COLOR);

}

static void * nativeCreateRefFromScreen(int x, int y, int width, int height){
	return NULL;
}

/*static IASize nativeGetSourceSize(void * bitmapRef){

}*/

static void nativeBind(void * bitmapRef){

}

static void nativeDestroyBitmapRef(void * bitmapRef){

}
