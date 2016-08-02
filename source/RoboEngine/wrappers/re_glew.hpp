#ifndef RE_GLEW_HPP
#define RE_GLEW_HPP

#include <GL/glew.h>
#include <GL/gl.h>

namespace RoboEngine
{

    #define RE_GLEW_OK GLEW_OK

    void RE_glewExperimental(bool _bool);
      GLenum RE_glewInit(void);
}

#endif //RE_GLEW_HPP
