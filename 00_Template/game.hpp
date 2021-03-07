#include <SDL2/SDL.h>

class Game {
public:
  Game();
  ~Game();
  bool Initialize();
  void RunGameLoop();
  void Shutdown();

private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event;
  bool is_running;
};
