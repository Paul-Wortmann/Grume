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
    m_data = m_entityManager->load("player/" + _fileName);

    if (m_data != nullptr)
    {
        gLogWrite(LOG_INFO, "Loading player: " + m_data->name, __FILE__, __LINE__, __FUNCTION__);

        m_data->owner = eEntityOwner::ownerNone;
        m_data->type  = eEntityType::entityTypeOther;

        // Load the biome sound database file
        cXML xmlSoundFile;
        xmlSoundFile.load(FILE_PATH_DATABASE + m_gameDatabase->sound.fileName);

        // Load audio file names
        if ((m_data->stateCount > 0) && (xmlSoundFile.lineCount() > 0))
        {
    
            for (std::uint32_t s = 0; s < m_data->stateCount; ++s)
            {
                if (m_data->state[s].audioDBIndex > 0)
                {
                    m_data->state[s].audioFile = xmlSoundFile.getString("<" + m_data->state[s].audioDBname + "_sound>", m_data->state[s].audioDBIndex);
                }
                else
                {
                    m_data->state[s].audioFile = xmlSoundFile.getString("<" + m_data->state[s].audioDBname + "_sound>", (rand() % (xmlSoundFile.getInstanceCount("<" + m_data->state[s].audioDBname + "_sound>") - 1)) + 1);
                }
            }
        }
        
        // Cleanup
        xmlSoundFile.free();
    }

    return m_data;
};

uint32 cPlayerManager::positionToTile(glm::vec3 _position)
{
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(m_mapPointer->width)  / 2.0f;
    float32 zo = static_cast<float32>(m_mapPointer->height) / 2.0f;

    uint32 x = static_cast<uint32>(_position.x + xo);
    uint32 z = static_cast<uint32>(_position.z + zo);
    return (z * m_mapPointer->width) + x;
};

glm::vec3 cPlayerManager::tileToPosition(uint32 _tile)
{ 
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(m_mapPointer->width)  / 2.0f;
    float32 zo = static_cast<float32>(m_mapPointer->height) / 2.0f;
    float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

    float32 x = static_cast<float32>(_tile % m_mapPointer->width) - xo + tp;
    float32 z = static_cast<float32>(_tile / m_mapPointer->width) - zo + tp;
    return glm::vec3(x, m_mapPointer->terrainHeight, z);
};

void cPlayerManager::setMouseClick(glm::vec3 _pos)
{
    uint32 clickedTile = positionToTile(_pos);
    if (clickedTile != m_mouseTile)
    {
        m_mouseClicked = true;
        m_mousePos     = _pos;
        m_mouseTile    = clickedTile;
    }
};
        
void cPlayerManager::process(const float32 &_dt)
{
    // Process mouse click event
    if (m_mouseClicked)
    {
        m_mouseClicked = false;

        // Mouse clicked outside of map bounds, invalid
        if (m_mouseTile >= m_mapPointer->numTiles)
        {
            return;
        }
        
        // If click object
        if (m_mapPointer->tile[m_mouseTile].object != 0)
        {
            std::cout << "object clicked: " << m_mouseTile << std::endl;
            
            // find object uid
            for (sEntity* entity = m_entityManager->getHead(); entity != nullptr; entity = entity->next)
            {
                if (entity->UID == m_mapPointer->tile[m_mouseTile].object)
                {
                    if (entity->interaction != nullptr)
                    {
                        // Toggle states
                        if (entity->interaction->type == 0)
                        {
                            m_entityManager->toggleState(entity->UID, entity->interaction->data_1, entity->interaction->data_2);
                        }
                        // Set state
                        else if (entity->interaction->type == 1)
                        {
                            m_entityManager->setState(entity->UID, entity->interaction->data_1);
                        }
                    }
                }
            }
            
        }
        
        // If click NPC
        if (m_mapPointer->tile[m_mouseTile].npc != 0)
        {
            std::cout << "NPC clicked: " << m_mouseTile << std::endl;
            
            // We should check the distance to the enemy first
            
            // Set state - attack
            m_entityManager->setState(m_data->UID, "attack");

            // Set npc state and set the npc for termination
            for (sEntity* entity = m_entityManager->getHead(); entity != nullptr; entity = entity->next)
            {
                if ((entity->terminate == false) && (entity->UID == m_mapPointer->tile[m_mouseTile].npc) && (m_data->UID != entity->UID))
                {
                    m_entityManager->setState(entity->UID, "die");
                    m_mapPointer->tile[m_mouseTile].npc = 0;
                    entity->terminate = true;
                }
            }
        }
        
        // If no object and no NPC, then path find to tile
        if ((m_mapPointer->tile[m_mouseTile].object == 0) && (m_mapPointer->tile[m_mouseTile].npc == 0))
        {
            m_data->movement->mapPath.destinationTile = m_mouseTile;
            gAStar(m_mapPointer, m_data->movement->mapPath);

            if (m_data->movement->mapPath.pathLength > 0)
            {
                m_data->movement->mapPath.currentPosition = 0;
                m_data->movement->pathing = true;

                // Set state - move
                m_entityManager->setState(m_data->UID, "move");
            }
        }
    }
    
    m_data->movement->moved = false;
    if (m_data->movement->mapPath.pathLength == 0)
    {
        m_data->movement->pathing = false;
    }
    if (m_data->movement->pathing)
    {
        // move amount
        m_data->movement->moveDelta.x = 0.0f;
        m_data->movement->moveDelta.z = 0.0f;
        
        // move direction, used as float comparison is problematic
        int32 deltaX = 0;
        int32 deltaZ = 0;
        
        //std::cout << "Current tile: " << m_path.path[m_path.currentPosition] << std::endl;
        m_data->movement->moved = true;
        glm::vec3 playerPos      = m_data->position;
        glm::vec3 playerPrevPos  = m_data->position;
        glm::vec3 playerRot      = m_data->rotation;
        uint32    currentTile    = m_data->movement->mapPath.path[m_data->movement->mapPath.currentPosition];
        glm::vec3 currentTilePos = tileToPosition(currentTile);
        
        // Get the distance to the destination tile
        float32   distanceToTileSqr = ((playerPos.x - currentTilePos.x) * (playerPos.x - currentTilePos.x)) + ((playerPos.z - currentTilePos.z) * (playerPos.z - currentTilePos.z));
        
        // if not center, move towards tile center
        if (distanceToTileSqr > (m_data->movement->movementSpeed + m_data->movement->movementBias))
        {
            // Position
            if ((playerPos.x + m_data->movement->movementSpeed) < currentTilePos.x)
            {
                playerPos.x += m_data->movement->movementSpeed;
                m_data->movement->moveDelta.x += m_data->movement->movementSpeed;
                deltaX = 1;
            }
            else if ((playerPos.x + m_data->movement->movementSpeed) > currentTilePos.x)
            {
                playerPos.x -= m_data->movement->movementSpeed;
                m_data->movement->moveDelta.x -= m_data->movement->movementSpeed;
                deltaX = -1;
            }
            if ((playerPos.z + m_data->movement->movementSpeed) < currentTilePos.z)
            {
                playerPos.z += m_data->movement->movementSpeed;
                m_data->movement->moveDelta.z += m_data->movement->movementSpeed;
                deltaZ = 1;
            }
            else if ((playerPos.z + m_data->movement->movementSpeed) > currentTilePos.z)
            {
                playerPos.z -= m_data->movement->movementSpeed;
                m_data->movement->moveDelta.z -= m_data->movement->movementSpeed;
                deltaZ = -1;
            }
            
            // Turn to face move direction
            float32 angle = static_cast<float32>(atan2(playerPos.z - playerPrevPos.z, playerPrevPos.x - playerPos.x));

            if (m_data->rotationAxis.x == 1)
            {
                playerRot.x = angle + m_data->rotationOffset.x;
            }
            else if (m_data->rotationAxis.y == 1)
            {
                playerRot.y = angle + m_data->rotationOffset.y;
            }
            else if (m_data->rotationAxis.z == 1)
            {
                playerRot.z = angle + m_data->rotationOffset.z;
            }
        }
        
        // move to tile center, set new tile in path
        else
        {
            //playerPos = currentTilePos;
            m_data->movement->mapPath.currentPosition++;
            if (m_data->movement->mapPath.currentPosition >= m_data->movement->mapPath.pathLength)
            {
                m_data->movement->pathing = false;
                m_data->movement->moveDelta.x = 0.0f;
                m_data->movement->moveDelta.z = 0.0f;
                
                // Set state - idle
                m_entityManager->setState(m_data->UID, "idle");
            }
        }

        m_data->position = playerPos; 
        m_data->movement->mapPath.currentTile = positionToTile(playerPos);
        m_data->rotation = playerRot; 
        m_updateMatrix();
    }
}

