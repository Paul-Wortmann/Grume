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

#include "graphics_engine.hpp"

bool cGraphicsEngine::m_windowClosed = false;

void cGraphicsEngine::m_errorCallback(int error, const char* description)
{
    gLogWrite(LOG_ERROR, " " + std::string(description), __FILE__, __LINE__, __FUNCTION__);
}

void cGraphicsEngine::m_closeWindowCallback(GLFWwindow* _windowContext)
{
    cGraphicsEngine::m_windowClosed = (glfwWindowShouldClose(_windowContext) == GLFW_TRUE);
}

cGraphicsEngine::cGraphicsEngine(void)
{
    
};

cGraphicsEngine::~cGraphicsEngine(void)
{
    
};

void cGraphicsEngine::setEntityHandle(sEntityGraphics *_entity)
{
    m_entityFirst = _entity;
}

uint32_t cGraphicsEngine::initialize(void)
{
    // Initialize GLFW
    glfwSetErrorCallback(m_errorCallback);
    if(!glfwInit())
    {
        gLogWrite(LOG_ERROR, "GLFW Initialization failed!", __FILE__, __LINE__, __FUNCTION__);
        return EXIT_FAILURE;
    }
    else
    {
        // Setup GLFW
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        if (!m_fullscreen)
        {
            // GLFW window creation
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), nullptr, nullptr);
        }
        else
        {
            // GLFW fullscreen window creation
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            m_window_w = mode->width;
            m_window_h = mode->height;
            m_window = glfwCreateWindow(m_window_w, m_window_h, m_windowTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
        }
        if (m_window == nullptr)
        {
            gLogWrite(LOG_ERROR, "GLFW window or OpenGL context creation failed!", __FILE__, __LINE__, __FUNCTION__);
            glfwTerminate();
            return EXIT_FAILURE;
        }
        else
        {
            // Create an OpenGL context
            m_aspectRatio = static_cast<float>(m_window_w) / static_cast<float>(m_window_h);
            glfwGetFramebufferSize(m_window, &m_frameBuffer_w, &m_frameBuffer_h);
            glfwMakeContextCurrent(m_window);
            
            // Glew setup
            glewExperimental = GL_TRUE;
            GLenum glewStatus = glewInit();
            if (glewStatus != GLEW_OK)
            {
                gLogWrite(LOG_ERROR, " GLEW initialization failed :  " + std::string(reinterpret_cast<const char*>(glewGetErrorString(glewStatus))), __FILE__, __LINE__, __FUNCTION__);
                glfwDestroyWindow(m_window);
                glfwTerminate();
                return EXIT_FAILURE;
            }
            else
            {
                // Log version information
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VERSION)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_VENDOR)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_RENDERER)), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION)), __FILE__, __LINE__, __FUNCTION__);

                gLogWrite(LOG_INFO, "GLFW version: " + std::string(glfwGetVersionString()), __FILE__, __LINE__, __FUNCTION__);
                gLogWrite(LOG_INFO, "GLEW version: " + std::string(reinterpret_cast<const char*>(glewGetString(GLEW_VERSION))), __FILE__, __LINE__, __FUNCTION__);
                
                std::string assimpVersion = std::to_string(aiGetVersionMajor()) + "." + std::to_string(aiGetVersionMinor()) + "." + std::to_string(aiGetVersionRevision());
                gLogWrite(LOG_INFO, "ASIMP version: " + assimpVersion, __FILE__, __LINE__, __FUNCTION__);
                /*
                std::string libMathVersion = std::to_string(LIBMATH_VERSION_MAJOR) + "." + std::to_string(LIBMATH_VERSION_MINOR) + "." + std::to_string(LIBMATH_VERSION_PATCH);
                gLogWrite(LOG_INFO, "LibMath version: " + libMathVersion, __FILE__, __LINE__, __FUNCTION__);
                std::string libRMGVersion = std::to_string(LIBRMG_VERSION_MAJOR) + "." + std::to_string(LIBRMG_VERSION_MINOR) + "." + std::to_string(LIBRMG_VERSION_PATCH);
                gLogWrite(LOG_INFO, "LibRMG version: " + libRMGVersion, __FILE__, __LINE__, __FUNCTION__);
                */
                
                //glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                
                // OpenGL setup
                glViewport(0, 0, m_frameBuffer_w, m_frameBuffer_h);
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_CULL_FACE);
                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);
                glFrontFace(GL_CCW);
                glClearDepth(1.0);
                glClearColor(0.2f, 0.2f, 0.8f, 1.0f);

                m_windowActive = true;
                
                // Camera setup
                m_camera.initialize(m_window_w, m_window_h, m_window_fov);
                m_camera.setCameraPosition(glm::vec3(0.0f, 2.0f, 3.0f));
                m_camera.setCameraTarget  (glm::vec3(0.0f, 0.0f, 0.0f));
                m_viewMatrix = m_camera.getViewMatrix();
                m_projectionMatrix = m_camera.getProjectionMatrixPerspective();
                
                // Shader setup
                m_shader_001.load(std::string(PATH_SHADER)+"shader_001");
                
            }
        }
    }
    return EXIT_SUCCESS;    
};

void cGraphicsEngine::m_initEntities(void)
{
    for (m_entityTemp = m_entityFirst; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp->model != nullptr) && (!m_entityTemp->initialized))
        {
            m_entityTemp->initialized = true;
            
            for (std::size_t i = 0; i < m_entityTemp->model->numMesh; ++i)
            {
                // VAO
                glGenVertexArrays(1, &m_entityTemp->model->mesh[i].VAO);
                glBindVertexArray(m_entityTemp->model->mesh[i].VAO);
                
                // IBO
                glGenBuffers(1, &m_entityTemp->model->mesh[i].IBO);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_entityTemp->model->mesh[i].IBO);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_entityTemp->model->mesh[i].numIndex * sizeof(uint32_t), &m_entityTemp->model->mesh[i].index[0], GL_STATIC_DRAW);
                
                // VBO vertices
                glGenBuffers(1, &m_entityTemp->model->mesh[i].VBO_vertices);
                glBindBuffer(GL_ARRAY_BUFFER, m_entityTemp->model->mesh[i].VBO_vertices);
                glBufferData(GL_ARRAY_BUFFER, m_entityTemp->model->mesh[i].numVertex * sizeof(sVertex), &m_entityTemp->model->mesh[i].vertex[0], GL_STATIC_DRAW);
                // position
                glEnableVertexAttribArray(0);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, position));
                // normal
                glEnableVertexAttribArray(1);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, normal));
                // tangent
                glEnableVertexAttribArray(2);
                glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, tangent));
                // bitangent
                glEnableVertexAttribArray(3);
                glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, bitangent));
                // texcoord
                glEnableVertexAttribArray(4);
                glVertexAttribPointer(4, 2, GL_FLOAT, GL_FALSE, sizeof(sVertex), (void*)offsetof(sVertex, texcoord));
                
                if (m_entityTemp->model->numBones > 0)
                {
                    // VBO bones
                    glGenBuffers(1, &m_entityTemp->model->mesh[i].VBO_bones);
                    glBindBuffer(GL_ARRAY_BUFFER, m_entityTemp->model->mesh[i].VBO_bones);
                    glBufferData(GL_ARRAY_BUFFER, m_entityTemp->model->mesh[i].numVertex * sizeof(sVertexBone), &m_entityTemp->model->mesh[i].vertexBone[0], GL_STATIC_DRAW);
                    // boneWeights
                    glEnableVertexAttribArray(5);
                    glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(sVertexBone), (void*)offsetof(sVertexBone, boneWeight));
                    // boneIDs
                    glEnableVertexAttribArray(6); // USE "glVertexAttrib I Pointer" <- 'I' very important!
                    glVertexAttribIPointer(6, 4, GL_INT, sizeof(sVertexBone), (void*)offsetof(sVertexBone, boneID));
                }
                
                glBindVertexArray(0);
            }
            checkOpenGL();
        }
    }
};

void cGraphicsEngine::terminate(void)
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
};

void cGraphicsEngine::process(void)
{
    glfwPollEvents();
    m_windowActive = (glfwWindowShouldClose(m_window) == 0); 
    m_initEntities();
};

void cGraphicsEngine::render(void)
{
    //std::cout << "Starting render frame....";

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if (m_currentShader != m_shader_001.getID())
    {
        m_shader_001.use();
        m_currentShader = m_shader_001.getID();
    }
    
    glUniformMatrix4fv(m_shader_001.getViewMatrixID(), 1, GL_FALSE, glm::value_ptr(m_viewMatrix));
    glUniformMatrix4fv(m_shader_001.getProjectionMatrixID(), 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));

    for (m_entityTemp = m_entityFirst; m_entityTemp != nullptr; m_entityTemp = m_entityTemp->next)
    {
        if ((m_entityTemp != nullptr) && (m_entityTemp->model != nullptr))
        {
            
            // skeletal animation uniforms for dynamic models
            if (m_entityTemp->model->numBones > 0)
            {
                // enable skinning
                glUniform1i(m_shader_001.getAnimationEnabledID(), 1);
                // bone transforms
                // either loop through the array and set them 1 at a time, or all at once as an optimization
                for (std::size_t i = 0; i < m_entityTemp->model->numBones; ++i)
                {
                    glUniformMatrix4fv(m_shader_001.getBoneMatrixID(i), 1, GL_FALSE, glm::value_ptr(m_entityTemp->model->bone[i].transformFinal));
                }
                //glUniformMatrix4fv(m_shader_001.getBoneMatrixID(0), m_entityTemp->model->numBones, GL_FALSE, glm::value_ptr(m_entityTemp->model->bone[0].transformFinal));
            }
            else // no bones
            {
                // disable skinning
                glUniform1i(m_shader_001.getAnimationEnabledID(), 0);
            }
            
            for (std::size_t i = 0; i < m_entityTemp->model->numInstances; ++i)
            {
                // model matrix
                glUniformMatrix4fv(m_shader_001.getModelMatrixID(), 1, GL_FALSE, glm::value_ptr(m_entityTemp->model->modelMatrix[i]));
                
                // model mesh
                for (std::size_t j = 0; j < m_entityTemp->model->numMesh; ++j)
                {
                    if (m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].diffuse.ID != 0)
                    {
                        glActiveTexture(GL_TEXTURE0);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].diffuse.ID);
                        glUniform1i(m_shader_001.getTextureDiffuseID(), 0);
                    }
                    if (m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].normal.ID != 0)
                    {
                        glActiveTexture(GL_TEXTURE1);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].normal.ID);
                        glUniform1i(m_shader_001.getTextureNormalID(), 1);
                    }
                    if (m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].specular.ID != 0)
                    {
                        glActiveTexture(GL_TEXTURE2);
                        glBindTexture(GL_TEXTURE_2D, m_entityTemp->model->material[m_entityTemp->model->mesh[j].materialID].specular.ID);
                        glUniform1i(m_shader_001.getTextureSpecularID(), 2);
                    }
                    
                    glBindVertexArray(m_entityTemp->model->mesh[j].VAO);
                    glDrawElements(GL_TRIANGLES, m_entityTemp->model->mesh[j].numIndex, GL_UNSIGNED_INT, 0);
                }
            }
        }
    }
    
    glfwSwapBuffers(m_window);
    //std::cout << "...Done!" << std::endl;;
}