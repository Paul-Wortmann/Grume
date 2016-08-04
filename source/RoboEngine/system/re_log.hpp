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

    void log_write(const std::string &s_fileName, const std::string &s_data, const bool &_consoleLogging);
    void log_write(const std::string &s_fileName, const std::string &s_dataFile, const std::string &s_dataFunction, const uint32_t &s_dataLine, const std::string &s_message);
    void log_write(const std::string &s_fileName, const std::string &s_dataFile, const std::string &s_dataFunction, const uint32_t &s_dataLine, const std::string &s_message, const bool &_consoleLogging);
    void log_write(const std::string &s_fileName, const std::string &s_data);
    void log_clear(const std::string &s_fileName);
    std::string stripPath(const std::string &s_fileName);

    class re_cLog
    {
        public:
            re_cLog(void) {m_fileName = ROBOENGINELOG; clear();}
            re_cLog(const std::string &_fileName) {m_fileName = _fileName; clear();}
            ~re_cLog(void) {}
            re_cLog(const re_cLog&) = default;
            re_cLog& operator=(const re_cLog& _rhs) {if (this == &_rhs) return *this; return *this;}
            void inline write(const std::string &s_data) {log_write(m_fileName, s_data, m_logToConsole);}
            void inline clear(void) {log_clear(m_fileName);}
            void inline setFileName(const std::string &_fileName) {m_fileName = _fileName; }
            void inline setConsoleLogging(const bool &_state) {m_logToConsole = _state; }
            bool inline getConsoleLogging(void) { return m_logToConsole; }
        protected:
        private:
            std::string m_fileName = DEFAULTLOG;
            bool m_logToConsole = false;
    };

}

#endif // RE_LOG_HPP
