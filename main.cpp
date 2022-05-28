#include <iostream>
#include"PlayState.h"


int main() {
    srand(time(NULL));
    int choice = 0;
    while (choice < 1 || choice > 2) {
        std::cout << "1) Player vs Machine" << std::endl;
        std::cout << "2) Player vs Player" << std::endl;
        std::cin >> choice;
    }
    Pong::PlayMode mode = (choice == 1) ? Pong::PlayMode::PlayerVsMachine : Pong::PlayMode::PlayerVsPlayer;
    Pong::PlayState(mode).start();
    return 0;
}
