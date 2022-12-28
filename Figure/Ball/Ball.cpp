//
// Created by Mishach on 28.12.2022.
//

#include "Ball.hpp"

namespace gm {
    Ball::Ball(float positionX, float positionY) {
        xPosition = positionX;
        yPosition = positionY;
        ball = new sf::CircleShape(radiusOfBall);
        ball-> setFillColor(colour);
        ball-> setOrigin(radiusOfBall, radiusOfBall);
    }

    Ball::~Ball() {

    }

    sf::CircleShape* Ball::getBall() {
        return ball;
    }


    void Ball::setPosition(float x, float y) {
        ball->setPosition(x, y);
    }

    void Ball::moveBall(float x, float y, float speed) {
        xPosition = x;
        yPosition = y;
        setPosition(yPosition,xPosition);
    }

    float Ball::getPositionX() {
        return xPosition;
    }

    float Ball::getPositionY() {
        return yPosition;
    }


} // gm