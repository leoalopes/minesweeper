#pragma once
#include "field.hpp"
#include <memory>

class Game {
    int size;
    int bombs;
    int flaggedBombs;
    int hiddenBlocks;
    bool victory;
    bool gameOver;
    std::unique_ptr<Field> field;

  private:
    void initialize();

    void revealCascade(int row, int column, int *revealedBlocks);

  public:
    Game(int size, int bombs);

    /*
     * Getters
     */
    [[nodiscard]] int getSize() const { return size; }
    [[nodiscard]] int getBombs() const { return bombs; }
    [[nodiscard]] int getFlaggedBombs() const { return flaggedBombs; }
    [[nodiscard]] int getHiddenBlocks() const { return hiddenBlocks; }
    [[nodiscard]] bool isVictory() const { return victory; }
    [[nodiscard]] bool isGameOver() const { return gameOver; }

    Field *getField();

    void flagBlock(int row, int column);
    void revealBlock(int row, int column);

    bool isBlockFlagged(int row, int column);
};
