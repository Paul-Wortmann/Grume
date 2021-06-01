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
    cXML xmlFile;
    xmlFile.load(std::string(FILE_PATH_ENTITY) + "player/" + _fileName);
    if (xmlFile.lineCount() > 0)
    {
        gLogWrite(LOG_INFO, "Loading player: " + xmlFile.getString("<name>"), __FILE__, __LINE__, __FUNCTION__);

        // Get the data from the XML file
        std::string  tName         = xmlFile.getString("<name>");
        glm::vec3    tPosition     = xmlFile.getVec3("<position>");
        glm::vec3    tScale        = xmlFile.getVec3("<scale>");
        glm::vec3    tRotation     = xmlFile.getVec3("<rotation>");
        std::string  tMaterialFile = xmlFile.getString("<material>");
        std::string  tModelFile    = xmlFile.getString("<model>");

        // Create and populate the entity data structure with the loaded XML data
        m_data           = m_entityManager->getNew();
        m_data->name     = tName;
        m_data->position = tPosition;
        m_data->scale    = tScale;
        m_data->rotation = tRotation;
        m_entityManager->updateModelMatrix(m_data);
        m_data->pathData = new sEntityPath;

        // Load the model from file
        if (tModelFile.length() > 3)
        {
            m_data->model = m_entityManager->loadModel(tModelFile);
        }

        // Load the material from file
        if (tMaterialFile.length() > 3)
        {
            m_data->material = m_entityManager->loadMaterial(tMaterialFile);
        }

        // Clean up
        xmlFile.free();
        return m_data;
    }
    return nullptr;
};

uint32 cPlayerManager::positionToTile(glm::vec3 _position)
{
    // Width and height offset, used to center the walls
    float32 xo = static_cast<float32>(m_mapPointer->width)  / 2.0f;
    float32 zo = static_cast<float32>(m_mapPointer->height) / 2.0f;
    float32 tp = 1.0f / 2.0f; // tile center positioning ( half model dimention)

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

void cPlayerManager::moveTo(glm::vec3 _pos)
{
    glm::vec3 destinationPosition = _pos;
    destinationPosition.y -= 0.0f;
    uint32 destinationTile = positionToTile(destinationPosition);
    setDestinationTile(destinationTile);
    if (m_data->pathData->mapPath.pathLength > 0)
    {
        m_data->pathData->mapPath.currentPosition = 0;
        m_data->pathData->pathing = true;
    }
};

void cPlayerManager::process(const float32 &_dt)
{
    m_data->pathData->moved = false;
    if (m_data->pathData->mapPath.pathLength == 0)
    {
        m_data->pathData->pathing = false;
    }
    if (m_data->pathData->pathing)
    {
        // move amount
        m_data->pathData->moveDelta.x = 0.0f;
        m_data->pathData->moveDelta.z = 0.0f;
        
        // move direction, used as float comparison is problematic
        int32 deltaX = 0;
        int32 deltaZ = 0;
        
        //std::cout << "Current tile: " << m_path.path[m_path.currentPosition] << std::endl;
        m_data->pathData->moved = true;
        glm::vec3 playerPos      = m_data->position;
        glm::vec3 playerRot      = m_data->rotation;
        uint32    currentTile    = m_data->pathData->mapPath.path[m_data->pathData->mapPath.currentPosition];
        glm::vec3 currentTilePos = tileToPosition(currentTile);
        
        // Get the distance to the destination tile
        float32   distanceToTileSqr = ((playerPos.x - currentTilePos.x) * (playerPos.x - currentTilePos.x)) + ((playerPos.z - currentTilePos.z) * (playerPos.z - currentTilePos.z));
        
        // if not center, move towards tile center
        if (distanceToTileSqr > (m_data->pathData->movementSpeed + m_data->pathData->movementBias))
        {
            // Position
            if ((playerPos.x + m_data->pathData->movementSpeed) < currentTilePos.x)
            {
                playerPos.x += m_data->pathData->movementSpeed;
                m_data->pathData->moveDelta.x += m_data->pathData->movementSpeed;
                deltaX = 1;
            }
            else if ((playerPos.x + m_data->pathData->movementSpeed) > currentTilePos.x)
            {
                playerPos.x -= m_data->pathData->movementSpeed;
                m_data->pathData->moveDelta.x -= m_data->pathData->movementSpeed;
                deltaX = -1;
            }
            if ((playerPos.z + m_data->pathData->movementSpeed) < currentTilePos.z)
            {
                playerPos.z += m_data->pathData->movementSpeed;
                m_data->pathData->moveDelta.z += m_data->pathData->movementSpeed;
                deltaZ = 1;
            }
            else if ((playerPos.z + m_data->pathData->movementSpeed) > currentTilePos.z)
            {
                playerPos.z -= m_data->pathData->movementSpeed;
                m_data->pathData->moveDelta.z -= m_data->pathData->movementSpeed;
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
            m_data->pathData->mapPath.currentPosition++;
            if (m_data->pathData->mapPath.currentPosition >= m_data->pathData->mapPath.pathLength)
            {
                m_data->pathData->pathing = false;
                m_data->pathData->moveDelta.x = 0.0f;
                m_data->pathData->moveDelta.z = 0.0f;
            }
        }
        setPosition(playerPos);
        setRotation(playerRot);
    }
};

