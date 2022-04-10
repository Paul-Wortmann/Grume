
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

void cFontManager::m_convertAlphaToRGBA(const std::uint32_t &_width, const std::uint32_t &_height, unsigned char* &_imageBuffer)
{
    std::uint32_t _r = 255;
    std::uint32_t _g = 127;
    std::uint32_t _b = 127;

    // Early exit
    if (_imageBuffer == nullptr)
        return;

    // GL_RGBA = 4 bytes
    const std::uint32_t format = 4;

    // Save the image data
    const std::uint32_t oldSize = _width * _height;
    unsigned char* inputImageBuffer = new unsigned char[oldSize];
    for (std::uint32_t i = 0; i < oldSize; ++i)
    {
        inputImageBuffer[i] = _imageBuffer[i];
    }

    // Resize the image buffer
    delete[] _imageBuffer;
    _imageBuffer = new unsigned char[oldSize * format];

    // Write the new data
    for (std::uint32_t i = 0; i < oldSize; ++i)
    {
            _imageBuffer[(i * format) + 0] = (inputImageBuffer[i] * _r) / 255;
            _imageBuffer[(i * format) + 1] = (inputImageBuffer[i] * _g) / 255;
            _imageBuffer[(i * format) + 2] = (inputImageBuffer[i] * _b) / 255;
            _imageBuffer[(i * format) + 3] = inputImageBuffer[i];
    }
}

void cFontManager::m_fontToImage(const std::string &_string, const float &_pixelSize)
{
    std::uint32_t numChar = _string.length();
    std::cout << "Num char: " << numChar << std::endl;

    // Calculate font scaling
    float scale = stbtt_ScaleForPixelHeight(&m_fontInfo, _pixelSize); // scale = pixels / (ascent - descent)

    // Calculate image width
    std::uint32_t width = 0;
    for (std::uint32_t i = 0; i < numChar; ++i)
    {
        int advanceWidth = 0;
        int leftSideBearing = 0;
        stbtt_GetCodepointHMetrics(&m_fontInfo, _string[i], &advanceWidth, &leftSideBearing);
        width += advanceWidth;
    }

    // create a bitmap image
    std::uint32_t bitmap_w = width * scale; // Width of bitmap
    std::uint32_t bitmap_h = _pixelSize; // Height of bitmap

    std::cout << "bitmap_w: " << bitmap_w << std::endl;
    std::cout << "bitmap_h: " << bitmap_h << std::endl;

    unsigned char *bitmap = new unsigned char[bitmap_w * bitmap_h];

    // Get the measurement in the vertical direction
    // ascent: The height of the font from the baseline to the top;
    // descent: The height from baseline to bottom is usually negative;
    // lineGap: The distance between two fonts;
    // The line spacing is: ascent - descent + lineGap.

    int ascent = 0;
    int descent = 0;
    int lineGap = 0;
    stbtt_GetFontVMetrics(&m_fontInfo, &ascent, &descent, &lineGap);

    // Adjust word height according to zoom
    ascent = roundf(ascent * scale);
    descent = roundf(descent * scale);

    int x = 0; /*x of bitmap*/

    // Cyclic loading of each character in _string
    for (std::uint32_t i = 0; i < numChar; ++i)
    {
        // Get the measurement in the horizontal direction
        // advanceWidth: Word width;
        // leftSideBearing: Left side position;

        int advanceWidth = 0;
        int leftSideBearing = 0;
        stbtt_GetCodepointHMetrics(&m_fontInfo, _string[i], &advanceWidth, &leftSideBearing);

        // Gets the border of a character
        int c_x1, c_y1, c_x2, c_y2;
        stbtt_GetCodepointBitmapBox(&m_fontInfo, _string[i], scale, scale, &c_x1, &c_y1, &c_x2, &c_y2);

        // Calculate the y of the bitmap (different characters have different heights)
        int y = ascent + c_y1;

        // Render character
        int byteOffset = x + roundf(leftSideBearing * scale) + (y * bitmap_w);
        stbtt_MakeCodepointBitmap(&m_fontInfo, bitmap + byteOffset, c_x2 - c_x1, c_y2 - c_y1, bitmap_w, scale, scale, _string[i]);

        // Adjust x
        x += roundf(advanceWidth * scale);

        // kerning
        int kern;
        kern = stbtt_GetCodepointKernAdvance(&m_fontInfo, _string[i], _string[i + 1]);
        x += roundf(kern * scale);
    }

    //write_raw("raw.txt", bitmap_w, bitmap_h, bitmap);

    //stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    //stbi_write_force_png_filter      = 4;

    m_convertAlphaToRGBA(bitmap_w, bitmap_h, bitmap);
    // Save the bitmap data to the 1-channel png image
    stbi_write_png("STB.png", bitmap_w, bitmap_h, 4, bitmap, bitmap_w * 4);

    free(bitmap);
}

std::uint32_t cFontManager::initialize(const std::string &_fileName)
{
    // Store font file name
    m_fileName = _fileName;
    
    // Read font file into memory buffer
    std::fstream fileStream(std::string(FILE_PATH_FONT) + m_fileName.c_str(), std::ios::in | std::ios::binary);
    if (fileStream.fail())
    {
        std::cout << "Failed to load file: " << m_fileName << std::endl;
        gLogWrite(LOG_ERROR, "Error - Failed to open file: " + m_fileName + " error : " + std::strerror(errno), __FILE__, __LINE__, __FUNCTION__);
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
    m_fontToImage("0.", 256);
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
