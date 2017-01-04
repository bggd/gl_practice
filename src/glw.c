struct Glw*
glw_create(const char* title, struct GlwOpt* opt)
{
  int x, y, width, height;
  int debug_flag = (opt->debug_output) ? SDL_GL_CONTEXT_DEBUG_FLAG : 0;

  struct Glw* w;

  w = (struct Glw*)malloc(sizeof(struct Glw));

  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, debug_flag);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  x = opt->set_pos ? opt->x : SDL_WINDOWPOS_UNDEFINED;
  y = opt->set_pos ? opt->y : SDL_WINDOWPOS_UNDEFINED;
  width = opt->w;
  height = opt->h;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, opt->major);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, opt->minor);

  w->win = SDL_CreateWindow(
    title,
    x, y,
    width, height,
    SDL_WINDOW_OPENGL
  );

  if (w->win) {
    w->glc = SDL_GL_CreateContext(w->win);
    if (w->glc == NULL) {
      SDL_DestroyWindow(w->win);
      return NULL;
    }

    SDL_GL_MakeCurrent(w->win, w->glc);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &w->info.major);
    SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &w->info.minor);

    SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &debug_flag);
    w->info.debug_output = debug_flag ? true : false;

    if (opt->vsync) {
      if (SDL_GL_SetSwapInterval(-1) < 0)
        SDL_GL_SetSwapInterval(1);
      w->info.vsync = SDL_GL_GetSwapInterval() != 0;
    }

    w->info.w = width;
    w->info.h = height;
  }

  return w;
}

void
glw_delete(struct Glw* w)
{
  SDL_GL_DeleteContext(w->glc);
  SDL_DestroyWindow(w->win);
}

void
glw_make_current(struct Glw* w)
{
  SDL_GL_MakeCurrent(w->win, w->glc);
}

void
glw_flip(struct Glw* w)
{
  SDL_GL_SwapWindow(w->win);
}
