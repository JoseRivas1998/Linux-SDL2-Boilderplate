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
    void draw(SDL_Renderer *renderer, SDL_Rect *srcRect);
    void draw(SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer, SDL_Rect *srcRect, int x, int y);
    void draw(SDL_Renderer *renderer, int x, int y);
    void draw(SDL_Renderer *renderer, SDL_Rect *srcRect, int x, int y, int draw_width, int draw_height);
    void draw(SDL_Renderer *renderer, int x, int y, int draw_width, int draw_height);
private:
    SDL_Texture *texture;
    int width;
    int height;
};


#endif //SDL2TEST_TEXTURE_HPP
