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

#ifndef NETWORK_ENGINE_HPP
#define NETWORK_ENGINE_HPP

#include "../core/includes.hpp"
#include "network_engine_defines.hpp"

class cNetworkEngine :tcTemplateEngine
{
    public:
        // Engine base
        std::uint32_t          initialize(void);
        void                   terminate(void) override;
        void                   process(const std::int64_t &_dt) override;
        sNetworkEvent*         getEvent(void) { return m_event.pop(); }

        // External system pointers
        void                   setGameConfigPointer(cGameConfig* _gameConfig) { m_GameConfig = _gameConfig; }

    protected:
    private:
        // Event
        tcQueue<sNetworkEvent> m_event          = {};

        // configuration management
        cGameConfig*       m_GameConfig         = nullptr;

};

#endif // NETWORK_ENGINE_HPP
