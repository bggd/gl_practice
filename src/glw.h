// glw (GL Window)

struct GlwOpt {

  bool set_pos;
  int x, y;
  int w, h;

  // OpenGL context stuff
  int major;
  int minor;
  bool debug_output;
  bool vsync;

};

struct Glw {

  SDL_Window* win;
  SDL_GLContext glc;

  struct GlwOpt info;

};


struct Glw* glw_create(const char* title, struct GlwOpt*);
void glw_make_current(struct Glw*);
void glw_flip(struct Glw*);
void glw_delete(struct Glw*);
