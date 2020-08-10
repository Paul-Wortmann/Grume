
#ifndef MANAGER_TEXTURE_HPP
#define MANAGER_TEXTURE_HPP

#include "includes.hpp"
#include "defines.hpp"
#include "texture_loader.hpp"

struct sTextureNode
{
    sTextureNode *next     = nullptr;
    uint32_t      ID       = 0;
    std::string   fileName = "";
};

class cTextureManager
{
    public:
        void initialize(void);
        void freeTextures(void);
        uint32_t add(const std::string &_fileName);

    protected:
    private:
        void freeTexture(uint32_t _ID);
        uint32_t load(const std::string &_fileName);
        uint32_t      m_count       = 0;
        sTextureNode *m_textureHead = nullptr;
        sTextureNode *m_textureTail = nullptr;
        sTextureNode *m_textureTemp = nullptr;
}; 

#endif //MANAGER_TEXTURE_HPP
