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

class cAudioEngine : public tcLinkedList<sAudio>
{
    public:
        std::uint32_t initialize(void);
        void          terminate(void);

        sAudio*       getNewSoundPointer(void) { return getNew(); };
        void          loadSound(const std::string &_fileName, ma_sound &_ma_sound);
        void          playSound(ma_sound &_ma_sound);
        void          freeSound(sAudio *&_pointer);
        void          deleteSound(sAudio *&_pointer);
        void          loadMusic(const std::string &_fileName);
        void          playMusic(void);

        // Volume
        void          setVolumeMaster(std::uint32_t _volume) {m_volumeMaster = _volume; m_updateVolume(); };
        std::uint32_t getVolumeMaster(void) {return m_volumeMaster; m_updateVolume(); };
        void          setVolumeMasterUp(void) { if (m_volumeMaster < m_volumeMax) m_volumeMaster++; m_updateVolume(); };
        void          setVolumeMasterDown(void) { if (m_volumeMaster > 0) m_volumeMaster--; m_updateVolume(); };
        void          setVolumeMusic(std::uint32_t _volume) {m_volumeMusic = _volume; m_updateVolume(); };
        std::uint32_t getVolumeMusic(void) {return m_volumeMusic; m_updateVolume(); };
        void          setVolumeMusicUp(void) { if (m_volumeMusic < m_volumeMax) m_volumeMusic++; m_updateVolume(); };
        void          setVolumeMusicDown(void) { if (m_volumeMusic > 0) m_volumeMusic--; m_updateVolume(); };
        void          setVolumeSound(std::uint32_t _volume) {m_volumeSound = _volume; m_updateVolume(); };
        std::uint32_t getVolumeSound(void) {return m_volumeSound; m_updateVolume(); };
        void          setVolumeSoundUp(void) { if (m_volumeSound < m_volumeMax) m_volumeSound++; m_updateVolume(); };
        void          setVolumeSoundDown(void) { if (m_volumeSound > 0) m_volumeSound--; m_updateVolume(); };

    protected:

    private:
        void          freeData(sAudio *&_pointer) override;

        void                m_updateVolume(void);

        ma_result           m_result        = {};
        ma_engine           m_engine        = {};

        const std::uint32_t m_volumeMax     = 100;
        std::uint32_t       m_volumeMaster  = 100;
        std::uint32_t       m_volumeMusic   = 100;
        std::uint32_t       m_volumeSound   = 100;

        sAudio*             m_music         = nullptr;
};

#endif // AUDIO_ENGINE_HPP
