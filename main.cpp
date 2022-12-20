#include <iostream>
#include "Game/Game.hpp"

int main(){
    unsigned int winCount = 3;
//    std::cout << "Write win count > 0: ";
//    std::cin  >> winCount;
    gm::Game newGame(winCount);

    return 0;
}
