#include "game_manager.hpp"
#include "../ui/user_interface.hpp"
#include <stdexcept>

GameManager::GameManager(UserInterface *interface) : interface(interface) {}

bool GameManager::shouldStartNewGame() {
    MenuAction action = interface->readMenuAction();
    return action == MenuAction::Play;
}

void GameManager::startGame() {
    if (gameInstance) {
        throw std::runtime_error("There is already a game in progress!");
    }

    Difficulty difficulty = interface->readDifficulty();
    switch (difficulty) {
    case Difficulty::Easy:
        gameInstance = std::make_unique<Game>(10, 10);
        break;
    case Difficulty::Intermediate:
        gameInstance = std::make_unique<Game>(20, 30);
        break;
    case Difficulty::Hard:
        gameInstance = std::make_unique<Game>(26, 50);
        break;
    }
}

GameAction GameManager::readGameAction() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    return interface->readGameAction(gameInstance.get());
}

void GameManager::performGameAction(GameAction action) {
    if (action == GameAction::Stop) {
        return;
    }

    auto [column, row] = interface->readCoordinates();

    if (row < 0 || row >= gameInstance->getSize() || column < 0 ||
        column >= gameInstance->getSize()) {
        return;
    }

    if (action == GameAction::Reveal) {
        bool isBlockFlagged = gameInstance->isBlockFlagged(row, column);
        if (isBlockFlagged) {
            bool shouldContinue = interface->askConfirmation(
                "The block selected is flagged as a bomb, "
                "do you want to continue?");
            if (!shouldContinue) {
                return;
            }
        }

        gameInstance->revealBlock(row, column);
    }

    if (action == GameAction::Flag) {
        gameInstance->flagBlock(row, column);
    }
}

bool GameManager::isGameOver() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    return gameInstance->isGameOver();
}

void GameManager::showGameOver() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    if (!gameInstance->isGameOver()) {
        return;
    }

    if (gameInstance->isVictory()) {
        interface->printVictory(gameInstance.get());
    } else {
        interface->printGameOver(gameInstance.get());
    }
}

void GameManager::stopGame() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    gameInstance.reset();
}
