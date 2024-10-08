#pragma once
#include "bomb_generator.hpp"
#include "difficulty.hpp"
#include <array>

#define MAX_FIELD_SIZE 26

template <typename T, std::size_t Row, std::size_t Column>
using Matrix = std::array<std::array<T, Column>, Row>;

class Field {
    int size;
    int bombs;
    BombGenerator bombGenerator;
    Matrix<int, MAX_FIELD_SIZE, MAX_FIELD_SIZE> values;
    Matrix<int, MAX_FIELD_SIZE, MAX_FIELD_SIZE> visibility;

  private:
    void initialize();
    void spreadBombs();

    bool shouldAddBomb();
    void incrementAround(int row, int column);

  public:
    explicit Field(DifficultyOptions options);

    [[nodiscard]] int getSize() const { return size; }
    [[nodiscard]] int getBombs() const { return bombs; }

    bool isBlockSafe(int row, int column);
    bool isBlockBomb(int row, int column);
    bool isBlockFlagged(int row, int column);
    bool isBlockVisible(int row, int column);

    int getBlockValue(int row, int column);

    void flagBlock(int row, int column);
    void revealBlock(int row, int column);
};
