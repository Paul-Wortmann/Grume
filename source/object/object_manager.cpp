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

void cObjectManager::process(const std::int64_t &_dt)
{
    // Map warp data
    std::string   mapName   = {};
    // bool          mapWarp   = false;
    // std::uint32_t mapPortal = 0;

    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp->base.inRnge) && (m_entityTemp->base.enabled) && (m_entityPlayer != nullptr) &&
           ((m_entityTemp->base.type == eEntityType::entityType_objectStatic) || (m_entityTemp->base.type == eEntityType::entityType_objectDynamic)))
        {
            // Calculate the distance to the player
            float distPlayerSqrd = (((m_entityTemp->base.position.x - m_entityPlayer->base.position.x) *
                                     (m_entityTemp->base.position.x - m_entityPlayer->base.position.x)) +
                                    ((m_entityTemp->base.position.z - m_entityPlayer->base.position.z) *
                                     (m_entityTemp->base.position.z - m_entityPlayer->base.position.z)));

            float playerAwareDistance    = 50.0f;
            // float playerAttackDistance   = 1.0f;
            // float playerMovetoDistance   = 10.0f;
            // float playerMoveAwayDistance = 0.75f;

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
                            // Avoid unintended mouse clicks
                            m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
                            m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
                            m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
                            m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

                            // object death state
                            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_die);
                            m_entityTemp->base.dying = true;

                            // remove object from map
                            m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;

                            // spawn debris
                            sEntity* tEntityDebris = m_particleEngine->spawnEntity(m_entityTemp->base.debris, 0, eDatabaseType::databaseTypeObject, m_entityTemp->base.position);
                            tEntityDebris->base.destructible = false;
                            tEntityDebris->base.collectable = false;

                            // spawn npc
                            if ((m_mapPointer->numNPCmob > 0) && ((rand() % 100) < 20))
                            {
                                sEntity* tEntityMob = m_particleEngine->spawnEntity(m_mapPointer->npcMob[0].databaseName, m_mapPointer->npcMob[0].databaseNumber, eDatabaseType::databaseTypeNpc, m_entityTemp->base.position);
                            }

                            // Loot:
                            if (m_entityTemp->loot != nullptr)
                            {
                                // Gold
                                if (m_entityTemp->loot->gold > 0)
                                {
                                    for (std::uint32_t i = 0; i < m_entityTemp->loot->gold; ++i)
                                    {
                                        std::uint32_t gold = m_entityTemp->loot->gold_min;
                                        gold += rand() % (m_entityTemp->loot->gold_max - m_entityTemp->loot->gold_min);

                                        glm::vec3 spawnPosition = m_entityTemp->base.position;
                                        //spawnPosition.y = m_mapPointer->info.terrainHeight - 1.0f;

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
                                            float rotation = gRandFloatNormalized() * static_cast<float>(M_PI) * 2.0f;
                                            tEntity->base.rotation.x = rotation * tEntity->base.rotationAxis.x;
                                            tEntity->base.rotation.y = rotation * tEntity->base.rotationAxis.y;
                                            tEntity->base.rotation.z = rotation * tEntity->base.rotationAxis.z;

                                            // Update model matrix
                                            m_entityManager->updateModelMatrix(tEntity);

                                            // text tool-tip
                                            tEntity->base.textActive = true;
                                            tEntity->base.textData = std::to_string(gold);
                                            tEntity->base.collectable = true;

                                            // loot: gold
                                            if (tEntity->loot == nullptr)
                                            {
                                                tEntity->loot = new sEntityLoot;
                                            }
                                            tEntity->loot->gold     = 1;
                                            tEntity->loot->gold_min = gold;
                                            tEntity->loot->gold_max = gold;
                                        }
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

                    // Collectible
                    if (m_entityTemp->base.collectable)
                    {
                        // Avoid unintended mouse clicks
                        m_io->keyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
                        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_LEFT] = false;
                        m_io->keyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;
                        m_io->keyReadyMap[GLFW_MOUSE_BUTTON_RIGHT] = false;

                        // Gold
                        if ((m_entityTemp->loot) && (m_entityTemp->loot->gold))
                        {
                            m_entityPlayer->character->gold += m_entityTemp->loot->gold_max;

                            // Set entity state
                            m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);

                            // Delete the entity from the game
                            m_mapPointer->tile[m_entityTemp->base.tileOnMap].entity.type = eTileEntityType::tileEntityNone;
                            m_entityTemp->base.dying = true;
                            m_particleEngine->deleteEntity(m_entityTemp);

                            // Event: gold drop
                            sObjectManagerEvent* event = new sObjectManagerEvent;
                            event->type = eObjectEventType::objectEventType_gold;
                            event->data = m_entityPlayer->character->gold;
                            m_event.push(event);

                        }

                        // item
                        else if (m_entityTemp->loot)// && (m_entityTemp->loot->itemID != 0))
                        {
                            //std::cout << "Item clicked: " << m_entityTemp->base.textData << std::endl;
                            //std::cout << "Item ID: " << m_entityTemp->loot->itemID << std::endl;
                            if (m_playerManager->getInventoryFreeSlotNum() > 0)
                            {
                                // Set entity state
                                m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);

                                // Pickup item
                                m_playerManager->inventoryPickupItem(m_entityTemp);
                            }
                            else
                            {
                                // Can't pick up item, no free inventory space

                                // pickup and drop.

                                // Set entity state
                                m_entityManager->stateSet(m_entityTemp, eEntityState::entityState_interact);
                            }

                        }
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
