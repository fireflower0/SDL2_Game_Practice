#pragma once

#include <SDL2/SDL.h>

class Game {
public:
  Game();
  ~Game();
  bool Initialize();
  void RunGameLoop();
  void Shutdown();

private:
  void EventProcess();
  void KeyInputProcess();
  void RenderingProcess();
  void ManageFrameRate();

  SDL_Window* window;
  SDL_Renderer* renderer;
  bool is_running;
  Uint32 start_ticks;

  const static int X_POS = 100;
  const static int Y_POS = 100;
  const static int WIN_WIDTH = 1024;
  const static int WIN_HEIGHT = 768;
};
