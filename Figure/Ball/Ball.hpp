//
// Created by Mishach on 28.12.2022.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

#pragma once

namespace gm {

    class Ball {
    public:
        Ball(float positionX, float positionY);
        ~Ball();

        ///*Function*///
        void setPosition(float x, float y);
        void moveBall(float x, float y, float speed);
        sf::CircleShape* getBall();
        float getPositionX();
        float getPositionY();
    private:
        ///*Radius of ball*///
        float radiusOfBall = 8.f;
        ///*Position of ball*///
        float xPosition;
        float yPosition;
        ///*Other*///
        sf::CircleShape* ball;
        sf::Color colour = sf::Color::Red;
    };

} // gm


