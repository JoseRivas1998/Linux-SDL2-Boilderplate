//
// Created by joserivas1998 on 9/8/19.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Rectangle::overlaps(Rectangle r) {
    return false;
}

float Rectangle::getX() const {
    return x;
}

void Rectangle::setX(float x) {
    Rectangle::x = x;
}

float Rectangle::getY() const {
    return y;
}

void Rectangle::setY(float y) {
    Rectangle::y = y;
}

float Rectangle::getWidth() const {
    return width;
}

void Rectangle::setWidth(float width) {
    Rectangle::width = width;
}

float Rectangle::getHeight() const {
    return height;
}

void Rectangle::setHeight(float height) {
    Rectangle::height = height;
}
