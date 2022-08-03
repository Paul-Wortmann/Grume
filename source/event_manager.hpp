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

#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "event_manager_defines.hpp"

class cEventManager :tcTemplateManager
{
    public:
        std::uint32_t initialize(void) override;
        void          terminate(void) override;
        void          process(const float &_dt) override;
        sEvent        getEvent(std::uint32_t _eventNum);
        void          addEvent(const sEvent &_event);
        std::uint32_t getEventPoolPosition(void) { return m_eventPool.eventCurrent; };

    protected:

    private:
        sEventPool m_eventPool = {};
};

#endif // EVENT_MANAGER_HPP
