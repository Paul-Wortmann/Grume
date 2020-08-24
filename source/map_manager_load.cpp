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
    file_pointer.open (PATH_MAPS+_fileName, std::ifstream::in);
    if (!file_pointer.good())
    {
        gLogWrite(LOG_ERROR, "Unable to load map: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return;
    }
    else
    {
        gLogWrite(LOG_INFO, "Loading map: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        bool is_map_name                    = false;
        bool is_map_pcg                     = false;
        bool is_map_size_x                  = false;
        bool is_map_size_y                  = false;
        bool is_map_seed                    = false;
        bool is_map_algorithm               = false;
        bool is_map_connectivityAlgorithm   = false;
        bool is_map_roomShape               = false;
        bool is_map_density                 = false;
        bool is_map_pass                    = false;
        bool is_map_direction_bias          = false;
        bool is_map_direction_bias_strength = false;
        bool is_map_biome                   = false;
        bool is_map_type                    = false;
        bool is_map_race                    = false;
        bool is_map_function                = false;
        bool is_map_floor_texture           = false;
        bool is_map_floor_shader            = false;
        bool is_map_tileset                 = false;

        std::string s_temp = "";
        uint32_t s_temp_length = 0;

        while (std::getline(file_pointer, s_temp))
        {
            s_temp_length = s_temp.length();
            if (s_temp.find("<map_name>") < s_temp_length)
                is_map_name                = true;
            if (s_temp.find("<map_pcg>") < s_temp_length)
                is_map_pcg                 = true;
            if (s_temp.find("<map_size_x>") < s_temp_length)
                is_map_size_x              = true;
            if (s_temp.find("<map_size_y>") < s_temp_length)
                is_map_size_y              = true;
            if (s_temp.find("<map_seed>") < s_temp_length)
                is_map_seed                = true;
            if (s_temp.find("<map_algorithm>") < s_temp_length)
                is_map_algorithm               = true;
            if (s_temp.find("<map_connectivityAlgorithm>") < s_temp_length)
                is_map_connectivityAlgorithm   = true;
            if (s_temp.find("<map_roomShape>") < s_temp_length)
                is_map_roomShape               = true;
            if (s_temp.find("<map_density>") < s_temp_length)
                is_map_density                 = true;
            if (s_temp.find("<pass>") < s_temp_length)
                is_map_pass                    = true;
            if (s_temp.find("<direction_bias>") < s_temp_length)
                is_map_direction_bias          = true;
            if (s_temp.find("<direction_bias_strength>") < s_temp_length)
                is_map_direction_bias_strength = true;
            if (s_temp.find("<map_biome>") < s_temp_length)
                is_map_biome               = true;
            if (s_temp.find("<map_type>") < s_temp_length)
                is_map_type                = true;
            if (s_temp.find("<map_race>") < s_temp_length)
                is_map_race               = true;
            if (s_temp.find("<map_function>") < s_temp_length)
                is_map_function            = true;
            if (s_temp.find("<map_floor_texture>") < s_temp_length)
                is_map_floor_texture       = true;
            if (s_temp.find("<map_floor_shader>") < s_temp_length)
                is_map_floor_shader        = true;
            if (s_temp.find("<map_tileset>") < s_temp_length)
                is_map_tileset             = true;

            if ((is_map_name) ||
                (is_map_pcg) ||
                (is_map_size_x) ||
                (is_map_size_y) ||
                (is_map_seed) ||
                (is_map_algorithm) ||
                (is_map_connectivityAlgorithm) ||
                (is_map_roomShape) ||
                (is_map_density) ||
                (is_map_pass) ||
                (is_map_direction_bias) ||
                (is_map_direction_bias_strength) ||
                (is_map_biome) ||
                (is_map_type) ||
                (is_map_race) ||
                (is_map_function) ||
                (is_map_floor_texture) ||
                (is_map_floor_shader) ||
                (is_map_tileset))
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
                if (is_map_name)
                {
                    m_map_name = temp.c_str();
                    is_map_name   = false;
                }
                if (is_map_pcg)
                {
                    if (s_temp.find("1") < s_temp_length)
                        m_map_pcg = true;
                    if (s_temp.find("true") < s_temp_length)
                        m_map_pcg = true;
                    if (s_temp.find("TRUE") < s_temp_length)
                        m_map_pcg = true;
                    if (s_temp.find("0") < s_temp_length)
                        m_map_pcg = false;
                    if (s_temp.find("false") < s_temp_length)
                        m_map_pcg = false;
                    if (s_temp.find("FALSE") < s_temp_length)
                        m_map_pcg = false;
                    is_map_pcg    = false;
                }
                if (is_map_size_x)
                {
                    m_map_width  = std::stoi(temp);
                    is_map_size_x      = false;
                }
                if (is_map_size_y)
                {
                    m_map_height = std::stoi(temp);
                    is_map_size_y      = false;
                }
                if (is_map_seed)
                {
                    m_map_seed  = std::stoi(temp);
                    is_map_seed     = false;
                }
                if (is_map_algorithm)
                {
                    if (s_temp.find("RMG_GEN_C1") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorC1;
                    if (s_temp.find("RMG_GEN_C2") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorC2;
                    if (s_temp.find("RMG_GEN_D1") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorD1;
                    if (s_temp.find("RMG_GEN_D2") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorD2;
                    if (s_temp.find("RMG_GEN_M1") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorM1;
                    if (s_temp.find("RMG_GEN_T1") < s_temp_length)
                        m_map_generationAlgorithm = eMapGenerator::mapGeneratorT1;
                    is_map_algorithm = false;
                }
                if (is_map_connectivityAlgorithm)
                {
                    if (s_temp.find("RMG_PATH_SL") < s_temp_length)
                        m_map_connectivityAlgorithm = eRoomConnectAlgorithm::connectSL;
                    if (s_temp.find("RMG_PATH_ND") < s_temp_length)
                        m_map_connectivityAlgorithm = eRoomConnectAlgorithm::connectND;
                    if (s_temp.find("RMG_PATH_DW") < s_temp_length)
                        m_map_connectivityAlgorithm = eRoomConnectAlgorithm::connectDW;
                    is_map_connectivityAlgorithm = false;
                }
                if (is_map_roomShape)
                {
                    if (s_temp.find("RMG_RANDOM") < s_temp_length)
                        m_map_roomShape = eRoomShape::roomShapeRandom;
                    if (s_temp.find("RMG_CIRCLE") < s_temp_length)
                        m_map_roomShape = eRoomShape::roomShapeCircle;
                    if (s_temp.find("RMG_SQUARE") < s_temp_length)
                        m_map_roomShape = eRoomShape::roomShapeSquare;
                    is_map_roomShape = false;
                }
                if (is_map_density)
                {
                    m_map_density  = std::stoi(temp);
                    is_map_density     = false;
                }
                if (is_map_pass)
                {
                    m_map_pass  = std::stoi(temp);
                    is_map_pass     = false;
                }
                if (is_map_direction_bias)
                {
                    if (s_temp.find("RMG_NONE") < s_temp_length)
                        m_map_directionBias = eDirection::directionNone;
                    if (s_temp.find("RMG_NORTH") < s_temp_length)
                        m_map_directionBias = eDirection::directionNorth;
                    if (s_temp.find("RMG_SOUTH") < s_temp_length)
                        m_map_directionBias = eDirection::directionSouth;
                    if (s_temp.find("RMG_EAST") < s_temp_length)
                        m_map_directionBias = eDirection::directionEast;
                    if (s_temp.find("RMG_WEST") < s_temp_length)
                        m_map_directionBias = eDirection::directionWest;
                    is_map_direction_bias = false;
                }
                if (is_map_direction_bias_strength)
                {
                    m_map_directionBiasStrength  = std::stoi(temp);
                    is_map_direction_bias_strength   = false;
                }
                if (is_map_biome)
                {
                    if (s_temp.find("MAP_BIOME_DEFAULT") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeDefault;
                    if (s_temp.find("MAP_BIOME_TEMPRATE") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeTemprate;
                    if (s_temp.find("MAP_BIOME_DESERT") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeDesert;
                    if (s_temp.find("MAP_BIOME_JUNGLE") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeJungle;
                    if (s_temp.find("MAP_BIOME_VOLCANIC") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeVolcanic;
                    if (s_temp.find("MAP_BIOME_FROZEN") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeFrozen;
                    if (s_temp.find("MAP_BIOME_WET") < s_temp_length)
                        m_map_boime = eMapBiome::mapBiomeSwamp;
                    is_map_biome = false;
                }
                if (is_map_type)
                {
                    if (s_temp.find("MAP_TYPE_DEFAULT") < s_temp_length)
                        m_map_type = eMapType::mapTypeDefault;
                    if (s_temp.find("MAP_TYPE_DUNGEON") < s_temp_length)
                        m_map_type = eMapType::mapTypeDungeon;
                    if (s_temp.find("MAP_TYPE_CAVE") < s_temp_length)
                        m_map_type = eMapType::mapTypeCave;
                    if (s_temp.find("MAP_TYPE_CATACOMB") < s_temp_length)
                        m_map_type = eMapType::mapTypeCatacomb;
                    if (s_temp.find("MAP_TYPE_LAND") < s_temp_length)
                        m_map_type = eMapType::mapTypeLand;
                    is_map_type = false;
                }
                if (is_map_race)
                {
                    if (s_temp.find("MAP_RACE_DEFAULT") < s_temp_length)
                        m_map_race = eMapRace::mapRaceDefault;
                    if (s_temp.find("MAP_RACE_HUMAN") < s_temp_length)
                        m_map_race = eMapRace::mapRaceHuman;
                    if (s_temp.find("MAP_RACE_VAMPIRE") < s_temp_length)
                        m_map_race = eMapRace::mapRaceVampire;
                    if (s_temp.find("MAP_RACE_LYCAN") < s_temp_length)
                        m_map_race = eMapRace::mapRaceLycan;
                    if (s_temp.find("MAP_CLASS_ELF") < s_temp_length)
                        m_map_race = eMapRace::mapRaceElf;
                    if (s_temp.find("MAP_RACE_BEAST") < s_temp_length)
                        m_map_race = eMapRace::mapRaceBeast;
                    if (s_temp.find("MAP_RACE_DWARF") < s_temp_length)
                        m_map_race = eMapRace::mapRaceDwarf;

                    is_map_race = false;
                }
                if (is_map_function)
                {
                    if (s_temp.find("MAP_FUNCTION_DEFAULT") < s_temp_length)
                        m_map_function = eMapFunction::mapFunctionDefault;
                    if (s_temp.find("MAP_FUNCTION_NONE") < s_temp_length)
                        m_map_function = eMapFunction::mapFunctionNone;
                    if (s_temp.find("MAP_FUNCTION_PATH") < s_temp_length)
                        m_map_function = eMapFunction::mapFunctionPath;
                    if (s_temp.find("MAP_FUNCTION_TOWN") < s_temp_length)
                        m_map_function = eMapFunction::mapFunctionTown;
                    if (s_temp.find("MAP_FUNCTION_BOSS") < s_temp_length)
                        m_map_function = eMapFunction::mapFunctionBoss;
                    is_map_function = false;
                }
                if (is_map_floor_texture)
                {
                    m_map_floor_texture = temp.c_str();
                    is_map_floor_texture = false;
                }
                if (is_map_floor_shader)
                {
                    m_map_floor_shader = temp.c_str();
                    is_map_floor_shader = false;
                }
                if (is_map_tileset)
                {
                    m_map_tileset_fileName = temp.c_str();
                    is_map_tileset = false;
                }
            }
        }
        file_pointer.close();
    }

    // import tileset data from file
    std::ifstream file_tileset_pointer;
    file_tileset_pointer.open (m_map_tileset_fileName.c_str(), std::ifstream::in);
    if (!file_tileset_pointer.good())
    {
        gLogWrite(LOG_ERROR, "Unable to load map tileset file: " + m_map_tileset_fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        bool is_tileset_base_name = false;
        bool is_count_wall        = false;
        bool is_count_corner      = false;

        std::string s_temp = "";
        uint32_t s_temp_length = 0;

        while (std::getline(file_tileset_pointer, s_temp))
        {
            s_temp_length = s_temp.length();

            if (s_temp.find("<base_name>") < s_temp_length)
            {
                is_tileset_base_name  = true;
            }
            if (s_temp.find("<count_wall>") < s_temp_length)
            {            
                is_count_wall = true;
            }
            if (s_temp.find("<count_corner>") < s_temp_length)
            {
                is_count_corner = true;
            }
            if ((is_tileset_base_name) ||
                (is_count_wall) ||
                (is_count_corner))
            {
                bool        ready   = false;
                std::string temp    = "";
                for (uint64_t i = 0; i < s_temp.length(); i++)
                {
                    if (!ready)
                    {
                        if (s_temp[i] == '>')
                        {
                            ready = true;
                        }
                    }
                    else
                    {
                        if (s_temp[i] == '<')
                        {
                            ready = false;
                        }
                        else
                        {
                            temp += s_temp[i];
                        }
                    }
                }
                if (is_tileset_base_name)
                {
                    m_map_tileset.base_name = temp.c_str();
                    is_tileset_base_name    = false;
                }
                if (is_count_wall)
                {
                    m_map_tileset.count_wall = std::stoi(temp);
                    is_count_wall            = false;
                }
                if (is_count_corner)
                {
                    m_map_tileset.count_corner = std::stoi(temp);
                    is_count_corner            = false;
                }
            }
        }
        file_tileset_pointer.close();
    }

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
        m_map_name = "genmesh_" + std::to_string(m_map_width) + "x" + std::to_string(m_map_height);
        m_map.data.name = m_map_name;
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
        m_map.data.name = m_map_name;
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
