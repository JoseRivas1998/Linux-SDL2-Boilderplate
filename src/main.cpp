#include "Game.hpp"

Game game;

int main(int argc, char **argv) {

    game.init("Lichengine++", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while(game.running()) {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

	return 0;
}
