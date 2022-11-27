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

#include "particle_engine.hpp"

std::uint32_t cParticleEngine::initialize(void)
{

    return EXIT_SUCCESS;
}

void cParticleEngine::terminate(void)
{

}

void cParticleEngine::m_sortParticles(std::uint32_t _maxIterations)
{
    // Find the first entity particle, so we don't need to iterate from the list head each time
    sEntity* tFirstEntity = nullptr;
    for (sEntity* tEntity = m_entityHead; tEntity != nullptr; tEntity = tEntity->next)
    {
        if ((tFirstEntity == nullptr) && (tEntity->particle != nullptr))
        {
            tFirstEntity = tEntity;
            break;
        }
    }

    // Find the last entity particle, so we don't need to iterate to the list tail each time
    sEntity* tLastEntity = nullptr;
    for (sEntity* tEntity = tFirstEntity; tEntity != nullptr; tEntity = tEntity->next)
    {
        if (tEntity->particle != nullptr)
        {
            tLastEntity = tEntity;
        }
    }

    // If no particles, early exit
    if (tFirstEntity == nullptr)
        return;

    bool          sorted         = true;
    std::uint32_t iterationCount = 0;
    glm::vec3     cameraPos      = m_graphicsEngine->getCameraPosition();

    // Bubble sort... not my proudest moment >>
    while ((sorted) && (iterationCount < _maxIterations))
    {
        // iterate and sort furthest first
        for (sEntity* tEntity1 = tFirstEntity; tEntity1 != tLastEntity->next; tEntity1 = tEntity1->next)
        {
            if (tEntity1->particle != nullptr)
            {
                for (sEntity* tEntity2 = tEntity1->next; tEntity2 != tLastEntity->next; tEntity2 = tEntity2->next)
                {
                    if (tEntity2->particle != nullptr)
                    {
                        // distance to camera
                        float distSqrd1 = ((cameraPos.x - tEntity1->base.position.x) * (cameraPos.x - tEntity1->base.position.x)) +
                                              ((cameraPos.y - tEntity1->base.position.y) * (cameraPos.y - tEntity1->base.position.y)) +
                                              ((cameraPos.z - tEntity1->base.position.z) * (cameraPos.z - tEntity1->base.position.z));
                        // distance to camera
                        float distSqrd2 = ((cameraPos.x - tEntity2->base.position.x) * (cameraPos.x - tEntity2->base.position.x)) +
                                              ((cameraPos.y - tEntity2->base.position.y) * (cameraPos.y - tEntity2->base.position.y)) +
                                              ((cameraPos.z - tEntity2->base.position.z) * (cameraPos.z - tEntity2->base.position.z));

                        if (distSqrd2 > distSqrd1)
                        {
                            // swap position
                            glm::vec3 tPosition = tEntity1->base.position;
                            tEntity1->base.position = tEntity2->base.position;
                            tEntity2->base.position = tPosition;

                            // swap life
                            float tLife = tEntity1->particle->life;
                            tEntity1->particle->life = tEntity2->particle->life;
                            tEntity2->particle->life = tLife;

                            // swap z acceleration
                            float tAccelerationZ = tEntity1->particle->accelerationZ;
                            tEntity1->particle->accelerationZ = tEntity2->particle->accelerationZ;
                            tEntity2->particle->accelerationZ = tAccelerationZ;

                            // swap x acceleration
                            float tAccelerationX = tEntity1->physics->acceleration;
                            tEntity1->physics->acceleration = tEntity2->physics->acceleration;
                            tEntity2->physics->acceleration = tAccelerationX;

                            // swap velocity
                            glm::vec3 tVelocity = tEntity1->physics->velocity;
                            tEntity1->physics->velocity = tEntity2->physics->velocity;
                            tEntity2->physics->velocity = tVelocity;

                            sorted = false;
                        }
                    }
                }
            }
        }
        ++iterationCount;
    }
}

void cParticleEngine::spawnParticles(const std::uint32_t &_type, const std::uint32_t &_amount, const glm::vec3 &_position)
{
    // Only spawn particles if the limit has not yet been reached
    if ((m_activeParticles  + _amount) < m_maxParticles)
    {

        // Temporary entity
        sEntity* tEntity = nullptr;

        // Spawn each particle
        for (std::uint32_t i = 0; i < _amount; ++i)
        {
            if (_type == eParticleType::particleType_blood)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("blood", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }
            else if (_type == eParticleType::particleType_fire)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("fire", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }
            else if (_type == eParticleType::particleType_smoke)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("smoke", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }
            else if (_type == eParticleType::particleType_dust)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("dust", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }
            else if (_type == eParticleType::particleType_slime)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("slime", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }
            else if (_type == eParticleType::particleType_ice)
            {
                std::string fileName = m_databaseManager->getDatabaseEntryFileName("ice", 1, eDatabaseType::databaseTypeParticle);
                tEntity = m_entityManager->load(fileName);
            }

            if (tEntity != nullptr)
            {
                tEntity->graphics->billboard      = true;
                tEntity->base.type                = eEntityType::entityType_particle;
                tEntity->base.owner               = eEntityOwner::entityOwner_particle;
                tEntity->base.position           += _position;
                tEntity->base.scale               = glm::vec3(0.75, 0.75, 0.75);
                tEntity->particle->life           = m_timeStep + (m_timeStep * (20 + rand() % 10));
                tEntity->particle->accelerationZ  = gRandFloatMinMax(-0.0025, 0.0025);
                tEntity->physics->acceleration    = gRandFloatMinMax(-0.0025, 0.0025);
                tEntity->physics->velocity        = glm::vec3(gRandFloatMinMax(-0.005, 0.005), gRandFloatMinMax(0.005, 0.01), gRandFloatMinMax(-0.005, 0.005));
                tEntity->physics->velocityMax     = 0.0125;

                m_entityManager->updateModelMatrix(tEntity);
                m_graphicsEngine->initializeEntity(tEntity);
            }
        }
        process(m_timeStep);
        m_sortParticles(_amount);
    }
}

void cParticleEngine::process(const float &_dt)
{
    // Calculate delta time
    float dt = _dt / m_timeStep;

    // reset particle count
    m_activeParticles = 0;

    // Process particle entities
    for (sEntity* tEntity = m_entityHead; tEntity != nullptr; tEntity = tEntity->next)
    {
        if ((tEntity->base.inRnge) && (tEntity->particle != nullptr))
        {
            // Update particle count
            m_activeParticles++;

            // Decrease particle life
            tEntity->particle->life -= _dt;
            if (tEntity->particle->life < 0.0f)
            {
                //die
                m_entityManager->deleteEntity(tEntity);

                //return;
                tEntity = m_entityHead;
            }
            else
            {
                // move
                tEntity->physics->velocity.y += tEntity->particle->gravity;
                tEntity->physics->velocity.x += tEntity->physics->acceleration;
                tEntity->physics->velocity.z += tEntity->particle->accelerationZ;
                tEntity->base.position += (tEntity->physics->velocity * dt);

                //if (tEntity->base.position.y < m_mapPointer->terrainHeight)
                    //tEntity->base.position.y = m_mapPointer->terrainHeight;

                m_entityManager->updateModelMatrix(tEntity);
            }
        }
    }
}

