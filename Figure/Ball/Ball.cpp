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
        ball->setRotation(180.f);
    }

    Ball::~Ball() {
        delete ball;
    }

    sf::CircleShape *Ball::getBall() {
        return ball;
    }

    void
    Ball::moveBall(gm::Rectangle &firstPlayer, gm::Rectangle &secondPlayer) {  //        window_x = 800; window_y = 400
        bool isCollisionFirstPlayer = ball->getGlobalBounds().intersects(
                secondPlayer.getRectangle()->getGlobalBounds());
        bool isCollisionSecondPlayer = ball->getGlobalBounds().intersects(
        firstPlayer.getRectangle()->getGlobalBounds());
        if ((_yPosition + _radiusOfBall >= window_y) || (_yPosition - _radiusOfBall <= 0))
            moveSpeed.y = -moveSpeed.y;
        if (((_xPosition + _radiusOfBall >= window_x) || (_xPosition - _radiusOfBall <= 0) || (isCollisionFirstPlayer) ||
            (isCollisionSecondPlayer)) && (!checkForGoal())) {
            moveSpeed.x = -moveSpeed.x;
        }
        if (!checkForGoal()) {
            _xPosition += moveSpeed.x;//* generateRandomAngle();
            _yPosition += moveSpeed.y;//* generateRandomAngle();
            ball->setPosition(_xPosition, _yPosition);
        }

    }

    float Ball::getPositionX() {
        return _xPosition;
    }

    float Ball::getPositionY() {
        return _yPosition;
    }

    float Ball::generateRandomAngle() {
        int low = 20;
        int high = 150;
        float r = low + static_cast <float> (rand()) / high + static_cast <float> (RAND_MAX);
        return r;
    }

    bool Ball::checkForGoal() {
        bool result = false;
        if ((ball->getPosition().x >= window_x - 16.f) || (ball->getPosition().x <= 16.f))
            result = true;
        return result;
    }

    void Ball::setPositionBall(float x, float y) {
        _xPosition = x;
        _yPosition = y;
        ball->setPosition(_xPosition, _yPosition);
    }


} // gm