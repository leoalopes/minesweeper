#include "core/game_manager.hpp"
#include "ui/cli.hpp"
#include "ui/user_interface.hpp"

int main() {
    Cli cliUi;
    GameManager gameManager(&cliUi);

    while (gameManager.shouldStartNewGame()) {
        gameManager.startGame();

        while (true) {
            GameAction action = gameManager.readGameAction();
            gameManager.performGameAction(action);

            if (action == GameAction::Stop || gameManager.isGameOver()) {
                break;
            }
        };

        gameManager.showGameOver();
        gameManager.stopGame();
    }
}
