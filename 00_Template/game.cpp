#include "game.hpp"

Game::Game() {}

Game::~Game() {}

bool Game::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    SDL_Log("Error: %s", SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("hello", X_POS, Y_POS, WIN_WIDTH, WIN_HEIGHT, 0);

  if (!window) {
    SDL_Log("Error: %s", SDL_GetError());
    return false;
  }

  Uint32 flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

  renderer = SDL_CreateRenderer(window, -1, flags);

  start_ticks = 0;
  is_running = true;

  return true;
}

void Game::RunGameLoop() {
  while (is_running) {
    EventProcess();
    KeyInputProcess();
    ManageFrameRate();
    UpdateGame();
    RenderingProcess();
  }
}

void Game::Shutdown() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// Private
// ==================================================

void Game::EventProcess() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) is_running = false;
  }
}

void Game::KeyInputProcess() {
  const Uint8* state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE]) is_running = false; // Quit by Escape key
}

void Game::RenderingProcess() {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // ...

  SDL_RenderPresent(renderer);
}

void Game::ManageFrameRate() {
  // ref: https://wiki.libsdl.org/SDL_TICKS_PASSED
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), start_ticks + 16))
    ;

  // ref: https://thenumbat.github.io/cpp-course/sdl2/08/08.html
  Uint32 end_ticks = SDL_GetTicks();
  float delta_time = (end_ticks - start_ticks) / 1000.0f;
  if (delta_time > 0.05f) delta_time = 0.05f;
  start_ticks = SDL_GetTicks();
}

void Game::UpdateGame() {}
