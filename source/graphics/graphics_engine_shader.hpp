


#ifndef GRAPHICS_ENGINE_SHADER_HPP
#define GRAPHICS_ENGINE_SHADER_HPP

#include "../includes.hpp"
#include "../utils/file_utils.hpp"

class cGraphicsEngineShader
{
    public:
        void initialize(void);
        void terminate(void);
        uint32 load(const std::string &_fileName);
        uint32 getID(void) {return m_shaderID;}
        uint32 getUniformLocation(const std::string &_name);
        uint32 getAttribLocation(const std::string &_name);
    
    protected:
        
    private:
        uint32 m_shaderID = 0;
};

#endif //GRAPHICS_ENGINE_SHADER_HPP
