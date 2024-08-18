#pragma once
#include "field.hpp"

/*enum Difficulty { Easy, Intermediate, Hard, Extreme };*/

class Game {
    int size;
    int bombs;
    int flaggedBombs;
    int hiddenBlocks;
    bool victory;
    bool gameOver;
    Field *field;

  private:
    void initialize();

  public:
    Game(int size, int bombs);
    ~Game();

    int getSize();
    int getBombs();
    int getFlaggedBombs();
    int getHiddenBlocks();
    bool isVictory();
    bool isGameOver();
    Field *getField();

    void flagBlock(int row, int column);
    void revealBlock(int row, int column);
};
