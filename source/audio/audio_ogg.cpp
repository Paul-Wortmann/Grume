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
    if (dataLength == -1)
    {
        // Log and error if we fail to open the file
        gLogWrite(LOG_ERROR, "Failed to open file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else if (dataLength == -2)
    {
        // Log and error if we fail to decode the file
        gLogWrite(LOG_ERROR, "Failed to decode file: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        // Save returned data
        _audioData->channels = channels;
        _audioData->audioFormat = (channels == 1) ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
        _audioData->sampleRate = sampleRate;
        _audioData->bitsPerSample = 0;
        
        const std::uint16_t wordSize = 1;
        //_audioData->bufferSize = dataLength * wordSize * _audioData->channels * sizeof(data);
        _audioData->bufferSize = dataLength * sizeof(std::int16_t);
        if (_audioData->buffer != nullptr)
        {
            delete[] _audioData->buffer;
        }
        
        //samples*2*sizeof(short)
        
        std::cout << "Channels: " << _audioData->channels << std::endl;
        std::cout << "SampleRate: " << _audioData->sampleRate << std::endl;
        std::cout << "BitsPerSample: " << _audioData->bitsPerSample << std::endl;
        std::cout << "Buffer size: " << _audioData->bufferSize << std::endl;
        
        _audioData->buffer = new char[_audioData->bufferSize];
        for (std::size_t i = 0; i < _audioData->bufferSize; ++i)
        {
            _audioData->buffer[i] = data[i];
        }
        
        
        //memcpy(&_audioData->buffer, &data, _audioData->bufferSize);
    }
    
    // clean up
    if (data != nullptr)
    {
        delete[] data;
    }
}


/*
INCLUDE openal.bac

CONST file$ = "test2.ogg"                                          : ' File to convert to PCM data

' STB Ogg Vorbis decoding -----------------------------------------------------------------------------------

PRAGMA INCLUDE canvas/stb-master/stb_vorbis.c                      : ' Include the stb_vorbis header file

DECLARE channels, sample_rate, samples TYPE int
DECLARE data TYPE short*

samples = stb_vorbis_decode_filename(file$, &channels, &sample_rate, &data)

PRINT "Channels: ", channels
PRINT "Samples: ", samples
PRINT "Sample rate: ", sample_rate

' OpenAL sound renderer -------------------------------------------------------------------------------------

DECLARE buffer, source, state TYPE int
DECLARE device, context TYPE void*

device = alcOpenDevice(NULL)                                       : ' Initialize sound device
IF device THEN
    context = alcCreateContext(device, NULL)                       : ' Create OpenAL context
    alcMakeContextCurrent(context)                                 : ' We are going to use this context
ELSE
    PRINT "Cannot open device."
    END 1
ENDIF

alGenBuffers(1, &buffer)                                           : ' Create a buffer to store sound data

alBufferData(buffer, AL_FORMAT_STEREO16, data, \
            samples*2*sizeof(short), sample_rate)                  : ' Put the decoded data into the OpenAL buffer

alGenSources(1, &source)                                           : ' Generate the sources

alSourceQueueBuffers(source, 1, &buffer)                           : ' Attach the buffer to a sound source

alSourcePlay(source)                                               : ' Now start playing the sound asynchronously

REPEAT
    SLEEP 10                                                       : ' Prevent CPU load of 100%
    alGetSourcei(source, AL_SOURCE_STATE, &state)                  : ' Check if we're still playing
UNTIL state <> AL_PLAYING

alDeleteSources(1, &source)                                        : ' Cleanup all resources
alDeleteBuffers(1, &buffer)
alcMakeContextCurrent(NULL) 
alcDestroyContext(context)
alcCloseDevice(device)
FREE data
*/