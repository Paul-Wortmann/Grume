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
    // Camera position
    glm::vec3 cameraPos = m_graphicsEngine->getCameraPosition();

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

    // If no particles, early exit
    if (tFirstEntity == nullptr)
        return;

    // Find the last entity particle, so we don't need to iterate to the list tail each time
    sEntity* tLastEntity = nullptr;
    for (sEntity* tEntity = tFirstEntity; tEntity != nullptr; tEntity = tEntity->next)
    {
        if (tEntity->particle != nullptr)
        {
            tLastEntity = tEntity;
        }
    }

    // iterate and calculate particle distance to camera
    for (sEntity* tEntity1 = tFirstEntity; tEntity1 != tLastEntity->next; tEntity1 = tEntity1->next)
    {
        if (tEntity1->particle != nullptr)
        {
            // distance to camera
            tEntity1->particle->distToCamera = ((cameraPos.x - tEntity1->base.position.x) * (cameraPos.x - tEntity1->base.position.x)) +
                                               ((cameraPos.y - tEntity1->base.position.y) * (cameraPos.y - tEntity1->base.position.y)) +
                                               ((cameraPos.z - tEntity1->base.position.z) * (cameraPos.z - tEntity1->base.position.z));
        }
    }

    // Lambda function to swap data
    auto swapData = [](sEntity* _entity1, sEntity* _entity2)
    {
        // swap position
        glm::vec3 tPosition = _entity1->base.position;
        _entity1->base.position = _entity2->base.position;
        _entity2->base.position = tPosition;

        // swap life
        float tLife = _entity1->particle->life;
        _entity1->particle->life = _entity2->particle->life;
        _entity2->particle->life = tLife;

        // swap z acceleration
        float tAccelerationZ = _entity1->particle->accelerationZ;
        _entity1->particle->accelerationZ = _entity2->particle->accelerationZ;
        _entity2->particle->accelerationZ = tAccelerationZ;

        // swap x acceleration
        float tAccelerationX = _entity1->physics->acceleration;
        _entity1->physics->acceleration = _entity2->physics->acceleration;
        _entity2->physics->acceleration = tAccelerationX;

        // swap velocity
        glm::vec3 tVelocity = _entity1->physics->velocity;
        _entity1->physics->velocity = _entity2->physics->velocity;
        _entity2->physics->velocity = tVelocity;

        // Swap distance to camera
        float tDistToCamera = _entity1->particle->distToCamera;
        _entity1->particle->distToCamera = _entity2->particle->distToCamera;
        _entity2->particle->distToCamera = tDistToCamera;
    };

    // Use selection sort
    for (sEntity* tEntity1 = tFirstEntity; tEntity1 != tLastEntity->next; tEntity1 = tEntity1->next)
    {
        if (tEntity1->particle != nullptr)
        {
            for (sEntity* tEntity2 = tEntity1->next; tEntity2 != tLastEntity->next; tEntity2 = tEntity2->next)
            {
                if (tEntity2->particle != nullptr)
                {
                    // sort based on distance to camera
                    if (tEntity1->particle->distToCamera > tEntity2->particle->distToCamera)
                    {
                        // swap data
                        swapData(tEntity1, tEntity2);
                    }
                }
            }
        }
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
                tEntity->particle->life           = m_timeStep + (m_timeStep * static_cast<float>(20 + (rand() % 10)));
                tEntity->particle->accelerationZ  = gRandFloatMinMax(-0.0025f, 0.0025f);
                tEntity->physics->acceleration    = gRandFloatMinMax(-0.0025f, 0.0025f);
                tEntity->physics->velocity        = glm::vec3(gRandFloatMinMax(-0.005f, 0.005f), gRandFloatMinMax(0.005f, 0.01f), gRandFloatMinMax(-0.005f, 0.005f));
                tEntity->physics->velocityMax     = 0.0125f;

                m_entityManager->updateModelMatrix(tEntity);
                m_graphicsEngine->initializeEntity(tEntity);
            }
        }
        process(static_cast<std::int64_t>(m_timeStep));
        m_sortParticles(_amount);
    }
}

void cParticleEngine::process(const std::int64_t &_dt)
{
    // Calculate delta time
    float dt = static_cast<float>(_dt) / m_timeStep;

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
            tEntity->particle->life -= static_cast<float>(_dt);
            if (tEntity->particle->life < 0.0f)
            {
                //die
                m_entityManager->deleteParticleEntity(tEntity);

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

