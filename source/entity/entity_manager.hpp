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

#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "entity_define.hpp"
#include "model_manager.hpp"
#include "../core/includes.hpp"
#include "../core/template_linked_list.hpp"
#include "../core/game_database.hpp"
#include "../audio/audio_manager.hpp"
#include "../utils/xml_parser.hpp"
#include "../map/map_define.hpp"

class cEntityManager : public tcLinkedList<sEntity>
{
    public:
        void             initialize(void);
        void             terminate(void);
        void             process(const float32 &_dt);
        void             setAudioPointer(cAudioManager* _audioManager) { m_audioManager = _audioManager; };
        void             setDatabasePointer(cGameDatabase* _gameDatabase) { m_gameDatabase = _gameDatabase; };
        void             setMapPointer(sMap* _map) { m_mapPointer = _map; };
        void             addModel(sEntityModel*& _model);
        sEntityModel*    getNewModel(void);
        sEntityModel*    loadModel(const std::string& _fileName);
        void             removeModel(sEntityModel*& _model);
        sEntityMaterial* loadMaterial(const std::string &_fileName);
        sEntityTexture*  loadTexture(const std::string &_fileName);
        GLFWimage*       loadIcon(const std::string &_fileName);
        void             freeIcon(GLFWimage*& _image);
        void             updateModelMatrix(sEntity*& _entity);
        sEntity*         load(const std::string& _fileName, sEntity* _entity = nullptr);
        void             activateState(const std::uint32_t& _UID, const std::string& _name);
        void             activateState(const std::uint32_t& _UID, const std::uint32_t& _state);
        void             setState(const std::uint32_t& _UID, const std::string& _name);
        void             setState(const std::uint32_t& _UID, const std::uint32_t& _state);
        void             toggleState(const std::uint32_t& _UID, const std::string& _name1, const std::string& _name2);
        void             toggleState(const std::uint32_t& _UID, const std::uint32_t& _state1, const std::uint32_t& _state2);
        void             saveScreenShot(const std::string &_fileName) { m_modelManager.saveScreenShot(_fileName); };
        void             freeData(sEntity*& _entity) { m_freeData(_entity); };

    protected:
        
    private:
        void             m_freeAll(void);
        void             m_freeData(sEntity*& _pointer);
        void             m_playSound(sEntity*& _entity, const std::uint32_t& _state);
        void             m_setAnimationState(sEntity*& _entity, const std::uint32_t& _state);
        void             m_setTileState(sEntity*& _entity, const std::uint32_t& _state);
        sEntity*         m_UIDtoEntity(const std::uint32_t& _UID);

        cAudioManager*   m_audioManager   = nullptr;
        cGameDatabase*   m_gameDatabase   = nullptr;
        sMap*            m_mapPointer     = nullptr;
        cModelManager    m_modelManager;
};

#endif //ENTITY_MANAGER_HPP
