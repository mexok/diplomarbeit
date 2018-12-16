cmake_minimum_required(VERSION 3.12.1)

project(Flower)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -UNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -UNDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -UDEBUG -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -UDEBUG -DNDEBUG")

set(EXECUTABLE_OUTPUT_PATH ../bin)

add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
		IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/lib/Release/x64/glew32s.lib
		INTERFACE_COMPILE_DEFINITIONS GLEW_STATIC
		INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/include)

add_library(opencv INTERFACE)
target_include_directories(opencv INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/include)

target_link_libraries(opencv
		INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/x64/mingw/bin/libopencv_core343.dll
		INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/x64/mingw/bin/libopencv_highgui343.dll
		INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/x64/mingw/bin/libopencv_imgcodecs343.dll
		INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/x64/mingw/bin/libopencv_imgproc343.dll)

file(COPY
		deps/opencv-3.4.3/x64/mingw/bin/libopencv_core343.dll
		deps/opencv-3.4.3/x64/mingw/bin/libopencv_highgui343.dll
		deps/opencv-3.4.3/x64/mingw/bin/libopencv_imgcodecs343.dll
		deps/opencv-3.4.3/x64/mingw/bin/libopencv_imgproc343.dll
		DESTINATION ${EXECUTABLE_OUTPUT_PATH})

add_subdirectory(impsengine)

add_library(opencv_glue STATIC
		deps/opencv-glue/OpenGLWinMappings.h
		deps/opencv-glue/OpenGLWinMappings.cpp)
target_link_libraries(opencv_glue opencv)
target_link_libraries(opencv_glue iaopengl iaclib)
target_link_libraries(opencv_glue glew)
target_link_libraries(opencv_glue opengl32.lib glu32.lib)
target_include_directories(opencv_glue PUBLIC deps/opencv-glue)

list(APPEND sources
		c/windows/CSrc.h
		c/windows/CSrc.c
		c/windows/main.c
		c/windows/Resources.h
		c/windows/Resources.c
		c/windows/AppManager.h
		c/windows/AppManager.c

		c/shared/model/HomeState.h
		c/shared/model/HomeState.c

		c/shared/presenter/Presenter.h
		c/shared/presenter/Presenter.c

		c/shared/view/MainView.h
		c/shared/view/MainView.c

		c/shared/view/Colors.h
		c/shared/view/Constants.h

		c/shared/view/custom-elements/small-tile/SmallTile.h
		c/shared/view/custom-elements/small-tile/SmallTile.c
		c/shared/view/custom-elements/small-tile/SmallTileAttributes.h
		c/shared/view/custom-elements/small-tile/SmallTileAttributes.c

		c/shared/view/custom-elements/tab-bar-button/TabBarButton.h
		c/shared/view/custom-elements/tab-bar-button/TabBarButton.c
		c/shared/view/custom-elements/tab-bar-button/TabBarButtonAttributes.h
		c/shared/view/custom-elements/tab-bar-button/TabBarButtonAttributes.c
		c/shared/view/custom-elements/tab-bar-button/TabBarButtonDelegate.h

		c/shared/view/elements/label/IALabel.h
		c/shared/view/elements/label/IALabel.c
		c/shared/view/elements/label/IALabelAttributes.h
		c/shared/view/elements/label/IALabelAttributes.c

		c/shared/view/elements/slider/IASlider.h
		c/shared/view/elements/slider/IASlider.c
		c/shared/view/elements/slider/IASliderAttributes.h
		c/shared/view/elements/slider/IASliderAttributes.c

		c/shared/view/layouts/IALayout.h
		c/shared/view/layouts/IALayout.c
		c/shared/view/layouts/IALayoutAttributes.h
		c/shared/view/layouts/IALayoutAttributes.c
		c/shared/view/layouts/scroll-layout/IAScrollLayout.h
		c/shared/view/layouts/scroll-layout/IAScrollLayout.c
		c/shared/view/layouts/scroll-layout/IAScrollLayoutAttributes.h
		c/shared/view/layouts/scroll-layout/IAScrollLayoutAttributes.c
		c/shared/view/layouts/scroll-layout/IAScrollLayoutDelegate.h
		c/shared/view/layouts/card-layout/IACardLayout.h
		c/shared/view/layouts/card-layout/IACardLayout.c
		c/shared/view/layouts/card-layout/IACardLayoutAttributes.h
		c/shared/view/layouts/card-layout/IACardLayoutAttributes.c
		c/shared/view/layouts/card-layout/IACardLayoutElement.h
		c/shared/view/layouts/card-layout/IACardLayoutElement.c
		c/shared/view/layouts/card-layout/IACardLayoutElementAttributes.h
		c/shared/view/layouts/card-layout/IACardLayoutElementAttributes.c
		c/shared/view/layouts/flow-layout/IAFlowLayout.h
		c/shared/view/layouts/flow-layout/IAFlowLayout.c
		c/shared/view/layouts/flow-layout/IAFlowLayoutAttributes.h
		c/shared/view/layouts/flow-layout/IAFlowLayoutAttributes.c
		c/shared/view/layouts/flow-layout/IAFlowLayoutElement.h
		c/shared/view/layouts/flow-layout/IAFlowLayoutElement.c
		c/shared/view/layouts/flow-layout/IAFlowLayoutElementAttributes.h
		c/shared/view/layouts/flow-layout/IAFlowLayoutElementAttributes.c
		c/shared/view/layouts/grid-layout/IAGridLayout.h
		c/shared/view/layouts/grid-layout/IAGridLayout.c
		c/shared/view/layouts/grid-layout/IAGridLayoutAttributes.h
		c/shared/view/layouts/grid-layout/IAGridLayoutAttributes.c
		c/shared/view/layouts/grid-layout/IAGridLayoutElement.h
		c/shared/view/layouts/grid-layout/IAGridLayoutElement.c
		c/shared/view/layouts/grid-layout/IAGridLayoutElementAttributes.h
		c/shared/view/layouts/grid-layout/IAGridLayoutElementAttributes.c)


add_executable(Flower ${sources})
target_include_directories(Flower PUBLIC
		c/windows
		c/shared/model
		c/shared/presenter
		c/shared/view
		c/shared/view/layouts
		c/shared/view/custom-elements
		c/shared/view/custom-elements/small-tile
		c/shared/view/custom-elements/tab-bar-button
		c/shared/view/elements/label
		c/shared/view/elements/slider
		c/shared/view/layouts/card-layout
		c/shared/view/layouts/flow-layout
		c/shared/view/layouts/grid-layout
		c/shared/view/layouts/scroll-layout
		generated
		deps/opencv-glue)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/c FILES ${sources})
target_link_libraries(Flower iaopengl iaclib iamulti_touch)
target_link_libraries(Flower glew)
target_link_libraries(Flower opencv opencv_glue)
target_link_libraries(Flower opengl32.lib glu32.lib)
target_generate_generics(Flower generated)
target_add_yaml_sources(Flower generated
		c/shared/view/yaml/ContentFavorites.yaml
		c/shared/view/yaml/OverlayLayout.yaml
		c/shared/view/yaml/SmallTileLayout.yaml)
