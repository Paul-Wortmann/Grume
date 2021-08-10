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
#include "../core/linked_list.hpp"
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
        void initialize(void);
        void terminate(void);
        void process(float32 _dt);
        
        // Volume
        void setVolumeMaster(float _volume) {m_listener.gain = _volume; alListenerf(AL_GAIN, _volume);}

        // Listener
        void setListenerPosition(glm::vec3 _position) {m_listener.position = _position; alListener3f(AL_POSITION, _position.x, _position.y, _position.z);}
        void setListenerVelocity(glm::vec3 _velocity) {m_listener.velocity = _velocity; alListener3f(AL_POSITION, _velocity.x, _velocity.y, _velocity.z);}

        // Audio sources
        uint32_t newAudioSource(void) {return m_sourceManager.newAudioSource()->ID;}
        void     attachSourceBuffer(uint32_t _sID, uint32_t _bID) {alSourcei(_sID, AL_BUFFER, _bID);}
        void     playSource(uint32_t _ID) {alSourcePlay(_ID);}
        void     stopSource(uint32_t _ID) {alSourceStop(_ID);}
        int32_t  getSourceState(uint32_t _ID) {int32_t state; alGetSourcei(_ID, AL_SOURCE_STATE, &state); return state;}
        void     setAudioSourcePitch(uint32_t _ID, float _pitch) {alSourcef(_ID, AL_PITCH, _pitch);}
        void     setAudioSourceGain(uint32_t _ID, float _gain) {alSourcef(_ID, AL_GAIN, _gain);}
        void     setAudioSourcePosition(uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_POSITION, _x, _y, _z);}
        void     setAudioSourcePosition(uint32_t _ID, glm::vec3 _position) {alSource3f(_ID, AL_POSITION, _position.x, _position.y, _position.z);}
        void     setAudioSourceVelocity(uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_VELOCITY, _x, _y, _z);}
        void     setAudioSourceVelocity(uint32_t _ID, glm::vec3 _velocity) {alSource3f(_ID, AL_VELOCITY, _velocity.x, _velocity.y, _velocity.z);}
        void     setAudioSourceLooping(uint32_t _ID, bool _looping) {alSourcei(_ID, AL_LOOPING, (_looping) ? AL_TRUE : AL_FALSE);}
        void     setAudioSourceLooping(uint32_t _ID, int32_t _looping) {alSourcei(_ID, AL_LOOPING, _looping);}
        
        // Audio buffers
        void     setAudioBufferName(uint32_t _ID, const std::string &_name);
        uint32_t findAudioBuffer(const std::string &_name) {sAudioBuffer* tB = m_bufferManager.findAudioBuffer(_name); return (tB == nullptr) ? 0 : tB->ID;}
        uint32_t newAudioBuffer(void) {return m_bufferManager.newAudioBuffer()->ID;}
        void     loadBufferWav(uint32_t _ID, const std::string &_fileName);
        void     loadBufferOgg(uint32_t _ID, const std::string &_fileName);
        
    protected:
        
    private:
        void m_freeAll(void);
        void m_freeData(sEntityAudio*& _pointer);

        ALCdevice*          m_device        = nullptr;
        ALCcontext*         m_context       = nullptr;

        cAudioSourceManager m_sourceManager = {};
        cAudioBufferManager m_bufferManager = {};
        sListener           m_listener      = {};
};

#endif //AUDIO_MANAGER_HPP
