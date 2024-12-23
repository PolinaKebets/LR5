#include <gtest/gtest.h>
#include <utility>
#include <iostream>
#include <cmath>
#include "pch.h"

// Прототипы функций
double** Init2DArray(int rows, int cols);
void InputArray(double** array, int rows, int cols);
std::pair<int**, int> FindZero(double** array, int rows, int cols);
double** SwapArray(double** array, int rows, int cols);
void PrintArray(double** array, int rows, int cols);
void Free2DArray(double** array, int rows);

// Тесты для функций

TEST(Init2DArrayTest, HandlesNonZeroInput) {
    int rows = 3;
    int cols = 3;
    double** array = Init2DArray(rows, cols);

    ASSERT_NE(array, nullptr);
    for (int i = 0; i < rows; ++i) {
        ASSERT_NE(array[i], nullptr);
    }

    Free2DArray(array, rows);
}

TEST(FindZeroTest, HandlesZerosCorrectly) {
    int rows = 3;
    int cols = 3;
    double** array = Init2DArray(rows, cols);
    array[0][0] = 0.0;
    array[1][1] = 0.0;
    array[2][2] = 0.0;

    std::pair<int**, int> result = FindZero(array, rows, cols);

    EXPECT_EQ(result.second, 3);
    EXPECT_EQ(result.first[0][0], 0);
    EXPECT_EQ(result.first[0][1], 1);
    EXPECT_EQ(result.first[0][2], 2);
    EXPECT_EQ(result.first[1][0], 0);
    EXPECT_EQ(result.first[1][1], 1);
    EXPECT_EQ(result.first[1][2], 2);

    Free2DArray(array, rows);
    delete[] result.first[0];
    delete[] result.first[1];
    delete[] result.first;
}

TEST(SwapArrayTest, HandlesSwapping) {
    int rows = 2;
    int cols = 2;
    double** array = Init2DArray(rows, cols);
    array[0][0] = 1.0;
    array[0][1] = 2.0;
    array[1][0] = 3.0;
    array[1][1] = 4.0;

    SwapArray(array, rows, cols);

    EXPECT_EQ(array[0][0], 4.0);
    EXPECT_EQ(array[0][1], 3.0);
    EXPECT_EQ(array[1][0], 2.0);
    EXPECT_EQ(array[1][1], 1.0);

    Free2DArray(array, rows);
}

// Главная функция для выполнения тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
