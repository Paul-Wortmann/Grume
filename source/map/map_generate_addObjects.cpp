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
                                    const std::string   &_on, // object name
                                    const std::uint32_t &_oi, // object index
                                    const float         &_s,  // scale
                                    const float         &_yr, // y rotation
                                    const std::uint32_t &_o)  // obstacle
{
    
    // Width and height offset, used to center the walls
    std::uint32_t  xo = _map->width  / 2;
    std::uint32_t  yo = _map->height / 2;

    // Load the biome object database file
    cXML xmlObjectFile;
    xmlObjectFile.load(FILE_PATH_DATABASE + m_gameDatabase->object.fileName);
    
    // Load the biome sound database file
    cXML xmlSoundFile;
    xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);

    // Only contine if we can load all the xml files
    if ((xmlObjectFile.lineCount() > 0) && (xmlSoundFile.lineCount() > 0))
    {
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
       
        // Get object entity database count
        std::uint32_t objectCount = xmlObjectFile.getInstanceCount("<object>" + _on + " ");

        // Get object data string
        if (objectCount > 0)
        {
            std::string tObjectDataString = "";
            if (_oi == 0)
            {
                tObjectDataString = xmlObjectFile.getString("<object>" + _on, 1 + (rand() % objectCount));
            }
            else
            {
                tObjectDataString = xmlObjectFile.getString("<object>" + _on, _oi);
            }

            // Get the object entity file name
            tObjectDataString += "    ";
            std::uint64_t tObjectDataStringLength = tObjectDataString.length();
            std::string   tObjectFileName     = "";
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            if (tObjectDataStringLength > 6)
            {
                for (std::uint64_t j = 0; j < tObjectDataStringLength; ++j)
                {
                    if (tObjectDataString[j] == ' ')
                    {
                        if (tStringNum == 0)
                        {
                            ; // Object name
                        }
                        else if (tStringNum == 1)
                        {
                            tObjectFileName = tString.c_str();
                        }

                        tStringNum++;
                        tString = "";
                    }
                    else
                    {
                        tString += tObjectDataString[j];
                    }
                }
            }
            
            // Load the object entity
            tEntity = m_entityManager->load(tObjectFileName);

            // Process the entity
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
    
    // Only contine if we can load the xml files
    if ((xmlSoundFile.lineCount() > 0) && (xmlObjectFile.lineCount() > 0) && (xmlMapFile.lineCount() > 0))
    {
        // Temporary pointer
        sEntity* tEntity = nullptr;

        // Load each object from the map file
        std::uint32_t mapObjectCount = xmlMapFile.getInstanceCount("<object>");
        for (std::uint32_t i = 0; i < mapObjectCount; ++i)
        {
            std::string   tObjectString = xmlMapFile.getString("<object>", i + 1);
            tObjectString += "    ";
            std::uint64_t tObjectStringLength = tObjectString.length();
            std::uint32_t tObjectTileNum  = 0;
            std::string   tObjectName     = "";
            std::uint32_t tObjectIndex    = 0;
            float         tObjectScale    = 0.0;
            float         tObjectRotation = 0.0;
            std::uint32_t tObjectObstacle = 0;
            std::uint32_t tObjectTrigger  = 0;
            std::uint32_t tStringNum = 0;
            std::string   tString = "";
            
            std::cout << tObjectString << std::endl;
            
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
                            tObjectName = tString.c_str();
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
                        else if (tStringNum == 6)
                        {
                            tObjectTrigger  = std::stoi(tString);
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
            
            std::uint32_t w = tObjectTileNum % _map->width;
            std::uint32_t h = tObjectTileNum / _map->width;
            
            // Get object data string
            std::uint32_t objectCount = xmlObjectFile.getInstanceCount("<object>" + tObjectName + " ");
            if (objectCount > 0)
            {
                std::string tObjectDataString = "";
                if (tObjectIndex == 0)
                {
                    tObjectDataString = xmlObjectFile.getString("<object>" + tObjectName, 1 + (rand() % objectCount));
                }
                else
                {
                    tObjectDataString = xmlObjectFile.getString("<object>" + tObjectName, tObjectIndex);
                }

                // Get the object entity file name
                tObjectDataString += "    ";
                std::uint64_t tObjectDataStringLength = tObjectDataString.length();
                std::string   tObjectFileName     = "";
                std::uint32_t tStringNum = 0;
                std::string   tString = "";
                if (tObjectDataStringLength > 6)
                {
                    for (std::uint64_t j = 0; j < tObjectDataStringLength; ++j)
                    {
                        if (tObjectDataString[j] == ' ')
                        {
                            if (tStringNum == 0)
                            {
                                ; // Object name
                            }
                            else if (tStringNum == 1)
                            {
                                tObjectFileName = tString.c_str();
                            }

                            tStringNum++;
                            tString = "";
                        }
                        else
                        {
                            tString += tObjectDataString[j];
                        }
                    }
                }
                
                // Load the object entity
                tEntity = m_entityManager->load(tObjectFileName);

                // If object entity was loaded, process it
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

                    // Trigger Tile 
                    tEntity->triggerTile = tObjectTrigger;
                }
            }
        }

        // Get debris count
        uint32 debrisCount = xmlMapFile.getInstanceCount("<debris>");
        
        if (debrisCount > 0)
        {
            // Create a data structure for the debris information
            struct sDebris
            {
                std::string objectName = "";
                float       scale_min  = 0.0;
                float       scale_max  = 0.0;
                uint32      prevalence = 0;
                uint32      obstacle   = 0;
            };
            
            sDebris *debris = nullptr;
            debris = new sDebris[debrisCount];
            
            // Load the debris information from the map file into the debris data structure
            for (uint32 i = 0; i < debrisCount; ++i)
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
                                debris[i].objectName = tString;
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
                        for (uint32 i = 0; i < debrisCount; ++i)
                        {
                            if ((!pDebris) && (rInt < debris[i].prevalence))
                            {
                                pDebris = true;
                                if (debris[i].obstacle != 0)
                                {
                                    _map->tile[t].base = eTileBase::tileFloorNoGo;
                                }
                                
                                // Get object entity database count
                                std::uint32_t objectCount = xmlObjectFile.getInstanceCount("<object>" + debris[i].objectName + " ");
                               
                               // If object found
                                if (objectCount > 0)
                                {
                                    // Get object entity file name
                                    std::string objectDataString = "";
                                    objectDataString = xmlObjectFile.getString("<object>" + debris[i].objectName, 1 + (rand() % objectCount));

                                    // Get the object entity file name
                                    objectDataString += "    ";
                                    std::uint64_t tObjectDataStringLength = objectDataString.length();
                                    std::string   tObjectFileName         = "";
                                    std::uint32_t tStringNum              = 0;
                                    std::string   tString                 = "";
                                    if (tObjectDataStringLength > 6)
                                    {
                                        for (std::uint64_t j = 0; j < tObjectDataStringLength; ++j)
                                        {
                                            if (objectDataString[j] == ' ')
                                            {
                                                if (tStringNum == 0)
                                                {
                                                    ; // Object name
                                                }
                                                else if (tStringNum == 1)
                                                {
                                                    tObjectFileName = tString.c_str();
                                                }

                                                tStringNum++;
                                                tString = "";
                                            }
                                            else
                                            {
                                                tString += objectDataString[j];
                                            }
                                        }
                                    }
                                    
                                    // Load the object entity
                                    tEntity = m_entityManager->load(tObjectFileName);
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
