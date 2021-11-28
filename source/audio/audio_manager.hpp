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

#ifndef AUDIO_MANAGER_HPP
#define AUDIO_MANAGER_HPP

#include "../core/includes.hpp"
#include "../entity/entity_audio.hpp"
#include "audio_defines.hpp"
#include "audio_debug.hpp"
#include "audio_ogg.hpp"
#include "audio_wav.hpp"
#include "audio_buffer_manager.hpp"
#include "audio_source_manager.hpp"

class cAudioManager : public tcLinkedList<sEntityAudio>
{
    public:
        void     initialize(void);
        void     terminate(void);
        void     process(float32 _dt);
        
        // Listener
        void     setListenerPosition(glm::vec3 _position) {m_listener.position = _position; alListener3f(AL_POSITION, _position.x, _position.y, _position.z);}
        void     setListenerVelocity(glm::vec3 _velocity) {m_listener.velocity = _velocity; alListener3f(AL_POSITION, _velocity.x, _velocity.y, _velocity.z);}

        // Audio sources
        uint32   newAudioSource(void) {return m_sourceManager.newAudioSource()->ID;}
        void     attachSourceBuffer(uint32 _sID, uint32 _bID) {alSourcei(_sID, AL_BUFFER, _bID);}
        void     playSource(uint32 _ID) {alSourcePlay(_ID);}
        void     stopSource(uint32 _ID) {alSourceStop(_ID);}
        int32    getSourceState(uint32 _ID) {int32 state; alGetSourcei(_ID, AL_SOURCE_STATE, &state); return state;}
        void     setAudioSourcePitch(uint32 _ID, float _pitch) {alSourcef(_ID, AL_PITCH, _pitch);}
        void     setAudioSourceGain(uint32 _ID, float _gain) {alSourcef(_ID, AL_GAIN, _gain);}
        void     setAudioSourcePosition(uint32 _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_POSITION, _x, _y, _z);}
        void     setAudioSourcePosition(uint32 _ID, glm::vec3 _position) {alSource3f(_ID, AL_POSITION, _position.x, _position.y, _position.z);}
        void     setAudioSourceVelocity(uint32 _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_VELOCITY, _x, _y, _z);}
        void     setAudioSourceVelocity(uint32 _ID, glm::vec3 _velocity) {alSource3f(_ID, AL_VELOCITY, _velocity.x, _velocity.y, _velocity.z);}
        void     setAudioSourceLooping(uint32 _ID, bool _looping) {alSourcei(_ID, AL_LOOPING, (_looping) ? AL_TRUE : AL_FALSE);}
        void     setAudioSourceLooping(uint32 _ID, int32 _looping) {alSourcei(_ID, AL_LOOPING, _looping);}
        
        // Audio buffers
        void     setAudioBufferName(uint32 _ID, const std::string &_name);
        uint32   findAudioBuffer(const string &_name) {sAudioBuffer* tB = m_bufferManager.findAudioBuffer(_name); return (tB == nullptr) ? 0 : tB->ID;}
        uint32   newAudioBuffer(void) {return m_bufferManager.newAudioBuffer()->ID;}
        void     loadBufferWav(uint32 _ID, const string &_fileName);
        void     loadBufferOgg(uint32 _ID, const string &_fileName);

        // Volume
        void     setVolumeMaster(uint32 _volume) {m_volumeMaster = _volume; m_updateVolume(); };
        uint32   getVolumeMaster(void) {return m_volumeMaster; m_updateVolume(); };
        void     setVolumeMasterUp(void) { if (m_volumeMaster < 100) m_volumeMaster++; m_updateVolume(); };
        void     setVolumeMasterDown(void) { if (m_volumeMaster > 0) m_volumeMaster--; m_updateVolume(); };
        void     setVolumeMusic(uint32 _volume) {m_volumeMusic = _volume; m_updateVolume(); };
        uint32   getVolumeMusic(void) {return m_volumeMusic; m_updateVolume(); };
        void     setVolumeMusicUp(void) { if (m_volumeMusic < 100) m_volumeMusic++; m_updateVolume(); };
        void     setVolumeMusicDown(void) { if (m_volumeMusic > 0) m_volumeMusic--; m_updateVolume(); };
        void     setVolumeSound(uint32 _volume) {m_volumeSound = _volume; m_updateVolume(); };
        uint32   getVolumeSound(void) {return m_volumeSound; m_updateVolume(); };
        void     setVolumeSoundUp(void) { if (m_volumeSound < 100) m_volumeSound++; m_updateVolume(); };
        void     setVolumeSoundDown(void) { if (m_volumeSound > 0) m_volumeSound--; m_updateVolume(); };
        
    protected:
        
    private:
        void     freeData(sEntityAudio*& _pointer);
        void     m_updateVolume(void);

        ALCdevice*          m_device        = nullptr;
        ALCcontext*         m_context       = nullptr;

        cAudioSourceManager m_sourceManager = {};
        cAudioBufferManager m_bufferManager = {};
        sListener           m_listener      = {};
        
        uint32       m_volumeMaster  = 100;
        uint32       m_volumeMusic   = 100;
        uint32       m_volumeSound   = 100;
};

#endif //AUDIO_MANAGER_HPP
