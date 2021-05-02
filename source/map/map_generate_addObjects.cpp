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

// Used to add objects specified in the map file
void cMapManager::m_addObjectEntities(sMap*& _map)
{
    // Map floor position on the y axis
    float32 y_pos = -1.0f;
    
    // Width and height offset, used to center the walls
    uint32  xo = _map->width  / 2;
    uint32  yo = _map->height / 2;
    float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    // Load the biome object file
    std::ifstream file;
    cXML xmlObjectFile;
    xmlObjectFile.load(FILE_PATH_BIOME + _map->biome->ObjectSet.fileName);
    
    // Load the map file
    std::ifstream mapFile;
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    
    // Only contine if we can load the biome object file and the map file
    if ((xmlObjectFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Load object names
        uint32 object_count = xmlObjectFile.getInstanceCount("<object");
        std::vector<std::string> object_names;
        for (std::size_t i = 0; i < object_count; ++i)
        {
            object_names.push_back(xmlObjectFile.getString("<object>", i + 1));
        }
        std::vector<std::uint32_t> object_counts;

        // Load object counts
        for (std::size_t i = 0; i < object_count; ++i)
        {
            object_counts.push_back(xmlObjectFile.getInteger("<" + object_names[i] + "_count>", 1));
        }

        sEntity* tEntity = nullptr;

        // Load each object from the map file
        std::uint32_t mapObjectCount = xmlMapFile.getInstanceCount("<object>");
        for (std::uint32_t i = 0; i < mapObjectCount; ++i)
        {
            std::string   tObjectString = xmlMapFile.getString("<object>", i + 1);
            tObjectString += "    ";
            std::uint32_t tObjectStringLength = tObjectString.length();
            std::uint32_t tObjectTileNum  = 0;
            std::uint32_t tObjectNumber   = 0;
            std::uint32_t tObjectIndex    = 0;
            float         tObjectScale    = 0.0;
            float         tObjectRotation = 0.0;
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
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tObjectString[j];
                    }
                }
            }
            _map->tile[tObjectTileNum].object = tObjectNumber;
            
            uint32 w = tObjectTileNum % _map->width;
            uint32 h = tObjectTileNum / _map->width;
           
            //std::cout << "Found object '" << tObjectTileNum << "'-'" << tObjectNumber << "'-'" << tObjectScale << "'-'" << tObjectRotation << "'" << std::endl;
            if (object_counts[tObjectNumber-1] > 0)
            {
                if (tObjectIndex == 0)
                {
                    tEntity = entityManager->load(xmlObjectFile.getString("<" + object_names[tObjectNumber-1] + "_entity>", 1 + (rand() % object_counts[tObjectNumber-1])));
                }
                else
                {
                    tEntity = entityManager->load(xmlObjectFile.getString("<" + object_names[tObjectNumber-1] + "_entity>", tObjectIndex));
                }
                if (tEntity != nullptr)
                {
                    tEntity->owner = eEntityOwner::ownerMap;
                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                    if ((tObjectScale > 1.00001f) || (tObjectScale < 0.99999f))
                    {
                        tEntity->scale *= glm::vec3(tObjectScale, tObjectScale, tObjectScale);
                    }
                    tEntity->rotation += glm::vec3(tEntity->rotation.x, tObjectRotation, tEntity->rotation.z);
                    entityManager->updateModelMatrix(tEntity);
                }
            }
        }

        // Get debris count
        uint32 debris_count = xmlMapFile.getInstanceCount("<debris>");
        
        if (debris_count > 0)
        {
            // Create a data structure for the debris information
            struct sDebris
            {
                uint32 object_number = 0;
                float  scale_min     = 0.0;
                float  scale_max     = 0.0;
                uint32 prevalence    = 0;
            };
            
            sDebris *debris = nullptr;
            debris = new sDebris[debris_count];
            
            // Load the debris information from the map file into the debris data structure
            for (uint32 i = 0; i < debris_count; ++i)
            {
                std::string   tDebrisString = xmlMapFile.getString("<debris>", i + 1);
                tDebrisString += "    ";
                std::uint32_t tDebrisStringLength = tDebrisString.length();
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDebrisStringLength > 6)
                {
                    for (std::uint32_t j = 0; j < tDebrisStringLength; ++j)
                    {
                        if (tDebrisString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                debris[i].object_number = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                debris[i].scale_min = std::stof(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                debris[i].scale_max = std::stof(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                debris[i].prevalence = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tDebrisString[j];
                        }
                    }
                }
            }
            
            // Add debris to map
            for (uint32 h = 1; h < _map->height-1; ++h)
            {
                for (uint32 w = 1; w < _map->width-1; ++w)
                {
                    uint32 t = (h * _map->width) + w;
                    if ((_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
                    {
                        uint32 rInt = rand() % 1000;
                        bool   pDebris = false;
                        for (uint32 i = 0; i < debris_count; ++i)
                        {
                            if ((!pDebris) && (rInt < debris[i].prevalence))
                            {
                                pDebris = true;
                                _map->tile[t].object = debris[i].object_number;
                                if (object_counts[debris[i].object_number-1] > 0)
                                {
                                    tEntity = entityManager->load(xmlObjectFile.getString("<" + object_names[debris[i].object_number-1] + "_entity>", 1 + (rand() % object_counts[debris[i].object_number-1])));
                                    if (tEntity != nullptr)
                                    {
                                        tEntity->owner = eEntityOwner::ownerMap;
                                        tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                        entityManager->updateModelMatrix(tEntity);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            // Debris cleanup
            if (debris != nullptr)
            {
                delete [] debris;
                debris = nullptr;
            }
        }
    }
    // Clean up
    xmlObjectFile.free();
    xmlMapFile.free();
}
