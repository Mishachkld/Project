//
// Created by Mishach on 28.12.2022.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../Rectnagle/Rectangle.hpp"
#include <cmath>
#include <iostream>


#pragma once

namespace gm {

    class Ball {
    public:
        Ball(float positionX, float positionY, unsigned int xWindow, unsigned int yWindow, float radiusOfBall);
        ~Ball();

        ///*Functions*///
        void moveBall(gm::Rectangle *firstPlayer, gm::Rectangle *secondPlayer);
        sf::CircleShape* getBall();
        void setPositionBall(float x, float y);
        void setSpeed(float speed);
        void setSaveSpeed();
        void getSaveSpeed();
        void increaseSpeed(float l);

    private:
        ///*Radius of ball*///
        float _radiusOfBall = 8.f;

        ///*Position of ball*///
        float _xPosition;
        float _yPosition;
        float _speed = 3.5f;
        unsigned int x_window_x;
        unsigned int y_window_y;
        sf::Vector2f moveSpeed = {_speed, _speed};
        sf::Vector2f savedSpeed = {_speed, _speed};

        ///*Other*///
        sf::CircleShape* ball;
        sf::Color colourMainBall = sf::Color::Yellow;
        sf::Color colourAccentBall = sf::Color::Red;

        ///*Functions*///
        bool checkForGoal();
    };

} // gm


