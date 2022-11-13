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

#include "ui_defines.hpp"

class cUIManager
{
    public:
        // ui_manager.cpp
        std::uint32_t      initialize(void);
        void               terminate(void);
        void               process(const float &_dt);

        std::uint32_t      getNumMenu(void) { return m_numMenu; };
        sUIMenu*           getMenu(void) { return m_menu; };
        bool               getMenuEnabled(const std::string &_name);
        void               setMenuEnabled(const std::string &_name, const bool &_state);
        bool               getMouseOverMenu(void) { return m_mouseOverMenu; };
        void               setMouseClicked(const bool &_state) { m_mouseClicked = _state; };
        void               setMousePressed(const bool &_state) { m_mousePressed = _state; };
        void               setMousePosition(const glm::vec2 &_mousePosition) {m_mousePosition = _mousePosition; };
        void               setWindowSize(const std::uint32_t &_width, const std::uint32_t &_height) { m_window_w = _width; m_window_h = _height; };
        std::uint32_t      getActiveWindowCount(void) { return m_activeWindowCount; };
        eComponentFunction getUIEvent(void) { return m_uiEvent; };
        void               setUIEvent(eComponentFunction _uiEvent) { m_uiEvent = _uiEvent; };
        void               setResourceManager(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; }
        void               setMapTitle(const std::string &_mapTitle);
        sTexture*          getTitleTexture(void) { return m_mapTitleTexture; };

        // ui_manager_load.cpp
        std::uint32_t      load(const std::string &_fileName);

    protected:

    private:
        // member variables
        std::uint32_t       m_numMenu           = 0;
        sUIMenu            *m_menu              = nullptr;
        std::uint32_t       m_window_w          = 1920;
        std::uint32_t       m_window_h          = 1080;
        bool                m_mouseOverMenu     = false;
        bool                m_mouseClicked      = false;
        bool                m_mousePressed      = false;
        glm::vec2           m_mousePosition     = glm::vec2(0.0f, 0.0f);
        std::uint32_t       m_activeWindowCount = 0;
        eComponentFunction  m_uiEvent           = eComponentFunction::componentFunctionNone;
        std::string         m_mapTitle          = "undefined";
        sTexture           *m_mapTitleTexture   = nullptr;

        // member pointer handles
        cResourceManager*   m_resourceManager   = nullptr;

        // internal member functions
        void m_freeAll(void);
        void m_freeData(sUIComponent*& _pointer);
};

#endif //UI_MANAGER_HPP
