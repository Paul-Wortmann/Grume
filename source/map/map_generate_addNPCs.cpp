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

// Used to add npcs specified in the map file
void cMapManager::m_addNPCEntities(sMap*& _map)
{
    // Map floor position on the y axis
    float32 y_pos = -1.0f;
    
    // Width and height offset, used to center the walls
    uint32  xo = _map->width  / 2;
    uint32  yo = _map->height / 2;
    float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    // Load the biome npc file
    cXML xmlNPCFile;
    xmlNPCFile.load(FILE_PATH_BIOME + _map->biome->NPCSet.fileName);
    
    // Load the map file
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    
    // Only contine if we can load the biome npc file and the map file
    if ((xmlNPCFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Load npc names
        uint32 npc_count = xmlNPCFile.getInstanceCount("<npc>");
        std::vector<std::string> npc_names;
        for (std::size_t i = 0; i < npc_count; ++i)
        {
            npc_names.push_back(xmlNPCFile.getString("<npc>", i + 1));
        }
        std::vector<std::uint32_t> npc_counts;

        // Load npc counts
        for (std::size_t i = 0; i < npc_count; ++i)
        {
            npc_counts.push_back(xmlNPCFile.getInteger("<" + npc_names[i] + "_count>", 1));
        }

        sEntity* tEntity = nullptr;

        // Load each npc from the map file
        std::uint32_t mapNPCCount = xmlMapFile.getInstanceCount("<npc>");
        for (std::uint32_t i = 0; i < mapNPCCount; ++i)
        {
            std::string   tNPCString = xmlMapFile.getString("<npc>", i + 1);
            tNPCString += "    ";
            std::uint32_t tNPCStringLength = tNPCString.length();
            std::uint32_t tNPCTileNum  = 0;
            std::uint32_t tNPCNumber   = 0;
            std::uint32_t tNPCIndex    = 0;
            float         tNPCScale    = 0.0;
            float         tNPCRotation = 0.0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tNPCStringLength > 6)
            {
                for (std::uint32_t j = 0; j < tNPCStringLength; ++j)
                {
                    if (tNPCString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            tNPCTileNum = std::stoi(tString);
                        }
                        else if (tStringNum == 1)
                        {
                            tNPCNumber = std::stoi(tString);
                        }
                        else if (tStringNum == 2)
                        {
                            tNPCIndex = std::stoi(tString);
                        }
                        else if (tStringNum == 3)
                        {
                            tNPCScale = std::stof(tString);
                        }
                        else if (tStringNum == 4)
                        {
                            tNPCRotation = std::stof(tString);
                        }
                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tNPCString[j];
                    }
                }
            }
            _map->tile[tNPCTileNum].object = tNPCNumber;
            
            uint32 w = tNPCTileNum % _map->width;
            uint32 h = tNPCTileNum / _map->width;
           
            //std::cout << "Found npc '" << tNPCTileNum << "'-'" << tNPCNumber << "'-'" << tNPCScale << "'-'" << tNPCRotation << "'" << std::endl;
            if (npc_counts[tNPCNumber-1] > 0)
            {
                if (tNPCIndex == 0)
                {
                    tEntity = entityManager->load(xmlNPCFile.getString("<" + npc_names[tNPCNumber-1] + "_entity>", 1 + (rand() % npc_counts[tNPCNumber-1])));
                }
                else
                {
                    tEntity = entityManager->load(xmlNPCFile.getString("<" + npc_names[tNPCNumber-1] + "_entity>", tNPCIndex));
                }
                if (tEntity != nullptr)
                {
                    tEntity->owner = eEntityOwner::ownerMap;
                    tEntity->type  = eEntityType::entityTypeNPC;
                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                    if ((tNPCScale > 1.00001f) || (tNPCScale < 0.99999f))
                    {
                        tEntity->scale *= glm::vec3(tNPCScale, tNPCScale, tNPCScale);
                    }
                    tEntity->rotation.y += tNPCRotation;
                    tEntity->rotation = glm::vec3(tEntity->rotation.x, tEntity->rotation.y, tEntity->rotation.z);
                    entityManager->updateModelMatrix(tEntity);
                }
            }
        }

        // Get mob count
        uint32 mob_count = xmlMapFile.getInstanceCount("<mob>");
        
        if (mob_count > 0)
        {
            // Create a data structure for the mob information
            struct sMob
            {
                uint32 npc_number = 0;
                float  scale_min     = 0.0;
                float  scale_max     = 0.0;
                uint32 prevalence    = 0;
            };
            
            sMob *mob = nullptr;
            mob = new sMob[mob_count];
            
            // Load the mob information from the map file into the mob data structure
            for (uint32 i = 0; i < mob_count; ++i)
            {
                std::string   tMobString = xmlMapFile.getString("<mob>", i + 1);
                tMobString += "    ";
                std::uint32_t tMobStringLength = tMobString.length();
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tMobStringLength > 6)
                {
                    for (std::uint32_t j = 0; j < tMobStringLength; ++j)
                    {
                        if (tMobString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                mob[i].npc_number = std::stoi(tString);
                            }
                            else if (tStringNum == 1)
                            {
                                mob[i].scale_min = std::stof(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                mob[i].scale_max = std::stof(tString);
                            }
                            else if (tStringNum == 3)
                            {
                                mob[i].prevalence = std::stoi(tString);
                            }
                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tMobString[j];
                        }
                    }
                }
            }
            
            // Add mob to map
            for (uint32 h = 1; h < _map->height-1; ++h)
            {
                for (uint32 w = 1; w < _map->width-1; ++w)
                {
                    uint32 t = (h * _map->width) + w;
                    if ((_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
                    {
                        uint32 rInt = rand() % 1000;
                        bool   pMob = false;
                        for (uint32 i = 0; i < mob_count; ++i)
                        {
                            if ((!pMob) && (rInt < mob[i].prevalence))
                            {
                                pMob = true;
                                _map->tile[t].object = mob[i].npc_number;
                                if (npc_counts[mob[i].npc_number-1] > 0)
                                {
                                    tEntity = entityManager->load(xmlNPCFile.getString("<" + npc_names[mob[i].npc_number-1] + "_entity>", 1 + (rand() % npc_counts[mob[i].npc_number-1])));
                                    if (tEntity != nullptr)
                                    {
                                        tEntity->owner = eEntityOwner::ownerMap;
                                        tEntity->type  = eEntityType::entityTypeNPC;
                                        tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                        entityManager->updateModelMatrix(tEntity);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            // Mob cleanup
            if (mob != nullptr)
            {
                delete [] mob;
                mob = nullptr;
            }
        }
    }
    // Clean up
    xmlNPCFile.free();
    xmlMapFile.free();
}
