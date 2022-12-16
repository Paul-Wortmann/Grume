cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project ("Grume")

cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion -static-libstdc++ -static-libgcc -fomit-frame-pointer -fexpensive-optimizations -flto -O3 -ffast-math ${CMAKE_CXX_FLAGS}")

include(FindPkgConfig)
include(GNUInstallDirs)
include(CheckIncludeFiles)
include(CheckLibraryExists)

find_package(OpenGL REQUIRED)
PKG_SEARCH_MODULE(GLFW3 REQUIRED glfw3)
PKG_SEARCH_MODULE(ASSIMP REQUIRED assimp)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  target_compile_options(my_app PUBLIC "-pthread")
endif()

message(${CMAKE_THREAD_LIBS_INIT})#pthread library
message(${CMAKE_DL_LIBS})#dl libs

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(/usr/include)

include_directories(common)

include_directories(source/debug)

file(GLOB_RECURSE GRUME_SOURCE "source/*.cpp")

add_executable(grume ${GRUME_SOURCE} )

target_Link_Libraries (grume ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS} ${ASSIMP_LIBRARIES} ${GLFW3_LIBRARIES} ${OPENGL_LIBRARIES})


