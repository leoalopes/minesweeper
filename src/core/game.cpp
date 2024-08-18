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

void Game::revealBlock(int row, int column) {
    if (gameOver) {
        throw std::runtime_error("Game over!");
    }

    bool isFlagged = field->isBlockFlagged(row, column);
    if (isFlagged) {
        flaggedBombs--;
    }

    int revealed = field->revealBlock(row, column);
    bool isBomb = field->isBlockBomb(row, column);
    if (isBomb) {
        victory = false;
        gameOver = true;
        return;
    }

    hiddenBlocks -= revealed;
    if (hiddenBlocks <= 0) {
        victory = true;
        gameOver = true;
    }
}
