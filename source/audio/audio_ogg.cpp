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
    OggVorbis_File oggFile = {};
    if (ov_fopen(_fileName.c_str(), &oggFile) == 0)
    {
        vorbis_info *pInfo = ov_info(&oggFile, -1);
        _audioData->channels = pInfo->channels;
        _audioData->audioFormat = (pInfo->channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        _audioData->sampleRate = pInfo->rate;
        _audioData->bitsPerSample = pInfo->bitrate_upper;
        uint16_t endian = 0;
        uint16_t wordSize = 2;
        uint16_t sampleSize = wordSize * pInfo->channels;
        _audioData->bufferSize = ov_pcm_total(&oggFile, -1) * sampleSize;
        if (_audioData->buffer != nullptr)
            delete[] _audioData->buffer;
        _audioData->buffer = new char [_audioData->bufferSize];
        uint64_t bufferPos = 0;
        uint32_t readLength = 4096;
        int32_t currentSection = 0;
        int32_t eof = 0;
        while(!eof)
        {
            uint64_t readSize = ov_read(&oggFile, &_audioData->buffer[bufferPos], readLength, endian, wordSize, 1, &currentSection);
            if (readSize == 0)
                eof = 1;
            bufferPos += readSize;
        }
        ov_clear(&oggFile);
    }
    else
    {
        gLogWrite(LOG_ERROR, "Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}
