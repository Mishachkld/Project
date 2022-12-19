#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.hpp"

namespace gm {


    void Game::delay() {
        sf::sleep(sf::milliseconds(10));
    }

    Game::Game() {
        startGame();
    }

    void Game::getSettings() {

    }

    void Game::startGame() {
        sf::RenderWindow window(sf::VideoMode(640, 480), "Project for BFU");
        sf::CircleShape shape;

        shape.setRadius(radius);
        shape.setPosition(320.f, 240.f);
        shape.setPosition(111.f, 222.f);
        shape.setFillColor(sf::Color::White);

        while (window.isOpen())
        {

            sf::Event event;
            shape.setPosition(xOfShape, yOfShape);
            myTread.launch();
            xOfShape+=1; yOfShape+=1;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                window.clear();
                window.draw(shape);
                window.display();
            }
    }}







    Game::~Game() {}






} // gm