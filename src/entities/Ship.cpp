//
// Created by joserivas1998 on 9/8/19.
//

#include "Ship.hpp"

#include <iostream>

Ship::Ship() : Entity() {
    this->initializeVertices(4);
    std::cout << this->numVertices() << std::endl;
}

void Ship::update() {

}

void Ship::draw(SDL_Renderer *renderer) {

}

void Ship::setShape() {

}
