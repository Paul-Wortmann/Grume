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

#include "includes.hpp"
#include "game_config.hpp"
#include "game_database.hpp"
#include "timer.hpp"
#include "version.hpp"
#include "../audio/audio_manager.hpp"
#include "../entity/animation_engine.hpp"
#include "../entity/entity_manager.hpp"
#include "../graphics/graphics_engine.hpp"
#include "../map/map_manager.hpp"
#include "../npc/npc_manager.hpp"
#include "../physics/physics_engine.hpp"
#include "../player/player_manager.hpp"
#include "../ui/ui_manager.hpp"

class cGameEngine
{
    public:
        uint32 run(const uint32 &_argc, char** _argv);

    protected:

    private:
        enum eGameState: uint16
        {
            startup  = 0,
            active   = 1,
            pause    = 2,
            shutdown = 3
        };
        eGameState m_state = eGameState::startup;

        cAudioManager    audioManager;
        cAnimationEngine animationEngine;
        cEntityManager   entityManager;
        cGameConfig      gameConfig;
        cGameDatabase    gameDatabase;
        cGraphicsEngine  graphicsEngine;
        cMapManager      mapManager;
        cNPCManager      npcManager;
        cPhysicsEngine   physicsEngine;
        cPlayerManager   playerManager;
        cTimer           timer;
        cUIManager       uiManager;
       
        // game_engine.cpp
        uint32 initialize(const uint32 &_argc, char** _argv);
        void   terminate(void);
        void   process(void);

        // game_load.cpp
        void load(void);
        void load(const uint32 &_slotNum);

        // game_save.cpp
        void save(const uint32 &_slotNum);
        
        sEntity* m_entityHead = nullptr;
        sEntity* m_entityTemp = nullptr;
};

#endif //GAME_ENGINE_HPP
