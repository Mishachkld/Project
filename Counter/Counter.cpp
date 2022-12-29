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
//        font.loadFromFile("arial.ttf");
//        text = new sf::Text(std::to_string(count),font ,48);
//        text->setString(std::to_string(count));
//        text->setFillColor(textColor);





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

    void Counter::loadFont() {

        if (!font.loadFromFile(FILE_PATH))
        {
            std::cout << "Errrorrrrrrrrrrrrrrrr...";

        }
    }

    sf::Text* Counter::getElementText() {
        return text;
    }

} // gm