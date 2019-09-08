//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_TEXTURE_HPP
#define SDL2TEST_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
public:
    Texture(const char *path, SDL_Renderer *renderer);
    ~Texture();
    void draw(SDL_Renderer *renderer);
private:
    SDL_Texture *texture;
};


#endif //SDL2TEST_TEXTURE_HPP
