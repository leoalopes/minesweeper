#pragma once
#include "../core/game.hpp"
#include <array>
#include <string>

enum class MenuAction { Play, Quit };
enum class Difficulty { Easy, Intermediate, Hard };
enum class GameAction { Reveal, Flag, Stop };

class UserInterface {
  public:
    virtual void printVictory(Game *gameInstance) = 0;
    virtual void printGameOver(Game *gameInstance) = 0;

    virtual MenuAction readMenuAction() = 0;
    virtual Difficulty readDifficulty() = 0;
    virtual GameAction readGameAction(Game *gameInstance) = 0;

    virtual std::array<int, 2> readCoordinates() = 0;

    virtual bool askConfirmation(std::string message) = 0;
};
