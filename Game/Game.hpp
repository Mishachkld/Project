#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#pragma once
namespace gm {
    class Game {
    public:
        Game(unsigned int count);
        unsigned int getCount();
        void changePosition(float x, float y);
        sf::RectangleShape generateRectangle();
        sf::CircleShape generateBall();
        ~Game();


    private:
        ///*Window*///


        ///*Shapes move*///
        float xPositionOfRectangle1 = 24.f;
        float yPositionOfRectangle1 = 0.f;
        float xPositionOfRectangle2 = 776.f;
        float yPositionOfRectangle2 = 0.f;
        float xPositionOfBall = 400.f;
        float yPositionOfBall = 200.f;

        ///*Size of shapes*///
        float xSizeOfRectangle = 16.f;
        float ySizeOfRectangle = 100.f;
        float radiusOfBall = 8.f;

        ///*Settings*///
        const unsigned int x_size = 800;
        const unsigned int y_size = 400;

        ///*Counter*///
        int countFirstPlayer = 0;
        int countSecondPlayer = 0;
        unsigned int win_count;

        ///*Functions*///
        void getSettings();
        void startGame();
        void update();
        void render();
    };

}