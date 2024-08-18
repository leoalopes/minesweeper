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

GameAction GameManager::readGameAction() {
    if (gameInstance == nullptr) {
        throw std::runtime_error("No game instance in progress!");
    }

    return ui->readGameAction(gameInstance);
}

void GameManager::performGameAction(GameAction action) {
    if (action == GameAction::Stop) {
        return;
    }

    int column = ui->readColumn();
    int row = ui->readRow();

    if (row < 0 || row >= gameInstance->getSize() || column < 0 ||
        column >= gameInstance->getSize()) {
        return;
    }

    if (action == GameAction::Reveal) {
        gameInstance->revealBlock(row, column);
    }
    if (action == GameAction::Flag) {
        gameInstance->flagBlock(row, column);
    }
}

bool GameManager::isGameOver() {
    if (gameInstance == nullptr) {
        throw std::runtime_error("No game instance in progress!");
    }

    return gameInstance->isGameOver();
}

void GameManager::showGameOver() {
    if (gameInstance == nullptr) {
        throw std::runtime_error("No game instance in progress!");
    }

    if (!gameInstance->isGameOver()) {
        return;
    }

    if (gameInstance->isVictory()) {
        ui->printVictory(gameInstance);
    } else {
        ui->printGameOver(gameInstance);
    }
}

void GameManager::stopGame() {
    if (gameInstance == nullptr) {
        throw std::runtime_error("No game instance in progress!");
    }

    delete gameInstance;
    gameInstance = nullptr;
}
