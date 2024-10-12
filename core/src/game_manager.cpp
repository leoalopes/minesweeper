#include "core/game_manager.hpp"
#include "core/difficulty.hpp"
#include "core/game.hpp"
#include <memory>
#include <stdexcept>

void GameManager::startGame(Difficulty difficulty) {
    if (gameInstance) {
        throw std::runtime_error("There is already a game in progress!");
    }

    gameInstance = std::make_unique<Game>(DifficultyOptions(difficulty));
}

Game *GameManager::getGameInstance() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    return gameInstance.get();
}

void GameManager::performGameAction(GameAction action, int row, int column) {
    if (action == GameAction::Stop) {
        return;
    }

    // TODO move to field and delete
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
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    return gameInstance->isGameOver();
}

void GameManager::stopGame() {
    if (!gameInstance) {
        throw std::runtime_error("No game instance in progress!");
    }

    gameInstance.reset();
}
