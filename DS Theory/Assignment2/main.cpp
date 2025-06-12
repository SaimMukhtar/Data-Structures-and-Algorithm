#include <iostream>
#include "game.h"

int main() {
    int difficulty;
    std::cout << "Choose difficulty (1: Easy, 2: Medium, 3: Hard): ";
    std::cin >> difficulty;

    Game game(difficulty);
    game.start();

    return 0;
}
