#ifndef RE_GLEW_HPP
#define RE_GLEW_HPP

#include <GL/gl.h>
#include <GL/glx.h>

namespace RoboEngine
{
    namespace glExt
    {
        extern PFNGLACTIVETEXTUREARBPROC         glActiveTextureARB;
        extern PFNGLMULTITEXCOORD2FARBPROC       glMultiTexCoord2fARB;
        extern PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays;
        extern PFNGLBINDVERTEXARRAYPROC          glBindVertexArray;
        extern PFNGLGENBUFFERSPROC               glGenBuffers;
        extern PFNGLBINDBUFFERPROC               glBindBuffer;
        extern PFNGLBUFFERDATAPROC               glBufferData;
        extern PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer;
        extern PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray;
        extern PFNGLCREATESHADERPROC             glCreateShader;
        extern PFNGLSHADERSOURCEPROC             glShaderSource;
        extern PFNGLCOMPILESHADERPROC            glCompileShader;
        extern PFNGLGETSHADERIVPROC              glGetShaderiv;
        extern PFNGLGETSHADERINFOLOGPROC         glGetShaderInfoLog;
        extern PFNGLCREATEPROGRAMPROC            glCreateProgram;
        extern PFNGLATTACHSHADERPROC             glAttachShader;
        extern PFNGLBINDATTRIBLOCATIONPROC       glBindAttribLocation;
        extern PFNGLLINKPROGRAMPROC              glLinkProgram;
        extern PFNGLGETPROGRAMIVPROC             glGetProgramiv;
        extern PFNGLGETPROGRAMINFOLOGPROC        glGetProgramInfoLog;
        extern PFNGLUSEPROGRAMPROC               glUseProgram;
        extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
        extern PFNGLDETACHSHADERPROC             glDetachShader;
        extern PFNGLDELETEPROGRAMPROC            glDeleteProgram;
        extern PFNGLDELETESHADERPROC             glDeleteShader;
        extern PFNGLDELETEBUFFERSPROC            glDeleteBuffers;
        extern PFNGLDELETEVERTEXARRAYSPROC       glDeleteVertexArrays;
        extern PFNGLGETSTRINGIPROC               glGetStringi;
        extern PFNGLGETATTRIBLOCATIONPROC        glGetAttribLocation;
        extern PFNGLGETUNIFORMLOCATIONPROC       glGetUniformLocation;
        extern void init(void **context);
    }
}

#endif //RE_GLEW_HPP
