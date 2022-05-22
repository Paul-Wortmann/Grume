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

#include "npc_manager.hpp"

void cNPCManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
}

void cNPCManager::terminate(void)
{

}

std::uint32_t cNPCManager::m_positionToTile(glm::vec3 _position)
{
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(m_mapPointer->width)  / 2.0f;
    float zo = static_cast<float>(m_mapPointer->height) / 2.0f;

    std::uint32_t x = static_cast<std::uint32_t>(_position.x + xo);
    std::uint32_t z = static_cast<std::uint32_t>(_position.z + zo);
    return (z * m_mapPointer->width) + x;
};

glm::vec3 cNPCManager::m_tileToPosition(std::uint32_t _tile)
{ 
    // Width and height offset, used to center the walls
    float xo = static_cast<float>(m_mapPointer->width)  / 2.0f;
    float zo = static_cast<float>(m_mapPointer->height) / 2.0f;
    float tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    float x = static_cast<float>(_tile % m_mapPointer->width) - xo + tp;
    float z = static_cast<float>(_tile / m_mapPointer->width) - zo + tp;
    return glm::vec3(x, m_mapPointer->terrainHeight, z);
};

void cNPCManager::process(const float &_dt)
{
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityPlayer != nullptr) && (m_entityTemp->type == eEntityType::entityTypeNPCmob) && (m_entityTemp->terminate == false))
        {
            // Health mana regen
            {
                // Health
                m_entityTemp->character->attributes.health.current += m_entityTemp->character->attributes.health.regen;
                if (m_entityTemp->character->attributes.health.current > m_entityTemp->character->attributes.health.max)
                {
                    m_entityTemp->character->attributes.health.current = m_entityTemp->character->attributes.health.max;
                }

                // Mana
                m_entityTemp->character->attributes.mana.current += m_entityTemp->character->attributes.mana.regen;
                if (m_entityTemp->character->attributes.mana.current > m_entityTemp->character->attributes.mana.max)
                {
                    m_entityTemp->character->attributes.mana.current = m_entityTemp->character->attributes.mana.max;
                }
            }
            
            // Proceed if entity has an AI compinent
            if (m_entityTemp->ai != nullptr)
            {
                // Direction angle to face
                float faceDirection = 0.0f;
                
                // Calculate the distance to the player
                float distancetoPlayer2 = (((m_entityTemp->position.x - m_entityPlayer->position.x) * 
                                            (m_entityTemp->position.x - m_entityPlayer->position.x)) +
                                           ((m_entityTemp->position.z - m_entityPlayer->position.z) * 
                                            (m_entityTemp->position.z - m_entityPlayer->position.z)));
                
                bool inRangeAttack = (distancetoPlayer2 < (m_entityTemp->ai->distanceAttack) * (m_entityTemp->ai->distanceAttack));
                bool inRangePursue = (distancetoPlayer2 < (m_entityTemp->ai->distanceMove) * (m_entityTemp->ai->distanceMove));
                bool playerVisable = false;
                
                // Check if player is visable (Only check if in pursue range)
                if (inRangePursue)
                {
                    playerVisable = gLineOfSight(m_mapPointer, m_positionToTile(m_entityPlayer->position), m_positionToTile(m_entityTemp->position));
                }
                
                // Check if player is in attack range, if so attack
                if (inRangeAttack)
                {
                    // Direction angle to face: player
                    faceDirection = static_cast<float>(atan2(m_entityTemp->position.z - m_entityPlayer->position.z, m_entityTemp->position.x - m_entityPlayer->position.x));

                    // Attack
                    //std::cout << "Can attack! : " << m_entityTemp->UID << std::endl;

                    m_entityTemp->ai->attackCounter += _dt;
                    if (m_entityTemp->ai->attackCounter > m_entityTemp->ai->attackFrequency)
                    {
                        m_entityTemp->ai->attackCounter = 0.0f;
                        
                        // Inflict damage on the player
                        // **** this should be based on NPC strength and player defense, etc...
                        
                        float damage = m_entityTemp->character->attributes.damagePhysical.base / 2.0f;
                        m_entityPlayer->character->attributes.health.current -= damage;

                        // Player death
                        if (m_entityPlayer->character->attributes.health.current <= 0)
                        {
                            m_entityPlayer->character->attributes.health.current = 0;
                        }

                        // Set attack state
                        m_entityManager->setState(m_entityTemp->UID, "attack");
                        m_entityManager->activateState(m_entityPlayer->UID, "gethit");
                    }
                    else
                    {
                        // Set move state
                        m_entityManager->setState(m_entityTemp->UID, "idle");
                    }
                }
                
                // Check if player is in move range and viasble, path to player
                else if ((inRangePursue) && (playerVisable == true))
                {
                    // If the player has moved, path to the new player position
                    if (m_entityTemp->ai->lastKnownPlayerTile != m_entityPlayer->movement->mapPath.currentTile)
                    {
                        // Current tile
                        m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = 0;
                        m_entityTemp->movement->mapPath.currentTile = m_positionToTile(m_entityTemp->position);

                        m_entityTemp->ai->lastKnownPlayerTile = m_entityPlayer->movement->mapPath.currentTile;
                        m_entityTemp->movement->mapPath.destinationTile = m_entityPlayer->movement->mapPath.currentTile;
                        gAStar(m_mapPointer, m_entityTemp->movement->mapPath);
                        if (m_entityTemp->movement->mapPath.pathLength > 0)
                        {
                            m_entityTemp->movement->mapPath.currentPosition = 0;
                            m_entityTemp->movement->pathing = true;

                            // Set move animation
                            m_entityManager->setState(m_entityTemp->UID, "move");
                        }
                    }
                    
                    // if path invalid, cancel pathing
                    m_entityTemp->movement->moved = false;
                    if (m_entityTemp->movement->mapPath.pathLength == 0)
                    {
                        m_entityTemp->movement->mapPath.currentPosition = 0;
                        m_entityTemp->movement->pathing = false;
                    }
                }
                
                // Check if player is in move range and not viasble, path to last known player position
                else if ((inRangePursue) && (playerVisable == false))
                {
                    // Continue with current objective
                    // if path invalid, cancel pathing
                    m_entityTemp->movement->moved = false;
                    m_entityTemp->movement->mapPath.currentTile = m_entityTemp->ai->lastKnownPlayerTile;
                    m_entityTemp->movement->mapPath.pathLength = 0;
                    m_entityTemp->movement->mapPath.currentPosition = 0;
                    m_entityTemp->movement->pathing = false;
                }

                // If the player is not in range, 
                // first move to the last known player tile,
                // then move back to ones spawn tile.
                else if ((m_entityTemp->movement->mapPath.currentTile == m_entityTemp->ai->lastKnownPlayerTile) &&
                         (m_entityTemp->movement->pathing == false))
                {
                    // Current tile
                    m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = 0;
                    m_entityTemp->movement->mapPath.currentTile = m_positionToTile(m_entityTemp->position);

                    m_entityTemp->movement->mapPath.destinationTile = m_entityTemp->ai->spawnTile;
                    gAStar(m_mapPointer, m_entityTemp->movement->mapPath);
                    if (m_entityTemp->movement->mapPath.pathLength > 0)
                    {
                        m_entityTemp->movement->mapPath.currentPosition = 0;
                        m_entityTemp->movement->pathing = true;

                        // Set move animation
                        m_entityManager->setState(m_entityTemp->UID, "move");
                    }
                    
                    // if path invalid, cancel pathing
                    m_entityTemp->movement->moved = false;
                    if (m_entityTemp->movement->mapPath.pathLength == 0)
                    {
                        m_entityTemp->movement->pathing = false;
                    }
                }
                
                // Idle
                else
                {
                    // Set idle animation
                    if (m_entityTemp->movement->pathing == false)
                    {
                        m_entityManager->setState(m_entityTemp->UID, "idle");
                    }
                }
                
                // Move if pathing active
                if (m_entityTemp->movement->pathing)
                {
                    // move amount
                    m_entityTemp->movement->moveDelta.x = 0.0f;
                    m_entityTemp->movement->moveDelta.z = 0.0f;
                    
                    m_entityTemp->movement->moved = true;
                    glm::vec3 entityPos = m_entityTemp->position;

                    m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = 0;
                    m_entityTemp->movement->mapPath.currentTile = m_entityTemp->movement->mapPath.path[m_entityTemp->movement->mapPath.currentPosition];
                    glm::vec3 currentTilePos = m_tileToPosition(m_entityTemp->movement->mapPath.currentTile);
                    
                    // Direction angle to face: tile
                    faceDirection = static_cast<float>(atan2(m_entityTemp->position.z - currentTilePos.z, m_entityTemp->position.x - currentTilePos.x));

                    // Get the distance to the destination tile
                    float   distanceToTileSqr = ((entityPos.x - currentTilePos.x) * (entityPos.x - currentTilePos.x)) + ((entityPos.z - currentTilePos.z) * (entityPos.z - currentTilePos.z));
                    
                    // if not center, move towards tile center
                    if (distanceToTileSqr > (m_entityTemp->movement->movementSpeed + m_entityTemp->movement->movementBias))
                    {
                        // Position
                        if ((entityPos.x + m_entityTemp->movement->movementSpeed) < currentTilePos.x)
                        {
                            entityPos.x += m_entityTemp->movement->movementSpeed;
                            m_entityTemp->movement->moveDelta.x += m_entityTemp->movement->movementSpeed;
                        }
                        else if ((entityPos.x + m_entityTemp->movement->movementSpeed) > currentTilePos.x)
                        {
                            entityPos.x -= m_entityTemp->movement->movementSpeed;
                            m_entityTemp->movement->moveDelta.x -= m_entityTemp->movement->movementSpeed;
                        }
                        if ((entityPos.z + m_entityTemp->movement->movementSpeed) < currentTilePos.z)
                        {
                            entityPos.z += m_entityTemp->movement->movementSpeed;
                            m_entityTemp->movement->moveDelta.z += m_entityTemp->movement->movementSpeed;
                        }
                        else if ((entityPos.z + m_entityTemp->movement->movementSpeed) > currentTilePos.z)
                        {
                            entityPos.z -= m_entityTemp->movement->movementSpeed;
                            m_entityTemp->movement->moveDelta.z -= m_entityTemp->movement->movementSpeed;
                        }
                    }
                    
                    // move to tile center, set new tile in path
                    else
                    {
                        // If we have reached the end of the path, or if it is blocked, stop
                        if (((m_entityTemp->movement->mapPath.currentPosition + 1) >= m_entityTemp->movement->mapPath.pathLength)
                          || (m_mapPointer->tile[m_entityTemp->movement->mapPath.currentPosition + 1].npc != 0))
                        {
                            m_entityTemp->movement->pathing = false;
                            m_entityTemp->movement->moveDelta.x = 0.0f;
                            m_entityTemp->movement->moveDelta.z = 0.0f;
                        }
                        else
                        {
                            // Continue pathing
                            m_entityTemp->movement->mapPath.currentPosition++;
                        }
                    }
                    m_entityTemp->position = entityPos; 
                    
                    // Update current tile if need be
                    m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = 0;
                    m_entityTemp->movement->mapPath.currentTile = m_positionToTile(m_entityTemp->position);
                    m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = m_entityTemp->UID;
                }
                
                // Turn to face the direction of interest
                if (m_entityTemp->rotationAxis.x != 0)
                {
                    m_entityTemp->rotation.x = m_entityTemp->rotationOffset.x + (faceDirection * m_entityTemp->rotationAxis.x);
                }
                else if (m_entityTemp->rotationAxis.y != 0)
                {
                    m_entityTemp->rotation.y = m_entityTemp->rotationOffset.y + (faceDirection * m_entityTemp->rotationAxis.y);
                }
                else if (m_entityTemp->rotationAxis.z != 0)
                {
                    m_entityTemp->rotation.z = m_entityTemp->rotationOffset.z + (faceDirection * m_entityTemp->rotationAxis.z);
                }
                
            }
            
            // Lastly update the entity's model matrix.
            m_entityManager->updateModelMatrix(m_entityTemp);
        }
    }
}




