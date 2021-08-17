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


#include "audio_wav.hpp"

void loadWav(const std::string &_fileName, sAudioData *_audioData)
{
    // Open the file
    std::ifstream inFile (_fileName, std::ifstream::binary);
    if (inFile)
    {
        // Read data from the file header
        const uint32_t HEADER_LENGTH = 44;
        inFile.seekg (0, inFile.end);
        _audioData->bufferSize = inFile.tellg();
        _audioData->bufferSize -= HEADER_LENGTH;
        inFile.seekg (0, inFile.beg);
        char *header = new char[HEADER_LENGTH];
        if (_audioData->buffer != nullptr)
        {
            delete[] _audioData->buffer;
        }
        _audioData->buffer = new char [_audioData->bufferSize];
        inFile.read(header,HEADER_LENGTH);
        inFile.read(_audioData->buffer,_audioData->bufferSize);
        inFile.close();
        uint16_t header_format = header[20];
        uint16_t header_channels = header[22];
        uint32_t header_sampleRate = (reinterpret_cast<unsigned char&>(header[25]) * 256) + reinterpret_cast<unsigned char&>(header[24]);
        uint32_t header_bitsPerSample = header[34];
        
        // Save data to the audio data struct
        _audioData->channels = header_channels;
        _audioData->sampleRate = header_sampleRate;
        _audioData->bitsPerSample = header_bitsPerSample;
        
        // Save audio format data to the audio data struct based on 
        // number of channels and bits per sample.
        if (_audioData->channels == 1)
        {
            _audioData->audioFormat = (_audioData->bitsPerSample == 8) ? AL_FORMAT_MONO8 : AL_FORMAT_MONO16;
        }
        else if  (_audioData->channels == 2)
        {
            _audioData->audioFormat = (_audioData->bitsPerSample == 8) ? AL_FORMAT_STEREO8 : AL_FORMAT_STEREO16;
        }
        else
        {
            _audioData->audioFormat = header_format;
        }

        // Clean up
        delete[] header;
    }
    else
    {
        // Log and error if we faile to open the file
        gLogWrite(LOG_ERROR, "Failed to load file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
}
