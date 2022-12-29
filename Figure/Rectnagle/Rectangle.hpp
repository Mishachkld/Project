#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#pragma once
namespace gm {
    class Rectangle {
    public:
            Rectangle(float xOfRectangle, float yOfRectangle, int ySizeOfWindow, int numberOfPlayer, sf::Vector2f sizeRectangle);
            ~Rectangle();
            ///*Functions*///
            void moveRectangle();
            void setPosition(float &x, float &y);
            sf::RectangleShape* getRectangle();

    private:
        ///*Size of rectangle*///
        float _xSizeOfRectangle = 16.f;
        float _ySizeOfRectangle = 100.f;

        ///*Position of rectangle*///
        float _xPosition;
        float _yPosition;
        int _ySizeOfWindow;
        int _numberPlayer;

        ///*Other*///
        float _speed = 3.5;
        sf::RectangleShape* player;
        sf::Color color = sf::Color::White;

    };

}

