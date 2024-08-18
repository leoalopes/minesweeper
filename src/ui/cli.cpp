#include "cli.hpp"
#include "user_interface.hpp"
#include <iostream>
#include <string>

Cli::Cli() {}

void Cli::clearScreen() { system("clear"); }

void Cli::printGreeting() {
    std::cout
        << "______________________________________________________________"
        << "\n";
    std::cout
        << "    __  ____           _____                                  "
        << "\n";
    std::cout
        << "   /  |/  (_____  ___ / ____      _____  ___  ____  ___  _____"
        << "\n";
    std::cout << "  / /|_/ / / __ \\/ _ \\\\__ | | /| / / _ \\/ _ \\/ __ \\/ _ "
                 "\\/ ___/"
              << "\n";
    std::cout
        << " / /  / / / / / /  _____/ | |/ |/ /  __/  __/ /_/ /  __/ /    "
        << "\n";
    std::cout
        << "/_/  /_/_/_/ /_/\\___/____/|__/|__/\\___/\\___/ .___/\\___/_/     "
        << "\n";
    std::cout
        << "                                          /_/                 "
        << "\n";
    std::cout
        << "______________________________________________________________"
        << "\n\n\n";
}

void Cli::printMenuActions() {
    std::cout << "1 - New game" << "\n";
    std::cout << "2 - Quit" << "\n";
}

MenuAction Cli::readMenuAction() {
    int option;

    while (option != 1 && option != 2) {
        clearScreen();
        printGreeting();
        printMenuActions();

        std::cout << std::endl;
        std::cout << "Input: ";
        std::cin >> option;
    }

    if (option == 1) {
        return MenuAction::Play;
    }

    return MenuAction::Quit;
}

void Cli::printDifficultyOptions() {
    std::cout << "1 - Easy" << "\n";
    std::cout << "2 - Intermediate" << "\n";
    std::cout << "3 - Hard" << "\n";
}

Difficulty Cli::readDifficulty() {
    int option;

    while (option != 1 && option != 2 && option != 3) {
        clearScreen();
        printGreeting();
        printDifficultyOptions();

        std::cout << std::endl;
        std::cout << "Input: ";
        std::cin >> option;
    }

    if (option == 1) {
        return Difficulty::Easy;
    }

    if (option == 2) {
        return Difficulty::Intermediate;
    }

    return Difficulty::Hard;
}

void Cli::printGameStatus(Game *gameInstance) {
    std::cout << "Blocks left: " << gameInstance->getHiddenBlocks() << "\n";
    std::cout << "Flagged bombs: " << gameInstance->getFlaggedBombs() << "\n";
    std::cout << "Total bombs: " << gameInstance->getBombs() << "\n\n";
}

void Cli::printGameField(Game *gameInstance) {
    int size = gameInstance->getSize();
    Field *field = gameInstance->getField();

    std::cout << "     ";
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int column = 0; column < size; column++) {
        std::cout << alphabet.at(column) << " ";
    }
    std::cout << "\n";

    for (int row = 0; row < size; row++) {
        std::cout << "\n";

        if (row < 9) {
            std::cout << " ";
        }
        std::cout << row + 1 << "   ";
        for (int column = 0; column < size; column++) {
            if (field->isBlockVisible(row, column)) {
                int value = field->getBlockValue(row, column);
                if (value == -1) {
                    std::cout << "\033[1;31m󰚑\033[0m";
                } else if (value == 0) {
                    std::cout << " ";
                } else {
                    std::cout << value;
                }
            } else if (field->isBlockFlagged(row, column)) {
                std::cout << "󰉀";
            } else {
                std::cout << "";
            }
            std::cout << " ";
        }
    }
    std::cout << "\n" << std::endl;
}

void Cli::printGameActions() {
    std::cout << "1 - Reveal a block" << "\n";
    std::cout << "2 - Flag a bomb" << "\n";
    std::cout << "3 - Stop" << "\n";
}

GameAction Cli::readGameAction(Game *gameInstance) {
    int option;

    while (option != 1 && option != 2 && option != 3) {
        clearScreen();
        printGameStatus(gameInstance);
        printGameField(gameInstance);
        printGameActions();

        std::cout << std::endl;
        std::cout << "Input: ";
        std::cin >> option;
    }

    if (option == 1) {
        return GameAction::Reveal;
    }

    if (option == 2) {
        return GameAction::Flag;
    }

    return GameAction::Stop;
}

int Cli::readRow() {
    int row;

    std::cout << "Choose row: ";
    std::cin >> row;

    return row - 1;
}

int Cli::readColumn() {
    std::string input;

    std::cout << "Choose column: ";
    std::cin >> input;

    std::string uppercaseAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

    std::size_t uppercaseMatch = uppercaseAlphabet.find(input.at(0));
    std::size_t lowercaseMatch = lowercaseAlphabet.find(input.at(0));

    if (uppercaseMatch == std::string::npos &&
        lowercaseMatch == std::string::npos) {
        return -1;
    }

    if (uppercaseMatch != std::string::npos) {
        return static_cast<int>(uppercaseMatch);
    }

    return static_cast<int>(lowercaseMatch);
}

void Cli::printVictory(Game *gameInstance) {
    clearScreen();

    printGameField(gameInstance);

    std::cout << "   __   __                 _        _ _ \n";
    std::cout << "   \\ \\ / /__ _  _  __ __ _(_)_ _   | | |\n";
    std::cout << "    \\ V / _ \\ || | \\ V  V / | ' \\  |_|_|\n";
    std::cout << "     |_|\\___/\\_,_|  \\_/\\_/|_|_||_| (_|_)\n";
    std::cout << "                                        \n";

    std::cin.ignore();
    std::cin.get();
}

void Cli::printGameOver(Game *gameInstance) {
    clearScreen();

    printGameField(gameInstance);

    std::cout << "     ___                   ___              \n";
    std::cout << "    / __|__ _ _ __  ___   / _ \\__ _____ _ _ \n";
    std::cout << "   | (_ / _` | '  \\/ -_) | (_) \\ V / -_) '_|\n";
    std::cout << "    \\___\\__,_|_|_|_\\___|  \\___/ \\_/\\___|_|  \n";
    std::cout << "                                            \n";

    std::cin.ignore();
    std::cin.get();
}
