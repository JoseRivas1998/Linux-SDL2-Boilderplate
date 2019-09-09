//
// Created by joserivas1998 on 9/8/19.
//

#include "Vector2.hpp"
#include "MathUtils.hpp"

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2 Vector2::cpy() {
    return Vector2(*this);
}

float Vector2::len(float x, float y) {
    return sqrtf(x * x + y * y);
}

float Vector2::len() {
    return Vector2::len(this->x, this->y);
}

float Vector2::len2(float x, float y) {
    return x * x + y * y;
}

float Vector2::len2() {
    return Vector2::len2(this->x, this->y);
}

void Vector2::set(float _x, float _y) {
    this->x = _x;
    this->y = _y;
}

Vector2 Vector2::operator-(const Vector2 &v) {
    return Vector2(this->x - v.x, this->y - v.y);
}

void Vector2::sub(float _x, float _y) {
    this->x -= _x;
    this->y -= _y;
}

Vector2 Vector2::operator+(const Vector2 &v) {
    return Vector2(this->x + v.x, this->y + v.y);
}

void Vector2::add(float _x, float _y) {
    this->x += _x;
    this->y += _y;
}

float Vector2::angle() {
    float angle = (float) atan2(this->y, this->x) * MathUtils::radiansToDegrees;
    if(angle < 0) {
        angle += 360;
    }
    return angle;
}

float Vector2::getX() const {
    return x;
}

void Vector2::setX(float x) {
    Vector2::x = x;
}

float Vector2::getY() const {
    return y;
}

void Vector2::setY(float y) {
    Vector2::y = y;
}

Vector2 Vector2::polar(float speed, float angle) {
    float x = speed * cosf(angle);
    float y = speed * sinf(angle);
    return Vector2(x, y);
}

Vector2::~Vector2() = default;
