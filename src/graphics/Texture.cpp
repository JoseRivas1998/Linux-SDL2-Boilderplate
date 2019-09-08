//
// Created by joserivas1998 on 9/8/19.
//

#include "Texture.hpp"

Texture::Texture(const char *path, SDL_Renderer *renderer) {
    SDL_Surface *tmpSurface = IMG_Load(path);
    this->texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);
    SDL_FreeSurface(tmpSurface);
}

Texture::~Texture() {
    SDL_DestroyTexture(this->texture);
}

void Texture::draw(SDL_Renderer *renderer, SDL_Rect *srcRect) {
    SDL_RenderCopy(renderer, this->texture, srcRect, nullptr);
}

void Texture::draw(SDL_Renderer *renderer) {
    this->draw(renderer, nullptr);
}

void Texture::draw(SDL_Renderer *renderer, SDL_Rect *srcRect, int x, int y) {
    this->draw(renderer,srcRect, x, y, this->width, this->height);
}

void Texture::draw(SDL_Renderer *renderer, int x, int y) {
    this->draw(renderer, x, y, this->width, this->height);
}

void Texture::draw(SDL_Renderer *renderer, SDL_Rect *srcRect, int x, int y, int draw_width, int draw_height) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = draw_width;
    dest.h = draw_height;
    SDL_RenderCopy(renderer, this->texture, srcRect, &dest);
}

void Texture::draw(SDL_Renderer *renderer, int x, int y, int draw_width, int draw_height) {
    this->draw(renderer, nullptr, x, y, draw_width, draw_height);
}
