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

#include "map_manager_defines.hpp"

class cMapManager :tcTemplateEngine
{
    public:
        // Engine base
        std::uint32_t     initialize(void) override;
        void              terminate(void) override;
        void              process(const std::int64_t &_dt) override;
        sMapManagerEvent* getEvent(void) { return m_event.pop(); }

        void          setAudioEngine(cAudioEngine* _audioEngine) { m_audioEngine = _audioEngine; };
        void          setEntityManager(cEntityManager* _entityManager) { m_entityManager = _entityManager; }
        void          setDatabaseManager(cDatabaseManager* _databaseManager) { m_databaseManager = _databaseManager; }
        void          setGraphicsEngine(cGraphicsEngine* _graphicsEngine) { m_graphicsEngine = _graphicsEngine; }
        void          setAnimationEngine(cAnimationEngine* _animationEngine) { m_animationEngine = _animationEngine; }
        void          setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; }
        void          setPlayerManager(cPlayerManager* _playerManager) { m_playerManager = _playerManager; }
        void          setQuestManager(cQuestManager* _questManager) { m_questManager = _questManager; };
        sMap*         getMapPointer(void) { return m_map; };
        void          setSpawnPortal(const std::uint32_t &_portalNumber) { m_spawnPortal = _portalNumber; }
        std::uint32_t load(const std::string &_fileName);
        void          save(const std::string &_fileName);
        std::uint32_t reloadMap(void);

        // Event
        tcQueue<sMapManagerEvent> m_event = {};

        // Map list - Used to store map names and associated generation seeds
        std::map<std::string, std::uint32_t> mapList;

        // Map town, last town visited
        std::string mapTown = {};

        // Helper functions
        std::uint32_t size_x(void) { return m_map->info.size_x; }
        std::uint32_t size_y(void) { return m_map->info.size_y; }
        void          setHasEntity(sEntity* _entity, const bool &_value);

    protected:
    private:
        cDatabaseManager* m_databaseManager    = nullptr;
        cEntityManager*   m_entityManager      = nullptr;
        cGraphicsEngine*  m_graphicsEngine     = nullptr;
        cAnimationEngine* m_animationEngine    = nullptr;
        cPlayerManager*   m_playerManager      = nullptr;
        cQuestManager*    m_questManager       = nullptr;
        sEntity*          m_entityPlayer       = nullptr;
        sMap*             m_map                = new sMap;
        const float       m_tileSize           = 1.0f;
        std::uint32_t     m_spawnPortal        = 0;

        // Audio
        cAudioEngine*     m_audioEngine        = nullptr;
        std::string       m_currentMusicFile   = {};

        // map_manager.cpp
        void              m_freeData(sMap*& _map);
        void              m_unloadMap(void);
        void              m_playMapMusic(void);
        void              m_updateHasFunction(void);
        void              m_setHasFunction(sEntity* _entity, const bool &_value);

        // map_manager_add_chests.cpp
        void              m_addChests(void);

        // map_manager_add_collision.cpp
        void              m_addCollisionData(sMap*& _map, sEntity*& _entity, const float &_rotation);

        // map_manager_add_debris.cpp
        void              m_addDebris(void);

        // map_manager_add_doors.cpp
        void              m_addDoors(void);

        // map_manager_add_events.cpp
        void              m_addEvents(void);

        // map_manager_add_floors.cpp
        bool              m_isFloorConfig(const std::uint32_t &_tile,
                                          const std::uint32_t &_tile_00, const std::uint32_t &_tile_10, const std::uint32_t &_tile_20,
                                          const std::uint32_t &_tile_01, const std::uint32_t &_tile_11, const std::uint32_t &_tile_21,
                                          const std::uint32_t &_tile_02, const std::uint32_t &_tile_12, const std::uint32_t &_tile_22);
        void              m_floorTypeOrientation(const std::uint32_t &_tile, eFloorType &_type, float &_orientation);
        void              m_addFloors(void);

        // map_manager_add_npc_mobs.cpp
        void              m_addNPC_mobs(void);

        // map_manager_add_npcs.cpp
        void              m_addNPCs(void);

        // map_manager_add_objects.cpp
        void              m_addObjects(void);

        // map_manager_add_paths.cpp
        bool              m_isPathConfig(const std::uint32_t &_tile,
                                         const std::uint32_t &_tile_00, const std::uint32_t &_tile_10, const std::uint32_t &_tile_20,
                                         const std::uint32_t &_tile_01, const std::uint32_t &_tile_11, const std::uint32_t &_tile_21,
                                         const std::uint32_t &_tile_02, const std::uint32_t &_tile_12, const std::uint32_t &_tile_22);
        void              m_pathTypeOrientation(const std::uint32_t &_tile, ePathType &_type, float &_orientation);
        void              m_addPaths(void);

        // map_manager_add_portals.cpp
        void              m_addPortals(void);

        // map_manager_add_prefabs.cpp
        void              m_addPrefabs(void);
        void              m_applyPrefab(const std::string &_fileName, const std::uint32_t &_r);

        // map_manager_add_rooms.cpp
        bool m_genCircleRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void m_genCircleRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        bool m_genSquareRoomOK(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void m_genSquareRoom(sMap*& _map, const std::uint32_t &_x, const std::uint32_t &_y, const std::uint32_t &_r);
        void m_mapFindRooms(sMap*& _map);
        std::uint32_t m_mapGetRoomArea(sMap*& _map, const std::uint16_t &_r);
        void m_mapRoomDiscardAllButLargest(sMap*& _map);
        void m_mapInitRooms(sMap*& _map);
        void m_mapInitRoomsND(sMap*& _map);
        std::int32_t m_getRoomFromTile(sMap*& _map, const std::uint32_t &_tile, const std::int32_t &_roomIgnore);
        void m_addRooms(void);

        // map_manager_add_torches.cpp
        void              m_addTorches(void);

        // map_manager_add_walls.cpp
        bool              m_isWallConfig(const std::uint32_t &_tile,
                                         const std::uint32_t &_tile_00, const std::uint32_t &_tile_10, const std::uint32_t &_tile_20,
                                         const std::uint32_t &_tile_01, const std::uint32_t &_tile_11, const std::uint32_t &_tile_21,
                                         const std::uint32_t &_tile_02, const std::uint32_t &_tile_12, const std::uint32_t &_tile_22);
        void              m_wallTypeOrientation(const std::uint32_t &_tile, eWallType &_type, float &_orientation);
        void              m_addWalls(void);

        // map_generate_connectivity.cpp
        void              m_mapConnectRooms_SL(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void              m_mapConnectRooms_ND(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void              m_mapConnectRooms_DW(sMap*& _map, const std::int32_t &_r1, const std::int32_t &_r2);
        void              m_mapAddDooryways(sMap*& _map);
        void              m_mapConnectRooms(sMap*& _map);

        // map_generate_map.cpp
        void              m_generateMap(sMap*& _map);

        // map_generate_map_C1.cpp
        std::uint32_t     m_numNeighborTiles(sMap*& _map, const std::uint32_t &_tile);
        void              m_generateMap_C1(sMap*& _map);

        // map_generate_map_C2.cpp
        void              m_genC2_internal(sMap*& _map);
        void              m_generateMap_C2(sMap*& _map);

        // map_generate_map_D1.cpp
        void              m_genD1_internal(sMap*& _map);
        void              m_generateMap_D1(sMap*& _map);

        // map_generate_map_D2.cpp
        void              m_genD2_internal(sMap*& _map);
        void              m_generateMap_D2(sMap*& _map);

        // map_generate_map_M1.cpp
        void              m_genM1_internal(sMap*& _map);
        void              m_generateMap_M1(sMap*& _map);

        // map_generate_map_T1.cpp
        void              m_generateMap_T1(sMap*& _map);

        // map_generate_map_portals.cpp
        void              m_generatePortals(sMap*& _map);

        // map_generate_utils.cpp
        void              m_mapTilesFlipV(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void              m_mapTilesFlipH(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void              m_mapTilesRotate90 (std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void              m_mapTilesRotate270(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void              m_mapTilesRotate180(std::uint32_t *&_tiles, const std::uint32_t &_w, const std::uint32_t &_h);
        void              m_mapGeneratePerimeterWall(sMap*& _map);
        std::uint32_t     m_mapGetFloorMin(sMap*& _map);
        std::uint32_t     m_mapGetFloorMax(sMap*& _map);
        std::uint32_t     m_mapGetFloorArea(sMap*& _map);
        void              m_mapRemoveAnomalies(sMap*& _map);
        std::uint32_t     m_mapGetFootprintCount(sMap*& _map, sEntity*& _entity);
        bool              m_mapGetFootprint(sMap*& _map, sEntity*& _entity, const std::uint32_t &_num, std::uint32_t &_x, std::uint32_t &_y);

        // map_manager_wall_utils.cpp
        bool              m_isFloor(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
        bool              m_isPath(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
        bool              m_isDoorway(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
        bool              m_isWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
        bool              m_isFullWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
        bool              m_isSolidWall(const std::int32_t &_tile_x, const std::int32_t &_tile_y);
};

#endif // MAP_MANAGER_HPP
