#pragma once
#include "../ui/user_interface.hpp"
#include "game.hpp"
#include <memory>

class GameManager {
    std::unique_ptr<Game> gameInstance;
    UserInterface *interface;

  public:
    explicit GameManager(UserInterface *interface);

    bool shouldStartNewGame();
    void startGame();

    GameAction readGameAction();
    void performGameAction(GameAction action);

    bool isGameOver();
    void showGameOver();
    void stopGame();
};
