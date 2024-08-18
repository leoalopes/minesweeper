#include "game.hpp"
#include "field.hpp"
#include <stdexcept>

Game::Game(int size, int bombs) {
    this->size = size;
    this->bombs = bombs;
    initialize();
}
Game::~Game() { delete field; }

/*
 * Initialize internal game control variables
 */
void Game::initialize() {
    hiddenBlocks = size * size - bombs;
    victory = false;
    gameOver = false;
    field = new Field(size, bombs);
}

/*
 * Getters
 */
int Game::getSize() { return size; }
int Game::getBombs() { return bombs; }
int Game::getFlaggedBombs() { return flaggedBombs; }
int Game::getHiddenBlocks() { return hiddenBlocks; }
bool Game::isVictory() { return victory; }
bool Game::isGameOver() { return gameOver; }
Field *Game::getField() { return field; }

/*
 * Actions
 */
void Game::flagBlock(int row, int column) {
    if (gameOver) {
        throw std::runtime_error("Game over!");
    }

    bool isRevealed = field->isBlockVisible(row, column);
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

    bool isFlagged = field->isBlockFlagged(row, column);
    if (isFlagged) {
        flaggedBombs--;
    }

    int revealedBlocks = 0;
    revealCascade(row, column, &revealedBlocks);

    bool isBomb = field->isBlockBomb(row, column);
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
