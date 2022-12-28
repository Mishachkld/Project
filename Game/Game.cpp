#include "Game.hpp"

namespace gm {



    Game::Game(unsigned int count) {
        win_count = count;
        startGame();
    }

    void Game::getSettings() {

    }

    void Game::startGame() {
        sf::RenderWindow window(sf::VideoMode(x_size, y_size), "Project for BFU");
        gm::Rectangle player1(xPositionOfRectangle1, yPositionOfRectangle1, 1);
        gm::Rectangle player2(xPositionOfRectangle2, yPositionOfRectangle2, 2);
//        player2.setOrigin(xSizeOfRectangle, 0);
        gm::Ball ball;
        ball.setOrigin(radiusOfBall, radiusOfBall);


        while (window.isOpen()){

            sf::Event event;
            player1.setPosition(xPositionOfRectangle1, y_size / 2 - ySizeOfRectangle / 2); // использовать creatVector
            player2.setPosition(xPositionOfRectangle2, y_size / 2 - ySizeOfRectangle / 2);
            ball.setPosition(xPositionOfBall, yPositionOfBall);
//            xSizeOfRectangle+=1; ySizeOfRectangle+=1;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
//                if (event.type == sf::Event::KeyPressed)
//                    window.close();
            }
            window.clear();
            window.draw(*player1.getRectangle());
            window.draw(*player2.getRectangle());
            window.draw(ball);
            window.display();
        }
    }



    unsigned int Game::getCount() {
        return win_count;
    }


    void Game::changePosition(float x, float y) {
        xSizeOfRectangle  += x;
        ySizeOfRectangle += y;
    }


    sf::CircleShape Game::generateBall() {
        sf::CircleShape shape;
        shape.setRadius(radiusOfBall);
        shape.setFillColor(sf::Color::Red);
        return shape;
    }



    void Game::update() {

    }

    void Game::render() {

    }

    Game::~Game() {}
} // gm