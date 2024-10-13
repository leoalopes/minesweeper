#include <core/difficulty.hpp>
#include <gtest/gtest.h>

TEST(Difficulty, SetsCorrectValues) {
    DifficultyOptions easy(Difficulty::Easy);
    EXPECT_EQ(easy.getFieldSize(), 10);
    EXPECT_EQ(easy.getBombQuantity(), 10);

    DifficultyOptions intermediate(Difficulty::Intermediate);
    EXPECT_EQ(intermediate.getFieldSize(), 20);
    EXPECT_EQ(intermediate.getBombQuantity(), 30);

    DifficultyOptions hard(Difficulty::Hard);
    EXPECT_EQ(hard.getFieldSize(), 26);
    EXPECT_EQ(hard.getBombQuantity(), 50);
}
