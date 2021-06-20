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

#ifndef MODEL_MANAGER_HPP
#define MODEL_MANAGER_HPP

#include "assimp_to_glm.hpp"
#include "entity_model.hpp"
#include "entity_material.hpp"
#include "entity_mesh.hpp"
#include "entity_texture.hpp"
#include "material_manager.hpp"
#include "../core/includes.hpp"
#include "../core/linked_list.hpp"
#include "../graphics/graphics_engine_defines.hpp"
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
        void saveScreenShot(const std::string &_fileName) { materialManager.saveScreenShot(_fileName); };

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
