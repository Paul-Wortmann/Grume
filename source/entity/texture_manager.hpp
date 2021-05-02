


#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "../includes.hpp"
#include "entity_texture.hpp"
#include "../linked_list.hpp"
#include "texture_loader.hpp"

class cTextureManager : public tcLinkedList<sEntityTexture>
{
    public:
        void initialize(void);
        void terminate(void);
        sEntityTexture* load(const std::string &_fileName);

    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sEntityTexture*& _pointer);

};

#endif // TEXTURE_MANAGER_HPP
