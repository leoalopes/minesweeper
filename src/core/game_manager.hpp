#pragma once
#include "../ui/user_interface.hpp"
#include "game.hpp"

class GameManager {
    Game *gameInstance;
    UserInterface *ui;

  public:
    GameManager(UserInterface *ui);
    ~GameManager();

    bool shouldStartNewGame();
    void startGame();

    GameAction readGameAction();
    void performGameAction(GameAction action);

    bool isGameOver();
    void showGameOver();
    void stopGame();
};
