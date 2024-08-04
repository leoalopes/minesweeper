#include <cstdlib>
#include <iostream>

class Field {
    int size;
    int bombQuantity;
    int **field;
    bool **visible;

  public:
    Field(int s, int b) {
        size = s;
        bombQuantity = b;
        initialize();
        generateBombs();
        updateField();
    }

    void debugField() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << field[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

  private:
    void initialize() {
        field = new int *[size];
        visible = new bool *[size];
        for (int i = 0; i < size; i++) {
            field[i] = new int[size];
            visible[i] = new bool[size];
            for (int j = 0; j < size; j++) {
                field[i][j] = 0;
                visible[i][j] = false;
            }
        }
    }

    int getRandomNumber() { return rand() % 100 + 1; }

    void generateBombs() {
        while (bombQuantity > 0) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (field[i][j] == -1) {
                        continue;
                    }

                    int randomNumber = getRandomNumber();
                    bool shouldAddBomb = randomNumber % 20 == 0;
                    if (shouldAddBomb) {
                        field[i][j] = -1;
                        bombQuantity--;
                        if (bombQuantity == 0) {
                            break;
                        }
                    }
                }
            }
        }
    }

    void updateField() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (field[i][j] != -1) {
                    if (i > 0 && j > 0 && field[i - 1][j - 1] == -1) {
                        field[i][j] += 1;
                    }

                    if (i < size - 1 && j < size - 1 &&
                        field[i + 1][j + 1] == -1) {
                        field[i][j] += 1;
                    }

                    if (i > 0 && j < size - 1 && field[i - 1][j + 1] == -1) {
                        field[i][j] += 1;
                    }

                    if (i < size - 1 && j > 0 && field[i + 1][j - 1] == -1) {
                        field[i][j] += 1;
                    }

                    if (i > 0 && field[i - 1][j] == -1) {
                        field[i][j] += 1;
                    }

                    if (i < size - 1 && field[i + 1][j] == -1) {
                        field[i][j] += 1;
                    }

                    if (j > 0 && field[i][j - 1] == -1) {
                        field[i][j] += 1;
                    }

                    if (j < size - 1 && field[i][j + 1] == -1) {
                        field[i][j] += 1;
                    }
                }
            }
        }
    }
};
