//
// Created by Mishach on 28.12.2022.
//
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

#pragma once

namespace gm {

    class Ball {
    public:
        Ball(float positionX, float positionY);
        ~Ball();
    private:
        float radiusOfBall = 8.f;
        sf::Color colour = sf::Color::Red;
        sf::CircleShape* ball;
    };

} // gm


