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

#include "re_entity_manager.hpp"

namespace RoboEngine
{

    void re_cEntityManager::freeAllEntities(void)
    {
        /// implement asap!
    }

    entity *re_cEntityManager::newEntity(void)
    {
        if (m_root == nullptr)
        {
            m_root = new entity;
            return m_root;
        }
        else
        {
            entity* t_entity = m_root;
            for (; t_entity->next != nullptr; t_entity = t_entity->next);
            t_entity->next = new entity;
            t_entity = t_entity->next;
            return t_entity;
        }
        return nullptr;
    }

}
