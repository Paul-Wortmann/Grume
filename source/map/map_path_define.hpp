
#ifndef MAP_PATH_DEFINE_HPP
#define MAP_PATH_DEFINE_HPP

#include "../includes.hpp"

// ----- used externally -----
struct sMapPath
{
    std::uint32_t  startTile       = 0;
    std::uint32_t  destinationTile = 0;
    std::uint32_t  currentTile     = 0;
    std::uint32_t  currentPosition = 0;

    std::uint32_t  pathLength      = 0;
    std::uint32_t* path            = nullptr;
};

// ----- used internally -----
enum ePathData:uint16_t { pathNone = 0, pathStart = 1, pathEnd = 2, pathOpen = 3, pathClosed = 4 };

// Astar path weights
#define AS_MOV_D  20 // Directional
#define AS_MOV_S  10 // 
#define AS_MOV_H  10 // 

struct sASTileData
{
    bool          c = false;               // completed flag
    std::uint32_t x = 0;                   // tile x position
    std::uint32_t y = 0;                   // tile y position
    std::uint32_t h = 0;                   // heuristic cost
    std::uint32_t g = 0;                   // movement cost
    std::uint32_t f = 0;                   // total cost
    std::uint32_t p = 0;                   // parent tile
    ePathData     a = ePathData::pathNone; // attribute
    ePathData     l = ePathData::pathNone; // list
};

#endif //MAP_PATH_DEFINE_HPP

