cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project ("Grume")

cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_FLAGS "-std=c++0x -Wall -Wextra -Wunused -Wshadow -Woverloaded-virtual -Wunreachable-code -Wconversion ${CMAKE_CXX_FLAGS}")


include(FindPkgConfig)
include(GNUInstallDirs)
include(CheckIncludeFiles)
include(CheckLibraryExists)

find_library(OGG_LIBRARY NAMES ogg)
find_library(VORBIS_LIBRARY NAMES vorbis)
find_library(VORBISFILE_LIBRARY NAMES vorbisfile)
find_library(VORBISENC_LIBRARY NAMES vorbisenc)
set(OGGVORBIS_LIBRARIES ${OGG_LIBRARY} ${VORBIS_LIBRARY} ${VORBISFILE_LIBRARY} ${VORBISENC_LIBRARY})

find_package(OpenAL REQUIRED)

find_package(OpenGL REQUIRED)
PKG_SEARCH_MODULE(GLFW3 REQUIRED glfw3)
find_package(PhysFS REQUIRED)
PKG_SEARCH_MODULE(ASSIMP REQUIRED assimp)

include_directories(/usr/include)

include_directories(common)

include_directories(source/debug)

file(GLOB_RECURSE FNF_S "source/*.cpp")

add_executable(grume ${FNF_S} )

link_directories( /path/to/PHYSFSlibs/)

target_Link_Libraries (grume ${OGGVORBIS_LIBRARIES} ${OPENAL_LIBRARY} ${ASSIMP_LIBRARIES} ${PHYSFS_LIBRARY} ${GLFW3_LIBRARIES} ${OPENGL_LIBRARIES})


