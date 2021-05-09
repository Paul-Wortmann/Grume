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
        sEntity*  getPlayerEntity(void) { return m_data; };
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
        void      stopPathing(void) {m_path.pathLength = 0; };

        bool      getMoved(void) { return m_moved; };
        void      moveTo(glm::vec3 _pos);
        glm::vec3 getMoveDelta(void) { return m_moveDelta; };

    protected:

    private:
        inline void     m_updateMatrix(void) { m_entityManager->updateModelMatrix(m_data); };
        cEntityManager* m_entityManager   = nullptr;
        sEntity*        m_data            = nullptr;

        sMapPath        m_path;
        sMap*           m_mapPointer      = nullptr;
        float32         m_terrainHeight   = -1;
        float32         m_movementSpeed   = 0.125f;
        float32         m_movementBias    = 0.00125f;
        
        bool            m_pathing         = false; // currently following a path?
        bool            m_moved           = false; // Did we move this frame?
        glm::vec3       m_moveDelta       = glm::vec3(0.0f, 0.0f, 0.0f); // How much did we move last frame?

};

#endif //PLAYER_MANAGER_HPP
