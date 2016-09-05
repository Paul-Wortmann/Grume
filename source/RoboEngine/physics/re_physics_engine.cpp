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

    bool re_cPhysicsEngine::collision2D(const re_sEntity &_entity1, const re_sEntity &_entity2)
    {
        return quadrangle_collision(_entity1.physics->position.x, _entity1.physics->position.y, _entity1.physics->scale.x, _entity1.physics->scale.y, _entity2.physics->position.x, _entity2.physics->position.y, _entity2.physics->scale.x, _entity2.physics->scale.y);
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
                    if (m_entity->physics->dynamic)
                    {
                        re_sEntity *tEntity = m_entityHead;
                        if (tEntity != nullptr)
                        {
                            while (tEntity  != nullptr)
                            {
                                if (collision2D(*m_entity, *tEntity))
                                {
                                    std::cout << "collision detected!" << std::endl;
                                }

                                tEntity = tEntity->next;
                            }
                        }
                    }

                    // If data changed update render entity
                    if ((m_entity->physics->updateMVP) && (m_entity->render != nullptr))
                    {
                        glm::mat4 tMVP = glm::mat4(1.0f);
                        //scale
                        //m_entity->physics->scale = glm::vec3(1.0f);
                        tMVP = glm::scale(tMVP, m_entity->physics->scale);
                        //rotate
                        tMVP = glm::rotate(tMVP, m_entity->physics->rotation.x, glm::vec3(1, 0, 0));
                        tMVP = glm::rotate(tMVP, m_entity->physics->rotation.y, glm::vec3(0, 1, 0));
                        tMVP = glm::rotate(tMVP, m_entity->physics->rotation.z, glm::vec3(0, 0, 1));
                        //translate
                        //glm::mat4(1.0f)
                        tMVP = glm::translate(tMVP, m_entity->physics->position);
                        //cleanup
                        m_entity->render->Model = tMVP;
                        m_entity->physics->updateMVP = false;
                    }
                }
                m_entity = m_entity->next;
            }
        }
    }

}

