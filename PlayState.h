//
// Created by visan on 5/25/22.
//

#ifndef PONG_PLAYSTATE_H
#define PONG_PLAYSTATE_H

#include"State.h"
#include"GameScreen.h"
#include"Player.h"
#include"AIController.h"
#include"Ball.h"
#include<iostream>
#include<thread>

namespace Pong {
    enum class PlayMode {
        PlayerVsPlayer,
        PlayerVsMachine
    };

    class PlayState : public State {
    private:
        Player a, b;

        Ball ball;

        //Process the collisions.
        void collisions();

        //Resets the ball into position.
        void reset();

    public:
        explicit PlayState(PlayMode mode = PlayMode::PlayerVsPlayer);

        void start() override;
    };
}


#endif //PONG_PLAYSTATE_H
