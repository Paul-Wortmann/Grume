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

#include "event_manager.hpp"

std::uint32_t cEventManager::initialize(void)
{


    return EXIT_SUCCESS;
}

void cEventManager::terminate(void)
{


}

void cEventManager::process(float _dt)
{


}

sEvent cEventManager::getEvent(std::uint32_t _eventNum)
{
    return m_eventPool.event[_eventNum];
}

void cEventManager::addEvent(const sEvent &_event)
{
    m_eventPool.eventCurrent = (m_eventPool.eventCurrent + 1) % m_eventPool.eventCount;
    m_eventPool.event[m_eventPool.eventCurrent] = _event;
}
