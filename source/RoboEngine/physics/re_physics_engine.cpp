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

#include "re_physics_engine.hpp"

namespace RoboEngine
{

    uint32_t re_cPhysicsEngine::initialize(void)
    {
        uint32_t return_value = EXIT_SUCCESS;
        return return_value;
    }

    void re_cPhysicsEngine::deinitialize(void)
    {
    }

    void re_cPhysicsEngine::process(int64_t _dt)
    {
        m_entity = m_entityHead;
        if (m_entity != nullptr)
        {
            while (m_entity  != nullptr)
            {
                if ((m_entity->enabled) && (m_entity->physics != nullptr))
                {
                    // process
                    bool updateMVP = false;

                    // if data changed...
                    updateMVP = true;




                    // Update render entity
                    if ((updateMVP) && (m_entity->render != nullptr))
                    {

                        //m_entity->physics->rotation.x = 0.001f;
                        m_entity->physics->rotation.y = 0.01f;
                        //m_entity->physics->scale = glm::vec3(1.0f);

                        m_entity->render->Model = glm::rotate(m_entity->render->Model, m_entity->physics->rotation.x, glm::vec3(1, 0, 0));
                        m_entity->render->Model = glm::rotate(m_entity->render->Model, m_entity->physics->rotation.y, glm::vec3(0, 1, 0));
                        m_entity->render->Model = glm::rotate(m_entity->render->Model, m_entity->physics->rotation.z, glm::vec3(0, 0, 1));
                        m_entity->render->Model = glm::scale(m_entity->render->Model, m_entity->physics->scale);


                    }
                }
                m_entity = m_entity->next;
            }
        }
    }

}

