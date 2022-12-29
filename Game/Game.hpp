#include <thread>
#include <chrono>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../Figure/Ball/Ball.hpp"
#include "../Counter/Counter.hpp"
#include "../Figure/Rectnagle/Rectangle.hpp"


#pragma once
namespace gm {
    class Game {
    public:
        Game(unsigned int count, unsigned int sizeWinX, unsigned int sizeWinY, std::string title);
        ~Game();
        void startGame();
        bool checkForGoal(float ballPositionX);
        bool checkForEnd();


    private:
        ///*Other*///
        gm::Counter* winPlayer;

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
        float _sizeOfCounter = 48.f;
        ///*Settings*///
        unsigned int x_size;
        unsigned int y_size;
        std::string _title;

        ///*Counter*///
        int countFirstPlayer = 0;
        int countSecondPlayer = 0;
        int numberOfWinPlayer = 0;
        unsigned int win_count;

        ///*Functions*///
        void settings();
        unsigned int getCount();
        void endActivity(sf::Event &event, sf::RenderWindow &window);

    };

}