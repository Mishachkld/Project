//
// Created by Mishach on 28.12.2022.
//

#include <iostream>
#include <cmath>
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

    sf::Vector2f create_vector(float angle) {
        sf::Vector2f coords;
        coords.x = cosf(angle * acos(-1) / 180.0);
        coords.y = sinf(angle * acos(-1) / 180.0);
        return coords;
    }

    void
    Ball::moveBall(gm::Rectangle &firstPlayer, gm::Rectangle &secondPlayer) {
        sf::Vector2f m_temp;
        bool isCollisionFirstPlayer = ball->getGlobalBounds().intersects(
                secondPlayer.getRectangle()->getGlobalBounds());
        bool isCollisionSecondPlayer = ball->getGlobalBounds().intersects(
                firstPlayer.getRectangle()->getGlobalBounds());
        if ((_yPosition + _radiusOfBall >= window_y) || (_yPosition - _radiusOfBall <= 0))
            moveSpeed.y = -moveSpeed.y;
        if (((_xPosition + _radiusOfBall >= window_x) || (_xPosition - _radiusOfBall <= 0) ||
             (isCollisionFirstPlayer) ||
             (isCollisionSecondPlayer)) && (!checkForGoal())) {
            if ((isCollisionSecondPlayer)) {
                float angle1 = 300 + std::rand() % (360 - 299); // a - min b - max  30-150   //300 - 360// a - min b - max  30-150   //0 - 60
                float angle2 = 0 + std::rand() % (60 - 0 + 1);
                if (rand() % 2)
                     m_temp = create_vector(angle1);
                else
                    m_temp = create_vector(angle2);
//                moveSpeed.x = -moveSpeed.x;
            }
            if ((isCollisionFirstPlayer)) {/// min 120 max 240
                float angle = 120 + std::rand() % (240 - 120 + 1);
                 m_temp = create_vector(angle);
            }
            moveSpeed.x = m_temp.x * _speed;
            moveSpeed.y = m_temp.y * _speed;
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