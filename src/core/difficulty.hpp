#pragma once

enum class Difficulty { Easy, Intermediate, Hard };

// Map difficulty to field size
enum class FieldSize : int { Easy = 10, Intermediate = 20, Hard = 26 };

// Map difficulty to quantity of bombs
enum class BombQuantity : int { Easy = 10, Intermediate = 30, Hard = 50 };

class DifficultyOptions {
    int bombQuantity;
    int fieldSize;

  public:
    explicit DifficultyOptions(Difficulty difficulty);

    [[nodiscard]] int getBombQuantity() const { return bombQuantity; }
    [[nodiscard]] int getFieldSize() const { return fieldSize; }
    [[nodiscard]] int getSafeBlocks() const {
        return this->getTotalBlocks() - this->getBombQuantity();
    }
    [[nodiscard]] int getTotalBlocks() const { return fieldSize * fieldSize; }
};
