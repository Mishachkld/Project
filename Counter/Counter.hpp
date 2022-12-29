#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

namespace gm {

    class Counter {
    public:
        Counter(int count, float sizeX, float sizeY);
        ~Counter();
        ///*Functions*///
        sf::RectangleShape* getCounter();
        void setPositionOfCounter(float x, float y);
        sf::Text* getElementText();

    private:
       ///*Position*///
       float _xPosition = 0.f;
       float _yPosition = 0.f;

        ///*Custom*///
        sf::Color color = sf::Color::Magenta;
        sf::Color textColor = sf::Color::Black;
        float _xSize = 48;
        float _ySize = 48;

        ///*Other*///
        int _count = 0;
        sf::RectangleShape* counter;
        sf::Text* text;
        sf::Font font;
        std::string FILE_PATH = "arial.ttf";

        ///*Functions*///
        void loadFont();


    };

}

