#pragma once
#include <array>

template <typename T, std::size_t Row, std::size_t Column>
using Matrix = std::array<std::array<T, Column>, Row>;

class Field {
    int size;
    int bombs;
    Matrix<int, 26, 26> values;
    Matrix<int, 26, 26> visibility;

  private:
    void initialize();
    void spreadBombs();

    bool shouldAddBomb();
    void incrementAround(int row, int column);

  public:
    Field(int size, int bombs);

    int getSize();
    int getBombs();

    bool isBlockSafe(int row, int column);
    bool isBlockBomb(int row, int column);
    bool isBlockFlagged(int row, int column);
    bool isBlockVisible(int row, int column);

    int getBlockValue(int row, int column);

    void flagBlock(int row, int column);
    void revealBlock(int row, int column);
};
