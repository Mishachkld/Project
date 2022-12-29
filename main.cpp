#include "Game/Game.hpp"
#define WIN_COUNT 1

int main(){
    gm::Game newGame(WIN_COUNT, 800, 400, "Project for BFU");
    newGame.startGame();
    return 0;
}
