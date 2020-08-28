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

void cMapManager::load(const std::string &_fileName)
{
    // import map data from file
    std::ifstream file_pointer;
    file_pointer.open (PATH_MAPS + _fileName, std::ifstream::in);
    if (!file_pointer.good())
    {
        gLogWrite(LOG_ERROR, "Unable to load map: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    else
    {
        gLogWrite(LOG_INFO, "Loading map: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        
        std::string data = "";
        
        while (std::getline(file_pointer, data))
        {
            // Extract the name of the map
            if (xmlFind(data, "<map_name>"))
            {
                m_map.data.name = xmlGetDataString(data);
            }

            // Extract the the tileset file name
            else if (xmlFind(data, "<map_tileset>"))
            {
                m_tileset_fileName = xmlGetDataString(data);
            }

            // Extract the dimentions of the map, in tiles
            else if (xmlFind(data, "<map_size"))
            {
                m_map.data.tile_x = xmlGetIntegerValue(data, "x");
                m_map.data.tile_y = xmlGetIntegerValue(data, "y");
            }

            // Extract information regarding the generation algorithm and seed
            else if (xmlFind(data, "<map_generation"))
            {
                // Seed
                m_map.data.seed = xmlGetIntegerValue(data, "seed");
                
                // Generation algorithm
                std::string tString = xmlGetDataValue(data, "algorithm");

                if (xmlFind(tString, "RMG_GEN_C1"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorC1;
                }
                else if (xmlFind(tString, "RMG_GEN_C2"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorC2;
                }
                else if (xmlFind(tString, "RMG_GEN_D1"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorD1;
                }
                else if (xmlFind(tString, "RMG_GEN_D2"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorD2;
                }
                else if (xmlFind(tString, "RMG_GEN_M1"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorM1;
                }
                else if (xmlFind(tString, "RMG_GEN_T1"))
                {
                    m_map.data.generator = eMapGenerator::mapGeneratorT1;
                }
            }
            
            // Extract the connectivity algorithm
            else if (xmlFind(data, "<map_connectivity"))
            {
                // Connectivity algorithm
                std::string tString = xmlGetDataValue(data, "algorithm");

                if (xmlFind(tString, "RMG_PATH_SL"))
                {
                    m_map.data.connect_algorithm = eRoomConnectAlgorithm::connectSL;
                }
                else if (xmlFind(tString, "RMG_PATH_ND"))
                {
                    m_map.data.connect_algorithm = eRoomConnectAlgorithm::connectND;
                }
                else if (xmlFind(tString, "RMG_PATH_DW"))
                {
                    m_map.data.connect_algorithm = eRoomConnectAlgorithm::connectDW;
                }
            }
            
            // Extract the room shape
            else if (xmlFind(data, "<map_room"))
            {
                // Room shape
                std::string tString = xmlGetDataValue(data, "shape");

                if (xmlFind(tString, "RMG_ROOM_RANDOM"))
                {
                    m_map.data.room_shape = eRoomShape::roomShapeRandom;
                }
                else if (xmlFind(tString, "RMG_ROOM_CIRCLE"))
                {
                    m_map.data.room_shape = eRoomShape::roomShapeCircle;
                }
                else if (xmlFind(tString, "RMG_ROOM_SQUARE"))
                {
                    m_map.data.room_shape = eRoomShape::roomShapeSquare;
                }
            }
            
            // Extract the map max density
            else if (xmlFind(data, "<map_density>"))
            {
                m_map.data.density = std::stoi(xmlGetDataString(data));
            }
            
            // Extract the map max itteration count 
            else if (xmlFind(data, "<map_itterate>"))
            {
                m_map.data.maxItterations = std::stoi(xmlGetDataString(data));
            }
            
            // Extract the direction data
            else if (xmlFind(data, "<map_direction"))
            {
                // Direction bias strength
                m_map.data.direction_biasStrength = xmlGetIntegerValue(data, "strength");

                // Direction bias
                std::string tString = xmlGetDataValue(data, "bias");

                if (xmlFind(tString, "RMG_DIRECTION_NONE"))
                {
                    m_map.data.direction_bias = eDirection::directionNone;
                }
                else if (xmlFind(tString, "RMG_DIRECTION_NORTH"))
                {
                    m_map.data.direction_bias = eDirection::directionNorth;
                }
                else if (xmlFind(tString, "RMG_DIRECTION_SOUTH"))
                {
                    m_map.data.direction_bias = eDirection::directionSouth;
                }
                else if (xmlFind(tString, "RMG_DIRECTION_EAST"))
                {
                    m_map.data.direction_bias = eDirection::directionEast;
                }
                else if (xmlFind(tString, "RMG_DIRECTION_WEST"))
                {
                    m_map.data.direction_bias = eDirection::directionWest;
                }
            }
            
            // Extract the map function
            else if (xmlFind(data, "<map_function>"))
            {
                // Map function
                std::string tString = xmlGetDataString(data);

                if (xmlFind(tString, "MAP_FUNCTION_DEFAULT"))
                {
                    m_map.data.function = eMapFunction::mapFunctionDefault;
                }
                else if (xmlFind(tString, "MAP_FUNCTION_NONE"))
                {
                    m_map.data.function = eMapFunction::mapFunctionNone;
                }
                else if (xmlFind(tString, "MAP_FUNCTION_PATH"))
                {
                    m_map.data.function = eMapFunction::mapFunctionPath;
                }
                else if (xmlFind(tString, "MAP_FUNCTION_TOWN"))
                {
                    m_map.data.function = eMapFunction::mapFunctionTown;
                }
                else if (xmlFind(tString, "MAP_FUNCTION_BOSS"))
                {
                    m_map.data.function = eMapFunction::mapFunctionBoss;
                }
            }
        }
        file_pointer.close();
    }

    // import tileset data from file
    std::ifstream file_tileset_pointer;
    file_tileset_pointer.open (PATH_TILESETS + m_tileset_fileName, std::ifstream::in);
    if (!file_tileset_pointer.good())
    {
        gLogWrite(LOG_ERROR, "Unable to load map tileset file: " + m_tileset_fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        gLogWrite(LOG_INFO, "Loading tileset: " + m_tileset_fileName, __FILE__, __LINE__, __FUNCTION__);

        std::string data = "";
        
        while (std::getline(file_pointer, data))
        {
            // Extract the name of the tileset
            if (xmlFind(data, "<tileset_name>"))
            {
                m_tileset.name = xmlGetDataString(data);
            }

            // Extract the music file name
            else if (xmlFind(data, "<tileset_music>"))
            {
                m_tileset.music = xmlGetDataString(data);
            }

            // Extract the biome
            else if (xmlFind(data, "<tileset_biome>"))
            {
                // Tileset biome
                std::string tString = xmlGetDataString(data);

                if (xmlFind(tString, "MAP_BIOME_DEFAULT"))
                {
                    m_tileset.biome = eMapBiome::mapBiomeDefault;
                }
                else if (xmlFind(tString, "MAP_BIOME_TEMPRATE"))
                {
                    m_tileset.biome = eMapBiome::mapBiomeTemprate;
                }

//got up to here, add the rest of the biomes and continue
                else if (xmlFind(tString, "MAP_BIOME_TEMPRATE"))
                {
                    m_tileset.biome = eMapBiome::mapBiomeTemprate;
                }


                
            }

/*
enum eMapBiome:uint16_t             { mapBiomeDefault = 0, mapBiomeTemprate = 1, mapBiomeDesert = 2, mapBiomeJungle = 3, mapBiomeVolcanic = 4, mapBiomeFrozen = 5, mapBiomeSwamp = 6 };
enum eMapType:uint16_t              { mapTypeDefault = 0, mapTypeDungeon = 1, mapTypeCave = 2, mapTypeCatacomb = 3, mapTypeLand = 4 };
enum eMapRace:uint16_t              { mapRaceDefault = 0, mapRaceHuman = 1, mapRaceVampire = 2, mapRaceLycan = 3, mapRaceElf = 4, mapRaceBeast = 5, mapRaceDwarf = 6 };
*/


        }
        file_tileset_pointer.close();
    }
    
    
    
    
    
/*
    if (m_map_pcg)
    {
        // Gen map
        m_map.data.generator = m_map_generationAlgorithm;
        m_map.data.connect_algorithm = m_map_connectivityAlgorithm;
        m_map.data.room_shape = m_map_roomShape;
        m_map.data.tile_x = m_map_width;
        m_map.data.tile_y = m_map_height;
        m_map.data.density = m_map_density;
        m_map.data.maxItterations = m_map_pass;
        m_map.data.direction_bias = m_map_directionBias;
        m_map.data.direction_biasStrength = m_map_directionBiasStrength;
        m_map.data.seed = m_map_seed;
        m_map.data.name = "genmesh_" + std::to_string(m_map_width) + "x" + std::to_string(m_map_height);
        m_map.generate();
    }
    else
    {
        // Load map from file.
        srand (m_map.data.seed);
        if (m_map.data.tile != nullptr)
        {
            m_map.free();
        }
        m_map.init();
        m_map.data.generator = m_map_generationAlgorithm;
        m_map.data.connect_algorithm = m_map_connectivityAlgorithm;
        m_map.data.room_shape = m_map_roomShape;
        m_map.data.tile_x = m_map_width;
        m_map.data.tile_y = m_map_height;
        m_map.data.density = m_map_density;
        m_map.data.maxItterations = m_map_pass;
        m_map.data.direction_bias = m_map_directionBias;
        m_map.data.direction_biasStrength = m_map_directionBiasStrength;
        m_map.data.seed = m_map_seed;
        m_map.data.tile_count = m_map.data.tile_x * m_map.data.tile_y;
        m_map.data.tile = new sLibRMGMapTile[m_map.data.tile_count];
        // import map data from file
        std::ifstream file_pointer;
        file_pointer.open (_fileName, std::ifstream::in);
        if (!file_pointer.good())
        {
            gLogWrite(LOG_ERROR, "ERROR -> importing map file  :  " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        }
        else
        {
            bool is_map_tile       = false;
            bool is_map_room_count = false;
            bool is_map_room       = false;
            uint32_t roomNumber    = 0;
            uint32_t tileNumber    = 0;

            std::string s_temp = "";
            uint32_t s_temp_length = 0;

            while (std::getline(file_pointer, s_temp))
            {
                s_temp_length = s_temp.length();

                if (s_temp.find("<map_tile>") < s_temp_length)
                    is_map_tile  = true;
                if (s_temp.find("<map_room_count>") < s_temp_length)
                    is_map_room_count = true;
                if ((s_temp.find("<map_room>") < s_temp_length) && (!is_map_room_count))
                    is_map_room = true;

                // room count
                if (is_map_room_count)
                {
                    bool        ready   = false;
                    std::string temp    = "";
                    for (uint64_t i = 0; i < s_temp.length(); i++)
                    {
                        if (!ready)
                        {
                            if (s_temp[i] == '>')
                                ready = true;
                        }
                        else
                        {
                            if (s_temp[i] == '<')
                                ready = false;
                            else
                                temp += s_temp[i];
                        }
                    }
                    m_map.data.room_count   = std::stoi(temp);
                    m_map.data.room   = new sLibRMGMapRoom[m_map.data.room_count];
                    is_map_room_count = false;
                }

                // map tile
                if (is_map_tile)
                {
                    uint32_t    value_1 = 0;
                    uint32_t    value_2 = 0;
                    uint32_t    value_3 = 0;
                    uint32_t    value_4 = 0;
                    uint32_t    value_5 = 0;
                    uint32_t    value_6 = 0;
                    uint16_t    sCount  = 0;
                    bool        ready   = false;
                    std::string temp    = "";
                    for (uint64_t i = 0; i < s_temp.length(); i++)
                    {
                        if (!ready)
                        {
                            if (s_temp[i] == '>')
                                ready = true;
                        }
                        else
                        {
                            if ((s_temp[i] == ' ') || (s_temp[i] == ','))
                            {
                                sCount++;
                                if (sCount == 1)
                                    value_1 = std::stoi(temp);
                                if (sCount == 2)
                                    value_2 = std::stoi(temp);
                                if (sCount == 3)
                                    value_3 = std::stoi(temp);
                                if (sCount == 4)
                                    value_4 = std::stoi(temp);
                                if (sCount == 5)
                                    value_5 = std::stoi(temp);
                                if (sCount == 6)
                                    value_6 = std::stoi(temp);
                                temp = "";
                            }
                            else
                                temp += s_temp[i];
                            if (s_temp[i] == '<')
                            {
                                ready = false;
                                value_6 = std::stoi(temp);
                            }
                        }
                    }
                    m_map.data.tile[tileNumber].base     = static_cast<eBase>(value_1);
                    m_map.data.tile[tileNumber].objectID = value_2;
                    m_map.data.tile[tileNumber].eventID  = value_3;
                    m_map.data.tile[tileNumber].roomID   = value_4;
                    m_map.data.tile[tileNumber].x        = value_5;
                    m_map.data.tile[tileNumber].y        = value_6;
                    is_map_tile = false;
                    tileNumber++;
                }
                // map room
                if (is_map_room)
                {
                    uint32_t    value_1  = 0;
                    uint32_t    value_2  = 0;
                    uint32_t    value_3  = 0;
                    uint32_t    value_4  = 0;
                    uint32_t    value_5  = 0;
                    uint32_t    value_6  = 0;
                    uint32_t    value_7  = 0;
                    uint32_t    value_8  = 0;
                    uint32_t    value_9  = 0;
                    uint32_t    value_10 = 0;
                    uint32_t    value_11 = 0;
                    uint32_t    value_12 = 0;
                    uint32_t    value_13 = 0;
                    uint16_t    sCount   = 0;
                    bool        ready    = false;
                    std::string temp     = "";
                    for (uint64_t i = 0; i < s_temp.length(); i++)
                    {
                        if (!ready)
                        {
                            if (s_temp[i] == '>')
                                ready = true;
                        }
                        else
                        {
                            if ((s_temp[i] == ' ') || (s_temp[i] == ','))
                            {
                                sCount++;
                                if (sCount == 1)
                                    value_1  = std::stoi(temp);
                                if (sCount == 2)
                                    value_2  = std::stoi(temp);
                                if (sCount == 3)
                                    value_3  = std::stoi(temp);
                                if (sCount == 4)
                                    value_4  = std::stoi(temp);
                                if (sCount == 5)
                                    value_5  = std::stoi(temp);
                                if (sCount == 6)
                                    value_6  = std::stoi(temp);
                                if (sCount == 7)
                                    value_7  = std::stoi(temp);
                                if (sCount == 8)
                                    value_8  = std::stoi(temp);
                                if (sCount == 9)
                                    value_9  = std::stoi(temp);
                                if (sCount == 10)
                                    value_10 = std::stoi(temp);
                                if (sCount == 11)
                                    value_11 = std::stoi(temp);
                                if (sCount == 12)
                                    value_12 = std::stoi(temp);
                                if (sCount == 13)
                                    value_13 = std::stoi(temp);
                                temp = "";
                            }
                            else
                                temp += s_temp[i];
                            if (s_temp[i] == '<')
                            {
                                ready    = false;
                                value_13 = std::stoi(temp);
                            }
                        }
                    }
                    m_map.data.room[roomNumber].type    = static_cast<eRoomFunction>(value_1);
                    m_map.data.room[roomNumber].posXMin = value_2;
                    m_map.data.room[roomNumber].posXMax = value_3;
                    m_map.data.room[roomNumber].posYMin = value_4;
                    m_map.data.room[roomNumber].posYMax = value_5;
                    m_map.data.room[roomNumber].x       = value_6;
                    m_map.data.room[roomNumber].y       = value_7;
                    m_map.data.room[roomNumber].w       = value_8;
                    m_map.data.room[roomNumber].h       = value_9;
                    m_map.data.room[roomNumber].exitN   = value_10;
                    m_map.data.room[roomNumber].exitS   = value_11;
                    m_map.data.room[roomNumber].exitE   = value_12;
                    m_map.data.room[roomNumber].exitW   = value_13;
                    is_map_room = false;
                    roomNumber++;
                }
            }
            file_pointer.close();
        }
    }
        // test
        //std::cout << " --- debug --- saving file..." << std::endl;
        //save("debug_save.xml");

    // Apply tile set
    for (uint64_t i = 0; i < m_map.data.tile_count; i++)
        m_map.data.tile[i].c = false;

    sEntity* entity = m_entityManager->getNew();
    m_entityManager->addComponentGraphics(entity);
    m_entityManager->addComponentPhysics(entity);
    
    m_entityManager->setScale(entity, 1.0f, 1.0f, 1.0f);
    m_entityManager->setPosition(entity, 0.0f, 0.0f, 0.0f);
    m_entityManager->setRotation(entity, 0.0f, 0.0f, 0.0f);

    sEntityModelGeneratorInfo info;
    info.name    = "map_floor";
    info.units_x = m_map_width;
    info.units_y = m_map_height;
    m_entityManager->generateModel(entity, info, m_map_floor_texture);
*/
/*
    float pi_p =  3.141592654f;

    for (uint32_t i = 0; i < m_map.data.tile_y; i++)
    {
        for (uint32_t j = 0; j < m_map.data.tile_x; j++)
        {
            // base layer
            if (!m_map.data.tile[(i * m_map.data.tile_x) + j].c)
            {
                if (m_map.data.tile[(i * m_map.data.tile_x) + j].base == eBase::baseWall)
                {
                    // border corners
                    if ((i == 0) && (j == 0))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i == (m_map.data.tile_y-1)) && (j == 0))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i == 0) && (j == (m_map.data.tile_x-1)))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i == (m_map.data.tile_y-1)) && (j == (m_map.data.tile_x-1)))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    // border walls
                    else if ((i == (m_map.data.tile_y-1)) && (j > 0)&& (j < (m_map.data.tile_x-1)))
                    {
                        if (m_map.tile[((i-1) * m_map.data.tile_x) + j].basease == eBase::baseFloor)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        else if (m_map.tile[((i-1) * m_map.data.tile_x) + j].basease == eBase::baseWall)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i > 0) && (i < (m_map.data.tile_y-1)) && (j == (m_map.data.tile_x-1)))
                    {
                        if (m_map.tile[(i * m_map.data.tile_x) + j - 1].base == eBase::baseFloor)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p / 2.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        else if (m_map.tile[(i * m_map.data.tile_x) + j - 1].base == eBase::baseWall)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.5f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i == 0) && (j > 0)&& (j < (m_map.data.tile_x-1)))
                    {
                        if (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        else if (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((i > 0) && (i < (m_map.data.tile_y-1)) && (j == 0))
                    {
                        if (m_map.tile[(i * m_map.data.tile_x) + j + 1].base == eBase::baseFloor)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p / 2.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        else if (m_map.tile[(i * m_map.data.tile_x) + j + 1].base == eBase::baseWall)
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                }
            }
        }
    }
    for (uint32_t i = 2; i < m_map.data.tile_y-2; i++)
    {
        for (uint32_t j = 2; j < m_map.data.tile_x-2; j++)
        {
            // base layer
            if (!m_map.tile[(i * m_map.data.tile_x) + j].c)
            {
                if (m_map.tile[(i * m_map.data.tile_x) + j].base == eBase::baseWall)
                {
                    // blocks find supported areas for 3 wide wall features.
                    // walls
                    if ((rand() % 1000) > 860)
                    {
                        if ((!m_map.tile[(i * m_map.data.tile_x) + j].c) &&
                            (!m_map.tile[(i * m_map.data.tile_x) + j+1].c) &&
                            (!m_map.tile[(i * m_map.data.tile_x) + j-1].c) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j-1].base == eBase::baseFloor) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j-1].base == eBase::baseFloor) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j+2].base == eBase::baseWall) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j-2].base == eBase::baseWall))
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_31.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                            m_map.tile[(i * m_map.data.tile_x) + j].c   = true;
                            m_map.tile[(i * m_map.data.tile_x) + j+1].c = true;
                            m_map.tile[(i * m_map.data.tile_x) + j-1].c = true;
                        }
                    }
                    if ((rand() % 1000) > 860)
                    {
                        if ((!m_map.tile[(i * m_map.data.tile_x) + j].c) &&
                            (!m_map.tile[((i+1) * m_map.data.tile_x) + j].c) &&
                            (!m_map.tile[((i-1) * m_map.data.tile_x) + j].c) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                            (m_map.tile[((i+2) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                            (m_map.tile[((i-2) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                            (m_map.tile[((i+1) * m_map.data.tile_x) + j-1].base == eBase::baseFloor) &&
                            (m_map.tile[((i-1) * m_map.data.tile_x) + j-1].base == eBase::baseFloor) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                            (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                        {
                            entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_31.xml"), _entityManager);
                            _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                            m_map.tile[(i * m_map.data.tile_x) + j].c     = true;
                            m_map.tile[((i+1) * m_map.data.tile_x) + j].c = true;
                            m_map.tile[((i-1) * m_map.data.tile_x) + j].c = true;
                        }
                    }
                }
            }
        }
    }
    for (uint32_t i = 0; i < m_map.data.tile_y; i++)
    {
        for (uint32_t j = 0; j < m_map.data.tile_x; j++)
        {
            // base layer
            if (!m_map.tile[(i * m_map.data.tile_x) + j].c)
            {
                if (m_map.tile[(i * m_map.data.tile_x) + j].base == eBase::baseWall)
                {
                    if ((!m_map.tile[(i * m_map.data.tile_x) + j].c) &&
                        (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                        (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                        (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                        (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((!m_map.tile[(i * m_map.data.tile_x) + j].c) &&
                             (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    // wall x junction
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_x_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    // wall t junctions
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_t_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    // wall corners
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_c_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    // wall end points
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_e_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_e_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_e_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 0.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_e_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    //pillar
                    else if ((m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseFloor) &&
                             (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseFloor))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_p_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                    else
                    {
                        std::cout << "Map tile apply error -> unsupported edge case found." << std::endl;
                        //entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_w_1.xml"), _entityManager);
                        //_entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        //_entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        //m_map.tile[(i * m_map.data.tile_x) + j].c = true;
                    }
                }
                if (m_map.tile[(i * m_map.data.tile_x) + j].base == eBase::baseFloor)
                {
                    // arch / doorway
                    if ((m_map.tile[(i * m_map.data.tile_x) + j].base   == eBase::baseFloor) &&
                        (m_map.tile[(i * m_map.data.tile_x) + j+1].base == eBase::baseWall) &&
                        (m_map.tile[(i * m_map.data.tile_x) + j-1].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_a_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, 0.0f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                    }
                    else if ((m_map.tile[(i * m_map.data.tile_x) + j].base   == eBase::baseFloor) &&
                        (m_map.tile[((i+1) * m_map.data.tile_x) + j].base == eBase::baseWall) &&
                        (m_map.tile[((i-1) * m_map.data.tile_x) + j].base == eBase::baseWall))
                    {
                        entity = loadEntity("data/map/" + m_map_tileset.base_name + "/" + m_map_tileset.base_name + std::string("_a_1.xml"), _entityManager);
                        _entityManager.setTransformRotation(entity, glm::vec3(0.0f, pi_p * 1.5f, 0.0f));
                        _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                    }
                    //objects
                    else
                    {
                        uint32_t rNum = rand() % 1000;
                        if ((rNum) > 978)
                        {
                            if (rNum == 979)
                                entity = loadEntity("data/map/monsters/monster_skeleton_001.xml", _entityManager);
                            if (rNum == 980)
                                entity = loadEntity("data/map/objects/object_chest_1.xml", _entityManager);
                            if (rNum == 981)
                                entity = loadEntity("data/map/objects/object_crate_1.xml", _entityManager);
                            if (rNum == 982)
                                entity = loadEntity("data/map/objects/object_crate_2.xml", _entityManager);
                            if (rNum == 983)
                                entity = loadEntity("data/map/objects/object_crystal_blue_1.xml", _entityManager);
                            if (rNum == 984)
                                entity = loadEntity("data/map/objects/object_crystal_blue_2.xml", _entityManager);
                            if (rNum == 985)
                                entity = loadEntity("data/map/objects/object_crystal_blue_3.xml", _entityManager);
                            if (rNum == 986)
                                entity = loadEntity("data/map/objects/object_crystal_blue_4.xml", _entityManager);
                            if (rNum == 987)
                                entity = loadEntity("data/map/objects/object_crystal_blue_5.xml", _entityManager);
                            if (rNum == 988)
                                entity = loadEntity("data/map/objects/object_crystal_blue_6.xml", _entityManager);
                            if (rNum == 989)
                                entity = loadEntity("data/map/objects/object_crystal_blue_7.xml", _entityManager);
                            if (rNum == 990)
                                entity = loadEntity("data/map/objects/object_crystal_blue_8.xml", _entityManager);
                            if (rNum == 991)
                                entity = loadEntity("data/map/objects/object_crystal_blue_9.xml", _entityManager);
                            if (rNum == 992)
                                entity = loadEntity("data/map/objects/object_crystal_blue_10.xml", _entityManager);
                            if (rNum == 993)
                                entity = loadEntity("data/map/objects/object_crystal_blue_11.xml", _entityManager);
                            if (rNum == 994)
                                entity = loadEntity("data/map/objects/object_crystal_blue_12.xml", _entityManager);
                            if (rNum == 995)
                                entity = loadEntity("data/map/objects/object_crystal_blue_13.xml", _entityManager);
                            if (rNum == 996)
                                entity = loadEntity("data/map/objects/object_crystal_blue_14.xml", _entityManager);
                            if (rNum == 997)
                                entity = loadEntity("data/map/objects/object_crystal_blue_15.xml", _entityManager);
                            if (rNum == 998)
                                entity = loadEntity("data/map/objects/object_crystal_blue_16.xml", _entityManager);
                            if (rNum == 999)
                                entity = loadEntity("data/map/objects/object_crystal_green_1.xml", _entityManager);
                            if (entity != nullptr)
                            _entityManager.setTransformPosition(entity, glm::vec3(((j) * 2.0f) - m_map_width, 0.0f, ((i) * 2.0f) - m_map_height));
                        }
                    }
                }
            }
        }
    }
*/
}
