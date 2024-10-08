#include "field.hpp"
#include "bomb_generator.hpp"
#include "difficulty.hpp"
#include <cstdlib>
#include <stdexcept>

const int bombChance = 5;

Field::Field(DifficultyOptions options)
    : size(options.getFieldSize()), bombs(options.getBombQuantity()),
      bombGenerator(bombChance), values(), visibility() {
    initialize();
}

/*
 * Initialize field state
 */
void Field::initialize() {
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            values.at(row).at(column) = 0;
            visibility.at(row).at(column) = 0;
        }
    }

    spreadBombs();
}

void Field::spreadBombs() {
    int bombsLeft = bombs;
    while (bombsLeft > 0) {
        for (int row = 0; row < size; row++) {
            for (int column = 0; column < size; column++) {
                if (values.at(row).at(column) != -1) {
                    if (this->bombGenerator.generate()) {
                        values.at(row).at(column) = -1;
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

void Field::incrementAround(int row, int column) {
    // Up
    if (row > 0 && values.at(row - 1).at(column) != -1) {
        values.at(row - 1).at(column) += 1;
    }

    // Down
    if (row < size - 1 && values.at(row + 1).at(column) != -1) {
        values.at(row + 1).at(column) += 1;
    }

    // Left
    if (column > 0 && values.at(row).at(column - 1) != -1) {
        values.at(row).at(column - 1) += 1;
    }

    // Right
    if (column < size - 1 && values.at(row).at(column + 1) != -1) {
        values.at(row).at(column + 1) += 1;
    }

    // UpLeft
    if (row > 0 && column > 0 && values.at(row - 1).at(column - 1) != -1) {
        values.at(row - 1).at(column - 1) += 1;
    }

    // UpRight
    if (row > 0 && column < size - 1 &&
        values.at(row - 1).at(column + 1) != -1) {
        values.at(row - 1).at(column + 1) += 1;
    }

    // DownLeft
    if (row < size - 1 && column > 0 &&
        values.at(row + 1).at(column - 1) != -1) {
        values.at(row + 1).at(column - 1) += 1;
    }

    // DownRight
    if (row < size - 1 && column < size - 1 &&
        values.at(row + 1).at(column + 1) != -1) {
        values.at(row + 1).at(column + 1) += 1;
    }
}

/*
 * Getters
 */
bool Field::isBlockSafe(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values.at(row).at(column) == 0;
}

bool Field::isBlockBomb(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values.at(row).at(column) == -1;
}

bool Field::isBlockFlagged(int row, int column) {
    return visibility.at(row).at(column) == -1;
}

bool Field::isBlockVisible(int row, int column) {
    return visibility.at(row).at(column) == 1;
}

int Field::getBlockValue(int row, int column) {
    if (!isBlockVisible(row, column)) {
        throw std::runtime_error("Block is not visible!");
    }

    return values.at(row).at(column);
}

/*
 * Actions
 */
void Field::flagBlock(int row, int column) {
    if (isBlockVisible(row, column)) {
        throw std::runtime_error("Block is visible!");
    }

    visibility.at(row).at(column) = -1;
}

void Field::revealBlock(int row, int column) {
    visibility.at(row).at(column) = 1;
}
