//
// Created by Mishach on 28.12.2022.
//

#include "Ball.hpp"

namespace gm {
    Ball::Ball(float positionX, float positionY) {
        xPosition = positionX;
        yPosition = positionY;
        ball = new sf::CircleShape();
        ball->setRadius(radiusOfBall);
        ball-> setFillColor(colour);
    }

    Ball::~Ball() {

    }

    sf::CircleShape Ball::getBall() {
        return sf::CircleShape();
    }

    float Ball::getPositionX() {
        return 0;
    }

    float Ball::getPositionY() {
        return 0;
    }
} // gm