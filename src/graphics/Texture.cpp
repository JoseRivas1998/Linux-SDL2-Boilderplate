//
// Created by joserivas1998 on 9/8/19.
//

#include "Texture.hpp"

Texture::Texture(const char *path, SDL_Renderer *renderer) {
    SDL_Surface *tmpSurface = IMG_Load(path);
    this->texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

Texture::~Texture() {
    SDL_DestroyTexture(this->texture);
}

void Texture::draw(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, this->texture, NULL, NULL);
}
