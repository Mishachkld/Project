//
// Created by Mishach on 28.12.2022.
//

#include "Ball.hpp"

namespace gm {
    Ball::Ball(float positionX, float positionY, unsigned int xWindow, unsigned int yWindow) {
        _xPosition = positionX;
        _yPosition = positionY;
        window_x = xWindow;
        window_y = yWindow;
        ball = new sf::CircleShape(_radiusOfBall);
        ball->setFillColor(colour);
        ball->setOrigin(_radiusOfBall, _radiusOfBall);
        ball->setPosition(_xPosition, _yPosition);
    }

    Ball::~Ball() {
        delete ball;
    }

    sf::CircleShape *Ball::getBall() {
        return ball;
    }


    void Ball::setPosition(float &x, float &y) {
        _xPosition = x;
        _yPosition = y;
        ball->setPosition(_xPosition, _yPosition);
    }

    void Ball::moveBall(gm::Rectangle &firstPlayer, gm::Rectangle &secondPlayer) {  //        window_x = 800; window_y = 400
        float m = 24.f;
        float widthOfRectangle = 16.f;
        float highOfRectangle = 100.f;
        if ((_yPosition + _radiusOfBall >= window_y) || (_yPosition - _radiusOfBall <= 0))
            moveSpeed.y = -moveSpeed.y;
        if ((_xPosition + _radiusOfBall >= window_x) || (_xPosition  - _radiusOfBall <= 0) || (ball->getGlobalBounds().intersects(secondPlayer.getRectangle()->getGlobalBounds()))||
                (ball->getGlobalBounds().intersects(firstPlayer.getRectangle()->getGlobalBounds())))

            moveSpeed.x = -moveSpeed.x;
        _xPosition += moveSpeed.x;
        _yPosition += moveSpeed.y;
        ball->setPosition(_xPosition, _yPosition);
    }

    float Ball::getPositionX() {
        return _xPosition;
    }

    float Ball::getPositionY() {
        return _yPosition;
    }


} // gm