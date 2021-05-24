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

void cMapManager::m_mapPrefabRoomFlipV(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < tileCount; i++)
    {
        _tiles[(tileCount-1)-i] = tile[i];
    }
    delete[] tile;
}

void cMapManager::m_mapPrefabRoomFlipH(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(i * _w) + ((_w-1)-j)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapPrefabRoomRotateR90(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(j * _w) + ((_w-1)-i)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapPrefabRoomRotateL90(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < _h; i++)
    {
        for (uint32_t j = 0; j < _w; j++)
        {
            _tiles[(i * _w) + j] = tile[(((_h-1)-j) * _w) + ((_w-1)-i)];
        }
    }
    delete[] tile;
}

void cMapManager::m_mapPrefabRoomRotate180(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h)
{
    std::uint32_t tileCount = _w * _h;
    std::uint32_t *tile = new std::uint32_t[tileCount];
    for (uint32_t i = 0; i < tileCount; i++)
    {
        tile[i] = _tiles[i];
    }
    for (uint32_t i = 0; i < tileCount; i++)
    {
        _tiles[(tileCount-1)-i] = tile[i];
    }
    delete[] tile;
}

void cMapManager::m_mapPrefabRooms(sMap*& _map)
{
    // Open the prefab database file
    cXML xmlMapPrefabDatabaseFile;
    xmlMapPrefabDatabaseFile.load(FILE_PATH_BIOME + _map->biome->databaseMapPrefab.fileName);
    if (xmlMapPrefabDatabaseFile.lineCount() > 0)
    {
        // temporary prefab data storage;
        struct sPrefabData
        {
            std::uint32_t roomType   = 0;
            std::uint32_t roomWidth  = 0;
            std::uint32_t roomHeight = 0;
            std::string   fileName   = "";
        };
        
        // Get the data from the XML file
        std::uint32_t prefabCount = xmlMapPrefabDatabaseFile.getInstanceCount("<prefab>");
        sPrefabData* tPrefabData = new sPrefabData[prefabCount];
        for (std::uint32_t p = 0; p < prefabCount; ++p)
        {
            std::string tPrefabString = xmlMapPrefabDatabaseFile.getString("<prefab>", p + 1);
            tPrefabString += "    ";
            std::uint32_t tPrefabStringLength = tPrefabString.length();
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tPrefabStringLength > 6)
            {
                for (std::uint32_t j = 0; j < tPrefabStringLength; ++j)
                {
                    if (tPrefabString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tPrefabData[p].roomType = std::stoi(tString);
                        }
                        else if (tStringNum == 1)
                        {
                            tPrefabData[p].roomWidth = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            tPrefabData[p].roomHeight = std::stoi(tString);
                        }
                        else if (tStringNum == 3)
                        {
                            tPrefabData[p].fileName = std::string(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tPrefabString[j];
                    }
                }
            }
        }

        // loop through each room in the map
        for (std::uint32_t r = 0; r < _map->roomCount; ++r)
        {
            // loop through each prefab, count number compatible
            std::uint32_t numCompatible = 0;
            for (std::uint32_t p = 0; p < prefabCount; ++p)
            {
                // look for a match
                if ((_map->room[r].w == tPrefabData[p].roomWidth) &&
                    (_map->room[r].h == tPrefabData[p].roomHeight) &&
                    ((_map->room[r].type == eMapRoomType::roomTypeNone) || 
                     (_map->room[r].type == static_cast<eMapRoomType>(tPrefabData[p].roomType))))
                {
                    numCompatible++;
                }
            }
            // Select one at random and apply it.
            if (numCompatible > 0)
            {
                std::uint32_t prefabNum = 0;

                // Generate random number
                std::uint32_t rndPrefab = rand() % numCompatible;

                // Generate random number
                for (std::uint32_t p = 0; p < prefabCount; ++p)
                {
                    // look for a match and apply the prefab
                    if ((_map->room[r].w == tPrefabData[p].roomWidth) &&
                        (_map->room[r].h == tPrefabData[p].roomHeight) &&
                        ((_map->room[r].type == eMapRoomType::roomTypeNone) || 
                         (_map->room[r].type == static_cast<eMapRoomType>(tPrefabData[p].roomType))))
                    {
                        if (prefabNum == rndPrefab)
                        {
                            m_mapApplyPrefab(_map, tPrefabData[p].fileName, r);
                        }
                        prefabNum++;
                    }
                }
            }
        }

        // Clean up
        xmlMapPrefabDatabaseFile.free();
        
        if (tPrefabData != nullptr)
        {
            delete[] tPrefabData;
            tPrefabData = nullptr;
        }
    }
}

void cMapManager::m_mapApplyPrefab(sMap*& _map, const std::string &_fileName, const std::uint32_t &_r)
{
    // Open the prefab database file
    cXML xmlMapPrefabFile;
    xmlMapPrefabFile.load(FILE_PATH_MAP_PREFAB + _fileName);
    if (xmlMapPrefabFile.lineCount() > 0)
    {
        // Prefab position delta
        std::uint32_t dx = _map->room[_r].x - (_map->room[_r].w / 2); // Start x position on the map
        std::uint32_t dy = _map->room[_r].y - (_map->room[_r].h / 2); // Start y position on the map

        // load the tile data from the prefab
        std::uint32_t* pTiles = new std::uint32_t[_map->room[_r].w * _map->room[_r].h];
        std::uint32_t  currentTile = 0;
        std::uint32_t tileKeyCount = xmlMapPrefabFile.getInstanceCount("<tiles>");
        for (std::uint32_t i = 0; i < tileKeyCount; ++i)
        {
            std::string tPTiles = xmlMapPrefabFile.getString("<tiles>", i + 1);
            tPTiles += "  ";
            std::uint32_t tPTilesLength = tPTiles.length();
            std::string   tString = "";
            std::uint32_t tileCount = 0;
            if (tPTilesLength > 6)
            {
                for (std::uint32_t j = 0; j < tPTilesLength; ++j)
                {
                    if (tPTiles[j] == ' ')
                    {
                        pTiles[currentTile] = std::stoi(tString);
                        currentTile++;
                        tString = "";
                        tileCount++;
                        if (tileCount == _map->room[_r].w)
                        {
                            j = tPTilesLength;
                        }
                    }
                    else
                    {
                        tString += tPTiles[j];
                    }
                }
            }
        }
        
        // Write the prefab tile data to the map
        for (std::uint32_t y = 0; y < _map->room[_r].h; ++y)
        {
            for (std::uint32_t x = 0; x < _map->room[_r].w; ++x)
            {
                _map->tile[((dy + y) * _map->width) + dx + x].base = static_cast<eTileBase>(pTiles[(y * _map->room[_r].w) + x]);
            }
        }
        
        // Write the prefab object data to the map
        std::uint32_t mapObjectCount = xmlMapPrefabFile.getInstanceCount("<object>");
        for (std::uint32_t i = 0; i < mapObjectCount; ++i)
        {
            std::string   tObjectString = xmlMapPrefabFile.getString("<object>", i + 1);
            tObjectString += "    ";
            std::uint32_t tObjectStringLength = tObjectString.length();
            std::uint32_t tObjectTileNum  = 0;
            std::uint32_t tObjectNumber   = 0;
            std::uint32_t tObjectIndex    = 0;
            float         tObjectScale    = 0.0;
            float         tObjectRotation = 0.0;
            uint32        tObjectObstacle = 0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tObjectStringLength > 6)
            {
                for (std::uint32_t j = 0; j < tObjectStringLength; ++j)
                {
                    if (tObjectString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tObjectTileNum = std::stoi(tString);
                        }
                        else if (tStringNum == 1)
                        {
                            tObjectNumber = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            tObjectIndex = std::stoi(tString);
                        }
                        else if (tStringNum == 3)
                        {
                            tObjectScale = std::stof(tString);
                        }
                        else if (tStringNum == 4)
                        {
                            tObjectRotation = std::stof(tString);
                        }
                        else if (tStringNum == 5)
                        {
                            tObjectObstacle = std::stoi(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tObjectString[j];
                    }
                }
                
                // Convert prefab tile number to map tile number
                std::uint32_t ox = tObjectTileNum % _map->room[_r].w;
                std::uint32_t oy = tObjectTileNum / _map->room[_r].w;
                std::uint32_t tp = ((dy + oy) * _map->width) + dx + ox;
                
                m_addObjectEntity(_map, tp, tObjectNumber, tObjectIndex, tObjectScale, tObjectRotation, tObjectObstacle);
            }
        }
        
        // Clean up
        xmlMapPrefabFile.free();
        
        if (pTiles != nullptr)
        {
            delete[] pTiles;
            pTiles = nullptr;
        }
    }
    
}
