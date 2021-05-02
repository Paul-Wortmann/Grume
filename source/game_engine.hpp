


#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "includes.hpp"
#include "timer.hpp"
#include "version.hpp"
#include "audio/audio_manager.hpp"
#include "entity/animation_engine.hpp"
#include "entity/entity_manager.hpp"
#include "graphics/graphics_engine.hpp"
#include "map/map_manager.hpp"
#include "npc/npc_manager.hpp"
#include "physics/physics_engine.hpp"
#include "player/player_manager.hpp"
#include "ui/ui_manager.hpp"

class cGameEngine
{
    public:
        void run(void);

        sEntity*      m_entityBat        = nullptr; // DELETE!

    protected:

    private:
        enum eGameState: uint16
        {
            startup  = 0,
            active   = 1,
            shutdown = 2
        };
        eGameState m_state = eGameState::startup;

        cAudioManager    audioManager;
        cAnimationEngine animationEngine;
        cEntityManager   entityManager;
        cGraphicsEngine  graphicsEngine;
        cMapManager      mapManager;
        cNPCManager      npcManager;
        cPhysicsEngine   physicsEngine;
        cPlayerManager   playerManager;
        cTimer           timer;
        cUIManager       uiManager;
       
        void initialize(void);
        void terminate(void);
        void process(void);
        void stopMusic(void);
        void playMusic(void);
        void resetPlayerPosition(void);

        sEntity*      m_entityHead        = nullptr;
        sEntity*      m_entityTemp        = nullptr;

};

#endif //GAME_ENGINE_HPP
