#include "core/game_manager.hpp"
#include "ui/cli.hpp"

int main() {
    Cli cliUi;
    GameManager gameManager(&cliUi);

    while (gameManager.shouldStartNewGame()) {
        gameManager.startGame();
        gameManager.printField();
    }
}
