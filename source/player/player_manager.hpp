


#ifndef PLAYER_MANAGER_HPP
#define PLAYER_MANAGER_HPP

#include "../includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_path_a_star.hpp"

class cPlayerManager
{
    public:
        void      initialize(cEntityManager* _entityManager);
        void      terminate(void);
        void      process(const float32 &_dt);
        sEntity*  load(const std::string &_fileName);
        void      setMapPointer(sMap* _map) { m_mapPointer = _map; };

        uint32    positionToTile(glm::vec3 _position);
        glm::vec3 tileToPosition(uint32 _tile);

        glm::vec3 getPosition(void) { return m_data->position; };
        void      setPosition(glm::vec3 _position) { m_data->position = _position; m_updateMatrix(); m_path.currentTile = positionToTile(_position); };
        glm::vec3 getRotation(void) { return m_data->rotation; };
        void      setRotation(glm::vec3 _rotation) { m_data->rotation = _rotation; m_updateMatrix();};
        float32   getMovementSpeed(void) { return m_movementSpeed; };
        void      setMovementSpeed(float32 _speed) { m_movementSpeed = _speed; };
        void      setTerrainHeight(float32 _height) { m_terrainHeight = _height; };

        void      setCurrentTile(uint32 _tileNum) { m_path.currentTile = _tileNum; m_data->position = tileToPosition(_tileNum); m_updateMatrix(); };
        uint32    getCurrentTile(void) { return m_path.currentTile; };
        void      setDestinationTile(uint32 _tileNum) { m_path.destinationTile = _tileNum; gAStar(m_mapPointer, m_path); };
        uint32    getDestinationTile(void) { return m_path.destinationTile; };
        void      resetStartTile(void) { m_data->rotation.z = m_mapPointer->playerStartDir; setCurrentTile(m_mapPointer->playerStartTile); m_updateMatrix(); };

        uint32    getPathLength(void) { return m_path.pathLength; };
        uint32    getPath(uint32 _i) { return m_path.path[_i]; };


    protected:

    private:
        inline void     m_updateMatrix(void) { m_entityManager->updateModelMatrix(m_data); };
        cEntityManager* m_entityManager   = nullptr;
        sEntity*        m_data            = nullptr;

        sMapPath        m_path;
        sMap*           m_mapPointer      = nullptr;
        float32         m_terrainHeight   = -1;
        float32         m_movementSpeed   = 0.125f;

};

#endif //PLAYER_MANAGER_HPP
