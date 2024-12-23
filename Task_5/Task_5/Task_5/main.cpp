#include <iostream>

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

int main() {

    setlocale(LC_ALL, "RU");
    int rows, cols;
    std::cout << "¬ведите количество строк: ";
    std::cin >> rows;
    std::cout << "¬ведите количество столбцов: ";
    std::cin >> cols;

    int** array = Init2DArray(rows, cols);

    std::cout << "¬ведите элементы массива:\n";
    InputArray(array, rows, cols);

    std::cout << "»сходный массив:\n";
    Print2DArray(array, rows, cols);

    int newSize;
    int* dynamicArray = CreateDynamicArray(array, rows, cols, newSize);

    std::cout << "ƒинамический массив из элементов, расположенных в четных столбцах и имеющих нечетное значение:\n";
    for (int i = 0; i < newSize; ++i) {
        std::cout << dynamicArray[i] << ' ';
    }
    std::cout << std::endl;

    Free2DArray(array, rows);
    Free1DArray(dynamicArray);

    return 0;
}