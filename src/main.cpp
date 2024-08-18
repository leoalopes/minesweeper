#include "core/game_manager.hpp"
#include "ui/cli.hpp"
#include "ui/user_interface.hpp"

int main() {
    Cli cliUi;
    GameManager gameManager(&cliUi);

    while (gameManager.shouldStartNewGame()) {
        gameManager.startGame();

        GameAction action;
        do {
            action = gameManager.readGameAction();
            gameManager.performGameAction(action);
        } while (action != GameAction::Stop && !gameManager.isGameOver());

        gameManager.showGameOver();
        gameManager.stopGame();
    }
}
