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

#ifndef XML_PARSER_HPP
#define XML_PARSER_HPP

#include "../core/includes.hpp"

class cXML
{
    public:
        void load(const std::string &_fileName);
        void free(void) { delete [] m_line; m_line = nullptr; }
        uint32      lineCount(void) { return m_lineCount; }
        std::string line(uint32 _lineNum) { return (_lineNum < m_lineCount) ? m_line[_lineNum] : ""; }
        uint32      getInstanceCount(const std::string &_key);
        std::string getString(const std::string &_key, const uint32 _instance = 1);
        uint32      getInteger(const std::string &_key, const uint32 _instance = 1);
        float32     getFloat(const std::string &_key, const uint32 _instance = 1);
        glm::vec3   getVec3(const std::string &_key, const uint32 _instance = 1);
        glm::vec2   getVec2(const std::string &_key, const uint32 _instance = 1);
        glm::ivec3  getIvec3(const std::string &_key, const uint32 _instance = 1);
        
    protected:

    private:
        std::string  m_lineFormat(const std::string &_string);
        uint32       m_lineCount = 0;
        std::string* m_line      = nullptr;
};

#endif // XML_PARSER_HPP
