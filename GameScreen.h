//
// Created by visan on 5/25/22.
//

#ifndef PONG_GAMESCREEN_H
#define PONG_GAMESCREEN_H

#include<SFML/Graphics.hpp>
#include"Util.h"

namespace Pong {

    class GameScreen : public sf::RenderWindow {
    private:
        static GameScreen *screen;

        GameScreen();

    public:
        //Returns a pointer to the main screen.
        static GameScreen *getScreen();
    };

}


#endif //PONG_GAMESCREEN_H
