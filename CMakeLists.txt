cmake_minimum_required(VERSION 3.12.1)

project(YamlGui)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -UNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -UNDEBUG")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -UDEBUG -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -UDEBUG -DNDEBUG")

add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
		IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/lib/Release/x64/glew32s.lib
		INTERFACE_COMPILE_DEFINITIONS GLEW_STATIC
		INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/include)

add_library(opencv_core STATIC IMPORTED)
set_target_properties(opencv_core PROPERTIES
		IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/x64/mingw/lib/libopencv_core343.dll.a)
target_include_directories(opencv_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv-3.4.3/include)

add_subdirectory(impsengine)

set(FREEGLUT_BUILD_STATIC_LIBS ON)
add_subdirectory(deps/freeglut-3.0.0)
target_compile_definitions(freeglut_static PUBLIC FREEGLUT_STATIC)
target_include_directories(freeglut_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/deps/freeglut-3.0.0/include)

list(APPEND sources
		c/windows/CSrc.h
		c/windows/CSrc.c
		c/windows/main.c
		c/windows/OpenGLWinMappings.h
		c/windows/OpenGLWinMappings.c
		c/windows/Resources.h
		c/windows/Resources.c
		c/windows/ViewManager.h
		c/windows/ViewManager.c
		c/shared/views/flow-layout-sample/FlowLayoutView.h
		c/shared/views/flow-layout-sample/FlowLayoutView.c
		c/shared/views/flow-layout-sample/SampleView.h
		c/shared/views/flow-layout-sample/SampleView.c
		c/shared/views/layouts/flow-layout/IAFlowLayout.h
		c/shared/views/layouts/flow-layout/IAFlowLayout.c
		c/shared/views/layouts/flow-layout/IAFlowLayoutAttributes.h
		c/shared/views/layouts/flow-layout/IAFlowLayoutAttributes.c
		c/shared/views/layouts/flow-layout/IAFlowLayoutElement.h
		c/shared/views/layouts/flow-layout/IAFlowLayoutElement.c
		c/shared/views/layouts/grid-layout/IAGridLayout.h
		c/shared/views/layouts/grid-layout/IAGridLayout.c
		c/shared/views/layouts/grid-layout/IAGridLayoutAttributes.h
		c/shared/views/layouts/grid-layout/IAGridLayoutAttributes.c
		c/shared/views/layouts/grid-layout/IAGridLayoutElement.h
		c/shared/views/layouts/grid-layout/IAGridLayoutElement.c
		c/shared/views/layouts/grid-layout/IAGridLayoutElementAttributes.h
		c/shared/views/layouts/grid-layout/IAGridLayoutElementAttributes.c)

add_executable(YamlGuiPrototyp ${sources})
target_include_directories(YamlGuiPrototyp PUBLIC
		c/windows
		c/shared/views/flow-layout-sample
		c/shared/views/layouts
		c/shared/views/layouts/flow-layout
		c/shared/views/layouts/grid-layout
		generated)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/c FILES ${sources})
target_link_libraries(YamlGuiPrototyp iaopengl iaclib iamulti_touch)
target_link_libraries(YamlGuiPrototyp glew)
target_link_libraries(YamlGuiPrototyp opencv_core)
target_link_libraries(YamlGuiPrototyp opengl32.lib glu32.lib)
target_generate_generics(YamlGuiPrototyp generated)
target_add_yaml_sources(YamlGuiPrototyp generated
		c/shared/views/flow-layout-sample/SampleLayout.yaml
		c/shared/views/flow-layout-sample/SampleLayout2.yaml)
