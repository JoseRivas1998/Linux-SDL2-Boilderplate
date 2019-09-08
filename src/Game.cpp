//
// Created by jose on 9/6/19.
//

#include "Game.hpp"

SDL_Texture *playerTex;
SDL_Rect srcR;
SDL_Rect destR;

Game::Game() {}

Game::~Game() {}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialised.." << std::endl;

        this->window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (this->window) {
            std::cout << "Window created!" << std::endl;
        }

        this->renderer = SDL_CreateRenderer(this->window, -1, 0);
        if (this->renderer) {
            SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;

    } else {
        isRunning = false;
    }

    SDL_Surface *tmpSurface = IMG_Load("../assets/idle-left.png");
    playerTex = SDL_CreateTextureFromSurface(this->renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::update() {
    cnt++;

    destR.h = 48 * 2;
    destR.w = 32 * 2;
    destR.x = cnt;

    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playerTex, NULL, &destR);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyTexture(playerTex);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
