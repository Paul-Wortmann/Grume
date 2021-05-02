


#ifndef MODEL_MANAGER_HPP
#define MODEL_MANAGER_HPP

#include "assimp_to_glm.hpp"
#include "entity_model.hpp"
#include "entity_material.hpp"
#include "entity_mesh.hpp"
#include "entity_texture.hpp"
#include "material_manager.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "../utils/file_utils.hpp"
#include "../utils/xml_parser.hpp"

class cModelManager : public tcLinkedList<sEntityModel>
{
    public:
        void initialize(void);
        void terminate(void);
        sEntityModel* load(const std::string &_fileName);
        sEntityMaterial* loadMaterial(const std::string &_fileName);
        sEntityTexture* loadTexture(const std::string &_fileName);

    protected:

    private:
        void m_freeAll(void);
        void m_freeData(sEntityModel*& _pointer);
        
        cMaterialManager materialManager;
        
        // model_loader.hpp
        std::vector<sEntityBone> m_boneMap = {};

        uint32        m_getNumMesh(const aiNode* _node, uint32 _numMesh = 0);
        void          m_processMesh(const aiScene*& _scene, const aiMesh* _mesh, sEntityModel*& _model);
        void          m_processNode(const aiScene*& _scene, const aiNode* _node, sEntityModel*& _model);
        void          m_addBoneMap(const std::string &_name, const glm::mat4 &_mat4);
        void          m_buildBoneMap(aiNode* _node, const aiScene* _scene);;
        void          m_buildBoneMapParents(aiNode* _node, aiNode* _nodeParent, const aiScene* _scene);
        int32         m_getBoneID(const std::string &_name);
        void          m_buildBoneMapNodes(aiNode* _node);
        glm::mat4     m_getRecursiveTransforms(int32 _ID);
        bool          m_getNodeTransform(const aiNode* _node, const std::string &_name, glm::mat4 &_matrix);
        void          m_addMissingBoneMap(const aiScene* _scene);
        void          m_loadBones(sEntityModel* _model, const aiScene* _scene);
        void          m_loadAnimations(sEntityModel* _model, const aiScene* _scene);
        sEntityModel* m_loadModel(const std::string &_fileName);;

};

#endif // MODEL_MANAGER_HPP
