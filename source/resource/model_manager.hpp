/**
 * Copyright (C) Paul Wortmann
 * This file is part of "Grume"
 *
 * "Grume" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Grume" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Grume" If not, see <http://www.gnu.org/licenses/>.
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
#include "material_define.hpp"
#include "model_dae.hpp"
#include "model_obj.hpp"
#include "../templates/template_linked_list.hpp"
#include "../entity/entity_model.hpp"

#include "../core/includes.hpp"

class cModelManager : public tcLinkedList<sEntityModel>
{
    public:
        std::uint32_t    initialize(void);
        void             terminate(void);
        sEntityModel*    load(const std::string &_fileName);

    protected:

    private:
        void freeData(sEntityModel*& _pointer) override;

        //cMaterialManager materialManager;

        // model_loader.hpp
        std::vector<sEntityBone> m_boneMap = {};

        std::uint32_t m_getNumMesh(const aiNode* _node, std::uint32_t _numMesh = 0);
        void          m_processMesh(const aiScene*& _scene, const aiMesh* _mesh, sEntityModel*& _model);
        void          m_processNode(const aiScene*& _scene, const aiNode* _node, sEntityModel*& _model);
        void          m_addBoneMap(const std::string &_name, const glm::mat4 &_mat4);
        void          m_buildBoneMap(aiNode* _node, const aiScene* _scene);
        void          m_buildBoneMapParents(aiNode* _node, aiNode* _nodeParent, const aiScene* _scene);
        std::int32_t  m_getBoneID(const std::string &_name);
        void          m_buildBoneMapNodes(aiNode* _node);
        glm::mat4     m_getRecursiveTransforms(std::int32_t _ID);
        bool          m_getNodeTransform(const aiNode* _node, const std::string &_name, glm::mat4 &_matrix);
        void          m_addMissingBoneMap(const aiScene* _scene);
        void          m_loadBones(sEntityModel* _model, const aiScene* _scene);
        void          m_loadAnimations(sEntityModel* _model, const aiScene* _scene);
        sEntityModel* m_loadModel(const std::string &_fileName);

};

#endif // MODEL_MANAGER_HPP

