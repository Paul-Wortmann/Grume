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

#include "audio_engine_debug.hpp"

uint32_t checkAudioError(void)
{
    ALCenum error;
    error = alGetError();
    if (error != AL_NO_ERROR)
        return error;
    return AL_NO_ERROR;
}

std::string getAudioErrorString(ALenum _error)
{
    switch(_error)
    {
        case AL_NO_ERROR:
            return std::string("AL_NO_ERROR - (No error).");
        break;
        case AL_INVALID_NAME:
            return std::string("AL_INVALID_NAME - Invalid Name parameter passed to AL call.");
        break;
        case AL_INVALID_ENUM:
            return std::string("AL_INVALID_ENUM - Invalid parameter passed to AL call.");
        break;
        case AL_INVALID_VALUE:
            return std::string("AL_INVALID_VALUE - Invalid enum parameter value.");
        break;
        case AL_INVALID_OPERATION:
            return std::string("AL_INVALID_OPERATION");
        break;
        case AL_OUT_OF_MEMORY:
            return std::string("AL_OUT_OF_MEMORY");
        break;
        default:
            return std::string("AL Unknown Error.");
        break;
    };
}

