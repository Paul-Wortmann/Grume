


#ifndef MATERIAL_MANAGER_HPP
#define MATERIAL_MANAGER_HPP

#include "../includes.hpp"
#include "entity_material.hpp"
#include "../linked_list.hpp"
#include "texture_manager.hpp"

class cMaterialManager : public tcLinkedList<sEntityMaterial>
{
    public:
        void initialize(void);
        void terminate(void);
        bool isLoaded(const std::string &_diffuse, const std::string &_emissive, const std::string &_normal, const std::string &_specular);
        sEntityMaterial* add(std::string _diffuse, std::string _emissive, std::string _normal, std::string _specular);
        sEntityTexture* loadTexture(const std::string &_fileName);
        
    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sEntityMaterial*& _pointer);
        
        cTextureManager textureManager;
};



#endif // MATERIAL_MANAGER_HPP
