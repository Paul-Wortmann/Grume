/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
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
    float xo = static_cast<float>(_map->width  / 2);
    float yo = static_cast<float>(_map->height / 2);

    // Load the biome npc database file
    cXML xmlNPCFile;
    xmlNPCFile.load(FILE_PATH_DATABASE + m_gameDatabase->npc.fileName);

    // Load the biome sound database file
    cXML xmlSoundFile;
    xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);
    
    // Load the map file
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    
    // Only contine if we can load all the xml files
    if ((xmlNPCFile.lineCount() > 0) && (xmlSoundFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Create temporary entity pointer
        sEntity* tEntity = nullptr;

        // Load each npc from the map file
        std::uint32_t mapNPCCount = xmlMapFile.getInstanceCount("<npc>");
        for (std::uint32_t i = 0; i < mapNPCCount; ++i)
        {
            std::string   tNPCString = xmlMapFile.getString("<npc>", i + 1);
            tNPCString += "    ";
            std::uint64_t tNPCStringLength = tNPCString.length();
            std::uint32_t tNPCTileNum  = 0;
            std::string   tNPCName     = {};
            std::uint32_t tNPCIndex    = 0;
            float         tNPCScale    = 0.0;
            float         tNPCRotation = 0.0;
            std::uint32_t tNPCEnemy    = 0;
            std::uint32_t tStringNum   = 0;
            std::string   tString      = {};
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
                            tNPCName = tString;
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
                        else if (tStringNum == 5)
                        {
                            tNPCEnemy = std::stoi(tString);
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
            
            std::uint32_t w = tNPCTileNum % _map->width;
            std::uint32_t h = tNPCTileNum / _map->width;
           
            // Get npc entity database count
            std::uint32_t npcCount = xmlNPCFile.getInstanceCount("<npc>" + tNPCName + " ");

            // Get npc data string
            if (npcCount > 0)
            {
                std::string tNPCDataString = "";
                if (tNPCIndex == 0)
                {
                    tNPCDataString = xmlNPCFile.getString("<npc>" + tNPCName, 1 + (rand() % npcCount));
                }
                else
                {
                    tNPCDataString = xmlNPCFile.getString("<npc>" + tNPCName, tNPCIndex);
                }

                // Get the npc entity file name
                tNPCDataString += "    ";
                std::uint64_t tNPCDataStringLength = tNPCDataString.length();
                std::string   tNPCFileName       = {};
                std::uint32_t tStringNumFileName = 0;
                std::string   tStringFileName    = {};
                if (tNPCDataStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tNPCDataStringLength; ++j)
                    {
                        if (tNPCDataString[j] == ' ')
                        {
                            if (tStringNumFileName == 0)
                            {
                                ; // npc name
                            }
                            else if (tStringNumFileName == 1)
                            {
                                tNPCFileName = tStringFileName.c_str();
                            }

                            tStringNumFileName++;
                            tStringFileName = "";
                        }
                        else
                        {
                            tStringFileName += tNPCDataString[j];
                        }
                    }
                }
                
                // Load the npc entity
                tEntity = m_entityManager->load(tNPCFileName);
        
                // If the entity was successfully loaded, proceed
                if (tEntity != nullptr)
                {
                    // Tile entity occupies
                    tEntity->tile = tNPCTileNum;

                    _map->tile[tNPCTileNum].npc = tEntity->UID;
                    tEntity->owner = eEntityOwner::entityOwnerMap;
                    tEntity->type  = (tNPCEnemy == 0) ? eEntityType::entityTypeNPC : eEntityType::entityTypeNPCmob;
                    tEntity->position += glm::vec3(static_cast<float>(w) + tp - xo, y_pos, static_cast<float>(h) + tp - yo);
                    if ((tNPCScale > 1.00001f) || (tNPCScale < 0.99999f))
                    {
                        tEntity->scale *= glm::vec3(tNPCScale, tNPCScale, tNPCScale);
                    }
                    tEntity->rotation.y += tNPCRotation;
                    tEntity->rotation = glm::vec3(tEntity->rotation.x, tEntity->rotation.y, tEntity->rotation.z);
                    m_entityManager->updateModelMatrix(tEntity);
                    
                    // Movement
                    if (tEntity->movement != nullptr)
                    {
                        tEntity->movement->mapPath.currentTile = tNPCTileNum;
                    }

                    // AI
                    if (tEntity->ai != nullptr)
                    {
                        tEntity->ai->spawnTile = tNPCTileNum;
                    }

                    // Load audio file names
                    if (tEntity->stateCount > 0)
                    {
                        for (std::uint32_t s = 0; s < tEntity->stateCount; ++s)
                        {
                            tEntity->state[s].audioFile = gGetFileName(xmlSoundFile, "<sound>" + tEntity->state[s].audioDBname + " ", tEntity->state[s].audioDBIndex);
                        }
                    }
                }
            }
        }

        // Get mob count
        std::uint32_t mob_count = xmlMapFile.getInstanceCount("<npc_mob>");
        
        if (mob_count > 0)
        {
            // Create a data structure for the mob information
            struct sMob
            {
                std::string   npcName    = {};
                float         scaleMin   = 0.0;
                float         scaleMax   = 0.0;
                std::uint32_t prevalence = 0;
            };
            
            sMob *mob = nullptr;
            mob = new sMob[mob_count];
            
            // Load the mob information from the map file into the mob data structure
            for (std::uint32_t i = 0; i < mob_count; ++i)
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
                                mob[i].npcName = tString;
                            }
                            else if (tStringNum == 1)
                            {
                                mob[i].scaleMin = std::stof(tString);
                            }
                            else if (tStringNum == 2)
                            {
                                mob[i].scaleMax = std::stof(tString);
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
            for (std::uint32_t h = 1; h < _map->height-1; ++h)
            {
                for (std::uint32_t w = 1; w < _map->width-1; ++w)
                {
                    std::uint32_t t = (h * _map->width) + w;
                    if ((_map->tile[t].npc == 0) && (_map->tile[t].object == 0) && (_map->tile[t].base == eTileBase::tileFloor))
                    {
                        std::uint32_t rInt = rand() % 1000;
                        bool   pMob = false;
                        for (std::uint32_t i = 0; i < mob_count; ++i)
                        {
                            if ((!pMob) && (rInt < mob[i].prevalence))
                            {
                                pMob = true;
                                
                                // Get npc entity database count
                                std::uint32_t npcCount = xmlNPCFile.getInstanceCount("<npc>" + mob[i].npcName + " ");
                               
                               // If npc found
                                if (npcCount > 0)
                                {
                                    // Get npc entity file name
                                    std::string npcDataString = "";
                                    npcDataString = xmlNPCFile.getString("<npc>" + mob[i].npcName, 1 + (rand() % npcCount));

                                    // Get the npc entity file name
                                    npcDataString += "    ";
                                    std::uint64_t tNPCDataStringLength = npcDataString.length();
                                    std::string   tNPCFileName         = {};
                                    std::uint32_t tStringNum           = 0;
                                    std::string   tString              = {};
                                    if (tNPCDataStringLength > 6)
                                    {
                                        for (std::uint64_t j = 0; j < tNPCDataStringLength; ++j)
                                        {
                                            if (npcDataString[j] == ' ')
                                            {
                                                if (tStringNum == 0)
                                                {
                                                    ; // Object name
                                                }
                                                else if (tStringNum == 1)
                                                {
                                                    tNPCFileName = tString.c_str();
                                                }

                                                tStringNum++;
                                                tString = "";
                                            }
                                            else
                                            {
                                                tString += npcDataString[j];
                                            }
                                        }
                                    }
                                    
                                    // Load the object entity
                                    tEntity = m_entityManager->load(tNPCFileName);                                
                                    
                                    // Proceed if the entity was successfully loaded
                                    if (tEntity != nullptr)
                                    {
                                        // Tile entity occupies
                                        tEntity->tile = t;

                                        _map->tile[t].npc = tEntity->UID;
                                        tEntity->owner = eEntityOwner::entityOwnerMap;
                                        tEntity->type  = eEntityType::entityTypeNPCmob;
                                        tEntity->position += glm::vec3(static_cast<float>(w) + tp - xo, y_pos, static_cast<float>(h) + tp - yo);
                                        tEntity->rotation = glm::vec3(tEntity->rotation.x, tEntity->rotation.y, tEntity->rotation.z);
                                        m_entityManager->updateModelMatrix(tEntity);

                                        // Movement
                                        if (tEntity->movement != nullptr)
                                        {
                                            tEntity->movement->mapPath.currentTile = t;
                                        }
                                        
                                        // AI
                                        if (tEntity->ai != nullptr)
                                        {
                                            tEntity->ai->spawnTile = t;
                                        }
                                        
                                        // Load audio file names
                                        if (tEntity->stateCount > 0)
                                        {
                                            for (std::uint32_t s = 0; s < tEntity->stateCount; ++s)
                                            {
                                                tEntity->state[s].audioFile = gGetFileName(xmlSoundFile, "<sound>" + tEntity->state[s].audioDBname + " ", tEntity->state[s].audioDBIndex);
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
