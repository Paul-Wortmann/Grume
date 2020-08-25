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

#ifndef MAP_MANAGER_HPP
#define MAP_MANAGER_HPP

#include "includes.hpp"
#include "defines.hpp"

#include "entity_manager.hpp"
#include "libRMG.hpp"
#include "map_defines.hpp"
#include "map_manager_tileset.hpp"
#include "xml_utils.hpp"

class cMapManager
{
    public:
        void initialize(void);
        void terminate(void);
        void process(void);
        void setEntityManagerHandle(cEntityManager *_entityManager);
        void load(const std::string &_fileName);
        void save(const std::string &_fileName);

        uint16_t getMapBiome(void)    {return m_map_boime;}
        uint16_t getMapType(void)     {return m_map_type;}
        uint16_t getMapRace(void)     {return m_map_race;}
        uint16_t getMapFunction(void) {return m_map_function;}

    protected:
    private:
        cEntityManager       *m_entityManager             = nullptr;
        cLibRMGMap            m_map                       = {};
        std::string           m_map_name                  = "";
        bool                  m_map_pcg                   = true;
        uint64_t              m_map_seed                  = 0;
        uint32_t              m_map_width                 = 100;
        uint32_t              m_map_height                = 100;
        eMapGenerator         m_map_generationAlgorithm   = eMapGenerator::mapGeneratorD2;
        eRoomConnectAlgorithm m_map_connectivityAlgorithm = eRoomConnectAlgorithm::connectND;
        eRoomShape            m_map_roomShape             = eRoomShape::roomShapeSquare;
        uint32_t              m_map_density               = 60;
        uint32_t              m_map_pass                  = 4;
        eDirection            m_map_directionBias         = eDirection::directionEast;
        uint32_t              m_map_directionBiasStrength = 6;

        eMapBiome             m_map_boime                 = eMapBiome::mapBiomeTemprate;
        eMapType              m_map_type                  = eMapType::mapTypeDungeon;
        eMapRace              m_map_race                  = eMapRace::mapRaceHuman;
        eMapFunction          m_map_function              = eMapFunction::mapFunctionDefault;

        std::string           m_map_floor_texture         = "";
        std::string           m_map_floor_shader          = "";
        std::string           m_map_tileset_fileName      = "";
        sMapTileset           m_map_tileset               = {};
};

#endif // MAP_MANAGER_HPP
