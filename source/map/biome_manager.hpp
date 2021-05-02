


#ifndef BIOME_MANAGER_HPP
#define BIOME_MANAGER_HPP

#include "../entity/entity_manager.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "biome_define.hpp"

class cBiomeManager : public tcLinkedList<sMapBiome>
{
    public:
        void initialize(cEntityManager* _entityManager);
        void terminate(void);
        sMapBiome* load(const std::string& _fileName);

    protected:

    private:
        cEntityManager* entityManager = nullptr;
        
        void m_freeAll(void);
        void m_freeData(sMapBiome*& _biome);

        void m_load_musicSet(sMapBiome*& _biome);
        void m_load_npcSet(sMapBiome*& _biome);
        void m_load_objectSet(sMapBiome*& _biome);
        void m_load_wallSet(sMapBiome*& _biome);
};

#endif // BIOME_MANAGER_HPP

