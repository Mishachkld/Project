#include <SFML/Graphics/RectangleShape.hpp>
#pragma once
namespace gm {
    class Rectangle {
    public:
            Rectangle(float xOfRectangle, float yOfRectangle, int numberOfPlayer);
            ~Rectangle();
            ///*Functions*///
            void moveRectangle(float x);
            void setPosition(float x, float y);
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
        int numberPlayer;
        ///*Other*///
        sf::RectangleShape* player;
        sf::Color color = sf::Color::White;

    };

}

