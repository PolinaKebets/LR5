#include <iostream>
#include <gtest/gtest.h>
#include "pch.h"

// Ваши функции

int** Init2DArray(int rows, int cols) {
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

void InputArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }
}

int* CreateDynamicArray(int** array, int rows, int cols, int& newSize) {
    int* dynamicArray = new int[rows * (cols / 2)];
    newSize = 0;

    for (int j = 0; j < cols; j += 2) {
        for (int i = 0; i < rows; ++i) {
            if (array[i][j] % 2 != 0) {
                dynamicArray[newSize] = array[i][j];
                newSize++;
            }
        }
    }
    return dynamicArray;
}

void Print2DArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void Free1DArray(int* array) {
    delete[] array;
}

// Тесты для Init2DArray
TEST(Init2DArrayTest, HandlesZeroInput) {
    int rows = 0;
    int cols = 0;
    int** array = Init2DArray(rows, cols);
    EXPECT_EQ(array, nullptr);
}

TEST(Init2DArrayTest, HandlesPositiveInput) {
    int rows = 3;
    int cols = 3;
    int** array = Init2DArray(rows, cols);
    ASSERT_NE(array, nullptr);
    for (int i = 0; i < rows; ++i) {
        ASSERT_NE(array[i], nullptr);
    }
    Free2DArray(array, rows);
}

// Тесты для CreateDynamicArray
TEST(CreateDynamicArrayTest, HandlesNoOddValues) {
    int rows = 3;
    int cols = 3;
    int** array = Init2DArray(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = 2 * (i * cols + j);  // Четные значения
        }
    }
    int newSize;
    int* dynamicArray = CreateDynamicArray(array, rows, cols, newSize);
    EXPECT_EQ(newSize, 0);
    Free2DArray(array, rows);
    Free1DArray(dynamicArray);
}

TEST(CreateDynamicArrayTest, HandlesOddValues) {
    int rows = 3;
    int cols = 3;
    int** array = Init2DArray(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = (i * cols + j);  // Четные и нечетные значения
        }
    }
    int newSize;
    int* dynamicArray = CreateDynamicArray(array, rows, cols, newSize);
    EXPECT_GT(newSize, 0);
    Free2DArray(array, rows);
    Free1DArray(dynamicArray);
}

// Главная функция для выполнения тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
