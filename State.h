//
// Created by visan on 5/25/22.
//

#ifndef PONG_STATE_H
#define PONG_STATE_H

namespace Pong {
    class State {
    public:
        //Run the state.
        virtual void start() = 0;
    };
}
#endif //PONG_STATE_H
