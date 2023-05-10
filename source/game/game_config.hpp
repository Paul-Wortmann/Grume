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

#ifndef GAME_CONFIG_HPP
#define GAME_CONFIG_HPP

#define CONFIG_FILE "config_001.txt" // Default config file name.

#include "../core/includes.hpp"
#include "../utils/xml_parser.hpp"

class cGameConfig
{
    public:
        void load(const std::string &_fileName = CONFIG_FILE);
        void save(const std::string &_fileName = CONFIG_FILE);

    protected:

    private:
    public:
        // These should all be set to low default values
        // The graphics engine will use the display's native resolution when fullscreen,
        // and will use the closest valid resolution to these values when not.

        // Graphics
        std::uint32_t m_resolution_x    = 1920;
        std::uint32_t m_resolution_y    = 1080;
        bool          m_fullscreen      = true;
        bool          m_basicRenderer   = false;
        bool          m_wireframeRender = false;

        // Audio
        std::uint32_t m_volume_max      = 100;
        std::uint32_t m_volume_master   = 30;
        std::uint32_t m_volume_music    = 40;
        std::uint32_t m_volume_sfx      = 50;
};

#endif // GAME_CONFIG_HPP

