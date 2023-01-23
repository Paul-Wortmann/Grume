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
#include "../entity/entity_manager.hpp"
#include "../map/map_define.hpp"
#include "../ui/ui_manager.hpp"

// Player storage slot struct
struct sPlayerStorageSlot
{
    bool               occupied   = false;
    sEntity*           entity     = nullptr;
    std::uint32_t      data       = 0;
    sTexture*          stackLabel = nullptr;
};

// Player storage struct
struct sPlayerStorage
{
    std::uint32_t       numSlot     = 0;
    std::uint32_t       numFreeSlot = 0;
    sPlayerStorageSlot* slot        = nullptr;
};

class cPlayerInventory
{
    public:
        std::uint32_t       initialize(void);
        void                terminate(void);
        void                freeData(void);

        // Set pointers
        void                setEntityManager(cEntityManager* _entityManager) { m_entityManager = _entityManager; }
        void                setResourceManagerPointer(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; }
        void                setUIManager(cUIManager* _UIManager) { m_UIManager = _UIManager; }
        void                setPlayerEntity(sEntity* _entity) { m_playerEntity = _entity; }
        void                setMapPointer(sMap* _map) { m_map = _map; }

        // member functions
        sEntity*            getSlotEntity(const std::uint32_t _slot) { return m_inventory.slot[_slot].entity; }
        void                setSlotEntity(const std::uint32_t _slot, sEntity* &_entity);
        void                setStorageSize(const std::uint32_t &_size);
        std::uint32_t       getStorageSize(void) { return m_inventory.numSlot; }
        std::uint32_t       freeSlotCount(void) { return m_inventory.numFreeSlot; }
        sPlayerStorage*     getStorage(void) { return &m_inventory; }
        sPlayerStorageSlot* getStorageSlot(const std::uint32_t _slot) { return &m_inventory.slot[_slot]; }
        bool                pickupItem(sEntity* &_entity);
        bool                dropItem(sEntity* &_entity);
        void                dropItem(const std::uint32_t &_slot);

        // other
        void                setStackColor(const glm::uvec4 &_color) { m_stackTextColor = _color; }

    protected:
    private:
        // Pointers
        sEntity*            m_playerEntity    = nullptr;
        cEntityManager*     m_entityManager   = nullptr;
        cResourceManager*   m_resourceManager = nullptr;
        cUIManager*         m_UIManager       = nullptr;
        sMap*               m_map             = nullptr;

        // Data
        sPlayerStorage      m_inventory       = {};

        glm::uvec4          m_stackTextColor  = glm::uvec4(200, 200, 200, 255);
};

#endif // PLAYER_INVENTORY_HPP
