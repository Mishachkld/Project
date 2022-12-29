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

        ///*Functions*///
        void startGame();
        bool checkForGoal(float ballPositionX);
        bool checkForGoalFirstPlayer(float x);
        bool checkForEnd();
        sf::RectangleShape generateCounter(float x,  int player);


    private:
        ///*Other*///
        gm::Counter* winPlayer;
        gm::Rectangle* player1;
        gm::Rectangle* player2;
        gm::Ball* ball;

        ///*Shapes move*///
        float _xPositionOfRectangle1 = 24.f;
        float _yPositionOfRectangle1 = 0.f;
        float _xPositionOfRectangle2 = 776.f;
        float _yPositionOfRectangle2 = 0.f;
        float _xPositionOfBall = 400.f;
        float _yPositionOfBall = 200.f;
        std::vector<sf::RectangleShape> _countersFirstPlayer;
        std::vector<sf::RectangleShape> _countersSecondPlayer;

        ///*Size of shapes*///
        float _xSizeOfRectangle = 16.f;
        float _ySizeOfRectangle = 100.f;
        float _sizeOfCounter = 48.f;
        float _radiusOfBall = 8.f;

        ///*Settings*///
        unsigned int x_size_x = 800.f;
        unsigned int y_size_y = 400.f;
        std::string _title;

        ///*Counter*///
        int scoreFirstPlayer = 0;
        int scoreSecondPlayer = 0;
        int numberOfWinPlayer = 0;
        unsigned int _winCount;

        ///*Functions*///
        void endActivity(sf::Event &event, sf::RenderWindow &window);

    };

}