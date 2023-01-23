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

#ifndef PLAYER_INVENTORY_HPP
#define PLAYER_INVENTORY_HPP

#include "../core/includes.hpp"
#include "player_storage.hpp"

class cPlayerInventory
{
    public:
        std::uint32_t       initialize(void);
        void                terminate(void);
        void                freeData(void);

        // Set pointers
        void                setEntityManager(cEntityManager* _entityManager);
        void                setResourceManager(cResourceManager* _resourceManager);
        void                setUIManager(cUIManager* _UIManager);
        void                setPlayerEntity(sEntity* _entity);
        void                setMap(sMap* _map);

        // member functions
        sEntity*            getSlotEntity(const std::uint32_t _slot) { return m_storage.getSlotEntity(_slot); }
        void                setSlotEntity(const std::uint32_t _slot, sEntity* &_entity) {m_storage.setSlotEntity(_entity); }
        std::uint32_t       getStorageSize(void) { return m_storageSize; }
        std::uint32_t       freeSlotCount(void) { return m_storage.freeSlotCount(); }
        sPlayerStorage*     getStorage(void) { return m_storage.getStorage(); }
        sPlayerStorageSlot* getStorageSlot(const std::uint32_t _slot) { return m_storage.getStorageSlot(_slot); }
        bool                pickupItem(sEntity* &_entity);
        bool                dropItem(sEntity* &_entity);
        void                dropItem(const std::uint32_t &_slot);

        // other
        void                setStackColor(const glm::uvec4 &_color) { m_storage.setTackColor(_color); }

    protected:
    private:
        // Pointers
        sEntity*            m_playerEntity    = nullptr;
        cEntityManager*     m_entityManager   = nullptr;
        cResourceManager*   m_resourceManager = nullptr;
        cUIManager*         m_UIManager       = nullptr;
        sMap*               m_map             = nullptr;

        // Data
        cPlayerStorage      m_storage         = {};
        const std::uint32_t m_storageSize     = 54;
};

#endif // PLAYER_INVENTORY_HPP
