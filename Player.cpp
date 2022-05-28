//
// Created by visan on 5/25/22.
//

#include "Player.h"
#include<iostream>

namespace Pong {
    Player::Player(float player_speed) : sf::RectangleShape(sf::Vector2f(PLAYER_SIZE_X, PLAYER_SIZE_Y)),
                                         controller(nullptr),
                                         speed(player_speed), score(0) {

        setOrigin(PLAYER_SIZE_X / 2.0f, PLAYER_SIZE_Y / 2.0f);
    }


    void Player::setController(const std::shared_ptr<PlayerController> &new_controller) {
        controller = new_controller;
    }

    const std::shared_ptr<PlayerController> &Player::getController() {
        return controller;
    }

    void Player::update(float delta_time) {
        if (controller == nullptr)
            return;
        Movement move = controller->getMovement();
        sf::Vector2f pos = getPosition();
        if (move == Movement::Up) {
            pos -= sf::Vector2f(0, speed * delta_time);
        } else if (move == Movement::Down) {
            pos += sf::Vector2f(0, speed * delta_time);
        }
        pos.y = std::max(pos.y, PLAYER_SIZE_Y / 2);
        pos.y = std::min(pos.y, SCREEN_SIZE_Y - PLAYER_SIZE_Y / 2);
        setPosition(pos);
    }

    unsigned int Player::getScore() const {
        return score;
    }

    void Player::setScore(unsigned int new_score) {
        score = new_score;
    }
}
