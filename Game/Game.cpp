
#include "Game.hpp"

namespace gm {


    Game::Game(unsigned int count, unsigned int sizeWinX, unsigned int sizeWinY, std::string title) {
        win_count = count;
        x_size = sizeWinX;
        y_size = sizeWinY;
        _title = title;

    }

    void Game::startGame() {
        float countSize = y_size / 2 - ySizeOfRectangle / 2;
        sf::RenderWindow window(sf::VideoMode(x_size, y_size), _title);
        gm::Rectangle player1(xPositionOfRectangle1, yPositionOfRectangle1, y_size, 1);
        gm::Rectangle player2(xPositionOfRectangle2, yPositionOfRectangle2, y_size, 2);
        gm::Ball ball(xPositionOfBall, yPositionOfBall, x_size, y_size);
        player1.setPosition(xPositionOfRectangle1, countSize); // использовать creatVector
        player2.setPosition(xPositionOfRectangle2, countSize);
        player2.getRectangle()->setOrigin(xSizeOfRectangle, 0);
        while (window.isOpen()) {
            sf::Event event;
            bool isEnd = checkForEnd();
            if (!isEnd) {
                player1.moveRectangle();
                player2.moveRectangle();
                ball.moveBall(player1, player2);
                if (checkForGoal(ball.getBall()->getPosition().x)) {
                    ball.setPositionBall(xPositionOfBall, yPositionOfBall);
                    ball.setSpeed(0);
                }
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        ball.setSpeed(3.5f);

                }
                window.clear();
                window.draw(*player1.getRectangle());
                window.draw(*player2.getRectangle());
                window.draw(*ball.getBall());
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            } else {
                endActivity(event, window);
            }
        }



    }


    unsigned int Game::getCount() {
        return win_count;
    }


    void Game::settings() {

    }

    Game::~Game() {
        delete winPlayer;
    }

    bool Game::checkForGoal(float ballPostionX) {
        bool result = false;
        if (ballPostionX >= x_size - xSizeOfRectangle) {
            result = true;
            countFirstPlayer += 1;
        }
        if ((ballPostionX <= xSizeOfRectangle)) {
            result = true;
            countSecondPlayer += 1;
        }
        return result;
    }

    bool Game::checkForEnd() {
        bool result = false;
        if ((countFirstPlayer >= win_count)){
            numberOfWinPlayer = 1;
            result = true;
        } else if((countSecondPlayer >= win_count)){
            numberOfWinPlayer = 2;
            result = true;
        }
        return result;
    }

    void Game::endActivity(sf::Event &event, sf::RenderWindow &window) {
        window.clear();
/*        sf::Font font;
        sf::Text Count;
        font.loadFromFile("arial.ttf");
        Count.setFont(font);
        Count.setString(std::to_string(42));
        Count.setColor(sf::Color::White);
        Count.setStyle(sf::Text::Bold);
        Count.setCharacterSize(50);
        Count.setPosition(500, 500);*/
        winPlayer = new gm::Counter(numberOfWinPlayer, _sizeOfCounter, _sizeOfCounter);
        if (numberOfWinPlayer == 1)
            winPlayer->setPositionOfCounter(x_size / 4 - _sizeOfCounter, y_size / 2 -_sizeOfCounter );
        else
            winPlayer->setPositionOfCounter(x_size * 3/4 - _sizeOfCounter, y_size / 2  - _sizeOfCounter);
        window.draw(*winPlayer->getCounter());
        window.display();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                window.close();
            }

        }

    }
} // gm