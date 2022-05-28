//
// Created by visan on 5/25/22.
//

#ifndef PONG_UTIL_H
#define PONG_UTIL_H

#include<cmath>

namespace Pong {
    const float PLAYER_SIZE_Y = 100.f;
    const float PLAYER_SIZE_X = 5.f;
    const int SCREEN_SIZE_X = 600;
    const int SCREEN_SIZE_Y = 400;
    const int BALL_RADIUS = 10;
    const float PLAYER_SPEED = 800.f;
    const float BALL_SPEED = 150.f;
    const int FONT_SIZE = 24;
    const float BALL_ACCELERATION = 1.1f;

    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };

    inline sf::Vector2f normalize(sf::Vector2f vec) {
        double sum = vec.x * vec.x + vec.y * vec.y;
        auto length = (float) sqrt(sum);
        if (length == 0) {
            return vec;
        } else {
            return vec / length;
        }
    }

    inline float randomFloat(float a, float b) {
        float random = ((float) rand()) / (float) RAND_MAX;
        float diff = b - a;
        float r = random * diff;
        return a + r;
    }

    inline int randomNumber(int a, int b) {
        int random = rand() % (b - a + 1);
        return a + random;
    }

}

#endif //PONG_UTIL_H
