#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef unsigned int GLuint;
typedef unsigned int GLint;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;

typedef char GLchar;

typedef ptrdiff_t GLsizeiptr;

#define GL_FALSE 0
#define GL_TRUE 1

#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_SHORT 0x1403
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

#define GL_TRIANGLES 0x0004

#define GL_DEBUG_OUTPUT 0x92E0
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242

#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506

#define GL_SCISSOR_TEST 0x0C11

#define GL_COLOR_BUFFER_BIT 0x00004000

#define GL_BLEND 0x0BE2
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303

#define GL_FUNC_ADD 0x8006

#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31

#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893

#define GL_STREAM_DRAW 0x88E0
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8

#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1

#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601

#define GL_RED 0x1903
#define GL_R8 0x8229
#define GL_ALPHA 0x1906
#define GL_ALPHA8 0x803C
#define GL_RGB 0x1907
#define GL_RGB8 0x8051
#define GL_RGBA 0x1908
#define GL_RGBA8 0x8058

#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_ALIGNMENT 0x0CF5

#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45


typedef void (*MY_DEBUG_PROC) (GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*, void*);

#define MY_GL_LIST \
  GL_DEF(DebugMessageCallback, MY_DEBUG_PROC, void*) \
  GL_DEF(Enable, GLenum) \
  GL_DEF(Disable, GLenum) \
  GL_DEF(Viewport, GLint, GLint, GLsizei, GLsizei) \
  GL_DEF(Scissor, GLint, GLint, GLsizei, GLsizei) \
  GL_DEF(ClearColor, GLclampf, GLclampf, GLclampf, GLclampf) \
  GL_DEF(Clear, GLbitfield) \
  GL_DEF(BlendEquation, GLenum) \
  GL_DEF(BlendFunc, GLenum, GLenum) \
  /* Shader */ \
  GL_DEF_RET(GLuint, CreateProgram) \
  GL_DEF_RET(GLuint, CreateShader, GLenum) \
  GL_DEF(ShaderSource, GLuint, GLsizei, const GLchar**, const GLint*) \
  GL_DEF(CompileShader, GLuint) \
  GL_DEF(GetShaderiv, GLuint, GLenum, GLint*) \
  GL_DEF(GetShaderInfoLog, GLuint, GLsizei, GLsizei*, GLchar*) \
  GL_DEF(BindAttribLocation, GLuint, GLuint, const GLchar*) \
  GL_DEF(AttachShader, GLuint, GLuint) \
  GL_DEF(LinkProgram, GLuint) \
  GL_DEF(GetProgramiv, GLuint, GLenum, GLint*) \
  GL_DEF(GetProgramInfoLog, GLuint, GLsizei, GLsizei*, GLchar*) \
  GL_DEF_RET(GLint, GetUniformLocation, GLuint, const GLchar*) \
  GL_DEF(UniformMatrix4fv, GLint, GLsizei, GLboolean, const GLfloat*) \
  GL_DEF(Uniform1i, GLint, GLint) \
  GL_DEF(BindFragDataLocation, GLuint, GLuint, const GLchar*) \
  GL_DEF(UseProgram, GLuint) \
  GL_DEF(DetachShader, GLuint, GLuint) \
  GL_DEF(DeleteShader, GLuint) \
  GL_DEF(DeleteProgram, GLuint) \
  /* VAO */ \
  GL_DEF(GenVertexArrays, GLsizei, GLuint*) \
  GL_DEF(BindVertexArray, GLuint) \
  /* VBO IBO */ \
  GL_DEF(GenBuffers, GLsizei, GLuint*) \
  GL_DEF(BindBuffer, GLenum, GLuint) \
  GL_DEF(EnableVertexAttribArray, GLuint) \
  GL_DEF(VertexAttribPointer, GLuint, GLint, GLenum, GLboolean, GLsizei, const GLvoid*) \
  GL_DEF(BufferData, GLenum, GLsizeiptr, const GLvoid*, GLenum) \
  GL_DEF(DrawArrays, GLenum, GLint, GLsizei) \
  GL_DEF(DrawElements, GLenum, GLsizei, GLenum, const GLvoid*) \
  /* Texture */ \
  GL_DEF(GenTextures, GLsizei, GLuint*) \
  GL_DEF(BindTexture, GLenum, GLuint) \
  GL_DEF(TexParameteri, GLenum, GLenum, GLint) \
  GL_DEF(PixelStorei, GLenum, GLint) \
  GL_DEF(TexImage2D, GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid*) \
  GL_DEF(ActiveTexture, GLenum) \
/* end of MY_GL_LIST */

#ifdef SINGLESPEED_GL_GET_ERROR
#define GL_DEF(name, ...) typedef void name##proc(__VA_ARGS__); extern name##proc* my_gl##name; extern name##proc* gl##name;
#define GL_DEF_RET(ret, name, ...) typedef ret name##proc(__VA_ARGS__); extern name##proc* my_gl##name; extern name##proc* gl##name;
#else
#define GL_DEF(name, ...) typedef void name##proc(__VA_ARGS__); extern name##proc* gl##name;
#define GL_DEF_RET(ret, name, ...) typedef ret name##proc(__VA_ARGS__); extern name##proc* gl##name;
#endif /* SINGLESPEED_GL_DEBUG */
MY_GL_LIST
#undef GL_DEF
#undef GL_DEF_RET


void debug_output_cb(GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar*, void*);
void load_gl_functions();

#ifdef __cplusplus
}
#endif
