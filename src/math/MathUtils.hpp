//
// Created by joserivas1998 on 9/8/19.
//

#ifndef SDL2TEST_MATHUTILS_HPP
#define SDL2TEST_MATHUTILS_HPP

#include <cmath>

class MathUtils {
public:
    static constexpr float PI = 3.1415927f;
    static constexpr float PI2 = PI * 2;

    static constexpr float E = 2.7182818f;

    static constexpr float radiansToDegrees = 180.0f / PI;
    static constexpr float radDeg = radiansToDegrees;

    static constexpr float degreesToRadians = PI / 180.0f;
    static constexpr float degRad = degreesToRadians;

};

#endif //SDL2TEST_MATHUTILS_HPP
