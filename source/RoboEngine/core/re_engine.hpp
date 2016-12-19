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

#ifndef RE_MAINLOOP_HPP
#define RE_MAINLOOP_HPP

#include <chrono>
#include <cstdlib>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <ratio>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "../roboengine.hpp"
#include "../entity/re_entity.hpp"
#include "../graphics/re_graphics_engine.hpp"
#include "../physics/re_physics_engine.hpp"
#include "../system/re_log.hpp"
#include "../system/re_time.hpp"
#include "../system/re_system_events.hpp"
#include "re_time_step.hpp"

namespace RoboEngine
{

    enum class eState : uint32_t { RE_STOP, RE_INIT, RE_ACTV, RE_TERM};

    class re_cRoboEngine
    {
        public:
            re_cRoboEngine(void) = default;
            virtual ~re_cRoboEngine(void) = default;
            re_cRoboEngine(const re_cRoboEngine&) = default;
            re_cRoboEngine& operator=(const re_cRoboEngine& _rhs) {if (this == &_rhs) return *this; return *this;}

            // external
            virtual uint32_t run(const uint32_t &_argc, char** _argv) final {return internal_run(_argc, _argv);};
            virtual uint32_t initialize(void) = 0;
            virtual uint32_t process(int64_t _dt) = 0;
            virtual uint32_t terminate(void) = 0;

            // engine
            virtual inline eState getState(void) final {return m_state;}

            // entity manager
            virtual inline uint32_t getNewEntity(void) final {re_sEntity *tEntity = m_entityManager.getNew(); return tEntity->ID;}
            virtual inline void addEntityPhysics(uint32_t _ID) {m_entityManager.addPhysics(_ID);}
            virtual inline void addEntityRender(uint32_t _ID) {m_entityManager.addRender(_ID);}
            virtual inline void setEntityPosition(uint32_t _ID, glm::vec3 _position) final {m_entityManager.setPosition(_ID, _position);}
            virtual inline void setEntityRotation(uint32_t _ID, glm::vec3 _rotation) final {m_entityManager.setRotation(_ID, _rotation);}
            virtual inline void setEntityScale(uint32_t _ID, glm::vec3 _scale) final {m_entityManager.setScale(_ID, _scale);}
            virtual inline void addEntityMesh(uint32_t _ID, std::string _fileName) final {m_entityManager.addMesh(_ID, _fileName);}
            virtual inline void addEntityShader(uint32_t _ID, std::string _fileName) final {m_entityManager.addShader(_ID, _fileName);}
            virtual inline void addEntityTexture(uint32_t _ID, std::string _fileName) final {m_entityManager.addTexture(_ID, _fileName);}
            virtual inline void setEntityDynamic(uint32_t _ID, bool _state) {m_entityManager.setDynamic(_ID, _state);}
            virtual inline glm::vec3 getEntityPosition(uint32_t _ID) final {return m_entityManager.getPosition(_ID);}
            virtual inline glm::vec3 getEntityRotation(uint32_t _ID) final {return m_entityManager.getRotation(_ID);}
            virtual inline glm::vec3 getEntityScale(uint32_t _ID) final {return m_entityManager.getScale(_ID);}

            // system events
            virtual inline bool getKey(uint32_t _key) final {return m_SystemEvents.getKey(_key);}

            // graphics engine
            virtual inline void setWindowTitle(const std::string& _title) final {m_graphicsEngine.setTitle(_title);}
            virtual inline void setCameraPosition(glm::vec3 _position, glm::vec3 _lookat) final {m_graphicsEngine.setCameraPosition(_position, _lookat);}
            virtual inline glm::vec3 getCameraPosition(void) final {return m_graphicsEngine.getCameraPosition();}
            virtual inline glm::vec3 getCameraLookat(void) final {return m_graphicsEngine.getCameraLookat();}

        private:
            static void glfw_error_callback(int _error, const char* _description);
            virtual uint32_t log_initialize(const std::string &_message) final;
            virtual uint32_t process_cl(const uint32_t &_argc, char** _argv) final;
            virtual uint32_t internal_initialize(void) final;
            virtual uint32_t internal_terminate(void) final;
            virtual uint32_t internal_run(const uint32_t &_argc, char** _argv) final;

            eState m_state = eState::RE_STOP;
            GLFWwindow* m_window = nullptr;

            re_cFrameTimer m_frameTimer = {};
            re_cGraphicsEngine m_graphicsEngine = {};
            re_cLog m_log = {};
            re_cSystemEvents m_SystemEvents = {};
            re_cPhysicsEngine m_physicsEngine = {};
            re_cEntityManager m_entityManager = {};
    };

}
#endif // RE_MAINLOOP_HPP
