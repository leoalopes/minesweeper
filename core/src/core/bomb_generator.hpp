#pragma once
#include <random>

enum class RandomizableValues : int { MIN = 1, MAX = 100 };

class BombGenerator {
    int chance;
    std::mt19937 generator;
    std::uniform_int_distribution<> distribution;

  public:
    explicit BombGenerator(int chance);

    bool generate();
};
