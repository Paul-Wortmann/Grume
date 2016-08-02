
#include "re_glx.hpp"

namespace RoboEngine
{
    namespace glExt
    {
        PFNGLACTIVETEXTUREARBPROC         glActiveTextureARB         = nullptr;
        PFNGLMULTITEXCOORD2FARBPROC       glMultiTexCoord2fARB       = nullptr;
        PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays          = nullptr;
        PFNGLBINDVERTEXARRAYPROC          glBindVertexArray          = nullptr;
        PFNGLGENBUFFERSPROC               glGenBuffers               = nullptr;
        PFNGLBINDBUFFERPROC               glBindBuffer               = nullptr;
        PFNGLBUFFERDATAPROC               glBufferData               = nullptr;
        PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer      = nullptr;
        PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray  = nullptr;
        PFNGLCREATESHADERPROC             glCreateShader             = nullptr;
        PFNGLSHADERSOURCEPROC             glShaderSource             = nullptr;
        PFNGLCOMPILESHADERPROC            glCompileShader            = nullptr;
        PFNGLGETSHADERIVPROC              glGetShaderiv              = nullptr;
        PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog         = nullptr;
        PFNGLCREATEPROGRAMPROC            glCreateProgram            = nullptr;
        PFNGLATTACHSHADERPROC             glAttachShader             = nullptr;
        PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation       = nullptr;
        PFNGLLINKPROGRAMPROC              glLinkProgram              = nullptr;
        PFNGLGETPROGRAMIVPROC             glGetProgramiv             = nullptr;
        PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog        = nullptr;
        PFNGLUSEPROGRAMPROC               glUseProgram               = nullptr;
        PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
        PFNGLDETACHSHADERPROC             glDetachShader             = nullptr;
        PFNGLDELETEPROGRAMPROC            glDeleteProgram            = nullptr;
        PFNGLDELETESHADERPROC             glDeleteShader             = nullptr;
        PFNGLDELETEBUFFERSPROC            glDeleteBuffers            = nullptr;
        PFNGLDELETEVERTEXARRAYSPROC       glDeleteVertexArrays       = nullptr;
        PFNGLGETSTRINGIPROC               glGetStringi               = nullptr;
        PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation        = nullptr;
        PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation       = nullptr;
        void init(void **context)
        {
            if (context != NULL)
            {
                glActiveTextureARB         = (PFNGLACTIVETEXTUREARBPROC)         glXGetProcAddressARB((const unsigned char*)"glActiveTextureARB");
                glMultiTexCoord2fARB       = (PFNGLMULTITEXCOORD2FARBPROC)       glXGetProcAddressARB((const unsigned char*)"glMultiTexCoord2fARB");
                glGenVertexArrays          = (PFNGLGENVERTEXARRAYSPROC)          glXGetProcAddressARB((const unsigned char*)"glGenVertexArrays");
                glBindVertexArray          = (PFNGLBINDVERTEXARRAYPROC)          glXGetProcAddressARB((const unsigned char*)"glBindVertexArray");
                glGenBuffers               = (PFNGLGENBUFFERSPROC)               glXGetProcAddressARB((const unsigned char*)"glGenBuffers");
                glBindBuffer               = (PFNGLBINDBUFFERPROC)               glXGetProcAddressARB((const unsigned char*)"glBindBuffer");
                glBufferData               = (PFNGLBUFFERDATAPROC)               glXGetProcAddressARB((const unsigned char*)"glBufferData");
                glVertexAttribPointer      = (PFNGLVERTEXATTRIBPOINTERPROC)      glXGetProcAddressARB((const unsigned char*)"glVertexAttribPointer");
                glEnableVertexAttribArray  = (PFNGLENABLEVERTEXATTRIBARRAYPROC)  glXGetProcAddressARB((const unsigned char*)"glEnableVertexAttribArray");
                glCreateShader             = (PFNGLCREATESHADERPROC)             glXGetProcAddressARB((const unsigned char*)"glCreateShader");
                glShaderSource             = (PFNGLSHADERSOURCEPROC)             glXGetProcAddressARB((const unsigned char*)"glShaderSource");
                glCompileShader            = (PFNGLCOMPILESHADERPROC)            glXGetProcAddressARB((const unsigned char*)"glCompileShader");
                glGetShaderiv              = (PFNGLGETSHADERIVPROC)              glXGetProcAddressARB((const unsigned char*)"glGetShaderiv");
                glGetShaderInfoLog         = (PFNGLGETSHADERINFOLOGPROC)         glXGetProcAddressARB((const unsigned char*)"glGetShaderInfoLog");
                glCreateProgram            = (PFNGLCREATEPROGRAMPROC)            glXGetProcAddressARB((const unsigned char*)"glCreateProgram");
                glAttachShader             = (PFNGLATTACHSHADERPROC)             glXGetProcAddressARB((const unsigned char*)"glAttachShader");
                glBindAttribLocation       = (PFNGLBINDATTRIBLOCATIONPROC)       glXGetProcAddressARB((const unsigned char*)"glBindAttribLocation");
                glLinkProgram              = (PFNGLLINKPROGRAMPROC)              glXGetProcAddressARB((const unsigned char*)"glLinkProgram");
                glGetProgramiv             = (PFNGLGETPROGRAMIVPROC)             glXGetProcAddressARB((const unsigned char*)"glGetProgramiv");
                glGetProgramInfoLog        = (PFNGLGETPROGRAMINFOLOGPROC)        glXGetProcAddressARB((const unsigned char*)"glGetProgramInfoLog");
                glUseProgram               = (PFNGLUSEPROGRAMPROC)               glXGetProcAddressARB((const unsigned char*)"glUseProgram");
                glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) glXGetProcAddressARB((const unsigned char*)"glDisableVertexAttribArray");
                glDetachShader             = (PFNGLDETACHSHADERPROC)             glXGetProcAddressARB((const unsigned char*)"glDetachShader");
                glDeleteProgram            = (PFNGLDELETEPROGRAMPROC)            glXGetProcAddressARB((const unsigned char*)"glDeleteProgram");
                glDeleteShader             = (PFNGLDELETESHADERPROC)             glXGetProcAddressARB((const unsigned char*)"glDeleteShader");
                glDeleteBuffers            = (PFNGLDELETEBUFFERSPROC)            glXGetProcAddressARB((const unsigned char*)"glDeleteBuffers");
                glDeleteVertexArrays       = (PFNGLDELETEVERTEXARRAYSPROC)       glXGetProcAddressARB((const unsigned char*)"glDeleteVertexArrays");
                glGetStringi               = (PFNGLGETSTRINGIPROC)               glXGetProcAddressARB((const unsigned char*)"glGetStringi");
                glGetAttribLocation        = (PFNGLGETATTRIBLOCATIONPROC)        glXGetProcAddressARB((const unsigned char*)"glGetAttribLocation");
                glGetUniformLocation       = (PFNGLGETUNIFORMLOCATIONPROC)       glXGetProcAddressARB((const unsigned char*)"glGetUniformLocation");
            }
        }
    }
}
