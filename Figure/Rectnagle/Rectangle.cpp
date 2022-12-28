#include "Rectangle.hpp"

namespace gm {


    Rectangle::Rectangle(float xOfRectangle, float yOfRectangle, int numberOfPlayer) {
        xPosition = xOfRectangle;
        yPosition = yOfRectangle;
        numberPlayer = numberOfPlayer;
        player = new sf::RectangleShape(sf::Vector2f(xSizeOfRectangle, ySizeOfRectangle));
        player->setFillColor(color);

    }

    Rectangle::~Rectangle() {
        delete player;
    }

    void Rectangle::moveRectangle(float y) {
        yPosition = y;
        setPosition(xPosition,yPosition);
    }

    sf::RectangleShape* Rectangle::getRectangle() {
        return player;
    }

    void Rectangle::setPosition(float x, float y) {
        player->setPosition(x, y);
    }

    float Rectangle::getPositionY() {
        return yPosition;
    }

    float Rectangle::getPositionX() {
        return xPosition;
    }




}