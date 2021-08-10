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

#ifndef UI_MANAGER_HPP
#define UI_MANAGER_HPP

#include "../core/includes.hpp"
#include "../core/linked_list.hpp"
#include "ui_defines.hpp"
#include "../entity/entity_manager.hpp"

class cUIManager : public tcLinkedList<sUIComponent>
{
    public:
        void initialize(cEntityManager* _entityManager);
        void terminate(void);
        void load(const std::string &_fileName);

    protected:

    private:
        cEntityManager* m_entityManager = nullptr;

        void m_freeAll(void);
        void m_freeData(sUIComponent*& _pointer);

};

#endif //UI_MANAGER_HPP
