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

    #define ROBOENGINELOG  "RoboEngine.log"
    #define DEFAULTLOG  "default.log"

    void log_write(const std::string &s_fileName, const std::string &s_data);
    void log_clear(const std::string &s_fileName);
    std::string stripPath(const std::string &s_fileName);

    class re_cLog
    {
        public:
            re_cLog(void) {m_fileName = ROBOENGINELOG; clear();}
            re_cLog(const std::string &fileName) {m_fileName = fileName; clear();}
            ~re_cLog(void) {}
            re_cLog(const re_cLog&) = default;
            re_cLog& operator=(const re_cLog& rhs) {if (this == &rhs) return *this; return *this;}
            void inline write(const std::string &s_data) {log_write(m_fileName, s_data);}
            void inline clear(void) {log_clear(m_fileName);}
            void inline setFileName(const std::string &fileName) {m_fileName = fileName; }
        protected:
        private:
            std::string m_fileName = DEFAULTLOG;
    };

}

#endif // RE_LOG_HPP
