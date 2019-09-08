//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_VECTOR2_HPP
#define SDL2TEST_VECTOR2_HPP


class Vector2 {

    Vector2() : Vector2(0, 0) {}

    Vector2(float x, float y);

    Vector2(const Vector2 &v) : Vector2(v.x, v.y) {}

    ~Vector2();

    Vector2 cpy();

    static float len(float x, float y);

    float len();

    static float len2(float x, float y);

    float len2();

    void set(float _x, float _y);

    void set(const Vector2& vector2) { this->set(vector2.x, vector2.y); }

    Vector2 operator - (const Vector2 &v);

    void sub(float _x, float _y);

    Vector2 operator + (const Vector2 &v);

    void add(float _x, float _y);

    float angle();

    float angle(Vector2 v);

private:
    float x;
    float y;


};


#endif //SDL2TEST_VECTOR2_HPP
