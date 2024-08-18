#pragma once

class Field {
    int size;
    int bombs;
    int **values;
    int **visibility;

  private:
    void initialize();
    void spreadBombs();

    bool shouldAddBomb();
    void incrementAround(int row, int column);

  public:
    Field(int size, int bombs);
    ~Field();

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
