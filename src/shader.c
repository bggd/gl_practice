static bool
shader_compile(struct Shader* s, GLenum type, const char* src)
{
  GLuint shdr = glCreateShader(type);
  glShaderSource(shdr, 1, &src, NULL);
  glCompileShader(shdr);

  GLint status;
  glGetShaderiv(shdr, GL_COMPILE_STATUS, &status);

  if (status == GL_FALSE) {
    GLint len;
    glGetShaderiv(shdr, GL_INFO_LOG_LENGTH, &len);

    GLchar* info_log = (GLchar*)malloc(sizeof(GLchar)*len);
    glGetShaderInfoLog(shdr, len, NULL, info_log);
    
    fprintf(stderr, "%s\n", info_log);
    free(info_log);

    glDeleteShader(shdr);

    return false;
  }

  if (type == GL_VERTEX_SHADER) s->vert = shdr;
  if (type == GL_FRAGMENT_SHADER) s->frag = shdr;

  return true;
}

struct Shader*
shader_create()
{
  struct Shader* s;
  s = (struct Shader*)malloc(sizeof(struct Shader));
  s->prog = glCreateProgram();
  return s;
}

void
shader_delete(struct Shader* s)
{
  glDeleteProgram(s->prog);
  free(s);
}

bool
shader_compile_vert(struct Shader* s, const char* src)
{
  return shader_compile(s, GL_VERTEX_SHADER, src);
}

bool
shader_compile_frag(struct Shader* s, const char* src)
{
  return shader_compile(s, GL_FRAGMENT_SHADER, src);
}

void
shader_bind_attr(struct Shader* s, GLuint location, const char* name)
{
  glBindAttribLocation(s->prog, location, name);
}

void
shader_bind_frag_data_location(struct Shader* s, GLuint color_number, const char* name)
{
  glBindFragDataLocation(s->prog, color_number, name);
}

bool
shader_link(struct Shader* s)
{
  glAttachShader(s->prog, s->vert);
  glAttachShader(s->prog, s->frag);
  glLinkProgram(s->prog);

  GLint status;
  glGetProgramiv(s->prog, GL_LINK_STATUS, &status);

  if (status == GL_FALSE) {
    GLint len;
    glGetProgramiv(s->prog, GL_INFO_LOG_LENGTH, &len);

    GLchar* info_log = (GLchar*)malloc(sizeof(GLchar)*len);
    glGetProgramInfoLog(s->prog, len, NULL, info_log);

    fprintf(stderr, "%s\n", info_log);
    free(info_log);

    glDeleteProgram(s->prog);
    glDeleteShader(s->vert);
    glDeleteShader(s->frag);

    return false;
  }

  glDetachShader(s->prog, s->vert);
  glDetachShader(s->prog, s->frag);

  return true;
}

void
shader_bind(struct Shader* s)
{
  s ? glUseProgram(s->prog) : glUseProgram(0);
}

GLint
shader_get_uniform_location(struct Shader* s, const char* name)
{
  return glGetUniformLocation(s->prog, name);
}

void
shader_set_uniform_mat4(struct Shader* s, GLint location, GLsizei count, const GLfloat* v)
{
  glUniformMatrix4fv(location, count, GL_FALSE, v);
}
