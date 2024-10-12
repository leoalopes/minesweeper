#pragma once
#include "../ui/user_interface.hpp"
#include "difficulty.hpp"
#include "game.hpp"
#include <memory>

class GameManager {
    std::unique_ptr<Game> gameInstance;

  public:
    void startGame(Difficulty difficulty);
    Game *getGameInstance();

    void performGameAction(GameAction action, int row, int column);

    bool isGameOver();
    void stopGame();
};
