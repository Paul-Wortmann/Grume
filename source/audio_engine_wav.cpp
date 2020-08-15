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

#include "audio_engine_wav.hpp"

void loadWav(const std::string &_fileName, sAudioData *_audioData)
{
    std::ifstream inFile (_fileName, std::ifstream::binary);
    if (inFile)
    {
        const uint32_t HEADER_LENGTH = 44;
        inFile.seekg (0, inFile.end);
        _audioData->bufferSize = inFile.tellg();
        _audioData->bufferSize -= HEADER_LENGTH;
        inFile.seekg (0, inFile.beg);
        char *header = new char[HEADER_LENGTH];
        _audioData->buffer = new char [_audioData->bufferSize];
        inFile.read(header,HEADER_LENGTH);
        inFile.read(_audioData->buffer,_audioData->bufferSize);
        inFile.close();
        uint16_t header_format;
        header_format = header[20];
        uint16_t header_channels;
        header_channels = header[22];
        uint32_t header_sampleRate = 0;
        header_sampleRate = (reinterpret_cast<unsigned char&>(header[25]) * 256) + reinterpret_cast<unsigned char&>(header[24]);
        uint32_t header_bitsPerSample = 0;
        header_bitsPerSample = header[34];
        _audioData->audioFormat = header_format;
        _audioData->channels = header_channels;
        _audioData->sampleRate = header_sampleRate;
        _audioData->bitsPerSample = header_bitsPerSample;
        _audioData->audioFormat = (_audioData->channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        delete[] header;
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}
