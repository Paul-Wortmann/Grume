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

// A class to hold an xml file content, and provide helper functions to extract data there from.
// *This does not cover the full XML specification, but a basic subset needed for this project.

class cXML
{
    public:
        std::uint32_t load(const std::string &_fileName);
        void          free(void) { delete [] m_line; m_line = nullptr; m_lineCount = 0; m_isValid = false;}
        bool          isValid(void) { return m_isValid; };
        std::uint32_t lineCount(void) { return m_lineCount; }
        std::string   line(std::uint32_t _lineNum) { return (_lineNum < m_lineCount) ? m_line[_lineNum] : ""; }
        std::uint32_t getInstanceCount(const std::string &_key);
        std::string   getString(const std::string &_key, const std::uint32_t  _instance = 1);
        std::int32_t  getInteger(const std::string &_key, const std::uint32_t  _instance = 1);
        std::uint64_t getInteger64(const std::string &_key, const std::uint32_t  _instance = 1);
        float         getFloat(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::vec4     getVec4(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::vec3     getVec3(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::vec2     getVec2(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::ivec4    getIvec4(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::ivec3    getIvec3(const std::string &_key, const std::uint32_t  _instance = 1);
        glm::ivec2    getIVec2(const std::string &_key, const std::uint32_t  _instance = 1);

    protected:

    private:
        std::string   m_formatLine(const std::string &_string);
        bool          m_isValid   = false;
        std::uint32_t m_lineCount = 0;
        std::string*  m_line      = nullptr;
};

#endif // XML_PARSER_HPP
