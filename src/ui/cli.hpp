#pragma once
#include "user_interface.hpp"

class Cli : public UserInterface {
  private:
    void static clearScreen();

    void static printGreeting();
    void static printMenuActions();

    void static printDifficultyOptions();

    void static printGameStatus(Game *gameInstance);
    void static printGameField(Game *gameInstance);
    void static printGameActions();

    int static readNumberInput(int fallback);

  public:
    Cli();

    void printVictory(Game *gameInstance) override;
    void printGameOver(Game *gameInstance) override;

    MenuAction readMenuAction() override;
    Difficulty readDifficulty() override;
    GameAction readGameAction(Game *gameInstance) override;

    std::array<int, 2> readCoordinates() override;

    bool askConfirmation(std::string message) override;
};
