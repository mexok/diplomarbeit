//
//  Resources.c
//


#include <dirent.h>

#include "IALibrary.h"
#include "Resources.h"
#include "IAColorRect.h"
#include "IAImageContext.h"
#include "IABitmapManagerSingleton.h"
#include "OpenGLWinMappings.h"

#define CLASSNAME "Resources"


static IAImageContext * context;
static IAColorableFontAtlas * atlas;


static bool isImage(struct dirent * entry){
	if (entry->d_namlen > 4) {
		const char *fileEnding = entry->d_name + entry->d_namlen - 4;
		if (strcmp(fileEnding, ".png") == 0) {
			return true;
		}
	}
	return false;
}

static void addImageToContext(struct dirent * entry){
	char image_file_name[entry->d_namlen + 1];
	memcpy(image_file_name, entry->d_name, entry->d_namlen);
	image_file_name[entry->d_namlen] = '\0';

	size_t image_name_len = (size_t) entry->d_namlen - 4;
	char image_name[image_name_len + 1];
	memcpy(image_name, entry->d_name, image_name_len);
	image_name[image_name_len] = '\0';

	IAImageContext_addImage(context, image_name, image_file_name);
}

void Resources_commence() {
	const char * assets_dir_name = OpenGLWinMappings_getAssetDirName();
	IABitmapManager * bitmapManager = IABitmapManagerSingleton_getDefaultBitmapManager();
	context = IAImageContext_new(bitmapManager);
	DIR * assets_dir = opendir (assets_dir_name);
	struct dirent * entry;
	while ((entry = readdir(assets_dir)) != NULL){
		if (isImage(entry)){
			addImageToContext(entry);
		}
	}
	closedir(assets_dir);
	atlas = IAColorableFontAtlas_new(bitmapManager);
	IAColorableFontAtlas_addGlyphsFromFnt(atlas, "roboto_regular_100", true);
}

IAImage * Resources_getImage(const char * name){
	IAImage * image = IAImageContext_getImage(context, name);
	if (strcmp(name, "slider_handle")
		|| strcmp(name, "tile_big_untouched")){
		return IAImage_copy(image);
	}else{
		return image;
	}
}

IAColor Resources_getLampColor(int index){
	debugAssert(index >= 0 && index <= 6);
	switch (index){
		case 0:
			// purple
			return IAColor_make(197, 50, 224, 255);
		case 1:
			return IAColor_blue;
		case 2:
			// turquoise
			return IAColor_make(64, 224, 208, 255);
		case 3:
			return IAColor_green;
		case 4:
			return IAColor_yellow;
		case 5:
			// orange - brown
			return IAColor_make(224, 132, 50, 255);
		case 6:
			return IAColor_red;
		default:
			break;
	}
}

IAImage * Resources_getLampColorImage(int index){
	debugAssert(index >= 0 && index <= 6);
	char lamp_color[20];
	sprintf(lamp_color, "lamp_color%d", (index + 1));
	return Resources_getImage(lamp_color);
}

IAColorableFontAtlas * Resources_getRegularFontAtlas(){
	return atlas;
}
