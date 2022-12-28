
#include "Game.hpp"

namespace gm {



    Game::Game(unsigned int count) {
        win_count = count;
        startGame();

    }

    void Game::startGame() {
        float countSize = y_size / 2 - ySizeOfRectangle / 2;
        sf::RenderWindow window(sf::VideoMode(x_size, y_size), "Project for BFU");
        gm::Rectangle player1(xPositionOfRectangle1, yPositionOfRectangle1,y_size, 1);
        gm::Rectangle player2(xPositionOfRectangle2, yPositionOfRectangle2, y_size, 2);
        gm::Ball ball(xPositionOfBall, yPositionOfBall);
        player1.setPosition(xPositionOfRectangle1, countSize); // использовать creatVector
        player2.setPosition(xPositionOfRectangle2, countSize);
        player2.getRectangle()->setOrigin(xSizeOfRectangle, 0);
        ball.setPosition(xPositionOfBall, yPositionOfBall);

        while (window.isOpen()){
            sf::Event event;
            player1.moveRectangle();
            player2.moveRectangle();
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
//               if (event.type == sf::Event::KeyPressed)
            }
            window.clear();
            window.draw(*player1.getRectangle());
            window.draw(*player2.getRectangle());
            window.draw(*ball.getBall());
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }



    unsigned int Game::getCount() {
        return win_count;
    }



    void Game::render() {

    }

    Game::~Game() {}
} // gm