


#ifndef MAP_MANAGER_HPP
#define MAP_MANAGER_HPP

//#pragma pack(pop)

#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine_utils.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "biome_manager.hpp"
#include "map_define.hpp"

class cMapManager : public tcLinkedList<sMap>
{
    public:
        // map_manager.cpp
        sMap*         getMapPointer(void) { return m_currentMap; };
        void          initialize(cEntityManager* _entityManager);
        void          terminate(void);
        void          load(const std::string &_fileName);
        void          unload(void);

        // Music
        std::string   getMapMusic(void) { return m_mapMusic; };
        std::uint32_t getMusicSID(void) { return m_musicSourceID; };
        std::uint32_t getMusicBID(void) { return m_musicBufferID; };
        void          setMusicSID(const std::uint32_t &_ID) { m_musicSourceID = _ID; };
        void          setMusicBID(const std::uint32_t &_ID) { m_musicBufferID = _ID; };

        // Dimentions
        std::uint32_t getMapWidth(void) { return m_currentMap->width; };
        std::uint32_t getMapHeight(void) { return m_currentMap->height; };

        // map_generate.cpp
        void          generateMap(sMap*& _map);

        // Test, delete!
        void applyObjects(sMap*& _map) { m_addObjectEntities(_map); };


    protected:

    private:
        cEntityManager* entityManager   = nullptr;
        cBiomeManager   biomeManager;
        sMap*           m_currentMap    = nullptr;
        std::string     m_mapMusic      = ""; // Map music file name
        std::uint32_t   m_musicSourceID = 0;  // Map music audio source
        std::uint32_t   m_musicBufferID = 0;  // Map music audio buffer
        
        // map_manager.cpp
        void m_freeAll(void);
        void m_freeData(sMap*& _map);

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

