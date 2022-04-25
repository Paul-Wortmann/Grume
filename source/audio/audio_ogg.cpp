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

#include "audio_ogg.hpp"

void loadOgg(const std::string &_fileName, sAudioData *_audioData)
{
    // Open the file
    OggVorbis_File oggFile = {};
    if (ov_fopen(_fileName.c_str(), &oggFile) == 0)
    {
        // Read data from the file header
        vorbis_info *pInfo = ov_info(&oggFile, -1);
        _audioData->channels = pInfo->channels;
        _audioData->audioFormat = (pInfo->channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        _audioData->sampleRate = pInfo->rate;
        _audioData->bitsPerSample = pInfo->bitrate_upper;

        std::uint16_t endian = 0;
        std::uint16_t wordSize = 2;
        std::uint16_t sampleSize = wordSize * pInfo->channels;
        _audioData->bufferSize = ov_pcm_total(&oggFile, -1) * sampleSize;
        if (_audioData->buffer != nullptr)
        {
            delete[] _audioData->buffer;
        }
        _audioData->buffer = new char [_audioData->bufferSize];
        std::uint64_t bufferPos = 0;
        std::uint32_t readLength = 4096;
        std::int32_t currentSection = 0;
        std::int32_t eof = 0;
        while(!eof)
        {
            std::uint64_t readSize = ov_read(&oggFile, &_audioData->buffer[bufferPos], readLength, endian, wordSize, 1, &currentSection);
            if (readSize == 0)
                eof = 1;
            bufferPos += readSize;
        }
        ov_clear(&oggFile);
    }
    else
    {
        // Log and error if we fail to open the file
        gLogWrite(LOG_ERROR, "Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}

void loadOggSTB(const std::string &_fileName, sAudioData *_audioData)
{
    // Temporary variables
    std::int32_t dataLength = 0;
    std::int32_t channels   = 0;
    std::int32_t sampleRate = 0;
    std::int16_t *data      = nullptr;
    
    // Decode file into buffer
    dataLength = stb_vorbis_decode_filename(_fileName.c_str(), &channels, &sampleRate, &data);

    // Check for errors
    if (dataLength == -2)
    {
        // Log and error if we fail to decode the file
        gLogWrite(LOG_ERROR, "Failed to decode file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else if (dataLength <= 0)
    {
        // Log and error if we fail to open the file
        gLogWrite(LOG_ERROR, "Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        // Save returned data
        _audioData->channels = channels;
        _audioData->audioFormat = (channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        _audioData->sampleRate = sampleRate;
        _audioData->bitsPerSample = 0;
        
        //const std::uint16_t wordSize = 2;
        //_audioData->bufferSize = dataLength * wordSize * _audioData->channels * sizeof(data);
        _audioData->bufferSize = dataLength * sizeof(std::int16_t);
        
        // Make sure the buffer is empty
        if (_audioData->buffer != nullptr)
        {
            delete[] _audioData->buffer;
        }
        
        // Save the data
        _audioData->buffer = new char[_audioData->bufferSize];
        memcpy(&_audioData->buffer, &data, _audioData->bufferSize);
    }
    
    // clean up
    if (data != nullptr)
    {
        delete[] data;
    }
}
