#include "bomb_generator.hpp"
#include <random>

// Disable warning about the random seed being predictable
// NOLINTNEXTLINE(cert-msc32-c, cert-msc51-cpp)
BombGenerator::BombGenerator(int chance) : chance(chance) {
    std::random_device device;
    const std::mt19937 generator(device());
    this->generator = generator;

    const std::uniform_int_distribution<> distribution(
        static_cast<int>(RandomizableValues::MIN),
        static_cast<int>(RandomizableValues::MAX));
    this->distribution = distribution;
};

bool BombGenerator::generate() {
    const int number = this->distribution(this->generator);
    return number <= this->chance;
}
