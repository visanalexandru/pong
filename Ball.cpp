//
// Created by visan on 5/26/22.
//

#include "Ball.h"

namespace Pong {
    Ball::Ball(float ball_speed, sf::Vector2f dir) : sf::CircleShape(BALL_RADIUS), speed(ball_speed), direction(dir) {
        setOrigin(sf::Vector2f(BALL_RADIUS, BALL_RADIUS));
    }

    void Ball::updatePosition(float delta_time) {
        sf::Vector2f pos = getPosition();
        pos += direction * speed * delta_time;
        setPosition(pos);
    }

    sf::Vector2f Ball::getDirection() const {
        return direction;
    }

    void Ball::setDirection(sf::Vector2f dir) {
        direction = dir;
    }

    float Ball::getSpeed() const {
        return speed;
    }

    void Ball::setSpeed(float new_speed) {
        speed = new_speed;
    }
}
