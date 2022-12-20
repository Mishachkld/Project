#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

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
        sf::CircleShape ball = generateBall();





        while (window.isOpen())
        {

            sf::Event event;
            rectanglePlayer1.setPosition(xPositionOfRectangle1, yPositionOfRectangle1);
            rectanglePlayer2.setPosition(xPositionOfRectangle2, yPositionOfRectangle2);
            ball.setPosition(xPositionOfBall, yPositionOfBall);
//            xOfRectangle+=1; yOfRectangle+=1;
            while (window.pollEvent(event))
                if (event.type == sf::Event::Closed)
                    window.close();

            window.clear();
            window.draw(rectanglePlayer1);
            window.draw(rectanglePlayer2);
            window.draw(ball);
            window.display();
    }}



    unsigned int Game::getCount() {
        return win_count;
    }


    void Game::changePosition(float x, float y) {
        xOfRectangle  += x;
        yOfRectangle += y;
    }

    sf::RectangleShape Game::generateRectangle() {
        sf::RectangleShape shape;
        shape.setSize(sf::Vector2f(xOfRectangle, yOfRectangle));
        shape.setFillColor(sf::Color::White);
        return shape;
    }

    sf::CircleShape Game::generateBall() {
        sf::CircleShape shape;
        shape.setRadius(radiusOfBall);
        shape.setFillColor(sf::Color::Red);
        return shape;
    }

    Game::~Game() {}


} // gm