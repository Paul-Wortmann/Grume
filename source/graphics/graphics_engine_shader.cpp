

#include "graphics_engine_shader.hpp"

void cGraphicsEngineShader::initialize(void)
{

}

void cGraphicsEngineShader::terminate(void)
{
    glUseProgram(0);
    glDeleteProgram(this->m_shaderID);
}

// Load a shader from file
uint32 cGraphicsEngineShader::load(const std::string &_fileName)
{
    // Vertex shader
    GLuint vertShader = 0;

    std::string file_vs = FILE_PATH_SHADER + _fileName + ".vs";
    bool exist_vs = (fileExists(file_vs));
    if (exist_vs)
    {
        // Load the shader
        vertShader = glCreateShader(GL_VERTEX_SHADER);
        std::string shaderStr = "";
        fileToString(file_vs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(vertShader, 1, &shaderSrc, NULL);
        glCompileShader(vertShader);

        // Check the shader
        GLint compileStatus = GL_FALSE;
        int32  logLength;
        glGetShaderiv(vertShader, GL_COMPILE_STATUS, &compileStatus);
        glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0)
        {
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(vertShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_vs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
        }
    }

    // Geometry shader
    GLuint geomShader = 0;

    std::string file_gs = FILE_PATH_SHADER + _fileName + ".gs";
    bool exist_gs = (fileExists(file_gs));
    if (exist_gs)
    {
        // Load the shader
        geomShader = glCreateShader(GL_GEOMETRY_SHADER);
        std::string shaderStr = "";
        fileToString(file_gs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(geomShader, 1, &shaderSrc, NULL);
        glCompileShader(geomShader);

        // Check the shader
        GLint compileStatus = GL_FALSE;
        int32  logLength;
        glGetShaderiv(geomShader, GL_COMPILE_STATUS, &compileStatus);
        glGetShaderiv(geomShader, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0)
        {
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(geomShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_gs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
        }
    }

    // Fragment shader
    GLuint fragShader = 0;

    std::string file_fs = FILE_PATH_SHADER + _fileName + ".fs";
    bool exist_fs = (fileExists(file_fs));
    if (exist_fs)
    {
        // Load the shader
        fragShader = glCreateShader(GL_FRAGMENT_SHADER);
        std::string shaderStr = "";
        fileToString(file_fs, shaderStr);
        const char *shaderSrc = shaderStr.c_str();

        // Compile the shader
        glShaderSource(fragShader, 1, &shaderSrc, NULL);
        glCompileShader(fragShader);

        // Check the shader
        GLint compileStatus = GL_FALSE;
        int32  logLength;
        glGetShaderiv(fragShader, GL_COMPILE_STATUS, &compileStatus);
        glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
        if (logLength > 0)
        {
            GLchar shaderLog[logLength+1];
            glGetShaderInfoLog(fragShader, logLength, NULL, &shaderLog[0]);
            gLogWrite(LOG_ERROR, "Error in shader: " + file_fs, __FILE__, __LINE__, __FUNCTION__);
            gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
        }
    }

    // Shader program
    // Attach the compiled shader components
    GLuint program = glCreateProgram();
    if (vertShader != 0)
        glAttachShader(program, vertShader);
    if (geomShader != 0)
        glAttachShader(program, geomShader);
    if (fragShader != 0)
        glAttachShader(program, fragShader);

    // Compile the shader program
    glLinkProgram(program);

    // Chech for errors
    GLint compileStatus = GL_FALSE;
    int32  logLength;
    glGetProgramiv(program, GL_LINK_STATUS, &compileStatus);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    if (logLength > 0)
    {
        GLchar shaderLog[logLength+1];
        glGetProgramInfoLog(program, logLength, NULL, &shaderLog[0]);
        gLogWrite(LOG_ERROR, "Error in shader: " + _fileName, __FILE__, __LINE__, __FUNCTION__);
        gLogWrite(LOG_ERROR, std::string(shaderLog), __FILE__, __LINE__, __FUNCTION__);
    }

    // Clean up
    if (vertShader != 0)
        glDeleteShader(vertShader);
    if (geomShader != 0)
        glDeleteShader(geomShader);
    if (fragShader != 0)
        glDeleteShader(fragShader);

    // Save and return the shader program ID
    m_shaderID = program;
    return program;
}

// Get a uniform location from the shader
uint32 cGraphicsEngineShader::getUniformLocation(const std::string &_name)
{
    return glGetUniformLocation(m_shaderID, _name.c_str());
}

// Get an atribute location from the shader
uint32 cGraphicsEngineShader::getAttribLocation(const std::string &_name)
{
    return glGetAttribLocation(m_shaderID, _name.c_str());
}
