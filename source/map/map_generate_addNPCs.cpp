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
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(_map->width  / 2);
    float32 yo = static_cast<float32>(_map->height / 2);

    // Load the biome npc database file
    cXML xmlNPCFile;
    xmlNPCFile.load(FILE_PATH_BIOME + _map->biome->databaseNPC.fileName);

    // Load the biome sound database file
    cXML xmlSoundFile;
    xmlSoundFile.load(FILE_PATH_BIOME + _map->biome->databaseSound.fileName);
    
    // Load the map file
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    
    // Only contine if we can load the biome npc file and the map file
    if ((xmlNPCFile.lineCount() > 0) && (xmlSoundFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Load npc names
        uint32 npc_count = xmlNPCFile.getInstanceCount("<npc>");
        std::vector<std::string> npc_names;
        for (std::uint32_t i = 0; i < npc_count; ++i)
        {
            npc_names.push_back(xmlNPCFile.getString("<npc>", i + 1));
        }
        std::vector<std::uint32_t> npc_counts;

        // Load npc counts
        for (std::uint32_t i = 0; i < npc_count; ++i)
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
            std::uint64_t tNPCStringLength = tNPCString.length();
            std::uint32_t tNPCTileNum  = 0;
            std::uint32_t tNPCNumber   = 0;
            std::uint32_t tNPCIndex    = 0;
            float         tNPCScale    = 0.0;
            float         tNPCRotation = 0.0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tNPCStringLength > 6)
            {
                for (std::uint64_t j = 0; j < tNPCStringLength; ++j)
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
            
            uint32 w = tNPCTileNum % _map->width;
            uint32 h = tNPCTileNum / _map->width;
           
            //std::cout << "Found npc '" << tNPCTileNum << "'-'" << tNPCNumber << "'-'" << tNPCScale << "'-'" << tNPCRotation << "'" << std::endl;
            if ((tNPCNumber > 0) && (npc_counts[tNPCNumber-1] > 0))
            {
                if (tNPCIndex == 0)
                {
                    tEntity = m_entityManager->load(xmlNPCFile.getString("<" + npc_names[tNPCNumber-1] + "_entity>", 1 + (rand() % npc_counts[tNPCNumber-1])));
                }
                else
                {
                    tEntity = m_entityManager->load(xmlNPCFile.getString("<" + npc_names[tNPCNumber-1] + "_entity>", tNPCIndex));
                }
                if (tEntity != nullptr)
                {
                    _map->tile[tNPCTileNum].object = tEntity->UID;
                    tEntity->owner = eEntityOwner::ownerMap;
                    tEntity->type  = eEntityType::entityTypeNPC;
                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                    if ((tNPCScale > 1.00001f) || (tNPCScale < 0.99999f))
                    {
                        tEntity->scale *= glm::vec3(tNPCScale, tNPCScale, tNPCScale);
                    }
                    tEntity->rotation.y += tNPCRotation;
                    tEntity->rotation = glm::vec3(tEntity->rotation.x, tEntity->rotation.y, tEntity->rotation.z);
                    m_entityManager->updateModelMatrix(tEntity);
                    
                    // Load audio file names
                    if (tEntity->stateCount > 0)
                    {
                        for (std::uint32_t s = 0; s < tEntity->stateCount; ++s)
                        {
                            if (tEntity->state[s].audioDBIndex > 0)
                            {
                                tEntity->state[s].audioFile = xmlSoundFile.getString("<" + tEntity->state[s].audioDBname + "_sound>", tEntity->state[s].audioDBIndex);
                            }
                            else
                            {
                                tEntity->state[s].audioFile = xmlSoundFile.getString("<" + tEntity->state[s].audioDBname + "_sound>", (rand() % (xmlSoundFile.getInstanceCount("<" + tEntity->state[s].audioDBname + "_sound>") - 1)) + 1);
                            }
                        }
                    }
                }
            }
        }

        // Get mob count
        uint32 mob_count = xmlMapFile.getInstanceCount("<npc_mob>");
        
        if (mob_count > 0)
        {
            // Create a data structure for the mob information
            struct sMob
            {
                uint32 npc_number = 0;
                float  scale_min  = 0.0;
                float  scale_max  = 0.0;
                uint32 prevalence = 0;
            };
            
            sMob *mob = nullptr;
            mob = new sMob[mob_count];
            
            // Load the mob information from the map file into the mob data structure
            for (uint32 i = 0; i < mob_count; ++i)
            {
                std::string   tMobString = xmlMapFile.getString("<npc_mob>", i + 1);
                tMobString += "    ";
                std::uint64_t tMobStringLength = tMobString.length();
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tMobStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tMobStringLength; ++j)
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
                                if (npc_counts[mob[i].npc_number-1] > 0)
                                {
                                    tEntity = m_entityManager->load(xmlNPCFile.getString("<" + npc_names[mob[i].npc_number-1] + "_entity>", 1 + (rand() % npc_counts[mob[i].npc_number-1])));
                                    if (tEntity != nullptr)
                                    {
                                        _map->tile[t].object = tEntity->UID;
                                        tEntity->owner = eEntityOwner::ownerMap;
                                        tEntity->type  = eEntityType::entityTypeNPCmob;
                                        tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                                        m_entityManager->updateModelMatrix(tEntity);

                                        // Load audio file names
                                         if (tEntity->stateCount > 0)
                                        {
                                            for (std::uint32_t s = 0; s < tEntity->stateCount; ++s)
                                            {
                                                if (tEntity->state[s].audioDBIndex > 0)
                                                {
                                                    tEntity->state[s].audioFile = xmlSoundFile.getString("<" + tEntity->state[s].audioDBname + "_sound>", tEntity->state[s].audioDBIndex);
                                                }
                                                else
                                                {
                                                    tEntity->state[s].audioFile = xmlSoundFile.getString("<" + tEntity->state[s].audioDBname + "_sound>", (rand() % (xmlSoundFile.getInstanceCount("<" + tEntity->state[s].audioDBname + "_sound>") - 1)) + 1);
                                                }
                                            }
                                        }
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
    xmlSoundFile.free();
}
