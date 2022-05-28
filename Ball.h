//
// Created by visan on 5/26/22.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H

#include<SFML/Graphics.hpp>
#include"Util.h"

namespace Pong {
    class Ball : public sf::CircleShape {
    private:
        //The speed of the ball.
        float speed;

        //The direction of the ball.
        sf::Vector2f direction;
    public:
        explicit Ball(float ball_speed, sf::Vector2f dir);

        //Update the ball's position.
        void updatePosition(float delta_time);

        sf::Vector2f getDirection() const;

        void setDirection(sf::Vector2f dir);

        float getSpeed() const;

        void setSpeed(float new_speed);
    };
}


#endif //PONG_BALL_H
