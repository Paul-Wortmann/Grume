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

#ifndef MODEL_LOADER_HPP
#define MODEL_LOADER_HPP

#include "includes.hpp"
#include "entity_component_model.hpp"
#include "model_assimp_to_glm.hpp"

class cModelLoader
{
    public:
        cModelLoader(void) = default;
        ~cModelLoader(void) = default;
        void load(sEntityModel* _model, const std::string &_fileName);

    protected:

    private:
        glm::mat4   m_getTranformMatrix(const aiMatrix4x4& _mat4);
        uint32_t    m_getMeshCount(aiNode* _node, const aiScene* _scene);
        uint64_t    m_getIndexCount(aiMesh* _mesh, const aiScene* _scene);
        void        m_buildBoneMap(aiNode* _node, const aiScene* _scene);
        void        m_buildBoneMapParents(aiNode* _node, aiNode* _nodeParent, const aiScene* _scene);
        int32_t     m_getBoneID(const std::string &_name);
        void        m_buildBoneMapNodes(aiNode* _node);
        glm::mat4   m_getRecursiveTransforms(int32_t _ID);
        void        m_loadBones(sEntityModel* _model, const aiScene* scene);
        void        m_loadAnimations(sEntityModel* _model, const aiScene* _scene);
        void        m_processMesh(sEntityModel* _model, aiMesh* _mesh, const aiScene* _scene);
        void        m_loadMeshes(sEntityModel* _model, aiNode* _node, const aiScene* _scene);
        void        m_saveMaterials(sEntityModel* _model);
        uint32_t    m_getMaterialID(const std::string &_diffuse, const std::string &_normal, const std::string &_specular);

        std::vector<sBone> m_boneMap = {};
        std::vector<sMaterial> m_materialMap = {};
};

#endif //MODEL_LOADER_HPP

