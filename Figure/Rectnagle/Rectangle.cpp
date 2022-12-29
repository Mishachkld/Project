#include "Rectangle.hpp"

namespace gm {


    Rectangle::Rectangle(float xOfRectangle, float yOfRectangle, int ySizeOfWindow, int numberOfPlayer,  sf::Vector2f sizeRectangle) {
        _xPosition = xOfRectangle;
        _yPosition = yOfRectangle;
        _numberPlayer = numberOfPlayer;
        _ySizeOfWindow = ySizeOfWindow;
        _xSizeOfRectangle = sizeRectangle.x;
        _ySizeOfRectangle = sizeRectangle.y;
        player = new sf::RectangleShape(sf::Vector2f(_xSizeOfRectangle, _ySizeOfRectangle));
        player->setFillColor(color);
    }

    Rectangle::~Rectangle() {
        delete player;
    }

    void Rectangle::moveRectangle() {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) and (_numberPlayer == 1) ||
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and (_numberPlayer == 2)) and (_yPosition > 0)){
            _yPosition -= _speed;
            setPosition(_xPosition, _yPosition);
        }
        if (((sf::Keyboard::isKeyPressed(sf::Keyboard::S) and (_numberPlayer == 1) ||
              (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and (_numberPlayer == 2)))) and (_ySizeOfWindow > (_yPosition + _ySizeOfRectangle))){
            _yPosition += _speed;
            setPosition(_xPosition, _yPosition);
        }
    }

    sf::RectangleShape *Rectangle::getRectangle() {
        return player;
    }

    void Rectangle::setPosition(float &x, float &y) {
        _xPosition = x;
        _yPosition = y;
        player->setPosition(_xPosition, _yPosition);
    }

}