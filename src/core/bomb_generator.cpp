#include "bomb_generator.hpp"
#include <random>

#define MIN_RANDOMIZED_VALUE 1
#define MAX_RANDOMIZED_VALUE 100

// NOLINTNEXTLINE(cert-msc32-c, cert-msc51-cpp)
BombGenerator::BombGenerator(int chance) : chance(chance) {
    std::random_device device;
    std::mt19937 generator(device());
    this->generator = generator;

    std::uniform_int_distribution<> distribution(MIN_RANDOMIZED_VALUE,
                                                 MAX_RANDOMIZED_VALUE);
    this->distribution = distribution;
};

bool BombGenerator::generate() {
    int number = this->distribution(this->generator);
    return number <= this->chance;
}
