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

#include <fstream>
#include <iostream>
#include <string>

#include "re_file.hpp"

namespace RoboEngine
{

    uint32_t re_logClear(const std::string &_fileName);
    void re_logToConsole(const std::string &_message, const std::string &_mFile, const uint32_t &_mLine, const std::string &_mFunction);
    void re_logToConsole(const std::string &_message);
    uint32_t re_logWrite(const std::string &_message, const std::string &_fileName, const std::string &_mFile, const uint32_t &_mLine, const std::string &_mFunction);
    uint32_t re_logWrite(const std::string &_message, const std::string &_fileName);

    class re_cLog
    {
        public:
            re_cLog(void) = default;
            explicit re_cLog(const std::string &_fileName) : m_fileName(_fileName) {clear();}
            virtual ~re_cLog(void) = default;
            re_cLog(const re_cLog&) = default;
            re_cLog& operator=(const re_cLog& _rhs) {if (this == &_rhs) return *this; return *this;}

            uint32_t initialize(const std::string &_fileName) {m_fileName = _fileName; return re_logClear(_fileName);}
            uint32_t write(const std::string &_message, const std::string &_mFile, const uint32_t &_mLine, const std::string &_mFunction)
            {
                if(m_logToConsole) re_logToConsole(_message, _mFile, _mLine, _mFunction);
                return re_logWrite(_message,m_fileName,  _mFile, _mLine, _mFunction);
            }
            uint32_t write(const std::string &_message)
            {
                if(m_logToConsole) re_logToConsole(_message);
                return re_logWrite(_message, m_fileName);
            }
            void setLogConsole(bool _bool) {m_logToConsole = _bool;}

            void clear(void)
            {
                re_logClear(m_fileName);
            }

        protected:

        private:
            std::string m_fileName = "RoboEngine.log";
            bool m_logToConsole = false;
    };

}

#endif // RE_LOG_HPP
