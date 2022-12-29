//
// Created by Mishach on 28.12.2022.
//

#include "Ball.hpp"

namespace gm {
    Ball::Ball(float positionX, float positionY, unsigned int xWindow, unsigned int yWindow, float radiusOfBall) {
        _xPosition = positionX;
        _yPosition = positionY;
        x_window_x = xWindow;
        y_window_y = yWindow;
        _radiusOfBall = radiusOfBall;
        ball = new sf::CircleShape(_radiusOfBall);
        ball->setFillColor(colourMainBall);
        ball->setOutlineColor(colourAccentBall);
        ball->setOrigin(_radiusOfBall, _radiusOfBall);
        ball->setPosition(_xPosition, _yPosition);
    }

    Ball::~Ball() {
        delete ball;
    }

    sf::CircleShape *Ball::getBall() {
        return ball;
    }

    sf::Vector2f createVector(float angle) {
        sf::Vector2f coords;
        coords.x = cosf(angle * acos(-1) / 180.0);
        coords.y = sinf(angle * acos(-1) / 180.0);
        return coords;
    }

    void Ball::moveBall(gm::Rectangle &firstPlayer, gm::Rectangle &secondPlayer) {
        sf::Vector2f angleVector;
        bool isCollisionSecondPlayer = ball->getGlobalBounds().intersects(
                secondPlayer.getRectangle()->getGlobalBounds());
        bool isCollisionFirstPlayer = ball->getGlobalBounds().intersects(
                firstPlayer.getRectangle()->getGlobalBounds());
        if ((_yPosition + _radiusOfBall >= y_window_y) || (_yPosition - _radiusOfBall <= 0))
            moveSpeed.y = -moveSpeed.y;
        if (((_xPosition + _radiusOfBall >= x_window_x) || (_xPosition - _radiusOfBall <= 0) ||
             (isCollisionSecondPlayer) ||
             (isCollisionFirstPlayer)) && (!checkForGoal())) {
            if ((isCollisionFirstPlayer)) {
                float angle1 = 300 + std::rand() % (360 - 299); //300 - 360// 30-150   //0 - 60
                float angle2 = 0 + std::rand() % (60 - 0 + 1);
                if (rand() % 2)
                    angleVector = createVector(angle1);
                else
                    angleVector = createVector(angle2);
            }
            if ((isCollisionSecondPlayer)) {
                float angle = 120 + std::rand() % (240 - 120 + 1);
                angleVector = createVector(angle);
            }
            moveSpeed.x = angleVector.x * _speed;
            moveSpeed.y = angleVector.y * _speed;
        }
        if (!checkForGoal()) {
            _xPosition += moveSpeed.x;
            _yPosition += moveSpeed.y;

            ball->setPosition(_xPosition, _yPosition);
        }

    }

    bool Ball::checkForGoal() {
        bool result = false;
        if ((ball->getPosition().x + _radiusOfBall >= x_window_x) || (ball->getPosition().x - _radiusOfBall<= 0))
            result = true;
        return result;
    }

    void Ball::setPositionBall(float x, float y) {
        _xPosition = x;
        _yPosition = y;
        ball->setPosition(_xPosition, _yPosition);
    }

    void Ball::setSpeed(float speed) {
        _speed = speed;
        moveSpeed = {_speed, _speed};

    }

    void Ball::setSaveSpeed() {
        savedSpeed = moveSpeed;
    }

    void Ball::getSaveSpeed(float speed) {
        _speed = 3.5;
        moveSpeed = savedSpeed;
    }

    void Ball::increaseSpeed(float k) {
        _speed *= k;
        moveSpeed.x * k;
        moveSpeed.y * k;
    }


} // gm