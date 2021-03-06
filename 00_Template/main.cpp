#include <SDL2/SDL.h>

int main(void) {
  // Initialize
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Error: %s", SDL_GetError());
    return -1;
  }

  SDL_Window* window = SDL_CreateWindow("hello", 100, 100, 1024, 768, 0);

  if (!window) {
    SDL_Log("Error: %s", SDL_GetError());
    return -1;
  }

  Uint32 flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, flags);

  // Game Loop
  SDL_Event event;
  bool is_running = true;

  while (is_running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) is_running = false;
    }

    // Get keyboard state
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) is_running = false; // Quit by Escape key

    // Render
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderPresent(renderer);
  }

  // Shutdown
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
