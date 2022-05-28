//
// Created by visan on 5/25/22.
//

#include "GameScreen.h"

namespace Pong {
    GameScreen *GameScreen::screen = nullptr;

    GameScreen::GameScreen() : sf::RenderWindow(sf::VideoMode(SCREEN_SIZE_X, SCREEN_SIZE_Y), "Pong") {

    }

    GameScreen *GameScreen::getScreen() {
        if (screen == nullptr) {
            screen = new GameScreen;
        }
        return screen;
    }

}
