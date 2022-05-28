//
// Created by visan on 5/25/22.
//

#include "PlayState.h"


namespace Pong {
    PlayState::PlayState(PlayMode mode) : a(PLAYER_SPEED), b(PLAYER_SPEED), ball(BALL_SPEED, sf::Vector2f(0, 0)) {
        a.setPosition(sf::Vector2f(PLAYER_SIZE_X / 2, SCREEN_SIZE_Y / 2.0f));
        b.setPosition(sf::Vector2f(SCREEN_SIZE_X - PLAYER_SIZE_X / 2, SCREEN_SIZE_Y / 2.0f));
        if (mode == PlayMode::PlayerVsPlayer) {
            a.setController(std::make_shared<LKeyboardPlayerController>());
            b.setController(std::make_shared<RKeyboardPlayerController>());
        } else {
            int left_or_right = randomNumber(1, 2);
            if (left_or_right == 1) {
                std::shared_ptr<PlayerController> ai = std::make_shared<AIController>(b, ball, 300.f);
                a.setController(std::make_shared<LKeyboardPlayerController>());
                b.setController(ai);
            } else {
                std::shared_ptr<PlayerController> ai = std::make_shared<AIController>(a, ball, 300.f);
                a.setController(ai);
                b.setController(std::make_shared<RKeyboardPlayerController>());
            }
        }

        reset();
    }

    void PlayState::reset() {
        ball.setSpeed(BALL_SPEED);
        ball.setPosition(sf::Vector2f(SCREEN_SIZE_X / 2.0f, SCREEN_SIZE_Y / 2.0f));
        float y_speed = randomFloat(-1.0, 1.0);
        if (a.getScore() > b.getScore()) {
            ball.setDirection(normalize(sf::Vector2f(1, y_speed)));
        } else {
            ball.setDirection(normalize(sf::Vector2f(-1, y_speed)));
        }
    }

    void PlayState::collisions() {
        sf::Vector2f ball_pos = ball.getPosition();
        sf::Vector2f ball_dir = ball.getDirection();
        sf::Vector2f left_player_pos = a.getPosition(), right_player_pos = b.getPosition();
        if (ball_pos.y - BALL_RADIUS <= 0) {
            ball_pos.y = BALL_RADIUS;
            ball_dir.y = -ball_dir.y;
        }

        if (ball_pos.y + BALL_RADIUS >= SCREEN_SIZE_Y) {
            ball_pos.y = SCREEN_SIZE_Y - BALL_RADIUS;
            ball_dir.y = -ball_dir.y;
        }

        ball.setDirection(ball_dir);
        ball.setPosition(ball_pos);

        if (ball_pos.x - BALL_RADIUS <= PLAYER_SIZE_X) {
            if (ball_pos.y >= left_player_pos.y - PLAYER_SIZE_Y / 2 - BALL_RADIUS &&
                ball_pos.y <= left_player_pos.y + PLAYER_SIZE_Y / 2 + BALL_RADIUS) {
                ball_pos.x = PLAYER_SIZE_X + BALL_RADIUS;
                ball_dir.x = -ball_dir.x;
                ball.setDirection(ball_dir);
                ball.setPosition(ball_pos);
                ball.setSpeed(ball.getSpeed() * BALL_ACCELERATION);
            } else {
                b.setScore(b.getScore() + 1);
                reset();
            }
        }

        if (ball_pos.x + BALL_RADIUS >= SCREEN_SIZE_X - PLAYER_SIZE_X) {
            if (ball_pos.y >= right_player_pos.y - PLAYER_SIZE_Y / 2 - BALL_RADIUS &&
                ball_pos.y <= right_player_pos.y + PLAYER_SIZE_Y / 2 + BALL_RADIUS) {
                ball_pos.x = SCREEN_SIZE_X - PLAYER_SIZE_X - BALL_RADIUS;
                ball_dir.x = -ball_dir.x;
                ball.setDirection(ball_dir);
                ball.setPosition(ball_pos);
                ball.setSpeed(ball.getSpeed() * BALL_ACCELERATION);
            } else {
                a.setScore(a.getScore() + 1);
                reset();
            }
        }


    }

    void PlayState::start() {
        GameScreen *screen = GameScreen::getScreen();
        screen->setVerticalSyncEnabled(true);
        sf::Clock delta_clock;
        sf::Text score_a, score_b;
        score_a.setCharacterSize(FONT_SIZE);
        score_b.setCharacterSize(FONT_SIZE);
        score_a.setPosition(SCREEN_SIZE_X / 4.f, FONT_SIZE);
        score_b.setPosition(3 * SCREEN_SIZE_X / 4.f, FONT_SIZE);
        sf::Font font;
        if (!font.loadFromFile("resources/arial.ttf")) {
            std::cerr << "Cannot find font: resources/arial.ttf" << std::endl;
            return;
        }
        score_a.setFont(font);
        score_b.setFont(font);


        while (screen->isOpen() && a.getScore() + b.getScore() < 5) {
            sf::Event event;
            while (screen->pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    screen->close();
            }

            sf::Time dt = delta_clock.restart();
            a.update(dt.asSeconds());
            b.update(dt.asSeconds());
            ball.updatePosition(dt.asSeconds());
            collisions();
            score_a.setString(std::to_string(a.getScore()));
            score_b.setString(std::to_string(b.getScore()));

            // clear the window with black color
            screen->clear(sf::Color::Black);
            screen->draw(a);
            screen->draw(b);
            screen->draw(ball);
            screen->draw(score_a);
            screen->draw(score_b);
            screen->display();
        }
    }
}
