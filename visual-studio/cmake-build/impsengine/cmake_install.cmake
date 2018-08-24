# Install script for directory: C:/diplomarbeit/impsengine

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/YamlGui")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAAssert.h;C:/diplomarbeit/impsengine/include/windows/IALibrary+SendOnMemoryWarningNotification.h;C:/diplomarbeit/impsengine/include/windows/IALibrary.h;C:/diplomarbeit/impsengine/include/windows/IAObject.h;C:/diplomarbeit/impsengine/include/windows/IAArray.h;C:/diplomarbeit/impsengine/include/windows/IAArrayIterator.h;C:/diplomarbeit/impsengine/include/windows/IAArrayList.h;C:/diplomarbeit/impsengine/include/windows/IAArrayListIterator.h;C:/diplomarbeit/impsengine/include/windows/IAAutoExpandingHashMap.h;C:/diplomarbeit/impsengine/include/windows/IAAutoExpandingHashMapIterator.h;C:/diplomarbeit/impsengine/include/windows/IAHashMap.h;C:/diplomarbeit/impsengine/include/windows/IAHashMapIterator.h;C:/diplomarbeit/impsengine/include/windows/IAStructArrayList.h;C:/diplomarbeit/impsengine/include/windows/IAAutoreleasePool+Internal.h;C:/diplomarbeit/impsengine/include/windows/IAAutoreleasePool.h;C:/diplomarbeit/impsengine/include/windows/IAMemoryPool.h;C:/diplomarbeit/impsengine/include/windows/IAMemoryPoolElement.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTracker.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTrackerElement.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTracking+Internal.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTracking.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTrackingDelegate.h;C:/diplomarbeit/impsengine/include/windows/IAAllocationTrackingElement.h;C:/diplomarbeit/impsengine/include/windows/IACharArray+Internal.h;C:/diplomarbeit/impsengine/include/windows/IACharArray.h;C:/diplomarbeit/impsengine/include/windows/IAHashing.h;C:/diplomarbeit/impsengine/include/windows/IANotificationDelegate.h;C:/diplomarbeit/impsengine/include/windows/IAOperatingSystem.h;C:/diplomarbeit/impsengine/include/windows/IAString.h;C:/diplomarbeit/impsengine/include/windows/IATime.h;C:/diplomarbeit/impsengine/include/windows/IACondition.h;C:/diplomarbeit/impsengine/include/windows/IALock.h;C:/diplomarbeit/impsengine/include/windows/IAPosixAvailable.h;C:/diplomarbeit/impsengine/include/windows/IARecursiveLock.h;C:/diplomarbeit/impsengine/include/windows/IACLibWinMappings.h;C:/diplomarbeit/impsengine/include/windows/IALogger.h;C:/diplomarbeit/impsengine/include/windows/IAOperatingSystem+Native.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/IAAssert.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/IALibrary+SendOnMemoryWarningNotification.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/IALibrary.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/IAObject.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAArray.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAArrayIterator.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAArrayList.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAArrayListIterator.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAAutoExpandingHashMap.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAAutoExpandingHashMapIterator.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAHashMap.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAHashMapIterator.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/container/IAStructArrayList.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/IAAutoreleasePool+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/IAAutoreleasePool.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/IAMemoryPool.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/IAMemoryPoolElement.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTracker.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTrackerElement.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTracking+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTracking.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTrackingDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/memory-management/allocation-tracking/IAAllocationTrackingElement.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IACharArray+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IACharArray.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IAHashing.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IANotificationDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IAOperatingSystem.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IAString.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/IATime.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/concurrency/IACondition.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/concurrency/IALock.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/concurrency/IAPosixAvailable.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/shared/supporting-classes/concurrency/IARecursiveLock.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/windows/IACLibWinMappings.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/windows/IALogger.h"
    "C:/diplomarbeit/impsengine/modules/common/clib/c/windows/IAOperatingSystem+Native.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAMath.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES "C:/diplomarbeit/impsengine/modules/common/mathlib/c/shared/IAMath.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAAsyncTask.h;C:/diplomarbeit/impsengine/include/windows/IAParallelThread.h;C:/diplomarbeit/impsengine/include/windows/IAProcess+AndroidNative.h;C:/diplomarbeit/impsengine/include/windows/IAThreadPool.h;C:/diplomarbeit/impsengine/include/windows/IAThreadPoolInstance.h;C:/diplomarbeit/impsengine/include/windows/IAThreadPoolWaitingQueueItem.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAAsyncTask.h"
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAParallelThread.h"
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAProcess+AndroidNative.h"
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAThreadPool.h"
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAThreadPoolInstance.h"
    "C:/diplomarbeit/impsengine/modules/common/concurrentlib/c/shared/IAThreadPoolWaitingQueueItem.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAKeyValueElement.h;C:/diplomarbeit/impsengine/include/windows/IAKeyValueElementAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAKeyValueElementOperations.h;C:/diplomarbeit/impsengine/include/windows/IAKeyValueHashMap.h;C:/diplomarbeit/impsengine/include/windows/IALocalisation.h;C:/diplomarbeit/impsengine/include/windows/IAAtlasAssets.h;C:/diplomarbeit/impsengine/include/windows/IAAtlasAssetsAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAStorage+Native.h;C:/diplomarbeit/impsengine/include/windows/IAStorage.h;C:/diplomarbeit/impsengine/include/windows/IAString+Assets+Native.h;C:/diplomarbeit/impsengine/include/windows/IAString+Assets.h;C:/diplomarbeit/impsengine/include/windows/IA_XML_Atlas.h;C:/diplomarbeit/impsengine/include/windows/IA_XML_Strings.h;C:/diplomarbeit/impsengine/include/windows/IAInputOutputWinMappings.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/key-value-countainer/IAKeyValueElement.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/key-value-countainer/IAKeyValueElementAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/key-value-countainer/IAKeyValueElementOperations.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/key-value-countainer/IAKeyValueHashMap.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/localisation/IALocalisation.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAAtlasAssets.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAAtlasAssetsAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAStorage+Native.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAStorage.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAString+Assets+Native.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IAString+Assets.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IA_XML_Atlas.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/shared/main/IA_XML_Strings.h"
    "C:/diplomarbeit/impsengine/modules/common/input-output/c/windows/IAInputOutputWinMappings.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAOpenGL.h;C:/diplomarbeit/impsengine/include/windows/IACurrentFramebuffer.h;C:/diplomarbeit/impsengine/include/windows/IADefaultFramebuffer+Internal.h;C:/diplomarbeit/impsengine/include/windows/IADefaultFramebuffer.h;C:/diplomarbeit/impsengine/include/windows/IAOffscreenFramebuffer.h;C:/diplomarbeit/impsengine/include/windows/IABackgroundColor.h;C:/diplomarbeit/impsengine/include/windows/IAColorRect.h;C:/diplomarbeit/impsengine/include/windows/IADrawable.h;C:/diplomarbeit/impsengine/include/windows/IADrawableRect.h;C:/diplomarbeit/impsengine/include/windows/IAGraphicRect.h;C:/diplomarbeit/impsengine/include/windows/IAImage.h;C:/diplomarbeit/impsengine/include/windows/IAImageAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAImageContext.h;C:/diplomarbeit/impsengine/include/windows/IATrimmedRect.h;C:/diplomarbeit/impsengine/include/windows/IAAcceleration.h;C:/diplomarbeit/impsengine/include/windows/IAAccelerationAnimation.h;C:/diplomarbeit/impsengine/include/windows/IAAccelerationAnimationAttributes.h;C:/diplomarbeit/impsengine/include/windows/IACompositedAnimation.h;C:/diplomarbeit/impsengine/include/windows/IACompositedAnimationDelegate.h;C:/diplomarbeit/impsengine/include/windows/IACompositedAnimationDelegateAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAFrameAnimation.h;C:/diplomarbeit/impsengine/include/windows/IAFrameAnimationAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAFrameAnimationCalculation.h;C:/diplomarbeit/impsengine/include/windows/IAFrameAnimationGroup.h;C:/diplomarbeit/impsengine/include/windows/IAFrameAnimationGroupAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAPauseAnimation.h;C:/diplomarbeit/impsengine/include/windows/IAArrayBuffer.h;C:/diplomarbeit/impsengine/include/windows/IABuffer.h;C:/diplomarbeit/impsengine/include/windows/IAElementArrayBuffer.h;C:/diplomarbeit/impsengine/include/windows/IAColorableFontAtlas.h;C:/diplomarbeit/impsengine/include/windows/IAFontAtlas+IterateOverGlyphList.h;C:/diplomarbeit/impsengine/include/windows/IAFontAtlas.h;C:/diplomarbeit/impsengine/include/windows/IAFontInformation.h;C:/diplomarbeit/impsengine/include/windows/IAFontInformationAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAGlyph.h;C:/diplomarbeit/impsengine/include/windows/IAGlyphInformation.h;C:/diplomarbeit/impsengine/include/windows/IAKerningAmount.h;C:/diplomarbeit/impsengine/include/windows/IATextAlignment.h;C:/diplomarbeit/impsengine/include/windows/IAUTF8Helper.h;C:/diplomarbeit/impsengine/include/windows/IABitmap+Native.h;C:/diplomarbeit/impsengine/include/windows/IABitmap.h;C:/diplomarbeit/impsengine/include/windows/IABitmapManager.h;C:/diplomarbeit/impsengine/include/windows/IABitmapManagerSingleton.h;C:/diplomarbeit/impsengine/include/windows/IATexture.h;C:/diplomarbeit/impsengine/include/windows/IATextureDelegate.h;C:/diplomarbeit/impsengine/include/windows/IATextureDelegateAttributes.h;C:/diplomarbeit/impsengine/include/windows/IATextureSelection.h;C:/diplomarbeit/impsengine/include/windows/IATextureSelectionData.h;C:/diplomarbeit/impsengine/include/windows/IAColor.h;C:/diplomarbeit/impsengine/include/windows/IAPoint.h;C:/diplomarbeit/impsengine/include/windows/IAPos.h;C:/diplomarbeit/impsengine/include/windows/IARect.h;C:/diplomarbeit/impsengine/include/windows/IASize.h;C:/diplomarbeit/impsengine/include/windows/IAIntent.h;C:/diplomarbeit/impsengine/include/windows/IAView.h;C:/diplomarbeit/impsengine/include/windows/IAViewAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAViewHolder.h;C:/diplomarbeit/impsengine/include/windows/IACurrentFrame+Private.h;C:/diplomarbeit/impsengine/include/windows/IACurrentFrame.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLConstants.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLResourceDelegate.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLResourceDelegateAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLResourceManager.h;C:/diplomarbeit/impsengine/include/windows/IAMatrix44.h;C:/diplomarbeit/impsengine/include/windows/IAColorRectProgram.h;C:/diplomarbeit/impsengine/include/windows/IAColorRectProgramSingleton.h;C:/diplomarbeit/impsengine/include/windows/IAImageProgram.h;C:/diplomarbeit/impsengine/include/windows/IAImageProgramSingleton.h;C:/diplomarbeit/impsengine/include/windows/IAProgram.h;C:/diplomarbeit/impsengine/include/windows/IAShader.h;C:/diplomarbeit/impsengine/include/windows/IADrawingBounds.h;C:/diplomarbeit/impsengine/include/windows/IAMeassure.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLAssert.h;C:/diplomarbeit/impsengine/include/windows/IAStopwatch.h;C:/diplomarbeit/impsengine/include/windows/IAViewPort+Internal.h;C:/diplomarbeit/impsengine/include/windows/IAViewPort.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLHeaders.h;C:/diplomarbeit/impsengine/include/windows/IAOpenGLWinMappings.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/IAOpenGL.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/framebuffers/IACurrentFramebuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/framebuffers/IADefaultFramebuffer+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/framebuffers/IADefaultFramebuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/framebuffers/IAOffscreenFramebuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IABackgroundColor.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IAColorRect.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IADrawable.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IADrawableRect.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IAGraphicRect.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IAImage.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IAImageAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IAImageContext.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/IATrimmedRect.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAAcceleration.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAAccelerationAnimation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAAccelerationAnimationAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IACompositedAnimation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IACompositedAnimationDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IACompositedAnimationDelegateAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAFrameAnimation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAFrameAnimationAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAFrameAnimationCalculation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAFrameAnimationGroup.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAFrameAnimationGroupAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/animation/IAPauseAnimation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/buffer/IAArrayBuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/buffer/IABuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/buffer/IAElementArrayBuffer.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAColorableFontAtlas.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAFontAtlas+IterateOverGlyphList.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAFontAtlas.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAFontInformation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAFontInformationAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAGlyph.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAGlyphInformation.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAKerningAmount.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IATextAlignment.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/text/IAUTF8Helper.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IABitmap+Native.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IABitmap.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IABitmapManager.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IABitmapManagerSingleton.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IATexture.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IATextureDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IATextureDelegateAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IATextureSelection.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/graphics/texture/IATextureSelectionData.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/helperstructs/IAColor.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/helperstructs/IAPoint.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/helperstructs/IAPos.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/helperstructs/IARect.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/helperstructs/IASize.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/layout/IAIntent.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/layout/IAView.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/layout/IAViewAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/layout/IAViewHolder.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IACurrentFrame+Private.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IACurrentFrame.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IAOpenGLConstants.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IAOpenGLResourceDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IAOpenGLResourceDelegateAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/main/IAOpenGLResourceManager.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/matrix/IAMatrix44.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAColorRectProgram/IAColorRectProgram.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAColorRectProgram/IAColorRectProgramSingleton.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAImageProgram/IAImageProgram.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAImageProgram/IAImageProgramSingleton.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAProgram.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/shaders/IAShader.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IADrawingBounds.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IAMeassure.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IAOpenGLAssert.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IAStopwatch.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IAViewPort+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/shared/supporting-classes/IAViewPort.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/windows/IAOpenGLHeaders.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl/c/windows/IAOpenGLWinMappings.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAButton.h;C:/diplomarbeit/impsengine/include/windows/IAButtonAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAMultiTouch.h;C:/diplomarbeit/impsengine/include/windows/IAOverscrollingBehavior.h;C:/diplomarbeit/impsengine/include/windows/IAOverscrollingHandler.h;C:/diplomarbeit/impsengine/include/windows/IAScrollView.h;C:/diplomarbeit/impsengine/include/windows/IAScrollViewAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAScrollingData.h;C:/diplomarbeit/impsengine/include/windows/IATouch+Internal.h;C:/diplomarbeit/impsengine/include/windows/IATouch.h;C:/diplomarbeit/impsengine/include/windows/IATouchDelegate.h;C:/diplomarbeit/impsengine/include/windows/IATouchDelegateAttributes.h;C:/diplomarbeit/impsengine/include/windows/IATouchHandler.h;C:/diplomarbeit/impsengine/include/windows/IATouchManager.h;C:/diplomarbeit/impsengine/include/windows/IAWinTouchHandler.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAButton.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAButtonAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAMultiTouch.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAOverscrollingBehavior.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAOverscrollingHandler.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAScrollView.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAScrollViewAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IAScrollingData.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouch+Internal.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouch.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouchDelegate.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouchDelegateAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouchHandler.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/shared/IATouchManager.h"
    "C:/diplomarbeit/impsengine/modules/common/multi-touch/c/windows/IAWinTouchHandler.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IAAppEntryPoint+Core.h;C:/diplomarbeit/impsengine/include/windows/IAAppEntryPoint.h;C:/diplomarbeit/impsengine/include/windows/IAApp.h;C:/diplomarbeit/impsengine/include/windows/IAAppAttributes.h;C:/diplomarbeit/impsengine/include/windows/IAAppHandler+Native.h;C:/diplomarbeit/impsengine/include/windows/IAAppHandler.h;C:/diplomarbeit/impsengine/include/windows/IAColorFormat.h;C:/diplomarbeit/impsengine/include/windows/IADepthFormat.h;C:/diplomarbeit/impsengine/include/windows/IAInterfaceOrientationMask.h;C:/diplomarbeit/impsengine/include/windows/IAMultisample.h;C:/diplomarbeit/impsengine/include/windows/IAStencilFormat.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/IAAppEntryPoint+Core.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/IAAppEntryPoint.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/IAApp.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/IAAppAttributes.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/IAAppHandler+Native.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/IAAppHandler.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/opengl-surface-options/IAColorFormat.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/opengl-surface-options/IADepthFormat.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/opengl-surface-options/IAInterfaceOrientationMask.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/opengl-surface-options/IAMultisample.h"
    "C:/diplomarbeit/impsengine/modules/common/opengl-renderer/c/shared/main/opengl-surface-options/IAStencilFormat.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IARandomNumberGenerator.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES "C:/diplomarbeit/impsengine/modules/advanced-math/random-number-generator/c/shared/IARandomNumberGenerator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/diplomarbeit/impsengine/include/windows/IADate+Native.h;C:/diplomarbeit/impsengine/include/windows/IADate.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "C:/diplomarbeit/impsengine/include/windows" TYPE FILE FILES
    "C:/diplomarbeit/impsengine/modules/utilities/date/c/shared/IADate+Native.h"
    "C:/diplomarbeit/impsengine/modules/utilities/date/c/shared/IADate.h"
    )
endif()

