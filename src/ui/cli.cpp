#include "cli.hpp"
#include "user_interface.hpp"
#include <iostream>

Cli::Cli() {}

void Cli::clearScreen() { system("clear"); }

void Cli::printGreeting() {
    std::cout
        << "\n"
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
        << "\n";
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

void Cli::printGameField(Field *field) {}

void Cli::printGameActions() {
    std::cout << "1 - Reveal a block" << "\n";
    std::cout << "2 - Flag a bomb" << "\n";
    std::cout << "3 - Quit" << "\n";
}

GameAction Cli::readGameAction(Field *field) {
    int option;

    while (option != 1 && option != 2 && option != 3) {
        clearScreen();
        printGameField(field);
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

    return GameAction::Quit;
}

void Cli::printVictory() {}

void Cli::printGameOver() {}
