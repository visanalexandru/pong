//
// Created by visan on 5/27/22.
//

#ifndef PONG_AICONTROLLER_H
#define PONG_AICONTROLLER_H

#include"PlayerController.h"
#include"Ball.h"
#include"Player.h"

namespace Pong {
    class AIController : public PlayerController {
    private:
        Player &player;
        Ball &ball;
        //The maximum distance to the ball before the machine reacts.
        float view_distance;
    public:
        AIController(Player &p, Ball &b, float view_dist);

        Movement getMovement() const override;
    };
}


#endif //PONG_AICONTROLLER_H
