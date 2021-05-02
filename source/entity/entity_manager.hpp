


#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "../includes.hpp"
#include "entity_define.hpp"
#include "../linked_list.hpp"
#include "model_manager.hpp"
#include "../utils/xml_parser.hpp"

class cEntityManager : public tcLinkedList<sEntity>
{
    public:
        void initialize(void);
        void terminate(void);
        void             addModel(sEntityModel*& _model);
        sEntityModel*    getNewModel(void);
        sEntityModel*    loadModel(const std::string& _fileName);
        void             removeModel(sEntityModel*& _model);
        sEntityMaterial* loadMaterial(const std::string &_fileName);
        sEntityTexture*  loadTexture(const std::string &_fileName);
        void             updateModelMatrix(sEntity*& _entity);
        sEntity*         load(const std::string& _fileName, sEntity* _entity = nullptr);

    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sEntity*& _pointer);

        cModelManager modelManager;
};

#endif //ENTITY_MANAGER_HPP
