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

#ifndef MAP_MANAGER_HPP
#define MAP_MANAGER_HPP

//#pragma pack(pop)

#include "../audio/audio_manager.hpp"
#include "../entity/animation_engine.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../graphics/graphics_engine_utils.hpp"
#include "../core/includes.hpp"
#include "../core/game_database.hpp"
#include "../core/linked_list.hpp"
#include "../player/player_manager.hpp"
#include "biome_manager.hpp"
#include "map_define.hpp"
#include "map_generate_database.hpp"

class cMapManager : public tcLinkedList<sMap>
{
    public:
        // map_manager.cpp
        sMap*         getMapPointer(void) { return m_currentMap; };
        void          initialize(cEntityManager* _entityManager);
        void          setAnimationPointer(cAnimationEngine* _animationEngine) { m_animationEngine = _animationEngine; };
        void          setAudioPointer(cAudioManager* _audioManager) { m_audioManager = _audioManager; };
        void          setDatabasePointer(cGameDatabase* _gameDatabase) { m_gameDatabase = _gameDatabase; };
        void          setGraphicsPointer(cGraphicsEngine* _graphicsEngine) { m_graphicsEngine = _graphicsEngine; };
        void          setPlayerPointer(cPlayerManager* _playerManager) { m_playerManager = _playerManager; };
        void          resetPlayerPosition(void) { m_resetPlayerPosition(); };
        void          playMusic(void) {m_playMusic(); };
        void          terminate(void);
        void          load(const std::string &_fileName);
        void          save(const std::string &_fileName);
        void          unload(void);
        void          process(const float64 &_dt);
        bool          getLoading(void) { return m_loadRequest; };

        // Dimentions
        std::uint32_t getMapWidth(void) { return m_currentMap->width; };
        std::uint32_t getMapHeight(void) { return m_currentMap->height; };

        // map_generate.cpp
        void          generateMap(sMap*& _map);
        
        // Map list - Used to store map names and associated generation seeds
        std::map<std::string, std::uint32_t> mapList;

        // Test, delete!
        void applyObjects(sMap*& _map) { m_addObjectEntities(_map); };

    protected:

    private:
        cAnimationEngine* m_animationEngine = nullptr;
        cAudioManager*    m_audioManager    = nullptr;
        cBiomeManager     m_biomeManager    = {};
        cEntityManager*   m_entityManager   = nullptr;
        cGameDatabase*    m_gameDatabase    = nullptr;
        cGraphicsEngine*  m_graphicsEngine  = nullptr;
        cPlayerManager*   m_playerManager   = nullptr;
        sMap*             m_currentMap      = nullptr;
        std::string       m_mapMusic        = ""; // Map music file name
        std::uint32_t     m_musicSourceID   = 0;  // Map music audio source
        std::uint32_t     m_musicBufferID   = 0;  // Map music audio buffer
        bool              m_loadRequest     = false;

        const float32 y_pos = -1.0f;       // Map floor position on the y axis
        const float32 tp    = 1.0f / 2.0f; // tile center positioning ( half model dimention)

        // map_manager.cpp
        void          m_freeAll(void);
        void          m_freeData(sMap*& _map);
        void          m_stopMusic(void);
        void          m_playMusic(void);
        void          m_resetPlayerPosition(void);
        
        // map_generate_addCollision.cpp
        void          m_addCollisionData(sMap*& _map, sEntity*& _entity, const std::uint32_t &_tile, const float32 &_rotation);

        // map_generate_addChests.cpp
        void          m_addChestEntities(sMap*& _map);

        // map_generate_addDoors.cpp
        void          m_addDoorEntities(sMap*& _map);

        // map_generate_addEvents.cpp
        void          m_addMapEvent(sMap*& _map, const std::uint32_t &_tile, const std::uint32_t &_type, const std::uint32_t &_data_1, const std::uint32_t &_data_2, const std::uint32_t &_data_3);
        void          m_addMapPortal(sMap*& _map, const std::uint32_t &_num, const std::uint32_t &_tile, const float32 &_dir);
        
        // map_generate_addNPCs.cpp
        void          m_addNPCEntities(sMap*& _map);

        // map_generate_addObjects.cpp
        void          m_addObjectEntity(sMap*& _map, const std::uint32_t &_tn, const std::string &_on, const std::uint32_t &_oi, const float &_s, const float &_yr, const std::uint32_t &_o);
        void          m_addObjectEntities(sMap*& _map);
        
        // map_generate_addStairs.cpp
        void          m_addStairsEntity(sMap*& _map);

        // map_generate_addTorches.cpp
        void          m_addTorchEntities(sMap*& _map);

        // map_generate_addTraps.cpp
        void          m_addTrapEntities(sMap*& _map);

        // map_generate_addWalls.cpp
        void          m_addWallEntities(sMap*& _map);
        void          m_addWallWideEntities(sMap*& _map);
        void          m_addWallThinEntities(sMap*& _map);
        bool          m_isFlat(sMap*& _map, const uint32 &_tile);
        bool          m_isNone(sMap*& _map, const std::uint32_t &_tile);
        bool          m_isFloor(sMap*& _map, const std::uint32_t &_tile);
        bool          m_isWall(sMap*& _map, const std::uint32_t &_tile);
        bool          m_isDWall(sMap*& _map, const std::uint32_t &_tile);
        bool          m_isDoor(sMap*& _map, const std::uint32_t &_tile);
        
        // map_generate_floorModel.cpp
        sEntityModel* m_generateFloor(sMap*& _map);

        // map_generate_npcs.cpp
        void          m_generateMap_npcs(sMap*& _map);

        // map_generate_objects.cpp
        void          m_generateMap_objects(sMap*& _map);

        // map_generate_utils.cpp
        void          m_mapTilesFlipV(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void          m_mapTilesFlipH(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void          m_mapTilesRotate90 (std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void          m_mapTilesRotate270(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void          m_mapTilesRotate180(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void          m_mapGeneratePerimeterWall(sMap*& _map);
        std::uint32_t m_mapGetFloorMin(sMap*& _map);
        std::uint32_t m_mapGetFloorMax(sMap*& _map);
        std::uint32_t m_mapGetFloorArea(sMap*& _map);
        void          m_mapRemoveAnomalies(sMap*& _map);

        // map_generate_rooms.cpp
        bool          m_genCircleRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void          m_genCircleRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        bool          m_genSquareRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void          m_genSquareRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void          m_mapFindRooms(sMap*& _map);
        std::uint32_t m_mapGetRoomArea(sMap*& _map, const uint16_t &_r);
        void          m_mapRoomDiscardAllButLargest(sMap*& _map);
        void          m_mapInitRooms(sMap*& _map);
        void          m_mapInitRoomsND(sMap*& _map); // No discard
        std::int32_t  m_getRoomFromTile(sMap*& _map, const std::uint32_t &_tile, const std::int32_t &_roomIgnore = -1);
        
        // map_generate_connectivity.cpp
        void          m_mapConnectRooms_SL(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void          m_mapConnectRooms_ND(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void          m_mapConnectRooms_DW(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void          m_mapConnectRooms(sMap*& _map);
        
        // map_generate_prefab.cpp
        void          m_mapPrefabRooms(sMap*& _map);
        void          m_mapApplyPrefab(sMap*& _map, const std::string &_fileName, const std::uint32_t &_r);

        // map_generate_C1.cpp
        std::uint32_t m_numNeighborTiles(sMap*& _map, const std::uint32_t &_tile);
        void          m_generateMap_C1(sMap*& _map);
        
        // map_generate_C2.cpp
        void          m_genC2_internal(sMap*& _map);
        void          m_generateMap_C2(sMap*& _map);
        
        // map_generate_D1.cpp
        void          m_genD1_internal(sMap*& _map);
        void          m_generateMap_D1(sMap*& _map);
        
        // map_generate_D2.cpp
        void          m_genD2_internal(sMap*& _map);
        void          m_generateMap_D2(sMap*& _map);
        
        // map_generate_M1.cpp
        void          m_genM1_internal(sMap*& _map);
        void          m_generateMap_M1(sMap*& _map);
        
        // map_generate_T1.cpp
        void          m_generateMap_T1(sMap*& _map);

};

#endif // MAP_MANAGER_HPP

