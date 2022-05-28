//
// Created by visan on 5/25/22.
//

#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

#include<SFML/Graphics.hpp>
#include<memory>
#include"PlayerController.h"
#include"Util.h"

namespace Pong {

    //This class holds the player data.
    class Player : public sf::RectangleShape {
    private:
        //The player controller that moves this player.
        std::shared_ptr<PlayerController> controller;

        //The speed of the player.
        float speed;

        //The score of the player.
        unsigned score;
    public:
        explicit Player(float player_speed);

        void setController(const std::shared_ptr<PlayerController> &new_controller);

        const std::shared_ptr<PlayerController> &getController();

        //Updates the player based on the player controller.
        void update(float delta_time);

        unsigned getScore() const;

        void setScore(unsigned new_score);
    };

}


#endif //PONG_PLAYER_H
