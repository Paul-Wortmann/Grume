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
    if (m_path.path != nullptr)
    {
        delete [] m_path.path;
        m_path.path = nullptr;
    }
}

sEntity* cPlayerManager::load(const std::string &_fileName)
{
    cXML xmlFile;
    xmlFile.load(std::string(FILE_PATH_ENTITY) + "player/" + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        gLogWrite(LOG_INFO, "Loading player: " + xmlFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);

        // Get the data from the XML file
        std::string  name         = xmlFile.getString("<name>");
        glm::vec3    position     = xmlFile.getVec3("<position>");
        glm::vec3    scale        = xmlFile.getVec3("<scale>");
        glm::vec3    rotation     = xmlFile.getVec3("<rotation>");
        std::string  materialFile = xmlFile.getString("<material>");
        std::string  modelFile    = xmlFile.getString("<model>");

        // Create and populate the entity data structure with the loaded XML data
        m_data           = m_entityManager->getNew();
        m_data->name     = name;
        m_data->position = position;
        m_data->scale    = scale;
        m_data->rotation = rotation;
        m_entityManager->updateModelMatrix(m_data);

        // Load the model from file
        if (modelFile.length() > 3)
        {
            m_data->model = m_entityManager->loadModel(modelFile);
        }

        // Load the material from file
        if (materialFile.length() > 3)
        {
            m_data->material = m_entityManager->loadMaterial(materialFile);
        }

        // Clean up
        xmlFile.free();
        return m_data;
    }
    return nullptr;
};

uint32 cPlayerManager::positionToTile(glm::vec3 _position)
{
    uint32 x = static_cast<uint32>(_position.x) + (m_mapPointer->width / 2);
    uint32 z = static_cast<uint32>(_position.z) + (m_mapPointer->height / 2);
    return (z * m_mapPointer->width) + x;
};

glm::vec3 cPlayerManager::tileToPosition(uint32 _tile)
{ 
    float x = (_tile % m_mapPointer->width) - (m_mapPointer->width / 2.0f);
    float z = (_tile / m_mapPointer->width) - (m_mapPointer->height / 2.0f);
    return glm::vec3(x, m_terrainHeight, z);
};

void cPlayerManager::moveTo(glm::vec3 _pos)
{
    glm::vec3 destinationPosition = _pos;
    destinationPosition.y -= 1.0f;
    uint32 destinationTile = positionToTile(destinationPosition);
    setDestinationTile(destinationTile);
    if (m_path.pathLength > 0)
    {
        m_path.currentPosition = 0;
        m_pathing = true;
    }
};

void cPlayerManager::process(const float32 &_dt)
{
    m_moved = false;
    if (m_path.pathLength == 0)
    {
        m_pathing = false;
    }
    if (m_pathing)
    {
        // move amount
        m_moveDelta.x = 0.0f;
        m_moveDelta.z = 0.0f;
        
        // move direction, used as float comparison is problematic
        int32 deltaX = 0;
        int32 deltaZ = 0;
        
        std::cout << "Current tile: " << m_path.path[m_path.currentPosition] << std::endl;
        m_moved = true;
        glm::vec3 playerPos      = m_data->position;
        glm::vec3 playerRot      = m_data->rotation;
        uint32    currentTile    = m_path.path[m_path.currentPosition];
        glm::vec3 currentTilePos = tileToPosition(currentTile);
        
        // Get the distance to the destination tile
        float32   distanceToTileSqr = ((playerPos.x - currentTilePos.x) * (playerPos.x - currentTilePos.x)) + ((playerPos.z - currentTilePos.z) * (playerPos.z - currentTilePos.z));
        
        // if not center, move towards tile center
        if (distanceToTileSqr > (m_movementSpeed + m_movementBias))
        {
            // Position
            if ((playerPos.x + m_movementSpeed) < currentTilePos.x)
            {
                playerPos.x += m_movementSpeed;
                m_moveDelta.x += m_movementSpeed;
                deltaX = 1;
            }
            else if ((playerPos.x + m_movementSpeed) > currentTilePos.x)
            {
                playerPos.x -= m_movementSpeed;
                m_moveDelta.x -= m_movementSpeed;
                deltaX = -1;
            }
            if ((playerPos.z + m_movementSpeed) < currentTilePos.z)
            {
                playerPos.z += m_movementSpeed;
                m_moveDelta.z += m_movementSpeed;
                deltaZ = 1;
            }
            else if ((playerPos.z + m_movementSpeed) > currentTilePos.z)
            {
                playerPos.z -= m_movementSpeed;
                m_moveDelta.z -= m_movementSpeed;
                deltaZ = -1;
            }
            
            // Rotation
            if (deltaX == 1)
            {
                if (deltaZ == 1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_45);
                }
                else if (deltaZ == -1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_135);
                }
                else
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_90);
                }
            }
            else if (deltaX == -1)
            {
                if (deltaZ == 1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_315);
                }
                else if (deltaZ == -1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_225);
                }
                else
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_270);
                }
            }
            else //(deltaX == 0)
            {
                if (deltaZ == 1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_0);
                }
                else if (deltaZ == -1)
                {
                    playerRot = glm::vec3(playerRot.x, playerRot.y, DTOR_180);
                }
            }
            
        }
        
        // move to tile center, set new tile in path
        else
        {
            //playerPos = currentTilePos;
            m_path.currentPosition++;
            if (m_path.currentPosition >= m_path.pathLength)
            {
                m_pathing = false;
                m_moveDelta.x = 0.0f;
                m_moveDelta.z = 0.0f;
            }
        }
        setPosition(playerPos);
        setRotation(playerRot);
    }
};

