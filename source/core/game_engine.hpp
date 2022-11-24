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

#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "game_engine_defines.hpp"

class cGameEngine
{
    public:
        std::uint32_t    run(const std::uint32_t &_argc, char** _argv);

    protected:

    private:
        // Functions
        std::uint32_t    initialize(const std::uint32_t &_argc, char** _argv);
        void             terminate(void);
        void             process();

        // game_new.cpp
        std::uint32_t    m_game_new(void);

        // game_load.cpp
        std::uint32_t    m_game_load(void);
        std::uint32_t    m_game_load(const std::uint32_t &_slotNum);

        // game_save.cpp
        std::uint32_t    m_game_save(const std::uint32_t &_slotNum);

        // Variables
        eEngineState     m_engineState     = eEngineState::engineStateNone;

        // Manager
        cDatabaseManager m_databaseManager = {};
        cEntityManager   m_entityManager   = {};
        cEventManager    m_eventManager    = {};
        cGameConfig      m_gameConfig      = {};
        cLootManager     m_lootManager     = {};
        cMapManager      m_mapManager      = {};
        cNPCManager      m_npcManager      = {};
        cObjectManager   m_objectManager   = {};
        cPlayerManager   m_playerManager   = {};
        cQuestManager    m_questManager    = {};
        cResourceManager m_resourceManager = {};
        cUIManager       m_uiManager       = {};

        // Engine
        cAnimationEngine m_animationEngine = {};
        cAudioEngine     m_audioEngine     = {};
        cGraphicsEngine  m_graphicsEngine  = {};
        cParticleEngine  m_particleEngine  = {};
        cPhysicsEngine   m_physicsEngine   = {};

        // Other
        cTimer           m_timer           = {};
};

#endif // GAME_ENGINE_HPP
