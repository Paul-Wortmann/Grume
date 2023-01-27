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

#include "../core/includes.hpp"
#include "graphics_engine_defines.hpp"

class cGraphicsEngine :tcTemplateEngine
{
    public:
        // Engine base
        std::uint32_t          initialize(void);
        void                   terminate(void) override;
        void                   process(const std::int64_t &_dt) override;
        sGraphicsEvent*        getEvent(void) { return m_event.pop(); }

        // External system pointers
        void                   setIOPointer(sIO* _io) { m_io = _io; }
        void                   setGameConfigPointer(cGameConfig* _gameConfig) { m_GameConfig = _gameConfig; }
        void                   setUIPointer(cUIManager* _UIManager) { m_UIManager = _UIManager; }
        void                   setPlayerActionBarPointer(cPlayerStorage* _playerActionBar) { m_playerActionBar = _playerActionBar; }
        void                   setPlayerInventoryPointer(cPlayerStorage* _playerInventory) { m_playerInventory = _playerInventory; }
        void                   setPlayerVendorPointer(cPlayerStorage* _playerVendor) { m_playerVendor = _playerVendor; }
        void                   setResourceManagerPointer(cResourceManager* _resourceManager) { m_resourceManager = _resourceManager; }

        // Engine config
        void setWireframeRender(bool _wireframeRender) { m_wireframe = _wireframeRender; }
        void setBasicRenderPath(bool _basicRenderer) { m_basicRender = _basicRenderer; }
        void setDisplay(std::uint32_t _resolution_x, std::uint32_t _resolution_y, bool _fullscreen) { m_window_w = _resolution_x; m_window_h = _resolution_y; m_fullscreen = _fullscreen; }

        // Window
        std::uint32_t          getWindow_w(void) { return m_window_w; }
        std::uint32_t          getWindow_h(void) { return m_window_h; }

        // Loading screen texture, icon and cursor images
        void                   setWindowIcon(GLFWimage* _image);
        void                   setMouseCursor(GLFWimage* _image);
        void                   setLoadTextureID(const std::uint32_t &_tid) { m_pls_renderTextureID = _tid; }
        void                   setLoading(const bool &_value) { m_loadRender = _value; }

        // Entity
        void                   setEntityHead(sEntity* _entity) { m_entityHead = _entity; }
        void                   initializeEntities(void) { m_initializeEntities(); }
        void                   initializeEntity(sEntity *&_entity)  { m_initializeEntity(_entity); }
        void                   setEntityPlayer(sEntity* _entity) { m_entityPlayer = _entity; }

        // Map
        void                   setMapPointer(sMap* _map) { m_map = _map; }

        // Camera
        glm::vec3              getCameraPosition(void) { return m_camera.getPosition(); };
        glm::vec3              getCameraTarget(void) { return m_camera.getTarget(); };
        glm::vec3              getCameraDirection(void) {return m_camera.getMouseRay(m_io->mousePosition); }
        void                   setCameraPosition(glm::vec3 &_position) { m_camera.setPosition(_position); };
        void                   setCameraTarget(glm::vec3 &_target) { m_camera.setTarget(_target); };
        void                   moveCamera(glm::vec3 &_position);
        void                   addScreenShake(const std::uint32_t &_st, const float &_sf) { m_camera.addScreenShake(_st, _sf); };

        // Lights
        void                   setPlayerLightPosition(const glm::vec3 &_position) { m_playerLight->position.x = _position.x; m_playerLight->position.z = _position.z; }

    protected:
    private:
        // Event
        tcQueue<sGraphicsEvent> m_event         = {};

        // UI component management
        cUIManager*        m_UIManager          = nullptr;

        // configuration management
        cGameConfig*       m_GameConfig         = nullptr;

        // Player inventory, action bar, vendor
        cPlayerStorage*    m_playerActionBar    = nullptr;
        cPlayerStorage*    m_playerInventory    = nullptr;
        cPlayerStorage*    m_playerVendor       = nullptr;

        // Resource management
        cResourceManager*  m_resourceManager    = nullptr;

        // Render settings
        bool               m_wireframe          = false;
        bool               m_basicRender        = false;
        bool               m_renderDebug        = false;
        bool               m_loadRender         = false;
        bool               m_animation          = true;

        // General
        std::int32_t       m_monitorCount       = 0;
        GLFWmonitor**      m_monitors           = nullptr;
        GLFWmonitor*       m_monitor            = nullptr;
        std::int32_t       m_videoModeCount     = 0;
        const GLFWvidmode* m_videoModes         = nullptr;
        const GLFWvidmode* m_currentVideoMode   = nullptr;
        GLFWwindow*        m_window             = nullptr;
        bool               m_windowClosed       = false;
        std::string        m_windowTitle        = "Grume";
        std::uint32_t      m_window_w           = 0;
        std::uint32_t      m_window_h           = 0;
        float              m_aspectRatio        = static_cast<float>(m_window_w) / static_cast<float>(m_window_h);
        std::uint32_t      m_fieldOfView        = 45;
        bool               m_fullscreen         = false;
        std::int32_t       m_framebufferSize_w  = 0;
        std::int32_t       m_framebufferSize_h  = 0;
        std::uint32_t      m_renderBufferSize_w = 1024;
        std::uint32_t      m_renderBufferSize_h = 1024;

        // Time
        float              m_time               = 0.0f;

        // GLFW callback functions
        inline static void sm_glfwErrorCallback(std::int32_t _error, const char* _description);
        inline static void sm_glfwWindowCloseCallback(GLFWwindow* _window);
        inline static void sm_glfwKeyCallback(GLFWwindow* _window, std::int32_t _key, std::int32_t _scancode, std::int32_t _action, std::int32_t _mods);
        inline static void sm_glfwCursorPosCallback(GLFWwindow* _window, double _xpos, double _ypos);
        inline static void sm_glfwMouseButtonCallback(GLFWwindow* _window, std::int32_t _button, std::int32_t _action, std::int32_t _mods);
        inline static void sm_glfwFramebufferSizeCallback(GLFWwindow* _window, std::int32_t _width, std::int32_t _height);
        inline static void sm_glfwMonitorCallback(GLFWmonitor* _monitor, std::int32_t _event);

        // Camera
        cGraphicsEngineCamera m_camera = {};

        // Entities
        void     m_initializeEntity(sEntity *&_entity);
        void     m_initializeEntities(void);
        sEntity* m_entityHead   = nullptr;
        sEntity* m_entityTemp   = nullptr;
        sEntity* m_entityPlayer = nullptr;

        // Entities
        sMap*    m_map          = nullptr;

        // IO
        sIO*     m_io           = nullptr;

        // Graphics engine light
        cGraphicsEngineLightManager m_lightManager;
        sGraphicsEnginePointLight*  m_playerLight = nullptr;

        // Common pipeline
        // graphics_engine_pipeline_pc.cpp
        void m_pc_initialize(void);
        void m_pc_terminate(void);
        std::uint32_t         m_pc_fsq_VAO                   = 0; // full screen quad
        std::uint32_t         m_pc_fsq_VBO                   = 0; // full screen quad
        std::uint32_t         m_pc_bbq_VAO                   = 0; // billboard quad
        std::uint32_t         m_pc_bbq_VBO                   = 0; // billboard quad
        std::uint32_t         m_pc_bbq_IBO                   = 0; // billboard quad

        // Render pipeline stage: Basic
        // graphics_engine_pipeline_basic.cpp
        void m_pb_initialize(void);
        void m_pb_terminate(void);
        void m_pb_render(void);
        cGraphicsEngineShader m_pb_shader                    = {};
        std::uint32_t         m_pb_fbo                       = 0;
        std::uint32_t         m_pb_renderTextureID           = 0;
        std::uint32_t         m_pb_depthTextureID            = 0;

        std::uint32_t         m_pb_loc_modelMatrix           = 0;
        std::uint32_t         m_pb_loc_viewMatrix            = 0;
        std::uint32_t         m_pb_loc_projectionMatrix      = 0;
        std::uint32_t         m_pb_loc_materialDiffuse       = 0;
        std::uint32_t         m_pb_loc_animationEnabled      = 0;
        std::uint32_t         m_pb_loc_boneMatrix[MAX_BONES] = {};

        std::uint32_t         m_pb_loc_time                  = 0;
        std::uint32_t         m_pb_loc_flexibility           = 0;

        std::uint32_t         m_pb_loc_billboard             = 0;
        std::uint32_t         m_pb_loc_collision             = 0;
        std::uint32_t         m_pb_loc_mouseOver             = 0;
        std::uint32_t         m_pb_loc_hasFunction           = 0;
        std::uint32_t         m_pb_loc_isText                = 0;
        std::uint32_t         m_pb_loc_textColor             = 0;

        // Render pipeline stage 1 (directional shadow map)
        // graphics_engine_pipeline_1.cpp
        void m_p1_initialize(void);
        void m_p1_terminate(void);
        void m_p1_render(void);
        cGraphicsEngineShader m_p1_shader                    = {};
        std::uint32_t         m_p1_fbo                       = 0;

        std::uint32_t         m_p1_depthMapID                = 0;
        glm::mat4             m_p1_lightMatrix               = glm::mat4(1.0f);
        glm::mat4             m_p1_viewMatrix                = glm::mat4(1.0f);
        glm::mat4             m_p1_projectionMatrix          = glm::mat4(1.0f);

        std::uint32_t         m_p1_loc_modelMatrix           = 0;
        std::uint32_t         m_p1_loc_lightMatrix           = 0;
        std::uint32_t         m_p1_loc_animationEnabled      = 0;
        std::uint32_t         m_p1_loc_boneMatrix[MAX_BONES] = {};

        std::uint32_t         m_p1_loc_time                  = 0;
        std::uint32_t         m_p1_loc_flexibility           = 0;

        // Render pipeline stage 2 (depth cube map)
        // graphics_engine_pipeline_2.cpp
        void m_p2_initialize(void);
        void m_p2_terminate(void);
        void m_p2_render(void);
        cGraphicsEngineShader m_p2_shader                                  = {};
        std::uint32_t         m_p2_fbo[MAX_POINT_LIGHTS]                   = {};
        float                 m_p2_aspectRatio                             = 1.0f;
        std::uint32_t         m_p2_depthCubemapID[MAX_POINT_LIGHTS]        = {};
        float                 m_p2_nearPlane                               = 0.1f;
        float                 m_p2_farPlane                                = 25.0f;
        glm::vec3             m_p2_lightPosition                           = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::mat4             m_p2_depthMatrix[6]                          = {};
        glm::mat4             m_p2_depthProjectionMatrix                   = glm::mat4(1);

        std::uint32_t         m_p2_loc_modelMatrix                         = 0;
        std::uint32_t         m_p2_loc_lightPosition                       = 0;
        std::uint32_t         m_p2_loc_farPlane                            = 0;
        std::uint32_t         m_p2_loc_depthMatrix[6]                      = {};
        std::uint32_t         m_p2_loc_animationEnabled                    = 0;
        std::uint32_t         m_p2_loc_boneMatrix[MAX_BONES]               = {};

        std::uint32_t         m_p2_loc_time                  = 0;
        std::uint32_t         m_p2_loc_flexibility           = 0;

        // Render pipeline stage 3 (final scene render - lighting)
        // graphics_engine_pipeline_3.cpp
        void m_p3_initialize(void);
        void m_p3_terminate(void);
        void m_p3_setLightUniformLocations(void);
        void m_p3_render(void);
        cGraphicsEngineShader m_p3_shader                                  = {};
        std::uint32_t         m_p3_fbo                                     = 0;
        std::uint32_t         m_p3_renderTextureID                         = 0;
        std::uint32_t         m_p3_depthTextureID                          = 0;

        std::uint32_t         m_p3_loc_renderTexture                       = 0;
        std::uint32_t         m_p3_loc_depthTexture                        = 0;
        std::uint32_t         m_p3_loc_projectionMatrix                    = 0;
        std::uint32_t         m_p3_loc_viewMatrix                          = 0;
        std::uint32_t         m_p3_loc_modelMatrix                         = 0;
        std::uint32_t         m_p3_loc_directionalLightMatrix              = 0;
        std::uint32_t         m_p3_loc_camera                              = 0;
        std::uint32_t         m_p3_loc_animationEnabled                    = 0;
        std::uint32_t         m_p3_loc_boneMatrix[MAX_BONES]               = {};

        std::uint32_t         m_p3_loc_materialDepthCube[MAX_POINT_LIGHTS] = {};
        std::uint32_t         m_p3_loc_materialDepth                       = 0;
        std::uint32_t         m_p3_loc_materialDiffuse                     = 0;
        std::uint32_t         m_p3_loc_materialNormal                      = 0;
        std::uint32_t         m_p3_loc_materialSpecular                    = 0;
        std::uint32_t         m_p3_loc_materialShininess                   = 0;

        std::uint32_t         m_p3_loc_farPlane                            = 0;

        std::uint32_t         m_p3_loc_billboard                           = 0;
        std::uint32_t         m_p3_loc_collision                           = 0;
        std::uint32_t         m_p3_loc_mouseOver                           = 0;
        std::uint32_t         m_p3_loc_hasFunction                         = 0;
        std::uint32_t         m_p3_loc_isText                              = 0;
        std::uint32_t         m_p3_loc_textColor                           = 0;

        std::uint32_t         m_p3_loc_time                                = 0;
        std::uint32_t         m_p3_loc_flexibility                         = 0;

        // Render pipeline stage UI
        // Take in the final scene render as a texture and renders
        // the UI on top. Output to default framebuffer.
        // graphics_engine_pipeline_ui.cpp
        void m_pui_initialize(void);
        void m_pui_terminate(void);
        void m_pui_render(void);
        cGraphicsEngineShader m_pui_shader                                 = {};
        const std::uint32_t   m_pui_fbo                                    = 0;

        glm::mat4             m_pui_modelMatrix                            = glm::mat4(1);

        std::uint32_t         m_pui_loc_diffuseMap                         = 0;
        std::uint32_t         m_pui_loc_modelMatrix                        = 0;

        // Render Loading screen
        // graphics_engine_pipeline_ls.cpp
        void m_pls_initialize(void);
        void m_pls_terminate(void);
        void m_pls_render(void);
        cGraphicsEngineShader m_pls_shader                                 = {};
        const std::uint32_t   m_pls_fbo                                    = 0;

        std::uint32_t         m_pls_loc_diffuseMap                         = 0;
        std::uint32_t         m_pls_renderTextureID                        = 0;
};

#endif // GRAPHICS_ENGINE_HPP
