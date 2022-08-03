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

#include "object_manager.hpp"

std::uint32_t cObjectManager::initialize(void)
{
    return EXIT_SUCCESS;
}

void cObjectManager::terminate(void)
{

}

void cObjectManager::process(const float &_dt)
{
    // Map warp data
    bool          mapWarp   = false;
    std::string   mapName   = {};
    std::uint32_t mapPortal = 0;

    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) && (m_entityPlayer != nullptr) && ((m_entityTemp->base.type == eEntityType::entityType_objectStatic) || (m_entityTemp->base.type == eEntityType::entityType_objectDynamic)))
        {
            // Calculate the distance to the player
            float distPlayerSqrd = (((m_entityTemp->base.position.x - m_entityPlayer->base.position.x) *
                                     (m_entityTemp->base.position.x - m_entityPlayer->base.position.x)) +
                                    ((m_entityTemp->base.position.z - m_entityPlayer->base.position.z) *
                                     (m_entityTemp->base.position.z - m_entityPlayer->base.position.z)));

            float playerAwareDistance    = 50.0f;
            float playerAttackDistance   = 1.0f;
            float playerMovetoDistance   = 10.0f;
            float playerMoveAwayDistance = 0.75f;

            // Entity clicked
            if (m_entityTemp->base.clicked)
            {
                m_entityTemp->base.clicked = false;

                // Close enough to the player?
                if (distPlayerSqrd < playerAwareDistance)
                {
                    // Turn to face direction of object
                    m_entityPlayer->base.rotation.y = 1.5f - gPhysicsAngleTwoPoints(m_entityPlayer->base.position.x, m_entityPlayer->base.position.z, m_entityTemp->base.position.x, m_entityTemp->base.position.z);

                    // Destructible
                    if (m_entityTemp->base.destructible)
                    {
                        if (m_entityTemp->base.hitPoints > 0)
                        {
                            m_particleEngine->spawnParticles(eParticleType::particleType_smoke, 40, glm::vec3(m_entityTemp->base.position.x, -1.0f, m_entityTemp->base.position.z));
                            m_entityTemp->base.hitPoints = (rand() % 100 < 50) ? 1 : m_entityTemp->base.hitPoints;
                            m_entityTemp->base.hitPoints--;
                        }
                        if (m_entityTemp->base.hitPoints <= 0)
                        {
                            // object death state
                            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_die);

                            // remove object from map
                            m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                            // spawn debris
                            sEntity* tEntity = m_particleEngine->spawnEntity(m_entityTemp->base.debris, 0, eDatabaseType::databaseTypeObject, m_entityTemp->base.position);
                            tEntity->base.destructible = false;
                            tEntity->base.collectable = false;

                            // spawn npc
                            if  ((rand() % 100) < 20)
                            {
                                tEntity = m_particleEngine->spawnEntity("bat", 0, eDatabaseType::databaseTypeNpc, glm::vec3(m_entityTemp->base.position.x, 1.0f, m_entityTemp->base.position.z));
                            }

                            glm::vec3 spawnPosition = m_entityTemp->base.position;
                            spawnPosition.y = m_mapPointer->info.terrainHeight - 1.0f;

                            // Loot:
                            if (m_entityTemp->loot != nullptr)
                            {
                                // Gold
                                if (m_entityTemp->loot->gold)
                                {
                                    m_entityTemp->loot->gold = false;

                                    std::uint32_t gold = m_entityTemp->loot->gold_min;
                                    gold += rand() % (m_entityTemp->loot->gold_max - m_entityTemp->loot->gold_min);

                                    sEntity* tEntity = nullptr;
                                    tEntity = m_particleEngine->spawnEntity("coins", 0, eDatabaseType::databaseTypeItem, spawnPosition);

                                    // if the entity could be loaded
                                    if (tEntity != nullptr)
                                    {
                                        // variation: position
                                        float posX = gRandFloatNormalized() - 1.0f;
                                        float posZ = gRandFloatNormalized() - 1.0f;
                                        tEntity->base.position.x += posX;
                                        tEntity->base.position.z += posZ;

                                        // variation: rotation
                                        float rotation = gRandFloatNormalized() * M_PI * 2;
                                        tEntity->base.rotation.x = rotation * tEntity->base.rotationAxis.x;
                                        tEntity->base.rotation.y = rotation * tEntity->base.rotationAxis.y;
                                        tEntity->base.rotation.z = rotation * tEntity->base.rotationAxis.z;

                                        // Update model matrix
                                        m_entityManager->updateModelMatrix(tEntity);

                                        // text tooltip
                                        tEntity->base.textActive = true;
                                        tEntity->base.textData = std::to_string(gold);
                                        tEntity->base.collectable = true;

                                        // loot: gold
                                        if (tEntity->loot == nullptr)
                                        {
                                            tEntity->loot = new sEntityLoot;
                                        }
                                        tEntity->loot->gold     = true;
                                        tEntity->loot->gold_min = gold;
                                        tEntity->loot->gold_max = gold;
                                    }
                                }
                            }

                            // Delete the entity from the game
                            m_particleEngine->deleteEntity(m_entityTemp);
                        }
                        else
                        {
                            // Object get hit state
                            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_defend);
                        }
                    }

                    // Collectable
                    if (m_entityTemp->base.collectable)
                    {
                        // Gold
                        if ((m_entityTemp->loot) && (m_entityTemp->loot->gold))
                        {
                            m_entityPlayer->character->gold += m_entityTemp->loot->gold_max;
                        }

                        // item
                        if (m_entityTemp->loot)// && (m_entityTemp->loot->itemID != 0))
                        {
                            //std::cout << "Item clicked: " << m_entityTemp->base.textData << std::endl;
                            //std::cout << "Item ID: " << m_entityTemp->loot->itemID << std::endl;
                        }

                        // Set entity state
                        m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);

                        // Delete the entity from the game
                        m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;
                        m_particleEngine->deleteEntity(m_entityTemp);
                    }

                    // Handle custom interaction states
                    if ((m_entityTemp->interaction != nullptr) && (m_entityTemp->interaction->mouse))
                    {
                        if ((m_entityTemp->interaction->type == eEntityInteraction::entityInteraction_activate) ||
                            (m_entityTemp->interaction->type == eEntityInteraction::entityInteraction_set) ||
                            (m_entityTemp->interaction->type == eEntityInteraction::entityInteraction_toggle))
                        {
                            m_entityManager->triggerEntity(m_entityTemp);
                        }
                    }

                    // Update player matrix
                    m_entityManager->updateModelMatrix(m_entityPlayer);
                }
            }
        }
    }
}