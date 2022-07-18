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

#ifndef AUDIO_ENGINE_HPP
#define AUDIO_ENGINE_HPP

#include "audio_engine_defines.hpp"

class cAudioEngine
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);
        void          process(float _dt);
        void          loadMusic(const std::string &_fileName);
        void          playMusic();
        std::uint32_t loadSound(const std::string &_fileName);
        void          playSound(const std::uint32_t &_bufferID);

        // Listener
        void          setListenerPosition(glm::vec3 _position) {m_listener.position = _position; alListener3f(AL_POSITION, _position.x, _position.y, _position.z);}
        void          setListenerVelocity(glm::vec3 _velocity) {m_listener.velocity = _velocity; alListener3f(AL_POSITION, _velocity.x, _velocity.y, _velocity.z);}

        // Audio sources
        std::uint32_t newAudioSource(void) {return m_sourceManager.newAudioSource()->ID;}
        void          attachSourceBuffer(std::uint32_t _sID, std::uint32_t _bID) {alSourcei(_sID, AL_BUFFER, _bID);}
        void          playSource(std::uint32_t _ID) {alSourcePlay(_ID);}
        void          stopSource(std::uint32_t _ID) {alSourceStop(_ID);}
        std::int32_t  getSourceState(std::uint32_t _ID) {std::int32_t state; alGetSourcei(_ID, AL_SOURCE_STATE, &state); return state;}
        void          setAudioSourcePitch(std::uint32_t _ID, float _pitch) {alSourcef(_ID, AL_PITCH, _pitch);}
        void          setAudioSourceGain(std::uint32_t _ID, float _gain) {alSourcef(_ID, AL_GAIN, _gain);}
        void          setAudioSourcePosition(std::uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_POSITION, _x, _y, _z);}
        void          setAudioSourcePosition(std::uint32_t _ID, glm::vec3 _position) {alSource3f(_ID, AL_POSITION, _position.x, _position.y, _position.z);}
        void          setAudioSourceVelocity(std::uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_VELOCITY, _x, _y, _z);}
        void          setAudioSourceVelocity(std::uint32_t _ID, glm::vec3 _velocity) {alSource3f(_ID, AL_VELOCITY, _velocity.x, _velocity.y, _velocity.z);}
        void          setAudioSourceLooping(std::uint32_t _ID, bool _looping) {alSourcei(_ID, AL_LOOPING, (_looping) ? AL_TRUE : AL_FALSE);}
        void          setAudioSourceLooping(std::uint32_t _ID, std::int32_t _looping) {alSourcei(_ID, AL_LOOPING, _looping);}

        // Audio buffers
        void          loadBufferWav(std::uint32_t _ID, const std::string &_fileName);
        void          loadBufferOgg(std::uint32_t _ID, const std::string &_fileName);

        // Volume
        void          setVolumeMaster(std::uint32_t _volume) {m_volumeMaster = _volume; m_updateVolume(); };
        std::uint32_t getVolumeMaster(void) {return m_volumeMaster; m_updateVolume(); };
        void          setVolumeMasterUp(void) { if (m_volumeMaster < 100) m_volumeMaster++; m_updateVolume(); };
        void          setVolumeMasterDown(void) { if (m_volumeMaster > 0) m_volumeMaster--; m_updateVolume(); };
        void          setVolumeMusic(std::uint32_t _volume) {m_volumeMusic = _volume; m_updateVolume(); };
        std::uint32_t getVolumeMusic(void) {return m_volumeMusic; m_updateVolume(); };
        void          setVolumeMusicUp(void) { if (m_volumeMusic < 100) m_volumeMusic++; m_updateVolume(); };
        void          setVolumeMusicDown(void) { if (m_volumeMusic > 0) m_volumeMusic--; m_updateVolume(); };
        void          setVolumeSound(std::uint32_t _volume) {m_volumeSound = _volume; m_updateVolume(); };
        std::uint32_t getVolumeSound(void) {return m_volumeSound; m_updateVolume(); };
        void          setVolumeSoundUp(void) { if (m_volumeSound < 100) m_volumeSound++; m_updateVolume(); };
        void          setVolumeSoundDown(void) { if (m_volumeSound > 0) m_volumeSound--; m_updateVolume(); };

    protected:

    private:
        void                m_updateVolume(void);

        ALCdevice*          m_device        = nullptr;
        ALCcontext*         m_context       = nullptr;

        cAudioSourceManager m_sourceManager = {};
        cAudioBufferManager m_bufferManager = {};
        sListener           m_listener      = {};

        std::uint32_t       m_volumeMaster  = 100;
        std::uint32_t       m_volumeMusic   = 100;
        std::uint32_t       m_volumeSound   = 100;

        std::uint32_t       m_musicBufferID = 0;
        sAudioSource*       m_musicSource   = nullptr;
};

#endif // AUDIO_ENGINE_HPP
