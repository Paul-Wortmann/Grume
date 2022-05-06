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

#include "player_manager.hpp"

void cPlayerManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
}

void cPlayerManager::terminate(void)
{
}

sEntity* cPlayerManager::load(const std::string &_fileName)
{
    m_player = m_entityManager->load("player/" + _fileName);

    if (m_player != nullptr)
    {
        gLogWrite(LOG_INFO, "Loading player: " + m_player->name, __FILE__, __LINE__, __FUNCTION__);

        m_player->owner = eEntityOwner::entityOwnerNone;
        m_player->type  = eEntityType::entityTypeOther;

        // Load the biome sound database file
        cXML xmlSoundFile;
        xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);

        // Load audio file names
        if ((m_player->stateCount > 0) && (xmlSoundFile.lineCount() > 0))
        {
            for (std::uint32_t s = 0; s < m_player->stateCount; ++s)
            {
                m_player->state[s].audioFile = gGetFileName(xmlSoundFile, "<sound>" + m_player->state[s].audioDBname + " ", m_player->state[s].audioDBIndex);
            }
        }

        // Cleanup
        xmlSoundFile.free();
    }

    return m_player;
};

std::uint32_t cPlayerManager::positionToTile(glm::vec3 _position)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(m_mapPointer->width)  / 2.0f;
    float zo = static_cast<float>(m_mapPointer->height) / 2.0f;
    float tp = 0.0f;//1.0f / 2.0f; // tile center positioning ( half model dimention)

    std::uint32_t x = static_cast<std::uint32_t>(_position.x + xo - tp);
    std::uint32_t z = static_cast<std::uint32_t>(_position.z + zo - tp);
    return (z * m_mapPointer->width) + x;
};

glm::vec3 cPlayerManager::tileToPosition(std::uint32_t _tile)
{ 
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(m_mapPointer->width)  / 2.0f;
    float zo = static_cast<float>(m_mapPointer->height) / 2.0f;
    float tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    float x = static_cast<float>(_tile % m_mapPointer->width) - xo + tp;
    float z = static_cast<float>(_tile / m_mapPointer->width) - zo + tp;
    return glm::vec3(x, m_mapPointer->terrainHeight, z);
};

void cPlayerManager::setMouseClick(glm::vec3 _pos)
{
    if (m_mouseTimerOK == true)
    {
        m_mouseTimerOK = false;
        m_mouseClicked = true;
        m_mousePos     = _pos;
        m_mouseTile    = positionToTile(_pos);
    }
};

void cPlayerManager::process(const float &_dt)
{
    // Process character atributes / characteristics
    // Health
    if (m_player->character->attributes.health.current <= 0.0f)
    {
        // Player death
        m_player->character->attributes.health.current = 0.0f;
    }
    else
    {
        // Health regen
        m_player->character->attributes.health.current += m_player->character->attributes.health.regen;
        if (m_player->character->attributes.health.current > m_player->character->attributes.health.max)
        {
            m_player->character->attributes.health.current = m_player->character->attributes.health.max;
        }
    }
    
    // Mana
    if (m_player->character->attributes.mana.current <= 0.0f)
    {
        m_player->character->attributes.mana.current = 0.0f;
    }
    else
    {
        // Mana regen
        m_player->character->attributes.mana.current += m_player->character->attributes.mana.regen;
        if (m_player->character->attributes.mana.current > m_player->character->attributes.mana.max)
        {
            m_player->character->attributes.mana.current = m_player->character->attributes.mana.max;
        }
    }
    
    // Process mouse timer
    if (m_mouseTimerOK != true)
    {
        m_mouseTimer += _dt;
        if (m_mouseTimer > m_mouseTimerMax)
        {
            m_mouseTimerOK = true;
        }
    }
    
    // Process mouse click event
    if (m_mouseClicked)
    {
        m_mouseClicked = false;

        // Mouse clicked outside of map bounds, invalid
        if (m_mouseTile >= m_mapPointer->numTiles)
        {
            return;
        }
        
        // Store position information
        glm::vec3 playerPos     = m_player->position;
        glm::vec3 entityTilePos = tileToPosition(m_mouseTile);
        
        // Get the distance to the destination tile
        float   distanceToTileSqr = ((playerPos.x - entityTilePos.x) * (playerPos.x - entityTilePos.x)) + ((playerPos.z - entityTilePos.z) * (playerPos.z - entityTilePos.z));
        
        bool      moveToEntity = false;
        
        // If click object
        if (m_mapPointer->tile[m_mouseTile].object != 0)
        {
            std::cout << "object clicked: " << m_mouseTile << std::endl;
            
            // find object uid
            for (sEntity* entity = m_entityManager->getHead(); entity != nullptr; entity = entity->next)
            {
                if (entity->UID == m_mapPointer->tile[m_mouseTile].object)
                {
                    if ((entity->interaction != nullptr) && (distanceToTileSqr <= entity->interaction->distance))
                    {
                        // Toggle states
                        if (entity->interaction->type == eEntityInteractionType::interactionTypeToggle)
                        {
                            m_entityManager->toggleState(entity->UID, entity->interaction->data_1, entity->interaction->data_2);
                        }
                        // Set state
                        else if (entity->interaction->type == eEntityInteractionType::interactionTypeSet)
                        {
                            m_entityManager->setState(entity->UID, entity->interaction->data_1);
                        }
                        
                        // Trigger tile
                        if (entity->triggerTile != 0)
                        {
                            if (m_mapPointer->tile[entity->triggerTile].object != 0)
                            {
                                std::cout << "object triggered: " << entity->triggerTile << std::endl;
                                
                                // find object uid
                                for (sEntity* tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
                                {
                                    if (tEntity->UID == m_mapPointer->tile[entity->triggerTile].object)
                                    {
                                        if ((tEntity->interaction != nullptr) && (distanceToTileSqr <= tEntity->interaction->distance))
                                        {
                                            // Toggle states
                                            if (tEntity->interaction->type == eEntityInteractionType::interactionTypeToggle)
                                            {
                                                m_entityManager->toggleState(tEntity->UID, tEntity->interaction->data_1, tEntity->interaction->data_2);
                                            }
                                            // Set state
                                            else if (tEntity->interaction->type == eEntityInteractionType::interactionTypeSet)
                                            {
                                                m_entityManager->setState(tEntity->UID, tEntity->interaction->data_1);
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // Stop all enemies from pathing, this will cause all enemies to recalculate thier paths
                        for (sEntity* pEntity = m_entityManager->getHead(); pEntity != nullptr; pEntity = pEntity->next)
                        {
                            if ((pEntity != nullptr) && (pEntity->movement != nullptr))
                            {
                                pEntity->movement->mapPath.pathLength = 0;
                                pEntity->movement->pathing = false;
                            }
                        }
                    }
                    else
                    {
                        moveToEntity = true;
                    }
                }
            }
        }
        
        // If click NPC
        if (m_mapPointer->tile[m_mouseTile].npc != 0)
        {
            std::cout << "NPC clicked: " << m_mouseTile << std::endl;
            
            // Get the entity pointer from the npc UID
            sEntity* tEntity = nullptr;
            for (tEntity = m_entityManager->getHead(); tEntity != nullptr; tEntity = tEntity->next)
            {
                if ((tEntity->UID == m_mapPointer->tile[m_mouseTile].npc) && (m_player->UID != tEntity->UID))
                {
                    break;
                }
            }
            
            // NPC
            if (tEntity->type == eEntityType::entityTypeNPC)
            {
                // Set npc state and set the npc for termination
                if (tEntity->interaction != nullptr)
                {
                    if (distanceToTileSqr <= tEntity->interaction->distance)
                    {
                        m_entityManager->activateState(tEntity->UID, "interact");
                    }
                    else
                    {
                        moveToEntity = true;
                    }
                }
            }
            
            // NPC Mob
            else if (tEntity->type == eEntityType::entityTypeNPCmob)
            {
                // We should check the distance to the enemy first

                // Set state - attack
                m_entityManager->setState(m_player->UID, "attack");

                // Set npc state and set the npc for termination
                if ((tEntity->interaction != nullptr) && (tEntity->terminate == false))
                {
                    if (distanceToTileSqr <= tEntity->interaction->distance)
                    {
                        // Damage the NPC
                        // **** this should be based on player stength and NPC defence, etc...
                        
                        float damage = (tEntity->character->attributes.health.max / 2.0f);
                        
                        tEntity->character->attributes.health.current -= damage;
                        
                        // NPC has been killed
                        if (tEntity->character->attributes.health.current <= 0.0f)
                        {
                            m_entityManager->setState(tEntity->UID, "die");
                            m_mapPointer->tile[m_mouseTile].npc = 0;
                            tEntity->terminate = true;
                            
                            // Screen shake on NPC death
                            if ((rand() % 100) <= tEntity->deathShakeChance)
                            {
                                m_graphicsEngine->addScreenShake(tEntity->deathShakeDuration, tEntity->deathShakeForce);
                            }
                            
                            // Award the player with experience if not max level
                            if (m_player->character->level.current < m_player->character->level.max)
                            {
                                // Experience derived from the slaughtered NPC
                                m_player->character->level.exp += tEntity->character->drop.experience;
                                if (m_player->character->level.exp > m_player->character->level.expNext)
                                {
                                    while (m_player->character->level.exp > m_player->character->level.expNext)
                                    {
                                        // Level up state
                                        m_entityManager->setForceState(m_player->UID, "levelUp");
                                        
                                        // Increase level
                                        m_player->character->level.exp -= m_player->character->level.expNext;
                                        m_player->character->level.expNext *= m_player->character->level.expMultiplier;
                                        m_player->character->level.current++;
                                        
                                        // Increase attributes + skills
                                        // *** Currently automatic, could be player controlled in the future ***
                                        
                                        // Health
                                        m_player->character->attributes.health.max += (m_player->character->attributes.health.max / 2.0f);
                                        m_player->character->attributes.health.current = m_player->character->attributes.health.max;
                                        m_player->character->attributes.health.regen += 0.005f;
                                        
                                        // Mana
                                        m_player->character->attributes.mana.max += (m_player->character->attributes.mana.max / 2.0f);
                                        m_player->character->attributes.mana.current = m_player->character->attributes.mana.max;
                                        m_player->character->attributes.mana.regen += 0.005f;
                                        
                                        // Damage
                                        m_player->character->attributes.damagePhysical.base += 1;
                                        m_player->character->attributes.damagePhysical.critChancev += 1.0f;
                                        m_player->character->attributes.damagePhysical.critMultiplier += 0.25f;
                                        m_player->character->attributes.damageFire.base += 1;
                                        m_player->character->attributes.damageFire.critChancev += 1.0f;
                                        m_player->character->attributes.damageFire.critMultiplier += 0.25f;
                                        m_player->character->attributes.damageFrost.base += 1;
                                        m_player->character->attributes.damageFrost.critChancev += 1.0f;
                                        m_player->character->attributes.damageFrost.critMultiplier += 0.25f;
                                        
                                        // Armor
                                        m_player->character->attributes.armorPhysical.base += 1;
                                        
                                        // Resistance
                                        m_player->character->attributes.resistanceFire.base += 1;
                                        m_player->character->attributes.resistanceFrost.base += 1;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        moveToEntity = true;
                    }
                }
            }
        }
        
        // If no object and no NPC, then path find to tile
        if (((m_mapPointer->tile[m_mouseTile].object == 0) && (m_mapPointer->tile[m_mouseTile].npc == 0)) || (moveToEntity))
        {
            // Only path to new destination if it is different
            if (m_player->movement->mapPath.destinationTile != m_mouseTile)
            {
                m_player->movement->mapPath.destinationTile = m_mouseTile;
                gAStar(m_mapPointer, m_player->movement->mapPath);

                if (m_player->movement->mapPath.pathLength > 0)
                {
                    m_player->movement->mapPath.currentPosition = 1;
                    m_player->movement->pathing = true;

                    // Set state - move
                    m_entityManager->setState(m_player->UID, "move");
                }
            }
        }
    }
    
    m_player->movement->moved = false;
    
    if (m_player->movement->mapPath.pathLength == 0)
    {
        m_player->movement->pathing = false;
    }
    
    if (m_player->movement->pathing)
    {
        // move amount
        m_player->movement->moveDelta.x = 0.0f;
        m_player->movement->moveDelta.z = 0.0f;
        
        //std::cout << "Current tile: " << m_path.path[m_path.currentPosition] << std::endl;
        m_player->movement->moved = true;
        glm::vec3     playerPos      = m_player->position;
        glm::vec3     playerPrevPos  = m_player->position;
        glm::vec3     playerRot      = m_player->rotation;
        std::uint32_t currentTile    = m_player->movement->mapPath.path[m_player->movement->mapPath.currentPosition];
        glm::vec3     currentTilePos = tileToPosition(currentTile);
        
        // Get the distance to the destination tile
        float   distanceToTileSqr = ((playerPos.x - currentTilePos.x) * (playerPos.x - currentTilePos.x)) + ((playerPos.z - currentTilePos.z) * (playerPos.z - currentTilePos.z));
        
        // if not center, move towards tile center
        if (distanceToTileSqr > (m_player->movement->movementSpeed + m_player->movement->movementBias))
        {
            // Position
            if ((playerPos.x + m_player->movement->movementSpeed) < currentTilePos.x)
            {
                playerPos.x += m_player->movement->movementSpeed;
                m_player->movement->moveDelta.x += m_player->movement->movementSpeed;
            }
            else if ((playerPos.x + m_player->movement->movementSpeed) > currentTilePos.x)
            {
                playerPos.x -= m_player->movement->movementSpeed;
                m_player->movement->moveDelta.x -= m_player->movement->movementSpeed;
            }
            if ((playerPos.z + m_player->movement->movementSpeed) < currentTilePos.z)
            {
                playerPos.z += m_player->movement->movementSpeed;
                m_player->movement->moveDelta.z += m_player->movement->movementSpeed;
            }
            else if ((playerPos.z + m_player->movement->movementSpeed) > currentTilePos.z)
            {
                playerPos.z -= m_player->movement->movementSpeed;
                m_player->movement->moveDelta.z -= m_player->movement->movementSpeed;
            }
            
            // Turn to face move direction
            float angle = static_cast<float>(atan2(playerPos.z - playerPrevPos.z, playerPrevPos.x - playerPos.x));
            if (m_player->rotationAxis.x != 0)
            {
                playerRot.x = m_player->rotationOffset.x + (angle * m_player->rotationAxis.x);
            }
            else if (m_player->rotationAxis.y != 0)
            {
                playerRot.y = m_player->rotationOffset.y + (angle * m_player->rotationAxis.y);
            }
            else if (m_player->rotationAxis.z != 0)
            {
                playerRot.z = m_player->rotationOffset.z + (angle * m_player->rotationAxis.z);
            }
        }
        
        // move to tile center, set new tile in path
        else
        {
            //playerPos = currentTilePos;
            m_player->movement->mapPath.currentPosition++;
            if (m_player->movement->mapPath.currentPosition >= m_player->movement->mapPath.pathLength)
            {
                m_player->movement->pathing = false;
                m_player->movement->moveDelta.x = 0.0f;
                m_player->movement->moveDelta.z = 0.0f;
                
                // Set state - idle
                m_entityManager->setState(m_player->UID, "idle");
            }
        }

        m_player->position = playerPos; 
        m_player->movement->mapPath.currentTile = positionToTile(playerPos);
        m_player->rotation = playerRot; 
        m_updateMatrix();
    }
}

