//
// Created by joserivas1998 on 9/8/19.
//

#include "GameObject.hpp"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren) {
    this->renderer = ren;
    objTexture = new Texture(textureSheet, ren);
}

void GameObject::Update() {

}

void GameObject::Render() {

}
