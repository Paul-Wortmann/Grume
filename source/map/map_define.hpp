


#ifndef MAP_DEFINE_HPP
#define MAP_DEFINE_HPP

#include "../includes.hpp"
#include "biome_define.hpp"
#include "../entity/entity_define.hpp"

#define FLOOR_SPRITESHEET_WIDTH  4
#define FLOOR_SPRITESHEET_HEIGHT 4
    
enum class eSpriteType : std::uint32_t 
    { 
        tileNone      = 0, // None
        tileFloor     = 1, // Floor tile
        tilePath      = 2, // Path  tile
        tilePathLine  = 3, // Path  tile -> Line
        tilePathOuter = 4, // Path  tile -> Corner, Outer
        tilePathInner = 5, // Path  tile -> Corner, Inner
    };

struct sMapSpriteTile
{
    eSpriteType   type       = eSpriteType::tileFloor;
    std::uint32_t processed  = 0; // Default == 0
    std::uint32_t spriteNumX = 0; // Default == 0
    std::uint32_t spriteNumY = 0; // Default == 0
    std::uint32_t rotation   = 0; // Default == 0 (0 -> 0 degrees, 1 -> 90 degrees, 2 -> 180 degrees, 3 -> 270 degrees)
};

enum class eTileBase : std::uint32_t 
    { 
        tileNone      = 0,
        tileFloor     = 1,
        tileWall      = 2,
        tileDoorway   = 3,
        tileWallShort = 4,
        tileFloorPath = 5,
        tileFloorNoGo = 6,
        tileLiquid    = 7
    };

struct sMapGenData
{
    std::uint32_t seed      = 0; // 0 for random seed
    std::uint32_t algorithm = 0; // 0: C1,
    std::uint32_t wallSize  = 0; // 0: Wide, 1: Thin
};

struct sMapTile
{
    std::uint32_t processed = 0; // Default == 0
    eTileBase     base      = eTileBase::tileFloor; // Default == 0
    std::uint32_t object    = 0; // Default == 0
    //std::uint32_t event = 0;
};

struct sMap
{
    // Linked list
    sMap*          next            = nullptr;

    // Infomation
    std::string    name            = "";
    std::string    fileName        = "";

    // Player start information
    std::uint32_t  playerStartTile = 10;
    float          playerStartDir  = 0.0f;

    // Entity to hold the floor
    sEntity*       floor           = nullptr;

    // Tile
    std::uint32_t  width           = 0;
    std::uint32_t  height          = 0;
    std::uint32_t  numTiles        = 0;
    sMapTile*      tile            = nullptr;

    // PCG
    sMapGenData    genData         = {};

    // Biome
    sMapBiome*     biome           = nullptr;
};

#endif //MAP_DEFINE_HPP

