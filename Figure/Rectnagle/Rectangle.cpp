#include "Rectangle.hpp"

namespace gm {


    Rectangle::Rectangle(float xOfRectangle, float yOfRectangle, int ySizeOfWindow, int numberOfPlayer) {
        xPosition = xOfRectangle;
        yPosition = yOfRectangle;
        numberPlayer = numberOfPlayer;
        sizeOfWindow = ySizeOfWindow;
        player = new sf::RectangleShape(sf::Vector2f(xSizeOfRectangle, ySizeOfRectangle));
        player->setFillColor(color);
    }

    Rectangle::~Rectangle() {
        delete player;
    }

    void Rectangle::moveRectangle() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and (numberPlayer == 1) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and (numberPlayer == 2)) {
            yPosition -= speed;
            setPosition(xPosition, yPosition);
        }
        if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) and (numberPlayer == 1) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and (numberPlayer == 2)))) and ()){
            yPosition += speed;
            setPosition(xPosition, yPosition);
        }
    }

    sf::RectangleShape *Rectangle::getRectangle() {
        return player;
    }

    void Rectangle::setPosition(float &x, float &y) {
        xPosition = x;
        yPosition = y;
        player->setPosition(xPosition, yPosition);
    }

    float Rectangle::getPositionY() {
        return yPosition;
    }

    float Rectangle::getPositionX() {
        return xPosition;
    }


}