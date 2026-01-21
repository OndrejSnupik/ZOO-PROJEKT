//
// Created by ondra on 04/12/2025.
//

#include "Game.h"

int main() {
    Game* game = new Game();
    game->run();
    delete game;
    return 0;
}