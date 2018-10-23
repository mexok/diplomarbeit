// CSrc.cpp : Defines the exported functions for the DLL application.
//


#include <time.h>
#include "CSrc.h"
#include "IAOpenGL.h"
#include "IAViewPort.h"
#include "IAAllocationTracker.h"
#include "IAString.h"
#include "IACLibWinMappings.h"
#include "IAInputOutputWinMappings.h"
#include "IATouchManager.h"
#include "IAWinTouchHandler.h"
#include "ViewManager.h"

#undef in

#include "IAOpenGLHeaders.h"

#define CLASSNAME "CSrc"

static HANDLE ghMutex;

debugOnly(static IAAllocationTracker * tracker);

static uint64_t CSrcs_getTimeInMilliseconds(){
	clock_t c = clock() / (CLOCKS_PER_SEC / 1000);
	return c;
}

static void CSrcs_nativeInitWithAsset(IAString * this, const char * assetName, const char * assetFileExtension){
	IAString * assetFile = IAString_new("..\\\\Assets\\\\");
	IAString_concat(assetFile, assetName);
	IAString_concat(assetFile, ".");
	IAString_concat(assetFile, assetFileExtension);

	FILE * file = fopen(IAString_toCharArray(assetFile), "r");
	IAString_init(this, "");
	if (file) {
		char buffer[4096];
		size_t read = 0;
		while (read = fread(buffer, 1, 4096, file)) {
			IAString_concatWithLength(this, buffer, read);
		}
		fclose(file);
	}
	
}

const char * CSrc_getLocaleId(void) {
	static const char * localeId = "en";
	return localeId;
}

void createResources(int frameBufferWidth, int frameBufferHeight){
	ghMutex = CreateMutex(
		NULL,              // default security attributes
		FALSE,             // initially not owned
		NULL);             // unnamed mute
	assert(ghMutex && "mutex could not be created");

	IACLibWinMappings clibMappings = {
		.IATime_getTimeInMilliseconds = CSrcs_getTimeInMilliseconds,
		.IATime_getTimeInNanoSeconds = CSrcs_getTimeInMilliseconds
	};
	IACLibWinMappings_setMappings(clibMappings);

	IAInputOutputWinMappings ioMappings = {
		.IALocalisation_getLocaleId = CSrc_getLocaleId,
		.IAString_nativeInitWithAsset = CSrcs_nativeInitWithAsset
	};
	IAInputOutputWinMappings_setMappings(ioMappings);

	glewInit();

	IALibrary_commenceIfNeeded();
	IAOpenGL_commence();

	IATouchManager_commence();

	IAOpenGL_onSurfaceCreated();

	IASize surfaceSize = IASize_make(frameBufferWidth, frameBufferHeight);
	IAOpenGL_onSurfaceChanged(surfaceSize);

	debugOnly(tracker = IAAllocationTracker_new());

	ViewManager_commence();

	IAWinTouchHandler_start(acquireApplicationLock, releaseApplicationLock);
}

void updateFramebufferSize(int frameBufferWidth, int frameBufferHeight) {
	acquireApplicationLock();
	IASize surfaceSize = IASize_make(frameBufferWidth, frameBufferHeight);
	IAOpenGL_onSurfaceChanged(surfaceSize);
	releaseApplicationLock();
}

void render(void){
	acquireApplicationLock();
	IAOpenGL_onRenderBegin();
	ViewManager_draw();
	IAOpenGL_onRenderEnd();
	releaseApplicationLock();
}

void setOpenGLWinMappings(IAOpenGLWinMappings mappings) {
	IAOpenGLWinMappings_setMappings(mappings);
}

void acquireApplicationLock() {
	DWORD dwWaitResult = WaitForSingleObject(
		ghMutex,    // handle to mutex
		INFINITE);  // no time-out interval
	IAAutoreleasePool_begin();
#ifdef DEBUG
	IAAllocationTracker_start(tracker);
#endif
}

void releaseApplicationLock() {
#ifdef DEBUG
	IAAllocationTracker_stop(tracker);
	//IAAllocationTracker_log(tracker);
	//IAAllocationTracker_assert(tracker);
#endif
	IAAutoreleasePool_end();
	ReleaseMutex(ghMutex);
}

