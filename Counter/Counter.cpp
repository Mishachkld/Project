//
// Created by Mishach on 19.12.2022.
//

#include "Counter.hpp"


namespace gm {


    Counter::Counter(int count, float sizeX, float sizeY) {
        _count = count;
        _xSzie = sizeX;
        _ySzie = sizeY;
        counter = new sf::RectangleShape(sf::Vector2f(_xSzie, _ySzie));
        counter->setFillColor(color);
        text = new sf::Text(std::to_string(count), font);
        text->setString(std::to_string(count));
        text->setCharacterSize(24);

    }

    sf::RectangleShape *Counter::getCounter() {
        return counter;
    }

    void Counter::setPositionOfCounter(float x, float y) {
        _xPosition = x;
        _yPosition = y;
        counter->setPosition(_xPosition, _yPosition);
    }

    Counter::~Counter() {
        delete counter;
    }

} // gm