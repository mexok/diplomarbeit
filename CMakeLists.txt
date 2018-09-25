cmake_minimum_required(VERSION 3.12.1)

project(YamlGui)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -UNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -UNDEBUG")

add_library(glew STATIC IMPORTED)
set_target_properties(glew PROPERTIES
		IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/lib/Release/x64/glew32s.lib
		INTERFACE_COMPILE_DEFINITIONS GLEW_STATIC
		INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/include)

add_subdirectory(impsengine)

set(FREEGLUT_BUILD_STATIC_LIBS ON)
add_subdirectory(deps/freeglut-3.0.0)
target_compile_definitions(freeglut_static PUBLIC FREEGLUT_STATIC)
target_include_directories(freeglut_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/deps/freeglut-3.0.0/include)

list(APPEND sources
		c/windows/CSrc.h
		c/windows/CSrc.c
		c/windows/main.c
		c/windows/ViewManager.h
		c/windows/ViewManager.c
		c/windows/Resources.h
		c/windows/Resources.c
		c/windows/views/flow-layout-sample/FlowLayoutView.h
		c/windows/views/flow-layout-sample/FlowLayoutView.c
		c/windows/views/flow-layout-sample/SampleView.h
		c/windows/views/flow-layout-sample/SampleView.c
		c/windows/views/layouts/IAFlowLayout.h
		c/windows/views/layouts/IAFlowLayout.c
		c/windows/views/layouts/IAFlowLayoutAttributes.h
		c/windows/views/layouts/IAFlowLayoutAttributes.c
		c/windows/views/layouts/IAFlowLayoutElement.h
		c/windows/views/layouts/IAFlowLayoutElement.c)

add_executable(YamlGuiPrototyp ${sources})
target_include_directories(YamlGuiPrototyp PUBLIC c/windows c/windows/views/flow-layout-sample c/windows/views/layouts generated)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/c FILES ${sources})
target_link_libraries(YamlGuiPrototyp iaopengl iaclib iamulti_touch)
target_link_libraries(YamlGuiPrototyp glew)
target_link_libraries(YamlGuiPrototyp opengl32.lib glu32.lib)
target_generate_generics(YamlGuiPrototyp generated)
target_add_yaml_sources(YamlGuiPrototyp generated
		c/windows/views/flow-layout-sample/SampleLayout.yaml
		c/windows/views/flow-layout-sample/SampleLayout2.yaml)
