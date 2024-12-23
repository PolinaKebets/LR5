// task_test.cpp
#include <gtest/gtest.h>
#include "pch.h"

// task.h
#ifndef TASK_H
#define TASK_H

void inputMatrix(int** A, int n, int k);
int* createEvenDiagonalArray(int** A, int size, int& newSize);
int calculateProduct(int* evenDiagonalArray, int newSize);
void printArray(int* evenDiagonalArray, int newSize);
int Task();

#endif // TASK_H


TEST(CreateEvenDiagonalArrayTest, HandlesNoEvenNumbers) {
    int n = 3;
    int k = 3;
    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[k];
    }
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;
    A[2][0] = 7; A[2][1] = 8; A[2][2] = 9;

    int newSize;
    int* result = createEvenDiagonalArray(A, std::min(n, k), newSize);

    EXPECT_EQ(newSize, 0);

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] result;
}

TEST(CreateEvenDiagonalArrayTest, HandlesEvenNumbers) {
    int n = 3;
    int k = 3;
    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[k];
    }
    A[0][0] = 2; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 1; A[1][1] = 4; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 6;

    int newSize;
    int* result = createEvenDiagonalArray(A, std::min(n, k), newSize);

    EXPECT_EQ(newSize, 3);
    EXPECT_EQ(result[0], 2);
    EXPECT_EQ(result[1], 4);
    EXPECT_EQ(result[2], 6);

    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] result;
}

TEST(CalculateProductTest, HandlesEmptyArray) {
    int* array = nullptr;
    int size = 0;
    int product = calculateProduct(array, size);
    EXPECT_EQ(product, 0);
}

TEST(CalculateProductTest, HandlesNonEmptyArray) {
    int array[] = { 2, 4, 6 };
    int size = 3;
    int product = calculateProduct(array, size);
    EXPECT_EQ(product, 48);
}

TEST(PrintArrayTest, HandlesNonEmptyArray) {
    int array[] = { 2, 4, 6 };
    int size = 3;
    std::ostringstream output;
    auto oldCoutBuf = std::cout.rdbuf(output.rdbuf());
    printArray(array, size);
    std::cout.rdbuf(oldCoutBuf);
    EXPECT_EQ(output.str(), "2 4 6 \n");
}

// Главная функция для выполнения тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
    