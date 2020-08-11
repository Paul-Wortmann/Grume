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

#include "includes.hpp"
#include "defines.hpp"
#include "entity_component_model.hpp"
#include "model_exporter.hpp"
#include "model_generator.hpp"
#include "model_loader.hpp"

class cModelManager
{
    public:
        void          initialize(void);
        void          terminate(void);
        sEntityModel *load(const std::string &_fileName);
        void          save(sEntityModel* _model, const std::string &_fileName);
        void          generateMesh(sEntityModel* _model, const sEntityModeleGeneratorInfo &_info);
        uint32_t      isLoaded(const std::string &_fileName); // return instance count
        void          addInstance(sEntityModel* _model, const glm::mat4 &_transform);
        uint32_t      getAnimationCount(sEntityModel* _model);
        void          setAnimation(sEntityModel* _model, uint32_t _anim);
        void          freeModels(void);

    protected:
    private:
        void m_freeModelData(sEntityModel *_model);
        void m_load(sEntityModel* _model, const std::string &_fileName);
        
        cModelExporter  m_modelExporter  = {};
        cModelLoader    m_modelLoader    = {};
        cModelGenerator m_modelGenerator = {};
        uint32_t        m_count          = 0;
        sEntityModel*   m_modelHead      = nullptr;
        sEntityModel*   m_modelTail      = nullptr;
        sEntityModel*   m_modelTemp      = nullptr;}; 

#endif //MODEL_MANAGER_HPP

