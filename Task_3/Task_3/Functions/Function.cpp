
#include<iostream>
#include <cmath>
#include <locale.h>

void inputMatrix(int** A, int n, int k) {
    std::cout << "Введите элементы матрицы размером " << n << "x" << k << ":\n";

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cout << "Введите элемент x (" << i << "," << j << "): ";
            std::cin >> A[i][j];
        }
    }
}

int* createEvenDiagonalArray(int** A, int size, int& newSize) {
    int* diagonalArray = new int[size];
    newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (A[i][i] % 2 == 0) {
            diagonalArray[newSize++] = A[i][i];
        }
    }
    return diagonalArray;
}

int calculateProduct(int* evenDiagonalArray, int newSize) {
    int product = 1;
    if (newSize == 0) {

        return 0;
    }
    for (int i = 0; i < newSize; ++i) {
        product *= evenDiagonalArray[i];
    }
    return product;
}

void printArray(int* evenDiagonalArray, int newSize) {
    for (int i = 0; i < newSize; ++i) {
        std::cout << evenDiagonalArray[i] << " ";
    }
    std::cout << std::endl;
}

int Task(){
    int n, k;
    std::cout << "Введите количество строк (n) и столбцов (k) матрицы: ";
    std::cin >> n >> k;

    int** A = new int* [n];
    for (int i = 0; i < n; ++i) {
        A[i] = new int[k];
    }

    inputMatrix(A, n, k);

    int size = std::min(n, k);
    int newSize;
    int* evenDiagonalArray = createEvenDiagonalArray(A, std::min(n, k), newSize);

    int product = calculateProduct(evenDiagonalArray, newSize);

    std::cout << "Массив четных элементов главной диагонали: ";
    printArray(evenDiagonalArray, newSize);
    std::cout << "Произведение элементов массива: " << product << std::endl;

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] evenDiagonalArray;

    return 0;

}
