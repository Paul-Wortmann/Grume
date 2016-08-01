/**
 * Copyright (C) Paul Wortmann, PhysHex Games, www.physhexgames.com
 * This file is part of "Frost And Flame"
 *
 * "Frost And Flame" is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 only.
 *
 * "Frost And Flame" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "Frost And Flame" If not, see <http://www.gnu.org/licenses/>.
 *
 * @author  Paul Wortmann
 * @email   physhex@gmail.com
 * @website www.physhexgames.com
 * @license GPL V2
 * @date 2011-11-11
 */

#ifndef RE_LOG_HPP
#define RE_LOG_HPP

#include <string>

namespace RoboEngine
{

    void log_write(const std::string &s_file_name, const std::string &s_data);
    void log_clear(const std::string &s_file_name);

    class c_log
    {
        public:
            c_log(const std::string &file_name) {m_file_name = file_name; clear();}
            ~c_log(void) {}
            c_log(const c_log&) = default;
            c_log& operator=(const c_log& rhs) {if (this == &rhs) return *this; return *this;}
            void inline write(const std::string &s_data) {log_write(m_file_name, s_data);}
            void inline clear(void) {log_clear(m_file_name);}
            void inline set_file_name(const std::string &file_name) {m_file_name = file_name; }
        protected:
        private:
        std::string m_file_name = "default.log";
    };

}

#endif // RE_LOG_HPP
