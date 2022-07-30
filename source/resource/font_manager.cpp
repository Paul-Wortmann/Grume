
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
    // Read font file into memory buffer
    std::fstream fileStream(std::string(FILE_PATH_FONT) + _fileName.c_str(), std::ios::in | std::ios::binary);
    if (fileStream.fail())
    {
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    fileStream.seekg(0, std::ios::end);
    std::uint64_t file_size = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    file_size -= fileStream.tellg();
    m_fontBuffer = new char[file_size];
    fileStream.read(m_fontBuffer, file_size);
    fileStream.close();

    // Error code
    std::uint32_t error_code = {};

    // Initialize the font
    error_code = stbtt_InitFont(&m_fontInfo, (unsigned char*)m_fontBuffer, 0);
    if (error_code != 1)
    {
        // Free the font data buffer if it exists
        if (m_fontBuffer != nullptr)
        {
            delete[] m_fontBuffer;
            m_fontBuffer = nullptr;
        }

        // Log error
        gLogWrite(LOG_ERROR, "Failed to initialize STB font Library: " + std::to_string(error_code), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }

    // Return successfully
    return EXIT_SUCCESS;
}

void cFontManager::terminate(void)
{
    // Free the opengl texture IDs.
    for (std::map<char, sFontCharacter>::const_iterator it = m_characters.begin(); it != m_characters.end(); it++)
    {
        delete[] m_characters[it->first].bitmap;
    }

    // Free the font data buffer if it exists
    if (m_fontBuffer != nullptr)
    {
        delete[] m_fontBuffer;
        m_fontBuffer = nullptr;
    }
}

std::uint32_t  cFontManager::initializeFont(void)
{
    // Generate textures
    m_generateGlyphs();
    return EXIT_SUCCESS;
}

void cFontManager::m_generateGlyphs(void)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    for (std::uint32_t c = 0; c < 128; c++)
    {
        // Load character glyph into a temporary buffer
        sFontCharacter character;
        unsigned char* tempBitmap = stbtt_GetCodepointBitmap(&m_fontInfo, 0, stbtt_ScaleForPixelHeight(&m_fontInfo, m_fontPixelScale),
                                                    c, &character.size.x, &character.size.y, &character.bearing.x, &character.bearing.y);

        // Create the bitmap buffer
        character.bitmap = new unsigned char[character.size.x * character.size.y];

        // Vertically flip the bitmap data
        for (std::int32_t y = 0; y < character.size.y; ++y)
        {
            for (std::int32_t x = 0; x < character.size.x; ++x)
            {
                character.bitmap[((character.size.y - 1 - y) * character.size.x) + x] = tempBitmap[(y * character.size.x) + x];
            }
        }

        // Store character for later use
        m_characters.insert(std::pair<char, sFontCharacter>(c, character));
    }
}

/*
/// FreeType Font Library
std::uint32_t cFontManager::initialize(const std::string &_fileName)
{
    // Error code
    std::uint32_t error_code   = {};

    // Initialize FreeType
    error_code = FT_Init_FreeType( &m_fontLibrary);
    if (error_code != 0)
    {
        gLogWrite(LOG_ERROR, "Failed to initialize FreeType font Library: " + std::to_string(error_code), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    // Version information
    else
    {
        std::int32_t  versionMajor = {};
        std::int32_t  versionMinor = {};
        std::int32_t  versionPatch = {};
        FT_Library_Version(m_fontLibrary, &versionMajor, &versionMinor, &versionPatch);
        gLogWrite(LOG_INFO, "FreeType version: " +
                    std::to_string(versionMajor) + "." +
                    std::to_string(versionMinor) + "." +
                    std::to_string(versionPatch), __FILE__, __LINE__, __FUNCTION__);
    }

    // Load and initialize the font file
    error_code = FT_New_Face(m_fontLibrary, (std::string(FILE_PATH_FONT) + _fileName).c_str(), 0, &m_fontFace);
    if (error_code == FT_Err_Unknown_File_Format)
    {
        gLogWrite(LOG_ERROR, "Failed to load font file: Unknown format: " + std::to_string(error_code), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    else if (error_code != 0)
    {
        gLogWrite(LOG_ERROR, "Failed to load font file: " + std::to_string(error_code), __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }

    // Set font pixel size
    FT_Set_Pixel_Sizes(m_fontFace, 0, m_fontPixelSize);

    // Return successfully
    return EXIT_SUCCESS;
}

std::uint32_t  cFontManager::initializeFont(void)
{
    // Generate textures
    m_generateGlyphs();
    return EXIT_SUCCESS;
}

void cFontManager::terminate(void)
{
    // Free the opengl texture IDs.
    for (std::map<char, sFontCharacter>::const_iterator it = m_characters.begin(); it != m_characters.end(); it++)
    {
        delete[] m_characters[it->first].bitmap;
    }

    FT_Done_Face(m_fontFace);
    FT_Done_FreeType(m_fontLibrary);
}

void cFontManager::m_generateGlyphs(void)
{
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // disable byte-alignment restriction

    for (std::uint32_t c = 0; c < 128; c++)
    {
        // Load character glyph
        if (FT_Load_Char(m_fontFace, c, FT_LOAD_RENDER))
        {
            gLogWrite(LOG_ERROR, "Failed to load font Glyph: " + std::to_string(c), __FILE__, __LINE__, __FUNCTION__);
            continue;
        }

        const std::uint32_t bufferSize = m_fontFace->glyph->bitmap.width * m_fontFace->glyph->bitmap.rows;

        sFontCharacter character;
        character.size.x    = m_fontFace->glyph->bitmap.width;
        character.size.y    = m_fontFace->glyph->bitmap.rows;
        character.bearing.x = m_fontFace->glyph->bitmap_left;
        character.bearing.y = m_fontFace->glyph->bitmap_top;
        character.advance   = m_fontFace->glyph->advance.x;
        character.bitmap    = new unsigned char[bufferSize];

        // Vertically flip the bitmap data
        for (std::uint32_t y = 0; y < m_fontFace->glyph->bitmap.rows; ++y)
        {
            for (std::uint32_t x = 0; x < m_fontFace->glyph->bitmap.width; ++x)
            {
                character.bitmap[((m_fontFace->glyph->bitmap.rows - 1 - y) * m_fontFace->glyph->bitmap.width) + x] = m_fontFace->glyph->bitmap.buffer[(y * m_fontFace->glyph->bitmap.width) + x];
            }
        }

        // Store character for later use
        m_characters.insert(std::pair<char, sFontCharacter>(c, character));
    }
}

*/
