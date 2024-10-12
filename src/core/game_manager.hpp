#pragma once
#include "difficulty.hpp"
#include "game.hpp"
#include <memory>

enum class MenuAction { Play, Quit };
enum class GameAction { Reveal, Flag, Stop };

class GameManager {
    std::unique_ptr<Game> gameInstance;

  public:
    void startGame(Difficulty difficulty);
    Game *getGameInstance();

    void performGameAction(GameAction action, int row, int column);

    bool isGameOver();
    void stopGame();
};
