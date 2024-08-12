#pragma once
#include "user_interface.hpp"

class Cli : public UserInterface {
  private:
    void clearScreen();

    void printGreeting();
    void printMenuActions();

    void printDifficultyOptions();

    void printGameField(Field *field);
    void printGameActions();

  public:
    Cli();

    MenuAction readMenuAction();
    Difficulty readDifficulty();
    GameAction readGameAction(Field *field);

    void printVictory();
    void printGameOver();
};
