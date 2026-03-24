/*
This is how we do some crazy crazy clear window and window color rendering.
*/

#define SDL_MAIN_USE_CALLBACKS 1
#define HEIGHT 600
#define WIDTH 400

#include <master.h>


static SDL_Window *global_window = NULL;
static SDL_Renderer *global_renderer = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
  if (!SDL_Init(SDL_INIT_VIDEO))
  {
    SDL_Log("SDL didn't initialize. Lolz XD [%s]\n", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  if (!SDL_CreateWindowAndRenderer("clear color renderer", HEIGHT, WIDTH, SDL_WINDOW_RESIZABLE, &global_window, &global_renderer))
  {
    SDL_Log("SDL couldn't make/create a window. You bafoon. [%s]", SDL_GetError());
    return SDL_APP_FAILURE;
  }
  return SDL_APP_CONTINUE;
}

/* This processes the in application events. For example, touches and inputs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
  if (event->type == SDL_EVENT_QUIT)
  {
    return SDL_APP_SUCCESS;
  }
  return SDL_APP_CONTINUE;
}

/* This function run per frame. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
  const double frames = ((double)SDL_GetTicks()) / 1000.0;

  SDL_SetRenderDrawColor(global_renderer, 200.0, 200.0, 200.0, SDL_ALPHA_OPAQUE);

  SDL_RenderClear(global_renderer);

  SDL_RenderPresent(global_renderer);

  SDL_RenderClear(global_renderer);
  
  return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
}


