#include <SDL.h>
#include "gl_def.h"
#include <cstdarg>
#include <cstdio>


#ifdef SINGLESPEED_GL_GET_ERROR
#define GL_DEF(name, ...) typedef void name##proc(__VA_ARGS__); name##proc* my_gl##name; name##proc* gl##name;
#define GL_DEF_RET(ret, name, ...) typedef ret name##proc(__VA_ARGS__); name##proc* my_gl##name; name##proc* gl##name;
#else
#define GL_DEF(name, ...) GL_DEF_RET(void, name, __VA_ARGS__)
#define GL_DEF_RET(ret, name, ...) typedef ret name##proc(__VA_ARGS__); name##proc* gl##name;
#endif /* SINGLESPEED_GL_DEBUG */

MY_GL_LIST

#undef GL_DEF
#undef GL_DEF_RET


static void
err_handle(const char* name, GLenum code)
{
#define PUTS_GL_ERR(err_name, name) fprintf(stderr, "glGetError: %s in %s\n", err_name, name)
  switch (code) {
    case GL_NO_ERROR:
      break;
    case GL_INVALID_ENUM:
      PUTS_GL_ERR("GL_INVALID_ENUM", name); break;
    case GL_INVALID_VALUE:
      PUTS_GL_ERR("GL_INVALID_VALUE", name); break;
    case GL_INVALID_OPERATION:
      PUTS_GL_ERR("GL_INVALID_OPERATION", name); break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      PUTS_GL_ERR("GL_INVALID_FRAMEBUFFER_OPERATION", name); break;
    case GL_OUT_OF_MEMORY:
      PUTS_GL_ERR("GL_OUT_OF_MEMORY", name); break;
    default:
      PUTS_GL_ERR("UNKNOWN", name); break;
      break;
  }
#undef PUTS_GL_ERR
}

extern "C" void
debug_output_cb(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, void* userParam)
{
  fprintf(stderr, "Debug Message (%d) %s\n", id, message);
}


typedef GLenum glGetErrorproc();
glGetErrorproc* glGetError;

static void
_load_gl_functions()
{
  glGetError = (glGetErrorproc*)SDL_GL_GetProcAddress("glGetError");
#ifdef SINGLESPEED_GL_GET_ERROR
#define GL_DEF(name, ...) my_gl##name = (name##proc*)SDL_GL_GetProcAddress("gl"#name); \
  gl##name = [](auto ...args) { \
    my_gl##name(args...); \
    err_handle("gl"#name, glGetError()); \
    return; \
  };
#define GL_DEF_RET(ret, name, ...) my_gl##name = (name##proc*)SDL_GL_GetProcAddress("gl"#name); \
  gl##name = [](auto ...args) { \
    ret r = my_gl##name(args...); \
    err_handle("gl"#name, glGetError()); \
    return r; \
  };
#else
#define GL_DEF(name, ...) GL_DEF_RET(void, name, __VA_ARGS__)
#define GL_DEF_RET(ret, name, ...) gl##name = (name##proc*)SDL_GL_GetProcAddress("gl"#name);
#endif /* SINGLESPEED_GL_DEBUG */

  MY_GL_LIST

#undef GL_DEF
#undef GL_DEF_RET
}

extern "C" void
load_gl_functions()
{
  _load_gl_functions();
}

