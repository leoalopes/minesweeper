#pragma once
#include <random>

class BombGenerator {
    int chance;
    std::mt19937 generator;
    std::uniform_int_distribution<> distribution;

  public:
    explicit BombGenerator(int chance);

    bool generate();
};
