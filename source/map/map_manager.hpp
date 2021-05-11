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

//#pragma pack(pop)

#include "../audio/audio_manager.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../graphics/graphics_engine_utils.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "../player/player_manager.hpp"
#include "biome_manager.hpp"
#include "map_define.hpp"

class cMapManager : public tcLinkedList<sMap>
{
    public:
        // map_manager.cpp
        sMap*         getMapPointer(void) { return m_currentMap; };
        void          initialize(cEntityManager* _entityManager);
        void          setPlayerPointer(cPlayerManager* _playerManager) { m_playerManager = _playerManager; };
        void          setGraphicsPointer(cGraphicsEngine* _graphicsEngine) { m_graphicsEngine = _graphicsEngine; };
        void          setAudioPointer(cAudioManager* _audioManager) { m_audioManager = _audioManager; };
        void          resetPlayerPosition(void) { m_resetPlayerPosition(); };
        void          playMusic(void) {m_playMusic(); };
        void          terminate(void);
        void          load(const std::string &_fileName);
        void          unload(void);
        void          process(const float32 &_dt);

        // Dimentions
        std::uint32_t getMapWidth(void) { return m_currentMap->width; };
        std::uint32_t getMapHeight(void) { return m_currentMap->height; };

        // map_generate.cpp
        void          generateMap(sMap*& _map);

        // Test, delete!
        void applyObjects(sMap*& _map) { m_addObjectEntities(_map); };


    protected:

    private:
        cEntityManager*  m_entityManager  = nullptr;
        cPlayerManager*  m_playerManager  = nullptr;
        cGraphicsEngine* m_graphicsEngine = nullptr;
        cAudioManager*   m_audioManager   = nullptr;
        cBiomeManager    m_biomeManager   = {};
        sMap*            m_currentMap     = nullptr;
        std::string      m_mapMusic       = ""; // Map music file name
        std::uint32_t    m_musicSourceID  = 0;  // Map music audio source
        std::uint32_t    m_musicBufferID  = 0;  // Map music audio buffer
        
        // map_manager.cpp
        void m_freeAll(void);
        void m_freeData(sMap*& _map);
        void m_stopMusic(void);
        void m_playMusic(void);
        void m_resetPlayerPosition(void);

        // map_generate_floorModel.cpp
        sEntityModel* m_generateFloor(sMap*& _map);

        // map_generate_addWalls.cpp
        void m_addWallEntities(sMap*& _map);
        void m_addWallWideEntities(sMap*& _map);
        void m_addWallThinEntities(sMap*& _map);
        bool m_isFlat(sMap*& _map, const uint32 &_tile);
        bool m_isNone(sMap*& _map, const std::uint32_t &_tile);
        bool m_isFloor(sMap*& _map, const std::uint32_t &_tile);
        bool m_isWall(sMap*& _map, const std::uint32_t &_tile);
        bool m_isDWall(sMap*& _map, const std::uint32_t &_tile);
        bool m_isDoor(sMap*& _map, const std::uint32_t &_tile);

        // map_generate_addObjects.cpp
        void m_addObjectEntities(sMap*& _map);
        
        // map_generate_addNPCs.cpp
        void m_addNPCEntities(sMap*& _map);
        
        // map_generate_C1.cpp
        std::uint32_t m_numNeighborTiles(sMap*& _map, const std::uint32_t &_tile);
        void m_generateMap_C1(sMap*& _map);

        // map_generate_npcs.cpp
        void m_generateMap_npcs(sMap*& _map);

        // map_generate_objects.cpp
        void m_generateMap_objects(sMap*& _map);

        // map_generate_utils.cpp
        void m_generatePerimeterWall(sMap*& _map);
};

#endif // MAP_MANAGER_HPP

