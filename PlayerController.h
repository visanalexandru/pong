//
// Created by visan on 5/25/22.
//

#ifndef PONG_PLAYERCONTROLLER_H
#define PONG_PLAYERCONTROLLER_H

#include<SFML/Window.hpp>

namespace Pong {

    //The type of movement in the game.
    enum class Movement {
        Up,
        Down,
        None
    };

    //This class is responsible for the player input.
    class PlayerController {
    public:
        virtual Movement getMovement() const = 0;
    };

    //Reads w and s keys.
    class LKeyboardPlayerController : public PlayerController {
    public:
        Movement getMovement() const override;
    };

    //Reads up and down keys.
    class RKeyboardPlayerController : public PlayerController {
    public:
        Movement getMovement() const override;
    };

}

#endif //PONG_PLAYERCONTROLLER_H
