
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

#include "font_manager.hpp"

std::uint32_t cFontManager::initialize(const std::string &_fileName)
{
    // Store font file name
    m_fileName = _fileName;
    
    // Read font file into memory buffer
    std::fstream fileStream(std::string(FILE_PATH_FONT) + m_fileName.c_str(), std::ios::in | std::ios::binary);
    if (fileStream.fail())
    {
        std::cout << "Failed to load file: " << m_fileName << std::endl;
        //gLogWrite(LOG_ERROR, "Error - Failed to open file: " + m_fileName + " error : " + std::strerror(errno), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    fileStream.seekg(0, std::ios::end);
    std::uint64_t file_size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file_size -= fileStream.tellg();
    m_fontBuffer = new char[file_size];
    fileStream.read(m_fontBuffer, file_size);
    fileStream.close();

    // Initialize the font
    if (!stbtt_InitFont(&m_fontInfo, (unsigned char*)m_fontBuffer, 0))
    {
        std::cout << "Failed to initialize font: " << m_fileName << std::endl;
        return EXIT_FAILURE;
    }

    // test
    //fontToImage("0.", 256);
    //std::cout << "Initialized font: " << m_fileName << std::endl;

    return EXIT_SUCCESS;
}

void cFontManager::terminate(void)
{
    if (m_fontBuffer != nullptr)
    {
        delete[] m_fontBuffer;
        m_fontBuffer = nullptr;
    }
}
