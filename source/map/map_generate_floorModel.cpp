/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#include "map_manager.hpp"


/// static bool _isFloor(sMap*& _map, std::uint32_t _tile)
static bool _isFloor(sMap*& _map, std::uint32_t _tile)
{
    bool returnValue = false;

    if ((_map->tile[_tile].base == eTileBase::tileFloor)
     || (_map->tile[_tile].base == eTileBase::tileDoorway)
     || (_map->tile[_tile].base == eTileBase::tileFloorNoGo))
    {
        returnValue = true;
    }

    return returnValue;
}

/// static bool _isPath(sMap*& _map, std::uint32_t _tile)
static bool _isPath(sMap*& _map, std::uint32_t _tile)
{
    bool returnValue = false;

    if ((_map->tile[_tile].base == eTileBase::tileFloorPath)
     || (_map->tile[_tile].base == eTileBase::tilePathNoGo))
    {
        returnValue = true;
    }

    return returnValue;
}

sEntityModel* cMapManager::m_generateFloor(sMap*& _map)
{
    // If the floor has not yet been generated for a previous map
    if (_map->floor->model == nullptr)
    {
        _map->floor->model = m_entityManager->getNewModel();
    }
    else // Cleanup previous floor data
    {
        if (_map->floor->model->mesh != nullptr)
        {
            for (std::uint32_t i = 0; i < _map->floor->model->numMesh; ++i)
            {
                // Cleanup vertex data
                if (_map->floor->model->mesh[i].vertex != nullptr)
                {
                    delete [] _map->floor->model->mesh[i].vertex;
                    _map->floor->model->mesh[i].vertex = nullptr;
                }
                
                // Cleanup index data
                if (_map->floor->model->mesh[i].index != nullptr)
                {
                    delete [] _map->floor->model->mesh[i].index;
                    _map->floor->model->mesh[i].index = nullptr;
                }
                
            }

            // Cleanup mesh data
            delete [] _map->floor->model->mesh;
            _map->floor->model->mesh = nullptr;
        }
    }

    // Fail if model is nullptr
    if (_map->floor->model == nullptr)
    {
        gLogWrite(LOG_ERROR, "Model generation failed:  " + _map->name, __FILE__, __LINE__, __FUNCTION__);
        //gLogWrite(LOG_ERROR, "Model generation failed:  " + _info.name, __FILE__, __LINE__, __FUNCTION__);
        return nullptr;
    }

    //gLogWrite(LOG_INFO, "Generating model:  " + _map->name, __FILE__, __LINE__, __FUNCTION__);

    // Generate spritesheet sprite location and rotation information
    // 1. Determine base tile type.
    sMapSpriteTile *spriteData = new sMapSpriteTile[_map->numTiles];
    for(std::size_t i = 0; i < _map->numTiles; ++i)
    {
        switch (_map->tile[i].base)
        {
            case eTileBase::tileFloorPath:
            case eTileBase::tilePathNoGo:
                spriteData[i].type       = eSpriteType::tilePath;
                spriteData[i].spriteNumX = 0;
                spriteData[i].spriteNumY = 0;
            break;
            case eTileBase::tileFloorNoGo:
                spriteData[i].type = eSpriteType::tileFloor;
                spriteData[i].spriteNumX = 1;
                spriteData[i].spriteNumY = 1;
            break;
            case eTileBase::tileFloor:
            case eTileBase::tileWallShort:
            case eTileBase::tileDoorway:
            case eTileBase::tileWall:
            case eTileBase::tileNone:
            case eTileBase::tileLiquid:
                spriteData[i].type = eSpriteType::tileFloor;
                spriteData[i].spriteNumX = 0;
                spriteData[i].spriteNumY = 1;
            break;
            default:
                spriteData[i].type = eSpriteType::tileNone;
            break;
        }
    }
    
    // 2. Determine tile type and rotation based on adjacent tiles.
    for (uint32 z = 1; z < _map->height - 1; ++z) // z, excluding border tiles
    {
        for (uint32 x = 1; x < _map->width - 1; ++x)  // x, excluding border tiles
        {
            uint32 tileNum = (z * _map->width) + x;

            // ---- Path next to floor, straight line ----
            // Case 1: path tile, and 1 floor tile to the left, rotate 90
            if ((_isPath(_map, tileNum)) &&
                (_isFloor(_map, tileNum - 1)) &&
                (_isPath(_map, tileNum - _map->width)) &&
                (_isPath(_map, tileNum + _map->width)))
            {
                // rotate 90
                spriteData[tileNum].rotation   = 1;
                spriteData[tileNum].spriteNumX = 2;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 2: path tile, and 1 floor tile to the right, rotate 270
            else if ((_isPath(_map, tileNum)) &&
                     (_isFloor(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - _map->width)) &&
                     (_isPath(_map, tileNum + _map->width)))
            {
                // rotate 270
                spriteData[tileNum].rotation   = 3;
                spriteData[tileNum].spriteNumX = 2;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 3: path tile, and 1 floor tile to the bottom, rotate 180
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isFloor(_map, tileNum - _map->width)))
            {
                // rotate 180
                spriteData[tileNum].rotation   = 2;
                spriteData[tileNum].spriteNumX = 2;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 4: path tile, and 1 floor tile to the top, rotate 0
             else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isFloor(_map, tileNum + _map->width)))
            {
                // rotate 0
                spriteData[tileNum].rotation   = 0;
                spriteData[tileNum].spriteNumX = 2;
                spriteData[tileNum].spriteNumY = 0;
            }

            // ---- Path next to floor, outer corner ----
            // Case 5: path tile, and 2 floor tiles, rotate 180
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isFloor(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isFloor(_map, tileNum - _map->width)))
            {
                // rotate 180
                spriteData[tileNum].rotation   = 2;
                spriteData[tileNum].spriteNumX = 3;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 6: path tile, and 2 floor tiles, rotate 0
            else if ((_isPath(_map, tileNum)) &&
                     (_isFloor(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isFloor(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)))
            {
                // rotate 0
                spriteData[tileNum].rotation   = 0;
                spriteData[tileNum].spriteNumX = 3;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 7: path tile, and 2 floor tiles, rotate 90
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isFloor(_map, tileNum - 1)) &&
                     (_isFloor(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)))
            {
                // rotate 90
                spriteData[tileNum].rotation   = 1;
                spriteData[tileNum].spriteNumX = 3;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 8: path tile, and 2 floor tiles, rotate 270
            else if ((_isPath(_map, tileNum)) &&
                     (_isFloor(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isFloor(_map, tileNum - _map->width)))
            {
                // rotate 270
                spriteData[tileNum].rotation   = 3;
                spriteData[tileNum].spriteNumX = 3;
                spriteData[tileNum].spriteNumY = 0;
            }

            // ---- Path next to floor, inner corner ----
            // Case 9: path tile, and 1 diagonal floor tile, rotate 0
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)) &&
                     (_isFloor(_map, tileNum + _map->width + 1)) &&
                     (_isPath(_map, tileNum - _map->width + 1)) &&
                     (_isPath(_map, tileNum + _map->width - 1)) &&
                     (_isPath(_map, tileNum - _map->width - 1)))
            {
                // rotate 0
                spriteData[tileNum].rotation   = 0;
                spriteData[tileNum].spriteNumX = 1;
                spriteData[tileNum].spriteNumY = 0;
            }

            // Case 10: path tile, and 1 diagonal floor tile, rotate 180
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)) &&
                     (_isPath(_map, tileNum + _map->width + 1)) &&
                     (_isPath(_map, tileNum - _map->width + 1)) &&
                     (_isPath(_map, tileNum + _map->width - 1)) &&
                     (_isFloor(_map, tileNum - _map->width - 1)))
            {
                // rotate 180
                spriteData[tileNum].rotation   = 2;
                spriteData[tileNum].spriteNumX = 1;
                spriteData[tileNum].spriteNumY = 0;
            }

            // ---- Path next to floor, inner corner ----
            // Case 11: path tile, and 1 diagonal floor tile, rotate 90
            else  if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)) &&
                     (_isPath(_map, tileNum + _map->width + 1)) &&
                     (_isPath(_map, tileNum - _map->width + 1)) &&
                     (_isFloor(_map, tileNum + _map->width - 1)) &&
                     (_isPath(_map, tileNum - _map->width - 1)))
            {
                // rotate 90
                spriteData[tileNum].rotation   = 1;
                spriteData[tileNum].spriteNumX = 1;
                spriteData[tileNum].spriteNumY = 0;
            }

            // ---- Path next to floor, inner corner ----
            // Case 12: path tile, and 1 diagonal floor tile, rotate 270
            else if ((_isPath(_map, tileNum)) &&
                     (_isPath(_map, tileNum + 1)) &&
                     (_isPath(_map, tileNum - 1)) &&
                     (_isPath(_map, tileNum + _map->width)) &&
                     (_isPath(_map, tileNum - _map->width)) &&
                     (_isPath(_map, tileNum + _map->width + 1)) &&
                     (_isFloor(_map, tileNum - _map->width + 1)) &&
                     (_isPath(_map, tileNum + _map->width - 1)) &&
                     (_isPath(_map, tileNum - _map->width - 1)))
            {
                // rotate 270
                spriteData[tileNum].rotation   = 3;
                spriteData[tileNum].spriteNumX = 1;
                spriteData[tileNum].spriteNumY = 0;
            }
        }
    }

    // Vertex position generation
    // number vertices = width x height x 2 triangles x 3 vertices per triangle
    // also add 10 triangles with 3 vertices each to complete the cube
    _map->floor->model->numMesh = 1;
    _map->floor->model->mesh = new sEntityMesh[_map->floor->model->numMesh];
    uint32 meshNum = 0;

    uint32 numMeshTiles = 0;
    for(std::size_t i = 0; i < _map->numTiles; ++i)
    {
        if ((_map->tile[i].base != eTileBase::tileNone))
        {
            numMeshTiles++;
        }
    }

    _map->floor->model->mesh[meshNum].numVertex = (numMeshTiles * 2 * 3);
    _map->floor->model->mesh[meshNum].vertex = new sEntityVertex[_map->floor->model->mesh[meshNum].numVertex];

    // Width and height offset, used to center the mesh
    float32 xo = static_cast<float32>(_map->width  / 2);
    float32 zo = static_cast<float32>(_map->height / 2);

    // Determine uint size of sprites on the spritesheet based on number of sprites
    float32 xStep = 1.0 / (float32)FLOOR_SPRITESHEET_WIDTH;
    float32 yStep = 1.0 / (float32)FLOOR_SPRITESHEET_HEIGHT;

    // The extracted x and y tile positions on the sprite sheet
    uint32 tileX = 0;
    uint32 tileY = 0;

    uint32 vertextNum = 0;
    for (uint32 z = 0; z < _map->height; ++z) // z
    {
        for (uint32 x = 0; x < _map->width; ++x)  // x
        {
            uint32 tileNum = (z * _map->width) + x;
            if ((_map->tile[tileNum].base != eTileBase::tileNone))
            {
                // Determine the tile location on the spritesheet using the map tile data (redundant)
                //tileX = (static_cast<uint32>(_map->tile[(z * _map->width) + x].base) - 1) % FLOOR_SPRITESHEET_WIDTH;
                //tileY = (static_cast<uint32>(_map->tile[(z * _map->width) + x].base) - 1) / FLOOR_SPRITESHEET_HEIGHT;

                // Determine the tile location on the spritesheet based on the map tile data
                tileX = spriteData[tileNum].spriteNumX;
                tileY = (FLOOR_SPRITESHEET_HEIGHT - 1) - spriteData[tileNum].spriteNumY; // Texture is flipped on load

                // Vertex position generation -> first triangle
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].position.x = static_cast<float32>(x + 1) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].position.z = static_cast<float32>(z + 0) - zo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].position.x = static_cast<float32>(x + 0) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].position.z = static_cast<float32>(z + 1) - zo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].position.x = static_cast<float32>(x + 1) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].position.z = static_cast<float32>(z + 1) - zo;

                // Vertex position generation -> second triangle
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].position.x = static_cast<float32>(x + 1) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].position.z = static_cast<float32>(z + 0) - zo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].position.x = static_cast<float32>(x + 0) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].position.z = static_cast<float32>(z + 0) - zo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].position.x = static_cast<float32>(x + 0) - xo;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].position.z = static_cast<float32>(z + 1) - zo;

/*
1.1 _____ 1.0
    |\  | 
    | \ | 
    |  \| 
0.1 ----- 0.0
*/
                if (spriteData[tileNum].rotation == 0) // 270 degree rotation
                {
                    // Texcoords generation -> first triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));

                    // Texcoords generation -> second triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                }
/*
0.1 _____ 1.1
    |\  | 
    | \ | 
    |  \| 
0.0 ----- 1.0
*/
                else if (spriteData[tileNum].rotation == 1) // 90 degree rotation
                {
                    // Texcoords generation -> first triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));

                    // Texcoords generation -> second triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                }
/*
0.0 _____ 0.1
    |\  | 
    | \ | 
    |  \| 
1.0 ----- 1.1
*/
                else if (spriteData[tileNum].rotation == 2) // 180 degree rotation
                {
                    // Texcoords generation -> first triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));

                    // Texcoords generation -> second triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                }
/*
1.0 _____ 0.0
    |\  | 
    | \ | 
    |  \| 
1.1 ----- 0.1
*/
                else if (spriteData[tileNum].rotation == 3) // 270 degree rotation
                {
                    // Texcoords generation -> first triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));

                    // Texcoords generation -> second triangle
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].texcoord.y = (0 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.x = (1 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.x = (0 * xStep) + (xStep * static_cast<float32>(tileX));
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].texcoord.y = (1 * yStep) + (yStep * static_cast<float32>(tileY));
                }


                // Normal generation -> First triangle
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].normal = generateNormal(_map->floor->model->mesh[meshNum].vertex[vertextNum + 0].position,
                                                                                     _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].position,
                                                                                     _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].position);
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 1].normal = _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].normal;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 2].normal = _map->floor->model->mesh[meshNum].vertex[vertextNum + 0].normal;

                // Normal generation -> Second triangle
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].normal = generateNormal(_map->floor->model->mesh[meshNum].vertex[vertextNum + 3].position,
                                                                                     _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].position,
                                                                                     _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].position);
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 4].normal = _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].normal;
                _map->floor->model->mesh[meshNum].vertex[vertextNum + 5].normal = _map->floor->model->mesh[meshNum].vertex[vertextNum + 3].normal;


                // Generate the tangents and bitangents
                for (uint32 k = 0; k < 6; ++k)
                {
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + k].tangent   = generateTangent(_map->floor->model->mesh[meshNum].vertex[vertextNum + k].normal);
                    _map->floor->model->mesh[meshNum].vertex[vertextNum + k].bitangent = generateBitangent(_map->floor->model->mesh[meshNum].vertex[vertextNum + k].normal, _map->floor->model->mesh[meshNum].vertex[vertextNum + k].tangent);
                }

                // Increment the vertext counter
                vertextNum += 6;
            }
        }
    }

    // Index generation
    _map->floor->model->mesh[meshNum].numIndex = _map->floor->model->mesh[meshNum].numVertex;
    _map->floor->model->mesh[meshNum].index = new uint32[_map->floor->model->mesh[meshNum].numIndex];
    for (uint32 i = 0; i < _map->floor->model->mesh[meshNum].numIndex; ++i)
    {
        _map->floor->model->mesh[meshNum].vertex[i].position.y -= 1.0f;
        _map->floor->model->mesh[meshNum].index[i] = i;
    }
    
    // Cleanup
    if (spriteData != nullptr)
    {
        delete [] spriteData;
        spriteData = nullptr;
    }
    
    return _map->floor->model;
}
