
#include "Game.hpp"

namespace gm {


    Game::Game(unsigned int count, unsigned int sizeWinX, unsigned int sizeWinY, std::string title) {
        _winCount = count;
        x_size_x = sizeWinX;
        y_size_y = sizeWinY;
        _title = title;
    }

    Game::~Game() {
        delete winPlayer;
        delete player1;
        delete player2;
        delete ball;
    }

    void Game::startGame() {
        ///*Костыли*///
        float countSize = y_size_y / 2 - _ySizeOfRectangle / 2;
        _xPositionOfBall = x_size_x / 2;
        _yPositionOfBall = y_size_y / 2;
        _xPositionOfRectangle2 = x_size_x - _xPositionOfRectangle1;

        sf::RenderWindow window(sf::VideoMode(x_size_x, y_size_y), _title);
        player1 = new gm::Rectangle(_xPositionOfRectangle1, _yPositionOfRectangle1, y_size_y, 1,
                                    sf::Vector2f(_xSizeOfRectangle, _ySizeOfRectangle));
        player2 = new gm::Rectangle(_xPositionOfRectangle2, _yPositionOfRectangle2, y_size_y, 2,
                                    sf::Vector2f(_xSizeOfRectangle, _ySizeOfRectangle));
        ball = new gm::Ball(_xPositionOfBall, _yPositionOfBall, x_size_x, y_size_y, _radiusOfBall);
        player1->setPosition(_xPositionOfRectangle1, countSize);
        player2->setPosition(_xPositionOfRectangle2, countSize);
        player2->getRectangle()->setOrigin(_xSizeOfRectangle, 0);

        while (window.isOpen()) {
            sf::Event event;
            bool isEnd = checkForEnd();
            if (!isEnd) {
                player1->moveRectangle();
                player2->moveRectangle();
                ball->moveBall(player1, player2);
                if (checkForGoal(ball->getBall()->getPosition().x)) {
                    if (checkForGoalFirstPlayer(ball->getBall()->getPosition().x))
                        generateCounter(40 * scoreFirstPlayer, 1);
                    else
                        generateCounter(40 * scoreSecondPlayer, 2);
                    ball->setSaveSpeed();
                    ball->setPositionBall(_xPositionOfBall, _yPositionOfBall);
                    ball->setSpeed(0);


                }
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed)
                        window.close();
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                        ball->getSaveSpeed(3.5f);

                }
                window.clear();
                window.draw(*player1->getRectangle());
                window.draw(*player2->getRectangle());
                window.draw(*ball->getBall());
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            } else {
                endActivity(event, window);
            }
        }
    }


    bool Game::checkForGoal(float ballPostionX) {
        bool result = false;
        if (ballPostionX >= x_size_x - _xSizeOfRectangle) {
            result = true;
            scoreFirstPlayer += 1;
        }
        if ((ballPostionX <= _xSizeOfRectangle)) {
            result = true;
            scoreSecondPlayer += 1;
        }
        return result;
    }

    bool Game::checkForEnd() {
        bool result = false;
        if ((scoreFirstPlayer >= _winCount)) {
            numberOfWinPlayer = 1;
            result = true;
        } else if ((scoreSecondPlayer >= _winCount)) {
            numberOfWinPlayer = 2;
            result = true;
        }
        return result;
    }

    void Game::endActivity(sf::Event &event, sf::RenderWindow &window) {
        window.clear();    ///не хочет шрифты подргружать:(
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
            winPlayer->setPositionOfCounter(x_size_x / 4 - _sizeOfCounter, y_size_y / 2 - _sizeOfCounter);
        else
            winPlayer->setPositionOfCounter(x_size_x * 3 / 4 - _sizeOfCounter, y_size_y / 2 - _sizeOfCounter);
        window.draw(*winPlayer->getCounter());
        window.display();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                window.close();
            }

        }
    }

    void Game::generateCounter(float x, int player) {   /// 20 * 18
        gm::Counter counter(player, x, 16);


    }

    bool Game::checkForGoalFirstPlayer(float x) {
        if (x >= x_size_x - _xSizeOfRectangle)
            return true;
        return false;
    }


} // gm