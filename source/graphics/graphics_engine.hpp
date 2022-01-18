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

#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include "graphics_engine_camera.hpp"
#include "graphics_engine_debug.hpp"
#include "graphics_engine_defines.hpp"
#include "graphics_engine_light_manager.hpp"
#include "graphics_engine_particles.hpp"
#include "graphics_engine_shader.hpp"
#include "../core/game_config.hpp"
#include "../core/includes.hpp"
#include "../entity/entity_define.hpp"
#include "../ui/ui_manager.hpp"

class cGraphicsEngine
{
    public:
        // Constructors
        cGraphicsEngine(void) = default;
        ~cGraphicsEngine(void) = default;

        // Member functions
        uint32     initialize(void);
        void       terminate(void);
        void       process(const float32 &_dt);
        void       setWindowIcon(GLFWimage* _image);
        void       setMouseCursor(GLFWimage* _image);
        void       setDisplay(const uint32 &_w, const uint32 &_h, const bool &_f) {m_window_w = _w; m_window_h = _h; m_fullscreen = _f; };
        uint32     getWindow_w(void) { return m_window_w; }
        uint32     getWindow_h(void) { return m_window_h; }
        bool       windowClosed(void) {return m_windowClosed; }
        void       setWindowClosed(void) { m_windowClosed = true; glfwSetWindowShouldClose(m_window, GLFW_TRUE); }
        void       setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void       setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; }
        void       setGameConfig(cGameConfig* _gameConfig) { m_GameConfig = _gameConfig; }
        void       initializeEntities(void) { m_initEntities(); }
        void       setUIPointer(cUIManager* _UIManager) { m_UIManager = _UIManager; }
        void       initializeUIComponents(void) { m_initUIComponents(); }
        bool       getKeyState(const uint32 &_key) { return m_keyMap[_key]; }
        void       setKeyState(const uint32 &_key, const bool &_state) { m_keyMap[_key] = _state; }
        bool       getKeyReadyState(const uint32 &_key) { return m_keyReadyMap[_key]; }
        void       setKeyReadyState(const uint32 &_key, const bool &_state) { m_keyReadyMap[_key] = _state; }
        void       setPlayerLightPosition(const glm::vec3 &_position) { m_playerLight->position = _position; }
        glm::vec3  getPlayerLightPosition(void) { return m_playerLight->position; }
        glm::vec3  getMouseTerrainPosition(void) { return m_camera.getMousePositionTerrain(m_mouseX, m_mouseY); }
        glm::vec2  getMousePosition(void) { return glm::vec2(m_mouseX, m_mouseY); }
        glm::vec3  getCameraTarget(void) { return m_camera.getTarget(); };
        void       setCameraTarget(glm::vec3 _target) { m_camera.setTarget(_target); };
        glm::vec3  getCameraPosition(void) { return m_camera.getPosition(); };
        void       setCameraPosition(glm::vec3 _position) { m_camera.setPosition(_position); };
        float32    getAspectRatio(void) { return m_aspectRatio; };
        void       addScreenShake(const float32 &_st, const float32 &_sf) { m_camera.addScreenShake(_st, _sf); }
        void       setParticleTextureID(const uint32 &_tid) { m_p4_particleTextureID = _tid; }
        void       setLoadTextureID(const uint32 &_tid) { m_pls_renderTextureID = _tid; }
        void       setLoading(const bool &_b) { m_loadRender = _b; }
        void       setBasicRenderPath(const bool &_b) { m_basicRender = _b; }

    protected:

    private:
        inline static void sm_glfwErrorCallback(int32 _error, const char* _description);
        inline static void sm_glfwKeyCallback(GLFWwindow* _window, int32 _key, int32 _scancode, int32 _action, int32 _mods);
        inline static void sm_glfwCursorPosCallback(GLFWwindow* _window, float64 _xpos, float64 _ypos);
        inline static void sm_glfwMouseButtonCallback(GLFWwindow* _window, int32 _button, int32 _action, int32 _mods);
        inline static void sm_glfwFramebufferSizeCallback(GLFWwindow* _window, int32 _width, int32 _height);
        inline static void sm_glfwMonitorCallback(GLFWmonitor* _monitor, int32 _event);
        void               m_initEntities(void);
        void               m_initUIComponents(void);

        // Entity management
        sEntity*           m_entityHead         = nullptr;
        sEntity*           m_entityTemp         = nullptr;
        sEntity*           m_entityPlayer       = nullptr;

        // UI component management
        cUIManager*        m_UIManager          = nullptr;

        // config management
        cGameConfig*       m_GameConfig         = nullptr;

        // General
        int32              m_monitorCount       = 0;
        GLFWmonitor**      m_monitors           = nullptr;
        GLFWmonitor*       m_monitor            = nullptr;
        int32              m_videoModeCount     = 0;
        const GLFWvidmode* m_videoModes         = nullptr;
        const GLFWvidmode* m_currentVideoMode   = nullptr;

        GLFWwindow*        m_window             = nullptr;
        bool               m_windowClosed       = false;
        std::string        m_windowTitle        = "Grume";
        uint32             m_window_w           = 0;
        uint32             m_window_h           = 0;
        float32            m_aspectRatio        = static_cast<float32>(m_window_w) / static_cast<float32>(m_window_h);
        uint32             m_fieldOfView        = 45;
        bool               m_fullscreen         = false;
        int32              m_framebufferSize_w  = 0;
        int32              m_framebufferSize_h  = 0;
        uint32             m_renderBufferSize_w = 1024;
        uint32             m_renderBufferSize_h = 1024;
        bool               m_wireframe          = false;
        bool               m_basicRender        = false;
        bool               m_loadRender         = true;
        bool               m_animation          = true;
        float              m_renderRange        = 800.0f;
        
        // Particles
        cGraphicsEngineParticles m_particleEngine;

        // IO
        std::unordered_map<int32, boolean> m_keyMap;
        std::unordered_map<int32, boolean> m_keyReadyMap;
        float32 m_mouseX = 0.0f;
        float32 m_mouseY = 0.0f;

        // Garaphics engine camera
        cGraphicsEngineCamera m_camera;

        // Garaphics engine light
        cGraphicsEngineLightManager m_lightManager;
        sGraphicsEnginePointLight*  m_playerLight = nullptr;

        // Render pipeline stage: Basic
        // graphics_engine_pipeline_basic.cpp
        void m_pb_initialize(void);
        void m_pb_terminate(void);
        void m_pb_render(void);
        cGraphicsEngineShader m_pb_shader                    = {};
        uint32                m_pb_fbo                       = 0;
        uint32                m_pb_renderTextureID           = 0;
        uint32                m_pb_depthTextureID            = 0;

        uint32                m_pb_loc_modelMatrix           = 0;
        uint32                m_pb_loc_viewMatrix            = 0;
        uint32                m_pb_loc_projectionMatrix      = 0;
        uint32                m_pb_loc_materialDiffuse       = 0;
        uint32                m_pb_loc_animationEnabled      = 0;
        uint32                m_pb_loc_boneMatrix[MAX_BONES] = {};

        // Render pipeline stage 1
        // graphics_engine_pipeline_1.cpp
        void m_p1_initialize(void);
        void m_p1_terminate(void);
        void m_p1_render(void);
        cGraphicsEngineShader m_p1_shader                    = {};
        uint32                m_p1_fbo                       = 0;

        uint32                m_p1_depthMapID                = 0;
        glm::mat4             m_p1_lightMatrix               = glm::mat4(1.0f);
        glm::mat4             m_p1_viewMatrix                = glm::mat4(1.0f);
        glm::mat4             m_p1_projectionMatrix          = glm::mat4(1.0f);

        uint32                m_p1_loc_modelMatrix           = 0;
        uint32                m_p1_loc_lightMatrix           = 0;
        uint32                m_p1_loc_animationEnabled      = 0;
        uint32                m_p1_loc_boneMatrix[MAX_BONES] = {};

        // Render pipeline stage 2 (depth cube map)
        // graphics_engine_pipeline_2.cpp
        void m_p2_initialize(void);
        void m_p2_terminate(void);
        void m_p2_render(void);
        cGraphicsEngineShader m_p2_shader                                  = {};
        uint32                m_p2_fbo[MAX_POINT_LIGHTS]                   = {};
        float32               m_p2_aspectRatio                             = 1.0f;
        uint32                m_p2_depthCubemapID[MAX_POINT_LIGHTS]        = {};
        float32               m_p2_nearPlane                               = 0.1f;
        float32               m_p2_farPlane                                = 25.0f;
        glm::vec3             m_p2_lightPosition                           = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::mat4             m_p2_depthMatrix[6]                          = {};
        glm::mat4             m_p2_depthProjectionMatrix                   = glm::mat4(1);

        uint32                m_p2_loc_modelMatrix                         = 0;
        uint32                m_p2_loc_lightPosition                       = 0;
        uint32                m_p2_loc_farPlane                            = 0;
        uint32                m_p2_loc_depthMatrix[6]                      = {};
        uint32                m_p2_loc_animationEnabled                    = 0;
        uint32                m_p2_loc_boneMatrix[MAX_BONES]               = {};

        // Render pipeline stage 3 (final scene render - lighting)
        // graphics_engine_pipeline_3.cpp
        void m_p3_initialize(void);
        void m_p3_terminate(void);
        void m_p3_setLightUniformLocations(void);
        void m_p3_render(void);
        cGraphicsEngineShader m_p3_shader                                  = {};
        uint32                m_p3_fbo                                     = 0;
        uint32                m_p3_renderTextureID                         = 0;
        uint32                m_p3_depthTextureID                          = 0;

        uint32                m_p3_loc_renderTexture                       = 0;
        uint32                m_p3_loc_depthTexture                        = 0;
        uint32                m_p3_loc_projectionMatrix                    = 0;
        uint32                m_p3_loc_viewMatrix                          = 0;
        uint32                m_p3_loc_modelMatrix                         = 0;
        uint32                m_p3_loc_directionalLightMatrix              = 0;
        uint32                m_p3_loc_camera                              = 0;
        uint32                m_p3_loc_animationEnabled                    = 0;
        uint32                m_p3_loc_boneMatrix[MAX_BONES]               = {};

        uint32                m_p3_loc_materialDepthCube[MAX_POINT_LIGHTS] = {};
        uint32                m_p3_loc_materialDepth                       = 0;
        uint32                m_p3_loc_materialDiffuse                     = 0;
        uint32                m_p3_loc_materialNormal                      = 0;
        uint32                m_p3_loc_materialSpecular                    = 0;
        uint32                m_p3_loc_materialShininess                   = 0;

        uint32                m_p3_loc_farPlane                            = 0;

        // Render pipeline stage 4 (particles)
        // graphics_engine_pipeline_4.cpp
        void m_p4_initialize(void);
        void m_p4_terminate(void);
        void m_p4_update(void);
        void m_p4_render(void);
        cGraphicsEngineShader m_p4_shader                                  = {};
        uint32                m_p4_particleCount                           = 0;
        uint32                m_p4_VAO                                     = 0;
        uint32                m_p4_vbo_vertex                              = 0;
        uint32                m_p4_vbo_position                            = 0;
        uint32                m_p4_vbo_color                               = 0;
        
        uint32                m_p4_particleTextureID                       = 0;
        
        uint32                m_p4_loc_cameraRight                         = 0;
        uint32                m_p4_loc_cameraUp                            = 0;
        uint32                m_p4_loc_VP                                  = 0;
        uint32                m_p4_loc_textureParticle                     = 0;

        // Render pipeline stage UI
        // Take in the final scene render as a texture and renders
        // the UI on top. Output to default framebuffer.
        // graphics_engine_pipeline_ui.cpp
        void m_pui_initialize(void);
        void m_pui_terminate(void);
        void m_pui_render(void);
        cGraphicsEngineShader m_pui_shader                                 = {};
        const uint32          m_pui_fbo                                    = 0;
        uint32                m_pui_VAO                                    = 0;
        uint32                m_pui_VBO                                    = 0;

        glm::mat4             m_pui_modelMatrix                            = glm::mat4(1);

        uint32                m_pui_loc_diffuseMap                         = 0;
        uint32                m_pui_loc_modelMatrix                        = 0;

        // Render Loading screen
        // graphics_engine_pipeline_ls.cpp
        void m_pls_initialize(void);
        void m_pls_terminate(void);
        void m_pls_render(void);
        cGraphicsEngineShader m_pls_shader                                 = {};
        const uint32          m_pls_fbo                                    = 0;
        uint32                m_pls_VAO                                    = 0;
        uint32                m_pls_VBO                                    = 0;

        uint32                m_pls_loc_diffuseMap                         = 0;
        uint32                m_pls_renderTextureID                        = 0;
};

#endif //GRAPHICS_ENGINE_HPP
