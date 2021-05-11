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

#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "entity_define.hpp"
#include "model_manager.hpp"
#include "../includes.hpp"
#include "../linked_list.hpp"
#include "../audio/audio_manager.hpp"
#include "../utils/xml_parser.hpp"

class cEntityManager : public tcLinkedList<sEntity>
{
    public:
        void initialize(void);
        void terminate(void);
        void             setAudioPointer(cAudioManager* _audioManager) { m_audioManager = _audioManager; };
        void             addModel(sEntityModel*& _model);
        sEntityModel*    getNewModel(void);
        sEntityModel*    loadModel(const std::string& _fileName);
        void             removeModel(sEntityModel*& _model);
        sEntityMaterial* loadMaterial(const std::string &_fileName);
        sEntityTexture*  loadTexture(const std::string &_fileName);
        void             updateModelMatrix(sEntity*& _entity);
        sEntity*         load(const std::string& _fileName, sEntity* _entity = nullptr);
        void             setState(const std::string& _name);
        void             setState(const std::uint32_t& _state);

    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sEntity*& _pointer);

        cAudioManager*   m_audioManager   = nullptr;
        cModelManager    modelManager;
};

#endif //ENTITY_MANAGER_HPP
