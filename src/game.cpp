#include "field.cpp"

enum Difficulty { Easy, Intermediate, Hard, Extreme };

class Game {
    Field field;

  public:
    Game(Difficulty difficulty)
        : field(getSize(difficulty), getBombQuantity(difficulty)) {}

    void debugField() { field.debugField(); }

  private:
    int getSize(Difficulty difficulty) {
        switch (difficulty) {
        case Extreme:
            return 100;
        case Hard:
            return 50;
        case Intermediate:
            return 20;
        default:
            return 10;
        }
    }
    int getBombQuantity(Difficulty difficulty) {
        switch (difficulty) {
        case Extreme:
            return 40;
        case Hard:
            return 20;
        case Intermediate:
            return 5;
        default:
            return 3;
        }
    }
};
