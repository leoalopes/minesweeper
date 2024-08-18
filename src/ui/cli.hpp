#pragma once
#include "user_interface.hpp"

class Cli : public UserInterface {
  private:
    void clearScreen();

    void printGreeting();
    void printMenuActions();

    void printDifficultyOptions();

    void printGameStatus(Game *gameInstance);
    void printGameField(Game *gameInstance);
    void printGameActions();

  public:
    Cli();

    void printVictory(Game *gameInstance);
    void printGameOver(Game *gameInstance);

    MenuAction readMenuAction();
    Difficulty readDifficulty();
    GameAction readGameAction(Game *gameInstance);

    int readRow();
    int readColumn();
};
