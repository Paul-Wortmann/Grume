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

#ifndef IO_MANAGER_HPP
#define IO_MANAGER_HPP

#include "../core/includes.hpp"
#include "io_define.hpp"

class cIOManager
{
    public:
        void initialize(void);
        void terminate(void);
        sIO* getIOPointer(void) { return m_io; }

        // IO
        bool      getKeyState(const std::uint32_t &_key) { return m_io->keyMap[_key]; }
        void      setKeyState(const std::uint32_t &_key, const bool &_state) { m_io->keyMap[_key] = _state; }
        bool      getKeyReadyState(const std::uint32_t &_key) { return m_io->keyReadyMap[_key]; }
        void      setKeyReadyState(const std::uint32_t &_key, const bool &_state) { m_io->keyReadyMap[_key] = _state; }

        // Mouse
        glm::vec2 getMousePosition(void) { return m_io->mousePosition; };
        glm::vec2 getMousePositionOpenGL(void) { return m_io->mousePositionGL; };

    protected:
    private:
        sIO* m_io = nullptr;
};

#endif // IO_MANAGER_HPP
