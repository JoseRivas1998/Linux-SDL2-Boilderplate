//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_GAMEOBJECT_HPP
#define SDL2TEST_GAMEOBJECT_HPP

#include "Game.hpp"
#include "graphics/Texture.hpp"

class GameObject {
public:
    GameObject(const char *textureSheet, SDL_Renderer *ren);

    ~GameObject();

    void Update();

    void Render();

private:
    int xpos;
    int ypos;

    Texture *objTexture;
    SDL_Rect srcRect;
    SDL_Renderer *renderer;
};


#endif //SDL2TEST_GAMEOBJECT_HPP
