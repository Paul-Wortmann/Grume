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
 
#include "npc_manager.hpp"

void cNPCManager::initialize(cEntityManager* _entityManager)
{
    m_entityManager = _entityManager;
}

void cNPCManager::terminate(void)
{

}

uint32 cNPCManager::m_positionToTile(glm::vec3 _position)
{
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(m_mapPointer->width)  / 2.0f;
    float32 zo = static_cast<float32>(m_mapPointer->height) / 2.0f;

    uint32 x = static_cast<uint32>(_position.x + xo);
    uint32 z = static_cast<uint32>(_position.z + zo);
    return (z * m_mapPointer->width) + x;
};

glm::vec3 cNPCManager::m_tileToPosition(uint32 _tile)
{ 
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(m_mapPointer->width)  / 2.0f;
    float32 zo = static_cast<float32>(m_mapPointer->height) / 2.0f;
    float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    float32 x = static_cast<float32>(_tile % m_mapPointer->width) - xo + tp;
    float32 z = static_cast<float32>(_tile / m_mapPointer->width) - zo + tp;
    return glm::vec3(x, m_mapPointer->terrainHeight, z);
};

void cNPCManager::process(const float32 &_dt)
{
    // Entities
    for(m_entityTemp = m_entityHead; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityPlayer != nullptr) && (m_entityTemp->type == eEntityType::entityTypeNPCmob) && (m_entityTemp->terminate == false))
        {
            // Turn to face the player
            //glm::vec3 rotation = m_entityTemp->rotation;
            float32 angle = static_cast<float32>(atan2(m_entityTemp->position.z - m_entityPlayer->position.z, m_entityTemp->position.x - m_entityPlayer->position.x));
            m_entityTemp->rotation.y = angle + m_entityTemp->rotationOffset.y;
            
            // Check if player is visable, if so continue
            if ((m_entityTemp->ai != nullptr) && (1 == 1)) // FIXME!
            {
                // Calculate the distance to the player
                float32 distancetoPlayer2 = (((m_entityTemp->position.x - m_entityPlayer->position.x) * 
                                              (m_entityTemp->position.x - m_entityPlayer->position.x)) +
                                             ((m_entityTemp->position.z - m_entityPlayer->position.z) * 
                                              (m_entityTemp->position.z - m_entityPlayer->position.z)));
                
                // Check if player is in attack range, if so attack
                if (distancetoPlayer2 < (m_entityTemp->ai->distanceAttack) * (m_entityTemp->ai->distanceAttack))
                {
                    // Attack
                    //std::cout << "Can attack! : " << m_entityTemp->UID << std::endl;

                    m_entityTemp->ai->attack_counter += _dt;
                    if (m_entityTemp->ai->attack_counter > m_entityTemp->ai->attack_frequency)
                    {
                        m_entityTemp->ai->attack_counter = 0.0f;

                        // Set attack state
                        m_entityManager->setState(m_entityTemp->UID, "attack");
                    }
                    else
                    {
                        // Set move state
                        m_entityManager->setState(m_entityTemp->UID, "idle");
                    }
                }
                
                // Check if player is in move range, if so continue
                else if (distancetoPlayer2 < (m_entityTemp->ai->distanceMove) * (m_entityTemp->ai->distanceMove))
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
                    
                    // if path is valid, move towards player
                    m_entityTemp->movement->moved = false;
                    if (m_entityTemp->movement->mapPath.pathLength == 0)
                    {
                        m_entityTemp->movement->pathing = false;
                    }
                    if (m_entityTemp->movement->pathing)
                    {
                        // move amount
                        m_entityTemp->movement->moveDelta.x = 0.0f;
                        m_entityTemp->movement->moveDelta.z = 0.0f;
                        
                        m_entityTemp->movement->moved = true;
                        glm::vec3 entityPos      = m_entityTemp->position;

                        m_mapPointer->tile[m_entityTemp->movement->mapPath.currentTile].npc = 0;
                        m_entityTemp->movement->mapPath.currentTile = m_entityTemp->movement->mapPath.path[m_entityTemp->movement->mapPath.currentPosition];
                        glm::vec3 currentTilePos = m_tileToPosition(m_entityTemp->movement->mapPath.currentTile);
                        
                        // Get the distance to the destination tile
                        float32   distanceToTileSqr = ((entityPos.x - currentTilePos.x) * (entityPos.x - currentTilePos.x)) + ((entityPos.z - currentTilePos.z) * (entityPos.z - currentTilePos.z));
                        
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
                }
                
                // Idle
                else
                {
                    // Set idle animation
                    m_entityManager->setState(m_entityTemp->UID, "idle");
                }
            }
            
            // Lastly update the entity's model matrix.
            m_entityManager->updateModelMatrix(m_entityTemp);
        }
    }
}




