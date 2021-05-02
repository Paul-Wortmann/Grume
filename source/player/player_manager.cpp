
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

void cPlayerManager::process(const float32 &_dt)
{
    
}

sEntity* cPlayerManager::load(const std::string &_fileName)
{
    std::ifstream file;
    cXML xmlFile;
    xmlFile.load(FILE_PATH_ENTITY + _fileName);
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
