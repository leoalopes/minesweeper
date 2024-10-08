#include "game_manager.hpp"
#include "../ui/user_interface.hpp"
#include "difficulty.hpp"
#include "game.hpp"
#include <memory>
#include <stdexcept>

GameManager::GameManager(UserInterface *interface) : interface(interface) {}

bool GameManager::shouldStartNewGame() {
    const MenuAction action = interface->readMenuAction();
    return action == MenuAction::Play;
}

void GameManager::startGame() {
    if (gameInstance) {
        throw std::runtime_error("There is already a game in progress!");
    }

    const Difficulty difficulty = interface->readDifficulty();
    gameInstance = std::make_unique<Game>(DifficultyOptions(difficulty));
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
        const bool isBlockFlagged = gameInstance->isBlockFlagged(row, column);
        if (isBlockFlagged) {
            const bool shouldContinue = interface->askConfirmation(
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
