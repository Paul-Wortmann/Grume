
#include "re_glew.hpp"

namespace RoboEngine
{
    void RE_glewExperimental(bool _bool)
    {
        glewExperimental = _bool;
    }

    GLenum RE_glewInit(void)
    {
        return glewInit();
    }

}

