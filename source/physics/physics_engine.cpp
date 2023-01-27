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

std::uint32_t cPhysicsEngine::initialize(void)
{


    return EXIT_SUCCESS;
}

void cPhysicsEngine::terminate(void)
{


}

void cPhysicsEngine::process(const std::int64_t &_dt)
{
    // Calculate delta time
    float dt = static_cast<float>(_dt) / m_timeStep;

    // tmin for 3D picking
    sEntity* tminEntity = m_entityHead;
    float    tminValue = std::numeric_limits<float>::max();
    float    tmin      = std::numeric_limits<float>::max();

    // Reset collisions, calculate positions, 3D picking
    for (sEntity* tEntity = m_entityHead; tEntity != nullptr; tEntity = tEntity->next)
    {
        if ((tEntity->physics != nullptr) && (tEntity->base.inRnge))
        {
            // Reset collision status
            tEntity->physics->collision = false;

            // Reset 3D picking status
            tEntity->physics->mouseOver = false;

            // move dynamic objects
            if (tEntity->physics->type == ePhysicsType::physicsTypeDynamic)
            {
                bool canMove = true;
                if (tEntity->movement != nullptr)
                {
                    canMove = (tEntity->movement->pathing == false);
                }
                if (canMove)
                {
                    if ((fabs(tEntity->physics->velocity.x) > 0.001f) || (fabs(tEntity->physics->velocity.z) > 0.001f))
                    {
                        // Remove collision data from map
                        m_mapPointer->tile[tEntity->base.tileOnMap].entity.UID  = 0;
                        eTileEntityType entityType = m_mapPointer->tile[tEntity->base.tileOnMap].entity.type;
                        m_mapPointer->tile[tEntity->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                        // Set tiles passable
                        gSetTileCollision(m_mapPointer, tEntity->base.tileOnMap, false);

                        // Calculate new positions
                        if (tEntity->physics->velocity.x > 0.0f)
                        {
                            tEntity->physics->velocity.x -= (tEntity->physics->mass * dt);
                            if (tEntity->physics->velocity.x < 0.0f)
                                tEntity->physics->velocity.x = 0.0f;
                            if (tEntity->physics->velocity.x > tEntity->physics->velocityMax)
                                tEntity->physics->velocity.x = tEntity->physics->velocityMax;
                        }
                        else if (tEntity->physics->velocity.x < 0.0f)
                        {
                            tEntity->physics->velocity.x += (tEntity->physics->mass * dt);
                            if (tEntity->physics->velocity.x > 0.0f)
                                tEntity->physics->velocity.x = 0.0f;
                            if (tEntity->physics->velocity.x < (tEntity->physics->velocityMax * -1))
                                tEntity->physics->velocity.x = (tEntity->physics->velocityMax * -1);
                        }


                        if (tEntity->physics->velocity.z > 0.0f)
                        {
                            tEntity->physics->velocity.z -= (tEntity->physics->mass * dt);
                            if (tEntity->physics->velocity.z < 0.0f)
                                tEntity->physics->velocity.z = 0.0f;
                            if (tEntity->physics->velocity.z > tEntity->physics->velocityMax)
                                tEntity->physics->velocity.z = tEntity->physics->velocityMax;
                        }
                        else if (tEntity->physics->velocity.z < 0.0f)
                        {
                            tEntity->physics->velocity.z += (tEntity->physics->mass * dt);
                            if (tEntity->physics->velocity.z > 0.0f)
                                tEntity->physics->velocity.z = 0.0f;
                            if (tEntity->physics->velocity.z < (tEntity->physics->velocityMax * -1))
                                tEntity->physics->velocity.z = (tEntity->physics->velocityMax * -1);
                        }

                        // Update position
                        tEntity->base.position.x += tEntity->physics->velocity.x;
                        tEntity->base.position.z += tEntity->physics->velocity.z;
                        m_entityManager->updateModelMatrix(tEntity);

                        // Add collision data to map
                        tEntity->base.tileOnMap = gMapPositionToTile(m_mapPointer, tEntity->base.position);
                        m_mapPointer->tile[tEntity->base.tileOnMap].entity.UID  = tEntity->UID;
                        m_mapPointer->tile[tEntity->base.tileOnMap].entity.type = entityType;

                        // Set tiles impassable
                        gSetTileCollision(m_mapPointer, tEntity->base.tileOnMap, true);
                    }
                }
            }

            // 3D picking
            if (gPhysicsCollision_ray_aabb(m_cameraPosition.x, m_cameraPosition.y, m_cameraPosition.z,
                                           m_cameraDirection.x, m_cameraDirection.y, m_cameraDirection.z,
                                           tEntity->base.position.x, tEntity->base.position.y - m_mapPointer->info.terrainHeight, tEntity->base.position.z,
                                           tEntity->physics->halfDimentions.x, tEntity->physics->halfDimentions.y, tEntity->physics->halfDimentions.z,
                                           tmin))
            {

                // Only closest valid object under mouse
                if ((!std::signbit(tmin)) && (tmin < tminValue))
                {
                    tminValue = tmin;
                    tminEntity->physics->mouseOver = false;
                    tEntity->physics->mouseOver = tEntity->base.interactable;
                    tminEntity = tEntity;
                }
            }

        }
    }

    // If mouse click object, create event
    if ((!m_mouseOverMenu) && (m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT]))
    {
        if (tminValue < std::numeric_limits<float>::max())
        {
            sPhysicsEvent* event = new sPhysicsEvent;
            event->type = ePhysicsEventType::physicsEventType_objectClick;
            event->data = tminEntity->UID; // entity ID
            tminEntity->base.clicked = true; // Set entity clicked
            m_event.push(event);
        }
        else
        {
            glm::vec3 planePoint = gPhysicsCollision_ray_plane(m_cameraDirection, m_cameraPosition);
            std::uint32_t tile = gMapPositionToTile(m_mapPointer, planePoint);

            if (tile < m_mapPointer->numTiles - 1)
            {
                sPhysicsEvent* event = new sPhysicsEvent;
                event->type = ePhysicsEventType::physicsEventType_tileClick;
                event->data = tile; // tile no.
                m_event.push(event);
            }
        }
    }

    // Recalculate collisions
    for (sEntity* tEntity1 = m_entityHead; tEntity1 != nullptr; tEntity1 = tEntity1->next)
    {
        if ((tEntity1->physics != nullptr) && (tEntity1->physics->type == ePhysicsType::physicsTypeDynamic) && tEntity1->base.inRnge)
        {
            for (sEntity* tEntity2 = m_entityHead; tEntity2 != nullptr; tEntity2 = tEntity2->next)
            {
                //only check if in range
                if (tEntity2->base.inRnge)
                {
                    // If flying, don't check for collisions with short walls
                    if (!((tEntity1->base.type == eEntityType::entityType_npc_fly) &&
                          ((tEntity2->base.type == eEntityType::entityType_wallLow) ||
                           (tEntity2->base.type == eEntityType::entityType_objectDynamicLow) ||
                           (tEntity2->base.type == eEntityType::entityType_objectStaticLow))))
                    {
                        if ((tEntity1 != tEntity2) && (tEntity2->physics != nullptr) && (tEntity2->physics->type != ePhysicsType::physicsTypeNone))
                        {
                            // Circle - circle
                            if (tEntity1->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeCircle &&
                                tEntity2->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeCircle)
                            {
                                // Collision detection
                                if (gPhysicsCollision_circle_circle(tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->radius,
                                                                    tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->radius))
                                {
                                    tEntity1->physics->collision = true;
                                    tEntity2->physics->collision = true;

                                    // Collision resolution
                                    gPhysicsResolution_circle_circle(tEntity1->physics->velocity.x, tEntity1->physics->velocity.z, tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->radius, tEntity1->physics->mass, (tEntity1->physics->type == ePhysicsType::physicsTypeStatic),
                                                                     tEntity2->physics->velocity.x, tEntity2->physics->velocity.z, tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->radius, tEntity2->physics->mass, (tEntity2->physics->type == ePhysicsType::physicsTypeStatic));
                                }
                            }

                            // aabs - aabs
                            else if (tEntity1->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeAABS &&
                                     tEntity2->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeAABS)
                            {
                                // Collision detection
                                if (gPhysicsCollision_aabs_aabs(tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->halfDimentions.x, tEntity1->physics->halfDimentions.z,
                                                                tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->halfDimentions.x, tEntity2->physics->halfDimentions.z))
                                {
                                    tEntity1->physics->collision = true;
                                    tEntity2->physics->collision = true;

                                    // Collision resolution
                                    gPhysicsResolution_aabs_aabs(tEntity1->physics->velocity.x, tEntity1->physics->velocity.z, tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->halfDimentions.x, tEntity1->physics->halfDimentions.z, tEntity1->physics->mass, (tEntity1->physics->type == ePhysicsType::physicsTypeStatic),
                                                                 tEntity2->physics->velocity.x, tEntity2->physics->velocity.z, tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->halfDimentions.x, tEntity2->physics->halfDimentions.z, tEntity2->physics->mass, (tEntity2->physics->type == ePhysicsType::physicsTypeStatic));
                                }
                            }

                            // circle - aabs
                            else if (tEntity1->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeCircle &&
                                     tEntity2->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeAABS)
                            {
                                // Collision detection
                                if (gPhysicsCollision_aabs_circle(tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->halfDimentions.x, tEntity1->physics->halfDimentions.z,
                                                                  tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->radius))
                                {
                                    tEntity1->physics->collision = true;
                                    tEntity2->physics->collision = true;

                                    // Collision resolution
                                    gPhysicsResolution_aabs_circle(tEntity1->physics->velocity.x, tEntity1->physics->velocity.z, tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->halfDimentions.x, tEntity1->physics->halfDimentions.z, tEntity1->physics->mass, (tEntity1->physics->type == ePhysicsType::physicsTypeStatic),
                                                                   tEntity2->physics->velocity.x, tEntity2->physics->velocity.z, tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->radius, tEntity2->physics->mass, (tEntity2->physics->type == ePhysicsType::physicsTypeStatic));
                                }
                            }

                            // aabs - circle
                            else if (tEntity1->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeAABS &&
                                     tEntity2->physics->boundingVolumeType == ePhysicsBoundingVolumeType::physicsBoundingVolumeTypeCircle)
                            {
                                if (gPhysicsCollision_aabs_circle(tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->halfDimentions.x, tEntity2->physics->halfDimentions.z,
                                                                  tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->radius))
                                {
                                    tEntity1->physics->collision = true;
                                    tEntity2->physics->collision = true;

                                    // Collision resolution
                                    gPhysicsResolution_aabs_circle(tEntity2->physics->velocity.x, tEntity2->physics->velocity.z, tEntity2->base.position.x, tEntity2->base.position.z, tEntity2->physics->halfDimentions.x, tEntity2->physics->halfDimentions.z, tEntity2->physics->mass, (tEntity2->physics->type == ePhysicsType::physicsTypeStatic),
                                                                   tEntity1->physics->velocity.x, tEntity1->physics->velocity.z, tEntity1->base.position.x, tEntity1->base.position.z, tEntity1->physics->radius, tEntity1->physics->mass, (tEntity1->physics->type == ePhysicsType::physicsTypeStatic));
                                }

                            }

                            if ((tEntity1->physics->collision) && (tEntity1->physics->type == ePhysicsType::physicsTypeDynamic))
                            {
                                // Inflict damage
                                if ((tEntity1->character) && (tEntity1->character->attribute.health.current > 0.00f) && (tEntity2->physics->damage > 0.0f))
                                {
                                    tEntity1->character->attribute.health.current -= tEntity2->physics->damage;
                                }

                                // Create events
                                sPhysicsEvent* event = new sPhysicsEvent;
                                event->type = ePhysicsEventType::physicsEventType_collision;
                                event->data = tEntity1->UID; // entity ID
                                m_event.push(event);
                            }
                            if ((tEntity2->physics->collision) && (tEntity2->physics->type == ePhysicsType::physicsTypeDynamic))
                            {
                                // Inflict damage
                                if ((tEntity2->character) && (tEntity2->character->attribute.health.current > 0.00f) && (tEntity1->physics->damage > 0.0f))
                                {
                                    tEntity2->character->attribute.health.current -= tEntity1->physics->damage;
                                }

                                // Create events
                                sPhysicsEvent* event = new sPhysicsEvent;
                                event->type = ePhysicsEventType::physicsEventType_collision;
                                event->data = tEntity2->UID; // entity ID
                                m_event.push(event);
                            }
                        }
                    }
                }
            }
        }
    }
}

