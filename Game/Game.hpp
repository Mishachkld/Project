//
// Created by Mishach on 19.12.2022.
//

#ifndef PROJECT_GAME_HPP
#define PROJECT_GAME_HPP

namespace gm {
    class Game {
    public:
        Game(): myTread(&Game::delay, this){}
        ~Game();

    private:
        float xOfShape = 0.f;
        float yOfShape = 0.f;
        float radius = 40.f;
        sf::Thread myTread;
        int countFirstPlayer = 0;
        int countSecondPlayer = 0;
        void getSettings();
        void delay();
        void startGame();
    };

}

#endif //PROJECT_GAME_HPP
