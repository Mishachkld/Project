#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#pragma once
namespace gm {
    class Rectangle {
    public:
            Rectangle(float xOfRectangle, float yOfRectangle, int ySizeOfWindow, int numberOfPlayer);
            ~Rectangle();
            ///*Functions*///
            void moveRectangle();
            void setPosition(float &x, float &y);
            sf::RectangleShape* getRectangle();
            float getPositionY();
            float getPositionX();
    private:
        ///*Size of rectangle*///
        float xSizeOfRectangle = 16.f;
        float ySizeOfRectangle = 100.f;

        ///*Position of rectangle*///
        float xPosition;
        float yPosition;
        int sizeOfWindow;
        int numberPlayer;

        ///*Other*///
        float speed = 3.5;
        sf::RectangleShape* player;
        sf::Color color = sf::Color::White;

    };

}

