struct Shader {
  GLuint vert;
  GLuint frag;
  GLuint prog;
};


struct Shader* shader_create();
void shader_delete(struct Shader* s);

bool shader_compile_vert(struct Shader* s, const char* src);
bool shader_compile_frag(struct Shader* s, const char* src);

void shader_bind_attr(struct Shader* s, GLuint location, const char* name);
void shader_bind_frag_data_location(struct Shader* s, GLuint color_number, const char* name);

bool shader_link(struct Shader* s);

void shader_bind(struct Shader* s);

GLint shader_get_uniform_location(struct Shader* s, const char* name);
void shader_set_uniform_mat4(struct Shader* s, GLint location, GLsizei count, const GLfloat* v);
