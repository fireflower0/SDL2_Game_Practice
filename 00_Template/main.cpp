#include "game.hpp"

int main(void) {
  Game game;

  if (game.Initialize()) {
    game.RunGameLoop();
  }
  game.Shutdown();

  return 0;
}
