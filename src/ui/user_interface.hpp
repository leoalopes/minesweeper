#pragma once
#include "../core/field.hpp"

enum class MenuAction { Play, Quit };
enum class Difficulty { Easy, Intermediate, Hard };
enum class GameAction { Reveal, Flag, Quit };

class UserInterface {
  public:
    virtual void printVictory() = 0;
    virtual void printGameOver() = 0;

    virtual MenuAction readMenuAction() = 0;
    virtual Difficulty readDifficulty() = 0;
    virtual GameAction readGameAction(Field *field) = 0;
};
