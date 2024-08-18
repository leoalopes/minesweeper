#pragma once
#include "../core/game.hpp"
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

    virtual int readRow() = 0;
    virtual int readColumn() = 0;

    virtual bool askConfirmation(std::string message) = 0;
};
