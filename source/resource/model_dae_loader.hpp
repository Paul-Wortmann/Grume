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

#ifndef MODEL_DAE_LOADER_HPP
#define MODEL_DAE_LOADER_HPP

#include "../core/includes.hpp"
#include "model_define.hpp"
#include "model_tools.hpp"
#include "xml_parser.hpp"

struct sDAEMesh
{
    std::string    name          = {};
    bool           smoothShading = false;
    glm::mat4      transform     = {};

    std::uint32_t  numPosition   = 0;
    glm::vec3     *position      = nullptr;

    glm::vec4      *boneWeight   = nullptr;
    glm::ivec4     *boneID       = nullptr;

    std::uint32_t  numNormal     = 0;
    glm::vec3     *normal        = nullptr;
    std::uint32_t  numTexCoord   = 0;
    glm::vec2     *texCoord      = nullptr;
    std::uint32_t  numColor      = 0;
    glm::ivec3    *color         = nullptr;

    std::uint32_t  numIndex      = 0;
    glm::ivec4    *index         = nullptr;
};

struct sDAEBone
{
    std::int32_t ID               = -1;
    std::int32_t parentID         = -1;
    std::string  name             = "";
    glm::mat4    transformNode    = glm::mat4(1); // node transformation matrix
    glm::mat4    transformPose    = glm::mat4(1); // inverse bind pose matrix
    glm::mat4    transformFinal   = glm::mat4(1); // the final animated transform
    glm::mat4    transformTemp    = glm::mat4(1); // an intermediary transform
};

struct sDAEModel
{
    std::string    name          = {};
    eUpAxis        upAxis        = eUpAxis::yUp;
    std::uint32_t  numMesh       = 0;
    sDAEMesh      *mesh          = nullptr;

    std::uint32_t  numSkinWeight = 0;
    float         *skinWeight    = nullptr;
    std::uint32_t  numBoneWeight = 0;
    std::uint32_t *boneWeight    = nullptr;
    std::uint32_t  numBoneCount  = 0;
    std::uint32_t *boneCount     = nullptr;
    std::uint32_t  numBone       = 0;
    sDAEBone      *bone          = nullptr;
};

void gFreeDAE(sDAEModel *&_dae);
void gLoadDAE(sDAEModel *&_dae, const std::string &_fileName);
void gSaveDAE(sDAEModel *&_dae, const std::string &_fileName);

void gExportModelDAE(const std::string &_fileName, sModel *&_model);
void gImportModelDAE(const std::string &_fileName, sModel *&_model);

#endif //MODEL_DAE_LOADER_HPP

