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

#ifndef AUDIO_ENGINE_HPP
#define AUDIO_ENGINE_HPP

#include "defines.hpp"
#include "includes.hpp"

#include "entity_component_audio.hpp"

#include "audio_engine_buffers.hpp"
#include "audio_engine_debug.hpp"
#include "audio_engine_ogg.hpp"
#include "audio_engine_sources.hpp"
#include "audio_engine_types.hpp"
#include "audio_engine_wav.hpp"

class cAudioEngine
{
    private:
        sEntityAudio *m_entityFirst = nullptr;
        sEntityAudio *m_entityTemp  = nullptr;

        ALCdevice *m_device = nullptr;
        ALCcontext *m_context = nullptr;
        cAudioEngineSourceManager m_sourceManager = {};
        cAudioEngineBufferManager m_bufferManager = {};
        sListener m_listener = {};

    protected:

    public:
        cAudioEngine(void);
        ~cAudioEngine(void);
        cAudioEngine(cAudioEngine &_other) = delete;
        cAudioEngine(const cAudioEngine &_other) = delete;
        cAudioEngine&operator=(const cAudioEngine& other) = delete;

        void initialize(void);
        void terminate(void);
        void process(void);
        
        // Entity
        void setEntityHandle(sEntityAudio *_entity);

        // Volume
        void setVolumeMaster(float _volume) {m_listener.gain = _volume; alListenerf(AL_GAIN, _volume);}

        // Listener
        void setListenerPosition(glm::vec3 _position) {m_listener.position = _position; alListener3f(AL_POSITION, _position.x, _position.y, _position.z);}
        void setListenerVelocity(glm::vec3 _velocity) {m_listener.velocity = _velocity; alListener3f(AL_POSITION, _velocity.x, _velocity.y, _velocity.z);}

        // Audio sources
        uint32_t newAudioSource(void) {return m_sourceManager.newAudioSource()->ID;}
        void attachSourceBuffer(uint32_t _sID, uint32_t _bID) {alSourcei(_sID, AL_BUFFER, _bID);}
        void playSource(uint32_t _ID) {alSourcePlay(_ID);}
        int32_t getSourceState(uint32_t _ID) {int32_t state; alGetSourcei(_ID, AL_SOURCE_STATE, &state); return state;}
        void setAudioSourcePitch(uint32_t _ID, float _pitch) {alSourcef(_ID, AL_PITCH, _pitch);}
        void setAudioSourceGain(uint32_t _ID, float _gain) {alSourcef(_ID, AL_GAIN, _gain);}
        void setAudioSourcePosition(uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_POSITION, _x, _y, _z);}
        void setAudioSourcePosition(uint32_t _ID, glm::vec3 _position) {alSource3f(_ID, AL_POSITION, _position.x, _position.y, _position.z);}
        void setAudioSourceVelocity(uint32_t _ID, float _x, float _y, float _z) {alSource3f(_ID, AL_VELOCITY, _x, _y, _z);}
        void setAudioSourceVelocity(uint32_t _ID, glm::vec3 _velocity) {alSource3f(_ID, AL_VELOCITY, _velocity.x, _velocity.y, _velocity.z);}
        void setAudioSourceLooping(uint32_t _ID, bool _looping) {alSourcei(_ID, AL_LOOPING, (_looping) ? AL_TRUE : AL_FALSE);}
        void setAudioSourceLooping(uint32_t _ID, int32_t _looping) {alSourcei(_ID, AL_LOOPING, _looping);}
        
        // Audio buffers
        void setAudioBufferName(uint32_t _ID, const std::string &_name);
        uint32_t findAudioBuffer(const std::string &_name) {sAudioBuffer* tB = m_bufferManager.findAudioBuffer(_name); return (tB == nullptr) ? 0 : tB->ID;}
        uint32_t newAudioBuffer(void) {return m_bufferManager.newAudioBuffer()->ID;}
        void loadBufferWav(uint32_t _ID, const std::string &_fileName);
        void loadBufferOgg(uint32_t _ID, const std::string &_fileName);

};

#endif // AUDIO_ENGINE_HPP
