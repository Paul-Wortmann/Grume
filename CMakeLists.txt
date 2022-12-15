cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project ("Grume")

cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion ${CMAKE_CXX_FLAGS}")


include(FindPkgConfig)
include(GNUInstallDirs)
include(CheckIncludeFiles)
include(CheckLibraryExists)

find_package(OpenGL REQUIRED)
PKG_SEARCH_MODULE(GLFW3 REQUIRED glfw3)
find_package(PhysFS REQUIRED)
PKG_SEARCH_MODULE(ASSIMP REQUIRED assimp)

include_directories(/usr/include)

include_directories(common)

include_directories(source/debug)

file(GLOB_RECURSE FNF_S "source/*.cpp")

add_executable(grume ${FNF_S} )

target_Link_Libraries (grume ${ASSIMP_LIBRARIES} ${GLFW3_LIBRARIES} ${OPENGL_LIBRARIES})


