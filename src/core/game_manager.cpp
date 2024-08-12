#include "game_manager.hpp"
#include "../ui/user_interface.hpp"
#include <stdexcept>

GameManager::GameManager(UserInterface *ui) {
    this->gameInstance = nullptr;
    this->ui = ui;
}
GameManager::~GameManager() {
    if (gameInstance != nullptr) {
        delete gameInstance;
    }
}

bool GameManager::shouldStartNewGame() {
    MenuAction action = ui->readMenuAction();
    return action == MenuAction::Play;
}

void GameManager::startGame() {
    if (gameInstance != nullptr) {
        throw std::runtime_error("There is already a game in progress!");
    }

    Difficulty difficulty = ui->readDifficulty();
    switch (difficulty) {
    case Difficulty::Easy:
        gameInstance = new Game(10, 10);
        break;
    case Difficulty::Intermediate:
        gameInstance = new Game(20, 30);
        break;
    case Difficulty::Hard:
        gameInstance = new Game(26, 50);
        break;
    }
}

void GameManager::printField() {
    if (gameInstance == nullptr) {
        throw std::runtime_error("No game instance in progress!");
    }

    ui->readGameAction(gameInstance->getField());
}
