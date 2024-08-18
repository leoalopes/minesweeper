#include "field.hpp"
#include <cstdlib>
#include <stdexcept>

Field::Field(int size, int bombs) {
    this->size = size;
    this->bombs = bombs;
    initialize();
}
Field::~Field() {
    for (int i = 0; i < size; i++) {
        delete[] values[i];
        delete[] visibility[i];
    }
    delete[] values;
    delete[] visibility;
}

/*
 * Initialize field state
 */
void Field::initialize() {
    values = new int *[size];
    visibility = new int *[size];
    for (int row = 0; row < size; row++) {
        values[row] = new int[size];
        visibility[row] = new int[size];
        for (int column = 0; column < size; column++) {
            values[row][column] = 0;
            visibility[row][column] = 0;
        }
    }

    spreadBombs();
}

void Field::spreadBombs() {
    int bombsLeft = bombs;
    while (bombsLeft > 0) {
        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                if (values[row][column] != -1) {
                    if (shouldAddBomb()) {
                        values[row][column] = -1;
                        incrementAround(row, column);

                        bombsLeft--;
                        if (bombsLeft <= 0) {
                            return;
                        }
                    }
                }
            }
        }
    }
}

bool Field::shouldAddBomb() { return (rand() % 100 + 1) <= 5; }

void Field::incrementAround(int row, int column) {
    // Up
    if (row > 0 && values[row - 1][column] != -1) {
        values[row - 1][column] += 1;
    }

    // Down
    if (row < size - 1 && values[row + 1][column] != -1) {
        values[row + 1][column] += 1;
    }

    // Left
    if (column > 0 && values[row][column - 1] != -1) {
        values[row][column - 1] += 1;
    }

    // Right
    if (column < size - 1 && values[row][column + 1] != -1) {
        values[row][column + 1] += 1;
    }

    // UpLeft
    if (row > 0 && column > 0 && values[row - 1][column - 1] != -1) {
        values[row - 1][column - 1] += 1;
    }

    // UpRight
    if (row > 0 && column < size - 1 && values[row - 1][column + 1] != -1) {
        values[row - 1][column + 1] += 1;
    }

    // DownLeft
    if (row < size - 1 && column > 0 && values[row + 1][column - 1] != -1) {
        values[row + 1][column - 1] += 1;
    }

    // DownRight
    if (row < size - 1 && column < size - 1 &&
        values[row + 1][column + 1] != -1) {
        values[row + 1][column + 1] += 1;
    }
}

/*
 * Getters
 */
int Field::getSize() { return size; }
int Field::getBombs() { return bombs; }

bool Field::isBlockSafe(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values[row][column] == 0;
}

bool Field::isBlockBomb(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values[row][column] == -1;
}

bool Field::isBlockFlagged(int row, int column) {
    return visibility[row][column] == -1;
}

bool Field::isBlockVisible(int row, int column) {
    return visibility[row][column] == 1;
}

int Field::getBlockValue(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values[row][column];
}

/*
 * Actions
 */
void Field::flagBlock(int row, int column) {
    if (isBlockVisible(row, column)) {
        throw std::runtime_error("Block is visible!");
    }

    visibility[row][column] = -1;
}

void Field::revealBlock(int row, int column) { visibility[row][column] = 1; }
