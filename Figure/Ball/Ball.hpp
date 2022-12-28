//
// Created by Mishach on 28.12.2022.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Rectnagle/Rectangle.hpp"


#pragma once

namespace gm {

    class Ball {
    public:
        Ball(float positionX, float positionY, unsigned int xWindow, unsigned int yWindow);
        ~Ball();

        ///*Function*///
        void setPosition(float &x, float &y);
        void moveBall(gm::Rectangle &firstPlayer, gm::Rectangle &secondPlayer);
        sf::CircleShape* getBall();
        float getPositionX();
        float getPositionY();
    private:
        ///*Radius of ball*///
        float _radiusOfBall = 8.f;

        ///*Position of ball*///
        float _xPosition;
        float _yPosition;
        float _speed = 1;
        unsigned int window_x;
        unsigned int window_y;
        sf::Vector2f moveSpeed = {_speed, _speed};

        ///*Other*///
        sf::CircleShape* ball;
        sf::Color colour = sf::Color::Red;
    };

} // gm

