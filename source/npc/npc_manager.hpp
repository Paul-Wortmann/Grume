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

#ifndef NPC_MANAGER_HPP
#define NPC_MANAGER_HPP

#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_define.hpp"
#include "../map/map_path_a_star.hpp"

class cNPCManager
{
    public:
        void     initialize(cEntityManager* _entityManager);
        void     terminate(void);
        void     process(const float32 &_dt);
        void     setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void     setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; }
        void     setMapPointer(sMap* _map) { m_mapPointer = _map; };

    protected:

    private:
        // Entity management
        cEntityManager* m_entityManager = nullptr;
        sEntity*        m_entityHead    = nullptr;
        sEntity*        m_entityTemp    = nullptr;
        sEntity*        m_entityPlayer  = nullptr;
        sMap*           m_mapPointer    = nullptr;

        uint32          m_positionToTile(glm::vec3 _position);
        glm::vec3       m_tileToPosition(uint32 _tile);
};

#endif //NPC_MANAGER_HPP
