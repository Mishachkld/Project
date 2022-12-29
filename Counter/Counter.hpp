#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace gm {

    class Counter {
    public:
        Counter(int count, float sizeX, float sizeY);
        ~Counter();
        sf::RectangleShape* getCounter();
        void setPositionOfCounter(float x, float y);

    private:

       ///*Position*///
       float _xPosition = 0.f;
       float _yPosition = 0.f;

        ///*Custom*///
        sf::Color color = sf::Color::White;
        float _xSzie = 48;
        float _ySzie = 48;

        ///*Other*///
        int _count = 0;
        sf::RectangleShape* counter;
        sf::Text* text;
        sf::Font font = sf::Font();

    };

}

