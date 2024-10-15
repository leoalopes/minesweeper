#include "core/difficulty.hpp"

DifficultyOptions::DifficultyOptions(Difficulty difficulty) {
    switch (difficulty) {
        case Difficulty::Easy:
            this->bombQuantity = static_cast<int>(BombQuantity::Easy);
            this->fieldSize = static_cast<int>(FieldSize::Easy);
            break;
        case Difficulty::Intermediate:
            this->bombQuantity = static_cast<int>(BombQuantity::Intermediate);
            this->fieldSize = static_cast<int>(FieldSize::Intermediate);
            break;
        case Difficulty::Hard:
            this->bombQuantity = static_cast<int>(BombQuantity::Hard);
            this->fieldSize = static_cast<int>(FieldSize::Hard);
            break;
    }
}
