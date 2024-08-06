#pragma once
#include "field.h"

enum Difficulty { Easy, Intermediate, Hard, Extreme };

class Game {
    Field field;

  public:
    Game(Difficulty difficulty);

    void debugField();

  private:
    int getSize(Difficulty difficulty);

    int getBombQuantity(Difficulty difficulty);
};
