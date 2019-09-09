//
// Created by joserivas1998 on 9/8/19.
//

#include "Entity.hpp"
#include "../math/MathUtils.hpp"

#include <iostream>

int Entity::entitiesCreated = 0;

Entity::Entity() {
    this->radius = 0;
    this->angle = 0;
    id = ++Entity::entitiesCreated;
    std::cout << "Created Entity " << this->id << std::endl;
}

Entity::~Entity() = default;

void Entity::initializeVertices(int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        this->vertices.emplace_back();
    }
}

void Entity::setVelocityPolar(float speed, float angle) {
    this->setVelocity(Vector2::polar(speed, angle));
}

void Entity::setVelocityPolarDegrees(float speed, float angle) {
    this->setVelocityPolar(speed, angle * MathUtils::degreesToRadians);
}

float Entity::getDirection() {
    return atan2(getVelocityY(), getVelocityX());
}

float Entity::getDirectionDegrees() {
    return getDirection() * MathUtils::radiansToDegrees;
}

void Entity::setDirection(float direction) {
    float speed = this->velocity.len();
    this->setVelocityPolar(speed, direction);
}

void Entity::setDirectionDegrees(float direction) {
    this->setDirection(direction * MathUtils::degreesToRadians);
}

float Entity::getSpeed() {
    return this->velocity.len();
}

void Entity::setSpeed(float speed) {
    float direction = this->getDirection();
    this->setVelocityPolar(speed, direction);
}

void Entity::applyVelocity() {
    this->position = this->position + this->velocity;
}

bool Entity::contains(const Vector2 &point) {
    return contains(point.getX(), point.getY());
}

bool Entity::contains(float x, float y) {
    bool b = false;
    for (int i = 0, j = (int) vertices.size() - 1;
         i < (int) vertices.size();
         j = i++) {
        if ((vertices[i].getY() > y) != (vertices[j].getY() > y) &&
            (x < (vertices[j].getX() - vertices[i].getX()) *
                 (y - vertices[i].getY()) / (vertices[j].getY() - vertices[i].getY())
                 + vertices[i].getX())) {
            b = !b;
        }
    }
    return b;
}

void Entity::drawPoints(SDL_Renderer *renderer) {
    Entity::drawVector(this->vertices, renderer, true);
}

void drawLine(SDL_Renderer *renderer, const Vector2 &p1, const Vector2 &p2) {
    int x1 = (int) p1.getX();
    int y1 = (int) p1.getY();
    int x2 = (int) p2.getX();
    int y2 = (int) p2.getY();
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Entity::drawVector(std::vector<Vector2> vertices, SDL_Renderer *renderer, bool connectEnds) {
    int x1;
    int y1;
    int x2;
    int y2;
    for (int i = 1; i < (int) vertices.size(); ++i) {
        drawLine(renderer, vertices[i - 1], vertices[i]);
    }
    if (connectEnds) {
        drawLine(renderer, vertices[(int) vertices.size() - 1], vertices[0]);
    }
}

void Entity::setPointRadians(int point, float length, float angleOffset) {
    Vector2 offset = Vector2::polar(length, this->angle + angleOffset);
    setPointOffset(point, offset);
}

void Entity::setPointDegrees(int point, float length, float angleOffset) {
    this->setPointRadians(point, length, angleOffset * MathUtils::degreesToRadians);
}

void Entity::setPointOffset(int point, const Vector2 &offset) {
    this->vertices[point] = this->position + offset;
}

void Entity::setPointOffset(int point, float xOffset, float yOffset) {
    this->vertices[point] = this->position + Vector2(xOffset, yOffset);
}

void Entity::setSquare() {
    setPointOffset(0, getRadius(), -getRadius());
    setPointOffset(1, getRadius(), getRadius());
    setPointOffset(2, -getRadius(), getRadius());
    setPointOffset(3, -getRadius(), -getRadius());
}

void Entity::wrapPosition(float xMin, float xMax, float yMin, float yMax) {
    this->position.setX(MathUtils::wrap(this->position.getX(), xMin, xMax));
    this->position.setY(MathUtils::wrap(this->position.getY(), yMin, yMax));
}

bool Entity::collidingWith(const Entity &e) {
    bool colliding = false;
    for (int i = 0; i < (int) e.vertices.size() && !colliding; ++i) {
        if (this->contains(e.vertices[i])) {
            colliding = true;
        }
    }
    return colliding;
}

int Entity::numVertices() {
    return this->vertices.size();
}
