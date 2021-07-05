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

// Used to add an object to the map
void cMapManager::m_addObjectEntity(sMap*& _map,              // Map pointer
                                    const std::uint32_t &_tn, // tile number
                                    const std::uint32_t &_on, // object number
                                    const std::uint32_t &_oi, // object index
                                    const float         &_s,  // scale
                                    const float         &_yr, // y rotation
                                    const std::uint32_t &_o)  // obstacle
{
    
    // Width and height offset, used to center the walls
    uint32  xo = _map->width  / 2;
    uint32  yo = _map->height / 2;

    // Load the biome object database file
    cXML xmlObjectFile;
    xmlObjectFile.load(FILE_PATH_DATABASE + m_gameDatabase->object.fileName);
    
    // Load the biome sound database file
    cXML xmlSoundFile;
    xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);

    // Only contine if we can load the biome object file and the map file
    if ((xmlObjectFile.lineCount() > 0) && (xmlSoundFile.lineCount() > 0))
    {
        // Load object names
        uint32 object_count = xmlObjectFile.getInstanceCount("<object>");
        std::vector<std::string> object_names;
        for (std::uint32_t i = 0; i < object_count; ++i)
        {
            object_names.push_back(xmlObjectFile.getString("<object>", i + 1));
        }
        std::vector<std::uint32_t> object_counts;

        // Load object counts
        for (std::uint32_t i = 0; i < object_count; ++i)
        {
            object_counts.push_back(xmlObjectFile.getInteger("<" + object_names[i] + "_count>", 1));
        }

        // Add the object to the map
        sEntity* tEntity = nullptr;
        if (_o != 0)
        {
            if (_map->tile[_tn].base == eTileBase::tileFloor)
            {
                _map->tile[_tn].base = eTileBase::tileFloorNoGo;
            }
            else if (_map->tile[_tn].base == eTileBase::tileFloorPath)
            {
                _map->tile[_tn].base = eTileBase::tilePathNoGo;
            }
            else
            {
                _map->tile[_tn].base = eTileBase::tileFloorNoGo;
            }
        }
        
        uint32 w = _tn % _map->width;
        uint32 h = _tn / _map->width;
       
        //std::cout << "Found object '" << _tn << "'-'" << _on << "'-'" << tObjectScale << "'-'" << tObjectRotation << "'" << std::endl;
        if (object_counts[_on-1] > 0)
        {
            if (_oi == 0)
            {
                tEntity = m_entityManager->load(xmlObjectFile.getString("<" + object_names[_on-1] + "_entity>", 1 + (rand() % object_counts[_on-1])));
            }
            else
            {
                tEntity = m_entityManager->load(xmlObjectFile.getString("<" + object_names[_on-1] + "_entity>", _oi));
            }
            if (tEntity != nullptr)
            {
                // Tile entity occupies
                tEntity->tile = _tn;

                m_addCollisionData(_map, tEntity, _tn, _yr);
                tEntity->owner = eEntityOwner::ownerMap;
                tEntity->type  = eEntityType::entityTypeObject;
                tEntity->position += glm::vec3(static_cast<float32>(w) + tp - static_cast<float32>(xo), y_pos, static_cast<float32>(h) + tp - static_cast<float32>(yo));
                if ((_s > 1.00001f) || (_s < 0.99999f))
                {
                    tEntity->scale *= glm::vec3(_s, _s, _s);
                }
                tEntity->rotation.y += _yr;
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
    // Clean up
    xmlObjectFile.free();
    xmlSoundFile.free();
}

// Used to add objects specified in the map file
void cMapManager::m_addObjectEntities(sMap*& _map)
{
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(_map->width  / 2);
    float32 yo = static_cast<float32>(_map->height / 2);

    // Load the biome object database file
    cXML xmlObjectFile;
    xmlObjectFile.load(FILE_PATH_DATABASE + m_gameDatabase->object.fileName);
    
    // Load the biome sound database file
    cXML xmlSoundFile;
    xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);

    // Load the map database file
    cXML xmlMapFile;
    xmlMapFile.load(FILE_PATH_MAP + _map->fileName);
    
    // Only contine if we can load the biome object file and the map file
    if ((xmlSoundFile.lineCount() > 0) && (xmlObjectFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Load object names
        uint32 object_count = xmlObjectFile.getInstanceCount("<object>");
        std::vector<std::string> object_names;
        for (std::uint32_t i = 0; i < object_count; ++i)
        {
            object_names.push_back(xmlObjectFile.getString("<object>", i + 1));
        }
        std::vector<std::uint32_t> object_counts;

        // Load object counts
        for (std::uint32_t i = 0; i < object_count; ++i)
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
            std::uint64_t tObjectStringLength = tObjectString.length();
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
                for (std::uint64_t j = 0; j < tObjectStringLength; ++j)
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
            }
            
            if (tObjectObstacle != 0)
            {
                if (_map->tile[tObjectTileNum].base == eTileBase::tileFloor)
                {
                    _map->tile[tObjectTileNum].base = eTileBase::tileFloorNoGo;
                }
                else if (_map->tile[tObjectTileNum].base == eTileBase::tileFloorPath)
                {
                    _map->tile[tObjectTileNum].base = eTileBase::tilePathNoGo;
                }
                else
                {
                    _map->tile[tObjectTileNum].base = eTileBase::tileFloorNoGo;
                }
            }
            
            uint32 w = tObjectTileNum % _map->width;
            uint32 h = tObjectTileNum / _map->width;
           
            //std::cout << "Found object '" << tObjectTileNum << "'-'" << tObjectNumber << "'-'" << tObjectScale << "'-'" << tObjectRotation << "'" << std::endl;
            if ((tObjectNumber > 0) && (object_counts[tObjectNumber-1] > 0))
            {
                if (tObjectIndex == 0)
                {
                    tEntity = m_entityManager->load(xmlObjectFile.getString("<" + object_names[tObjectNumber-1] + "_entity>", 1 + (rand() % object_counts[tObjectNumber-1])));
                }
                else
                {
                    tEntity = m_entityManager->load(xmlObjectFile.getString("<" + object_names[tObjectNumber-1] + "_entity>", tObjectIndex));
                }
                if (tEntity != nullptr)
                {
                    // Tile entity occupies
                    tEntity->tile = tObjectTileNum;

                    m_addCollisionData(_map, tEntity, tObjectTileNum, tObjectRotation);
                    tEntity->owner = eEntityOwner::ownerMap;
                    tEntity->type  = eEntityType::entityTypeObject;
                    tEntity->position += glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
                    if ((tObjectScale > 1.00001f) || (tObjectScale < 0.99999f))
                    {
                        tEntity->scale *= glm::vec3(tObjectScale, tObjectScale, tObjectScale);
                    }
                    tEntity->rotation.y += tObjectRotation;
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
                uint32 obstacle      = 0;
            };
            
            sDebris *debris = nullptr;
            debris = new sDebris[debris_count];
            
            // Load the debris information from the map file into the debris data structure
            for (uint32 i = 0; i < debris_count; ++i)
            {
                std::string   tDebrisString = xmlMapFile.getString("<debris>", i + 1);
                tDebrisString += "    ";
                std::uint64_t tDebrisStringLength = tDebrisString.length();
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tDebrisStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tDebrisStringLength; ++j)
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
                            else if (tStringNum == 4)
                            {
                                debris[i].obstacle = std::stoi(tString);
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
                                if (debris[i].obstacle != 0)
                                {
                                    _map->tile[t].base = eTileBase::tileFloorNoGo;
                                }
                                if (object_counts[debris[i].object_number-1] > 0)
                                {
                                    tEntity = m_entityManager->load(xmlObjectFile.getString("<" + object_names[debris[i].object_number-1] + "_entity>", 1 + (rand() % object_counts[debris[i].object_number-1])));
                                    if (tEntity != nullptr)
                                    {
                                        // Tile entity occupies
                                        tEntity->tile = t;

                                        m_addCollisionData(_map, tEntity, t, 0.0);
                                        tEntity->owner = eEntityOwner::ownerMap;
                                        tEntity->type  = eEntityType::entityTypeObject;
                                        tEntity->position = glm::vec3(static_cast<float32>(w) + tp - xo, y_pos, static_cast<float32>(h) + tp - yo);
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
    xmlSoundFile.free();
    xmlMapFile.free();
}
