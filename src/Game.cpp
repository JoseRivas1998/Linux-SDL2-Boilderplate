//
// Created by jose on 9/6/19.
//

#include "Game.hpp"
#include "graphics/Texture.hpp"
#include "entities/Ship.hpp"

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
            SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0x00);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;

    } else {
        isRunning = false;
    }

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

    std::cout << cnt << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
