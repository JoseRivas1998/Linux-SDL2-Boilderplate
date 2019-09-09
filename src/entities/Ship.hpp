//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_SHIP_HPP
#define SDL2TEST_SHIP_HPP

#include "Entity.hpp"

class Ship : Entity {
public:
    Ship();

    void update() override;

    void draw(SDL_Renderer *renderer) override;

protected:

    void setShape() override;
};


#endif //SDL2TEST_SHIP_HPP
