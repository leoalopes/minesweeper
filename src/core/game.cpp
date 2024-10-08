#include "game.hpp"
#include "difficulty.hpp"
#include "field.hpp"
#include <memory>
#include <stdexcept>

Game::Game(DifficultyOptions options)
    : size(options.getFieldSize()), bombs(options.getBombQuantity()),
      flaggedBombs(0), hiddenBlocks(options.getSafeBlocks()), victory(false),
      gameOver(false) {
    field = std::make_unique<Field>(options);
}

/*
 * Initialize internal game control variables
 */
void Game::initialize() {}

Field *Game::getField() { return field.get(); }

/*
 * Actions
 */
void Game::flagBlock(int row, int column) {
    if (gameOver) {
        throw std::runtime_error("Game over!");
    }

    const bool isRevealed = field->isBlockVisible(row, column);
    if (!isRevealed) {
        field->flagBlock(row, column);
        flaggedBombs++;
    }
}

void Game::revealCascade(int row, int column, int *revealedBlocks) {
    field->revealBlock(row, column);
    *revealedBlocks += 1;

    if (!field->isBlockSafe(row, column)) {
        return;
    }

    // Up
    if (row > 0 && !field->isBlockVisible(row - 1, column)) {
        revealCascade(row - 1, column, revealedBlocks);
    }

    // Down
    if (row < size - 1 && !field->isBlockVisible(row + 1, column)) {
        revealCascade(row + 1, column, revealedBlocks);
    }

    // Left
    if (column > 0 && !field->isBlockVisible(row, column - 1)) {
        revealCascade(row, column - 1, revealedBlocks);
    }

    // Right
    if (column < size - 1 && !field->isBlockVisible(row, column + 1)) {
        revealCascade(row, column + 1, revealedBlocks);
    }
}

void Game::revealBlock(int row, int column) {
    if (gameOver) {
        throw std::runtime_error("Game over!");
    }

    const bool isFlagged = field->isBlockFlagged(row, column);
    if (isFlagged) {
        flaggedBombs--;
    }

    int revealedBlocks = 0;
    revealCascade(row, column, &revealedBlocks);

    const bool isBomb = field->isBlockBomb(row, column);
    if (isBomb) {
        victory = false;
        gameOver = true;
        return;
    }

    hiddenBlocks -= revealedBlocks;
    if (hiddenBlocks <= 0) {
        victory = true;
        gameOver = true;
    }
}

bool Game::isBlockFlagged(int row, int column) {
    return field->isBlockFlagged(row, column);
}
