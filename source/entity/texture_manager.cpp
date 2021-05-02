
#include "texture_manager.hpp"

void cTextureManager::initialize(void)
{

}

void cTextureManager::terminate(void)
{
    m_freeAll();
}

void cTextureManager::m_freeData(sEntityTexture*& _pointer)
{
    if (_pointer->ID != 0)
    {
        glDeleteTextures(1, &_pointer->ID);
    }
}

void cTextureManager::m_freeAll(void)
{
    for (sEntityTexture* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        m_freeData(m_temp);
    }
}

sEntityTexture* cTextureManager::load(const std::string &_fileName)
{
    for (sEntityTexture* m_temp = getHead(); m_temp != nullptr; m_temp = m_temp->next)
    {
        if (m_temp->fileName.compare(_fileName) == 0)
        {
            return m_temp;
        }
    }

    int width      = 0;
    int height     = 0;
    int numChannel = 0;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load((std::string(FILE_PATH_TEXTURE)+_fileName).c_str(), &width, &height, &numChannel, 0);
    if (data)
    {
        // Setup format enum based on the number of channels in the image
        GLenum format = 0;
        if (numChannel == 1)
            format = GL_RED;
        else if (numChannel == 3)
            format = GL_RGB;
        else if (numChannel == 4)
            format = GL_RGBA;
        
        // Create a new texture pointer
        sEntityTexture* texture = getNew();
        texture->fileName = _fileName;
        glGenTextures(1, &texture->ID);
        glBindTexture(GL_TEXTURE_2D, texture->ID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
        return texture;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Error - Failed to laod texture: " + std::string(FILE_PATH_TEXTURE) + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    return nullptr;
}

