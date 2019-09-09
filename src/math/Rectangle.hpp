//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_RECTANGLE_HPP
#define SDL2TEST_RECTANGLE_HPP


class Rectangle {
public:
    Rectangle() : Rectangle(0, 0, 0, 0) {}

    Rectangle(float x, float y, float width, float height);

    ~Rectangle() = default;

    bool overlaps(Rectangle r);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

    float getWidth() const;

    void setWidth(float width);

    float getHeight() const;

    void setHeight(float height);

private:
    float x;
    float y;
    float width;
    float height;
};


#endif //SDL2TEST_RECTANGLE_HPP
