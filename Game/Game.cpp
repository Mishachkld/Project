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
        sf::RectangleShape rectanglePlayer1 = generateRectangle();
        sf::RectangleShape rectanglePlayer2 = generateRectangle();
        rectanglePlayer2.setOrigin(xSizeOfRectangle, 0);
        sf::CircleShape ball = generateBall();
        ball.setOrigin(radiusOfBall, radiusOfBall);


        while (window.isOpen()){

            sf::Event event;
            rectanglePlayer1.setPosition(xPositionOfRectangle1, y_size/2 - ySizeOfRectangle / 2); // использовать creatVector
            rectanglePlayer2.setPosition(xPositionOfRectangle2, y_size/2 - ySizeOfRectangle / 2);
            ball.setPosition(xPositionOfBall, yPositionOfBall);
//            xSizeOfRectangle+=1; ySizeOfRectangle+=1;
            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    window.close();
            window.clear();
            window.draw(rectanglePlayer1);
            window.draw(rectanglePlayer2);
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

    sf::RectangleShape Game::generateRectangle() {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(xSizeOfRectangle, ySizeOfRectangle));
        shape.setFillColor(sf::Color::White);
        return shape;
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