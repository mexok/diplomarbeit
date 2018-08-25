cmake_minimum_required(VERSION 3.12.1)
include_guard()


project(YamlGui)

# Fix for pthreads (optional)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")

set(CMAKE_HAVE_THREADS_LIBRARY 1)

set(CMAKE_USE_WIN32_THREADS_INIT 0)

set(CMAKE_USE_PTHREADS_INIT 1)


set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG -UNDEBUG")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -UNDEBUG")

add_subdirectory(impsengine)

list(APPEND sources
	c/windows/CSrc.h
	c/windows/CSrc.c
	c/windows/dllmain.c
	c/windows/ViewManager.h
	c/windows/ViewManager.c
	c/windows/views/flow-layout-sample/FlowLayoutView.h
	c/windows/views/flow-layout-sample/FlowLayoutView.c
)

add_library(CSrc SHARED ${sources})

target_include_directories(CSrc PUBLIC c/windows c/windows/views/flow-layout-sample generated)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/c FILES ${sources})

target_link_libraries(CSrc iaopengl iaclib iamulti_touch GLEW_CUSTOM)

target_link_libraries(CSrc opengl32.lib glu32.lib)

target_generate_generics(CSrc generated)
