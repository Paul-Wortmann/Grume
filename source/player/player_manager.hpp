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

#ifndef PLAYER_MANAGER_HPP
#define PLAYER_MANAGER_HPP

#include "../core/includes.hpp"
#include "../core/game_database.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../map/map_path_a_star.hpp"
#include "../map/map_generate_database.hpp"

class cPlayerManager
{
    public:
        void          initialize(cEntityManager* _entityManager);
        void          terminate(void);
        void          process(const float &_dt);
        sEntity*      load(const std::string &_fileName);
        sEntity*      getPlayerEntity(void) { return m_player; };
        void          setDatabasePointer(cGameDatabase* _gameDatabase) { m_gameDatabase = _gameDatabase; };
        void          setGraphicsEnginePointer(cGraphicsEngine* _graphicsEngine) { m_graphicsEngine = _graphicsEngine; };
        void          setMapPointer(sMap* _map) { m_mapPointer = _map; };
        std::uint32_t positionToTile(glm::vec3 _position);
        glm::vec3     tileToPosition(std::uint32_t _tile);
        glm::vec3     getPosition(void) { return m_player->position; };
        glm::vec3     getRotation(void) { return m_player->rotation; };
        void          setRotation(const glm::vec3 &_rotation) { m_player->rotation = _rotation; };
        void          setTerrainHeight(float _height) { m_mapPointer->terrainHeight = _height; };
        void          setCurrentTile(std::uint32_t _tileNum) { m_player->movement->mapPath.currentTile = _tileNum; m_player->position = tileToPosition(_tileNum); m_updateMatrix(); };
        std::uint32_t getCurrentTile(void) { return m_player->movement->mapPath.currentTile; };
        void          resetStartTile(void) { m_player->rotation.z = m_mapPointer->playerStartDir; setCurrentTile(m_mapPointer->playerStartTile); m_updateMatrix(); };
        void          stopPathing(void) {m_player->movement->mapPath.pathLength = 0; };
        bool          getMoved(void) { return m_player->movement->moved; };
        glm::vec3     getMoveDelta(void) { return m_player->movement->moveDelta; };
        void          setMouseClick(glm::vec3 _pos);

    protected:

    private:
        inline void      m_updateMatrix(void) { m_entityManager->updateModelMatrix(m_player); };
        cEntityManager*  m_entityManager   = nullptr;
        sEntity*         m_player          = nullptr;
        cGameDatabase*   m_gameDatabase    = nullptr;
        sMap*            m_mapPointer      = nullptr;
        cGraphicsEngine* m_graphicsEngine  = nullptr;
        
        bool             m_mouseClicked    = false;
        glm::vec3        m_mousePos        = glm::vec3(0.0f, 0.0f, 0.0f);
        std::uint32_t    m_mouseTile       = 0;
        bool             m_mouseTimerOK    = true;
        float            m_mouseTimer      = 0.0f;
        float            m_mouseTimerMax   = 1000.0f; // 1000ms
};

#endif //PLAYER_MANAGER_HPP
