//
// Created by visan on 5/27/22.
//

#include "AIController.h"

namespace Pong {
    AIController::AIController(Player &p, Ball &b, float view_dist) : player(p), ball(b), view_distance(view_dist) {

    }

    Movement AIController::getMovement() const {
        float distance = (ball.getPosition().x - player.getPosition().x);
        if (distance < 0)
            distance *= -1;

        if (distance < view_distance) {
            if (player.getPosition().y + PLAYER_SIZE_Y / 2.0 < ball.getPosition().y) {
                return Movement::Down;
            } else if (player.getPosition().y - PLAYER_SIZE_Y / 2.0 > ball.getPosition().y) {
                return Movement::Up;
            }
        }

        return Movement::None;
    }
}

