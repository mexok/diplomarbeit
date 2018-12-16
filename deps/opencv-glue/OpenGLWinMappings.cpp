//
//  OpenGLWinMappings.cpp
//


#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

extern "C" {
#include "IALibrary.h"
#include "IAOpenGLWinMappings.h"
#include "IAOpenGLHeaders.h"
}

#include "OpenGLWinMappings.h"


#define CLASSNAME "OpenGLWinMappings"

using namespace cv;

static void * nativeCreateRefFromAsset(const char * assetName);
static void * nativeCreateRefFromScreen(int x, int y, int width, int height);
static IASize nativeGetSourceSize(void * bitmapRef);
static void nativeBind(void * bitmapRef);
static void nativeDestroyBitmapRef(void * bitmapRef);

static const char * assets_dir_name = "../assets/";


const char * OpenGLWinMappings_getAssetDirName(){
	return assets_dir_name;
}

void OpenGLWinMappings_setMappings() {
	IAOpenGLWinMappings mappings = {
			.IABitmap_nativeCreateRefFromAsset = nativeCreateRefFromAsset,
			.IABitmap_nativeCreateRefFromScreen = nativeCreateRefFromScreen,
			.IABitmap_nativeGetSourceSize = nativeGetSourceSize,
			.IABitmap_nativeBind = nativeBind,
			.IABitmap_nativeDestroyBitmapRef = nativeDestroyBitmapRef
	};
	IAOpenGLWinMappings_setMappings(mappings);
}

static void * nativeCreateRefFromAsset(const char * assetName){
	String string = String(assets_dir_name) + String(assetName);
	Mat image = imread(string, IMREAD_UNCHANGED);
	//premultiply alpha
	size_t data_len = image.rows * image.cols * 4;
	for (size_t i = 0; i < data_len; i+=4) {
		float alpha = image.data[i+3] / 255.0f;
		image.data[i] *= alpha;
		image.data[i+1] *= alpha;
		image.data[i+2] *= alpha;
	}
	Mat * result = new Mat(image);
	return result;
}

static void * nativeCreateRefFromScreen(int x, int y, int width, int height){
	return NULL;
}

static IASize nativeGetSourceSize(void * bitmapRef){
	Mat * image = (Mat *) bitmapRef;
	IASize result = {
		.width = (float) image->cols,
		.height = (float) image->rows
	};
	return result;
}

static void nativeBind(void * bitmapRef){
	Mat * image = (Mat *) bitmapRef;
	Mat temp = *image;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D,
	             0,
	             GL_RGBA,
	             temp.cols,
	             temp.rows,
	             0,
	             GL_BGRA,
	             GL_UNSIGNED_BYTE,
	             temp.ptr());
}

static void nativeDestroyBitmapRef(void * bitmapRef){
	Mat * image = (Mat *) bitmapRef;
	delete image;
}
