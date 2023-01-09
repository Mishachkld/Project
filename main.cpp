#include "Game/Game.hpp"
#define WIN_COUNT 3
#define SIZE_X 800
#define SIZE_Y 400

int main(){
    gm::Game newGame(WIN_COUNT, SIZE_X, SIZE_Y, "Project for BFU: PONG");
    newGame.startGame();
    return 0;
}
