//
// Created by jose on 9/6/19.
//

#ifndef SDL2TEST_GAME_HPP
#define SDL2TEST_GAME_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Game {
public:
    Game();

    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();

    void update();

    void render();

    void clean();

    bool running() { return this->isRunning; }

private:
    int cnt = 0;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif //SDL2TEST_GAME_HPP
