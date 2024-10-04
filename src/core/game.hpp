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

    int getSize();
    int getBombs();
    int getFlaggedBombs();
    int getHiddenBlocks();
    bool isVictory();
    bool isGameOver();
    Field *getField();

    void flagBlock(int row, int column);
    void revealBlock(int row, int column);

    bool isBlockFlagged(int row, int column);
};
