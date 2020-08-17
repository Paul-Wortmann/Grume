
#include "map_manager.hpp"

void cMapManager::save(const std::string &_fileName)
{
    // export map data to file
    std::ofstream file_pointer;
    file_pointer.open (_fileName, std::ifstream::out);
    if (!file_pointer.good())
        gLogWrite(LOG_ERROR, "ERROR -> saving map file  :  " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    else
    {
        file_pointer << "<map>" << std::endl;
        file_pointer << "   <map_name>" << m_map_name << "</map_name>" << std::endl;
        if (m_map_pcg)
            file_pointer << "   <map_pcg>true</map_pcg>" << std::endl;
        else
            file_pointer << "   <map_pcg>false</map_pcg>" << std::endl;
        file_pointer << "   <map_size_x>" << m_map_width << "</map_size_x>" << std::endl;
        file_pointer << "   <map_size_y>" << m_map_height << "</map_size_y>" << std::endl;
        file_pointer << "   <map_seed>" << m_map_seed << "</map_seed>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorC1)
            file_pointer << "   <map_algorithm>RMG_GEN_C1</map_algorithm>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorC2)
            file_pointer << "   <map_algorithm>RMG_GEN_C2</map_algorithm>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorD1)
            file_pointer << "   <map_algorithm>RMG_GEN_D1</map_algorithm>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorD2)
            file_pointer << "   <map_algorithm>RMG_GEN_D2</map_algorithm>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorM1)
            file_pointer << "   <map_algorithm>RMG_GEN_M1</map_algorithm>" << std::endl;
        if (m_map_generationAlgorithm == eMapGenerator::mapGeneratorT1)
            file_pointer << "   <map_algorithm>RMG_GEN_T1</map_algorithm>" << std::endl;
        if (m_map_connectivityAlgorithm == eRoomConnectAlgorithm::connectSL)
            file_pointer << "   <map_connectivityAlgorithm>RMG_PATH_SL</map_connectivityAlgorithm>" << std::endl;
        if (m_map_connectivityAlgorithm == eRoomConnectAlgorithm::connectND)
            file_pointer << "   <map_connectivityAlgorithm>RMG_PATH_ND</map_connectivityAlgorithm>" << std::endl;
        if (m_map_connectivityAlgorithm == eRoomConnectAlgorithm::connectDW)
            file_pointer << "   <map_connectivityAlgorithm>RMG_PATH_DW</map_connectivityAlgorithm>" << std::endl;
        if (m_map_roomShape == eRoomShape::roomShapeRandom)
            file_pointer << "   <map_roomShape>RMG_RANDOM</map_roomShape>" << std::endl;
        if (m_map_roomShape == eRoomShape::roomShapeCircle)
            file_pointer << "   <map_roomShape>RMG_CIRCLE</map_roomShape>" << std::endl;
        if (m_map_roomShape == eRoomShape::roomShapeSquare)
            file_pointer << "   <map_roomShape>RMG_SQUARE</map_roomShape>" << std::endl;
        file_pointer << "   <map_density>" << m_map_density << "</map_density>" << std::endl;
        file_pointer << "   <map_pass>" << m_map_pass << "</map_pass>" << std::endl;
        if (m_map_directionBias == eDirection::directionNone)
            file_pointer << "   <map_direction_bias>RMG_NONE</map_direction_bias>" << std::endl;
        if (m_map_directionBias == eDirection::directionNorth)
            file_pointer << "   <map_direction_bias>RMG_NORTH</map_direction_bias>" << std::endl;
        if (m_map_directionBias == eDirection::directionSouth)
            file_pointer << "   <map_direction_bias>RMG_SOUTH</map_direction_bias>" << std::endl;
        if (m_map_directionBias == eDirection::directionEast)
            file_pointer << "   <map_direction_bias>RMG_EAST</map_direction_bias>" << std::endl;
        if (m_map_directionBias == eDirection::directionWest)
            file_pointer << "   <map_direction_bias>RMG_WEST</map_direction_bias>" << std::endl;
        file_pointer << "   <map_direction_bias_strength>" << m_map_directionBiasStrength << "</map_direction_bias_strength>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeDefault)
            file_pointer << "   <map_biome>MAP_BIOME_DEFAULT</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeTemprate)
            file_pointer << "   <map_biome>MAP_BIOME_TEMPRATE</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeDesert)
            file_pointer << "   <map_biome>MAP_BIOME_DESERT</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeJungle)
            file_pointer << "   <map_biome>MAP_BIOME_JUNGLE</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeVolcanic)
            file_pointer << "   <map_biome>MAP_BIOME_VOLCANIC</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeFrozen)
            file_pointer << "   <map_biome>MAP_BIOME_FROZEN</map_biome>" << std::endl;
        if (m_map_boime == eMapBiome::mapBiomeSwamp)
            file_pointer << "   <map_biome>MAP_BIOME_WET</map_biome>" << std::endl;
        if (m_map_type == eMapType::mapTypeDefault)
            file_pointer << "   <map_type>MAP_TYPE_DEFAULT</map_type>" << std::endl;
        if (m_map_type == eMapType::mapTypeDungeon)
            file_pointer << "   <map_type>MAP_TYPE_DUNGEON</map_type>" << std::endl;
        if (m_map_type == eMapType::mapTypeCave)
            file_pointer << "   <map_type>MAP_TYPE_CAVE</map_type>" << std::endl;
        if (m_map_type == eMapType::mapTypeCatacomb)
            file_pointer << "   <map_type>MAP_TYPE_CATACOMB</map_type>" << std::endl;
        if (m_map_type == eMapType::mapTypeLand)
            file_pointer << "   <map_type>MAP_TYPE_LAND</map_type>" << std::endl;
        if (m_map_race == eMapRace::mapRaceDefault)
            file_pointer << "   <map_race>MAP_RACE</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceHuman)
            file_pointer << "   <map_race>MAP_RACE_HUMAN</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceVampire)
            file_pointer << "   <map_race>MAP_RACE_VAMPIRE</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceLycan)
            file_pointer << "   <map_race>MAP_RACE_LYCAN</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceElf)
            file_pointer << "   <map_race>MAP_RACE_ELF</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceBeast)
            file_pointer << "   <map_race>MAP_RACE_BEAST</map_race>" << std::endl;
        if (m_map_race == eMapRace::mapRaceDwarf)
            file_pointer << "   <map_race>MAP_RACE_DWARF</map_race>" << std::endl;
        if (m_map_function == eMapFunction::mapFunctionDefault)
            file_pointer << "   <map_function>MAP_FUNCTION</map_function>" << std::endl;
        if (m_map_function == eMapFunction::mapFunctionNone)
            file_pointer << "   <map_function>MAP_FUNCTION_NONE</map_function>" << std::endl;
        if (m_map_function == eMapFunction::mapFunctionPath)
            file_pointer << "   <map_function>MAP_FUNCTION_PATH</map_function>" << std::endl;
        if (m_map_function == eMapFunction::mapFunctionTown)
            file_pointer << "   <map_function>MAP_FUNCTION_TOWN</map_function>" << std::endl;
        if (m_map_function == eMapFunction::mapFunctionBoss)
            file_pointer << "   <map_function>MAP_FUNCTION_BOSS</map_function>" << std::endl;
        file_pointer << "   <map_floor_texture>" << m_map_floor_texture.c_str() << "</map_floor_texture>" << std::endl;
        file_pointer << "   <map_floor_shader>" << m_map_floor_shader.c_str() << "</map_floor_shader>" << std::endl;
        file_pointer << "   <map_tileset>" << m_map_tileset_fileName.c_str() << "</map_tileset>" << std::endl;

        // Non PCG map
        if (m_map_pcg == false)
        {
            file_pointer << "   <map_tiles>" << std::endl;
            file_pointer << "      <map_tile_count>" << m_map.data.tile_count << "</map_tile_count>" << std::endl;
            uint64_t mapSize = m_map_width * m_map_height;
            for (uint64_t i = 0; i < mapSize; i++)
            {
                file_pointer << "      <map_tile>"
                             << static_cast<uint16_t>(m_map.data.tile[i].base) << ","
                             << m_map.data.tile[i].objectID << ","
                             << m_map.data.tile[i].eventID << ","
                             << m_map.data.tile[i].roomID << ","
                             << m_map.data.tile[i].x << ","
                             << m_map.data.tile[i].y
                             << "</map_tile>" << std::endl;
            }
            file_pointer << "   </map_tiles>" << std::endl;
            file_pointer << "   <map_rooms>" << std::endl;
            file_pointer << "      <map_room_count>" << m_map.data.room_count << "</map_room_count>" << std::endl;
            for (uint64_t i = 0; i < m_map.data.room_count; i++)
            {
                file_pointer << "      <map_room>"
                             << static_cast<uint16_t>(m_map.data.room[i].type) << ","
                             << m_map.data.room[i].posXMin << ","
                             << m_map.data.room[i].posXMax << ","
                             << m_map.data.room[i].posYMin << ","
                             << m_map.data.room[i].posYMax << ","
                             << m_map.data.room[i].x << ","
                             << m_map.data.room[i].y << ","
                             << m_map.data.room[i].w << ","
                             << m_map.data.room[i].h << ","
                             << m_map.data.room[i].exitN << ","
                             << m_map.data.room[i].exitS << ","
                             << m_map.data.room[i].exitE << ","
                             << m_map.data.room[i].exitW
                             << "</map_room>" << std::endl;
            }
            file_pointer << "   </map_rooms>" << std::endl;
        }
        file_pointer << "</map>" << std::endl;
        file_pointer.close();
    }
}
