#include "Game.hpp"

int main(int argc, char **argv) {
    Game game;

    game.init("Lichengine++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    constexpr int FPS = 60;
    constexpr int frameDelay = 1000 / FPS;

    Uint32 frameTime = 0;

    while (game.running()) {
        frameTime = SDL_GetTicks();
        game.handleEvents();
        game.update();
        game.render();
        frameTime = SDL_GetTicks() - frameTime;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game.clean();

    return 0;
}
