#pragma once
#include <array>
#include <core/difficulty.hpp>
#include <core/game.hpp>
#include <core/game_manager.hpp>
#include <string>

class Cli {
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
    void static printVictory(Game *gameInstance);
    void static printGameOver(Game *gameInstance);

    MenuAction static readMenuAction();
    Difficulty static readDifficulty();
    GameAction static readGameAction(Game *gameInstance);

    std::array<int, 2> static readCoordinates();

    bool static askConfirmation(const std::string &message);
};
