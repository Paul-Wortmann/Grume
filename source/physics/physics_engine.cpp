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

#include "physics_engine.hpp"

uint32 cPhysicsEngine::initialize(void)
{
    return EXIT_SUCCESS;
}

void cPhysicsEngine::terminate(void)
{
}

void cPhysicsEngine::process(const float32 &_dt)
{
    for (sEntity* entity_1 = m_entityHead; entity_1 != nullptr; entity_1 = entity_1->next)
    {
        if ((entity_1->physics != nullptr) && (entity_1->physics->bodyType == eBodyType::dynamicBody))
        {
            for (sEntity* entity_2 = entity_1; entity_2 != nullptr; entity_2 = entity_2->next)
            {
                if ((entity_2->physics != nullptr) && (entity_1 != entity_2))
                {
                    // Broad phase //

                    float32 radialSumSquared = ((entity_2->physics->dimentions.w + entity_1->physics->dimentions.w) *
                                                (entity_2->physics->dimentions.w + entity_1->physics->dimentions.w));
                    float32 distanceSquared  = (((entity_2->position.x - entity_1->position.x) *
                                                 (entity_2->position.x - entity_1->position.x)) + 
                                                ((entity_2->position.z - entity_1->position.z) *
                                                 (entity_2->position.z - entity_1->position.z)));

                    // Check distance squared against the sum of the objects' radii
                    if (distanceSquared < radialSumSquared)
                    {
                        // Narrow phase //
                        //std::cout << "Collision! ID: " << entity_1->UID << " and ID: " << entity_2->UID << std::endl;
                        
                        
                        // push physics event
                        sPhysicsEvent* event = new sPhysicsEvent;
                        event->type = ePhysicsEventType::physicsEventType_collision;
                        event->data = entity_1->UID; // entity ID
                        m_event.push(event);
                    }
                }
            }
        }
    }

    //distanceSquared
}

