#pragma once

class Field {
    int size;
    int bombQuantity;
    int **field;
    bool **visible;

  public:
    Field(int size, int bombQuantity);

    void debugField();

  private:
    void initialize();

    int getRandomNumber();

    void generateBombs();

    void updateField();
};
