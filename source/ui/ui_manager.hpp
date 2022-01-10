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

#include "../core/game_database.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_manager.hpp"
#include "ui_defines.hpp"

class cUIManager
{
    public:
        // ui_manager.cpp
        void initialize(cEntityManager* _entityManager);
        void terminate(void);
        void process(const uint32 &_dt);

        uint32             getNumMenu(void) { return m_numMenu; };
        sUIMenu*           getMenu(void) { return m_menu; };
        bool               getMenuEnabled(const std::string &_name);
        void               setMenuEnabled(const std::string &_name, const bool &_state);
        bool               getMouseOverMenu(void) { return m_mouseOverMenu; };
        void               setMouseClicked(const bool &_state) { m_mouseClicked = _state; };
        void               setMousePressed(const bool &_state) { m_mousePressed = _state; };
        void               setMousePosition(const glm::vec2 &_mousePosition) {m_mousePosition = _mousePosition; };
        void               setWindowSize(const uint32 &_width, const uint32 &_height) { m_window_w = _width; m_window_h = _height; };
        uint32             getActiveWindowCount(void) { return m_activeWindowCount; };
        eComponentFunction getUIEvent(void) { return m_uiEvent; };
        void               setUIEvent(eComponentFunction _uiEvent) { m_uiEvent = _uiEvent; };

        // ui_manager_load.cpp
        void load(const std::string &_fileName);

    protected:

    private:
        // member variables
        uint32              m_numMenu           = 0;
        sUIMenu            *m_menu              = nullptr;
        uint32              m_window_w          = 1920;
        uint32              m_window_h          = 1080;
        bool                m_mouseOverMenu     = false;
        bool                m_mouseClicked      = false;
        bool                m_mousePressed      = false;
        glm::vec2           m_mousePosition     = glm::vec2(0.0f, 0.0f);
        uint32              m_activeWindowCount = 0;
        eComponentFunction  m_uiEvent           = eComponentFunction::componentFunctionNone;
        
        // member pointer handles
        cEntityManager* m_entityManager = nullptr;

        // internal member functions
        void m_freeAll(void);
        void m_freeData(sUIComponent*& _pointer);
};

#endif //UI_MANAGER_HPP
