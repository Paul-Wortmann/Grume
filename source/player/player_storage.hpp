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

#ifndef PLAYER_STORAGE_HPP
#define PLAYER_STORAGE_HPP

#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "../map/map_define.hpp"
#include "../ui/ui_manager.hpp"

#include "player_storage_define.hpp"

class cPlayerStorage
{
    public:
        std::uint32_t       initialize(void);
        void                terminate(void);
        void                freeData(void);

        // Set pointers
        void                setEntityManager(cEntityManager* _entityManager) { m_entityManager = _entityManager; }
        void                setResourceManager(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; }
        void                setUIManager(cUIManager* _UIManager) { m_UIManager = _UIManager; }
        void                setPlayerEntity(sEntity* _entity) { m_playerEntity = _entity; }
        void                setMap(sMap* _map) { m_map = _map; }

        // member functions
        sEntity*            getSlotEntity(const std::uint32_t _slot) { return m_storage.slot[_slot].entity; }
        void                setSlotEntity(const std::uint32_t _slot, sEntity* &_entity);
        void                purgeSlotEntity(const std::uint32_t _slot);
        void                setStorageSize(const std::uint32_t &_size);
        std::uint32_t       getStorageSize(void) { return m_storage.numSlot; }
        std::uint32_t       freeSlotCount(void) { return m_storage.numFreeSlot; }
        sPlayerStorage*     getStorage(void) { return &m_storage; }
        sPlayerStorageSlot* getStorageSlot(const std::uint32_t _slot) { return &m_storage.slot[_slot]; }
        sPlayerStorageSlot* getStorageSlot(const ePlayerStorageSlotType _type);
        bool                pickupItem(sEntity* &_entity);
        bool                dropItem(sEntity* &_entity);
        void                dropItem(const std::uint32_t &_slot);
        void                setDrag(const std::uint32_t _slot, const bool &_state) { m_storage.slot[_slot].dragged = _state; }

        // other
        void                setStackColor(const glm::uvec4 &_color) { m_stackTextColor = _color; }
        void                setSlot1(const eComponentFunction &_slot_1) { m_slot_1 = _slot_1; }
        void                setStack1(const eComponentFunction &_stack_1) { m_stack_1 = _stack_1; }
        void                setStorageType(const ePlayerStorageType &_type) { m_storage.type = _type; }
        void                setUISlotEnabled(const std::uint32_t &_slot, const bool &_state);
        void                setSlotType(const ePlayerStorageSlotType &_type, const std::uint32_t &_slot) { m_storage.slot[_slot].type = _type; }

    protected:
    private:
        // Pointers
        sEntity*            m_playerEntity    = nullptr;
        cEntityManager*     m_entityManager   = nullptr;
        cResourceManager*   m_resourceManager = nullptr;
        cUIManager*         m_UIManager       = nullptr;
        sMap*               m_map             = nullptr;

        // Data
        sPlayerStorage      m_storage         = {};

        eComponentFunction  m_slot_1          = eComponentFunction::componentFunctionNone;
        eComponentFunction  m_stack_1         = eComponentFunction::componentFunctionNone;
        glm::uvec4          m_stackTextColor  = glm::uvec4(200, 200, 200, 255);
};

#endif // PLAYER_STORAGE_HPP
