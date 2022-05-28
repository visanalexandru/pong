cmake_minimum_required(VERSION 3.15)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp State.h GameScreen.cpp GameScreen.h PlayState.cpp PlayState.h PlayerController.h PlayerController.cpp Player.cpp Player.h Util.h Ball.cpp Ball.h AIController.cpp AIController.h)
target_link_libraries(Pong sfml-system sfml-graphics sfml-window)
