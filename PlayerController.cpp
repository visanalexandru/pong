//
// Created by visan on 5/25/22.
//


#include"PlayerController.h"

namespace Pong {
    Movement LKeyboardPlayerController::getMovement() const {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            return Movement::Up;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            return Movement::Down;
        }
        return Movement::None;
    }

    Movement RKeyboardPlayerController::getMovement() const {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            return Movement::Up;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            return Movement::Down;
        }
        return Movement::None;
    }


}