#include "ui/cli.hpp"
#include <core/difficulty.hpp>
#include <core/game.hpp>
#include <core/game_manager.hpp>

namespace {
void performGameLoop(GameManager *gameManager, Cli *interface) {
    while (true) {
        Game *gameInstance = gameManager->getGameInstance();
        const GameAction gameAction = interface->readGameAction(gameInstance);

        if (gameAction == GameAction::Stop) {
            gameManager->stopGame();
            break;
        }

        auto [column, row] = interface->readCoordinates();

        if (gameAction == GameAction::Reveal) {
            const bool isBlockFlagged =
                gameInstance->isBlockFlagged(row, column);
            if (isBlockFlagged) {
                const bool isCorrect = interface->askConfirmation(
                    "The block selected is flagged as a bomb, "
                    "do you want to continue?");
                if (!isCorrect) {
                    continue;
                }
            }
        }

        gameManager->performGameAction(gameAction, row, column);
        if (gameManager->isGameOver()) {
            if (gameInstance->isVictory()) {
                interface->printVictory(gameInstance);
            } else {
                interface->printGameOver(gameInstance);
            }

            gameManager->stopGame();
            break;
        }
    }
}
} // namespace

int main() {
    Cli cli;
    GameManager gameManager;

    while (true) {
        const MenuAction menuAction = cli.readMenuAction();
        if (menuAction != MenuAction::Play) {
            break;
        }

        const Difficulty difficulty = cli.readDifficulty();
        gameManager.startGame(difficulty);

        performGameLoop(&gameManager, &cli);
    }
}
