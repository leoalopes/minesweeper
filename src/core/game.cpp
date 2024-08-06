#include "game.h"
#include "field.h"

Game::Game(Difficulty difficulty)
    : field(getSize(difficulty), getBombQuantity(difficulty)) {}

void Game::debugField() { field.debugField(); }

int Game::getSize(Difficulty difficulty) {
    switch (difficulty) {
    case Extreme:
        return 100;
    case Hard:
        return 50;
    case Intermediate:
        return 20;
    default:
        return 10;
    }
}
int Game::getBombQuantity(Difficulty difficulty) {
    switch (difficulty) {
    case Extreme:
        return 40;
    case Hard:
        return 20;
    case Intermediate:
        return 5;
    default:
        return 3;
    }
}
