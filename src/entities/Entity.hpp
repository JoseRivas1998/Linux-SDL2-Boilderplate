//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_ENTITY_HPP
#define SDL2TEST_ENTITY_HPP

#include <SDL2/SDL.h>
#include <vector>
#include "../math/Vector2.hpp"

class Entity {
public:
    Entity();

    ~Entity();

    virtual void update() = 0;

    virtual void draw(SDL_Renderer *renderer) = 0;

    float getAngle() { return this->angle; }

    float getX() { return this->position.getX(); }

    void setX(float x) { this->position.setX(x); };

    float getY() { return this->position.getY(); }

    void setY(float y) { this->position.setY(y); }

    Vector2 getPosition() { return Vector2(this->position); }

    void setPosition(float x, float y) { this->position.set(x, y); }

    void setPosition(const Vector2 &pos) { this->position.set(pos); }

    float getVelocityX() { return this->velocity.getX(); }

    void setVelocityX(float x) { this->velocity.setX(x); }

    float getVelocityY() { return this->velocity.getY(); }

    void setVelocityY(float y) { this->velocity.setY(y); }

    void setVelocity(float x, float y) { this->velocity.set(x, y); }

    void setVelocity(const Vector2 &vel) { this->velocity.set(vel); }

    void setVelocityPolar(float speed, float angle);

    void setVelocityPolarDegrees(float speed, float angle);

    float getDirection();

    float getDirectionDegrees();

    void setDirection(float direction);

    void setDirectionDegrees(float direction);

    float getSpeed();

    void setSpeed(float speed);

    void applyVelocity();

    bool collidingWith(const Entity &e);

    bool contains(const Vector2 &point);

    bool contains(float x, float y);

protected:

    void initializeVertices(int numPoints);

    int numVertices();

    virtual void setShape() = 0;

    void drawPoints(SDL_Renderer *renderer);

    static void drawVector(std::vector<Vector2> vertices, SDL_Renderer *renderer, bool connectEnds);

    void setPointRadians(int point, float length, float angleOffset);

    void setPointDegrees(int point, float length, float angleOffset);

    void setPointOffset(int point, const Vector2 &offset);

    void setPointOffset(int point, float xOffset, float yOffset);

    void setSquare();

    float getRadius() { return this->radius; }

    void setRadius(float radius) { this->radius = radius; }

    void wrapPosition(float xMin, float xMax, float yMin, float yMax);

    Vector2 getVertex(int index) { return Vector2(vertices[index]); };

private:
    static int entitiesCreated;
    std::vector<Vector2> vertices;
    Vector2 position;
    Vector2 velocity;
    int id;
    float radius;
    float angle;
};


#endif //SDL2TEST_ENTITY_HPP
