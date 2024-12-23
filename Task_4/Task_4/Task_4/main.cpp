#include <iostream>
#include <cmath>

double** Init2DArray(int rows, int cols) {
    double** array = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new double[cols];
    }
    return array;
}

void InputArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> array[i][j];
        }
    }
}

std::pair<int**, int> FindZero(double** array, int rows, int cols) {
    int zeroCount = 0;
    int** positions = new int* [2];
    positions[0] = new int[rows * cols];
    positions[1] = new int[rows * cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] == 0) {
                positions[0][zeroCount] = i;
                positions[1][zeroCount] = j;
                ++zeroCount;
            }
        }
    }

    return std::make_pair(positions, zeroCount);
}

double** SwapArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows / 2; ++i) {
        for (int j = 0; j < cols; ++j) {
            double temp = array[i][j];
            array[i][j] = array[rows - 1 - i][j];
            array[rows - 1 - i][j] = temp;
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols / 2; ++j) {
            double temp = array[i][j];
            array[i][j] = array[i][cols - 1 - j];
            array[i][cols - 1 - j] = temp;
        }
    }
    return array;
}

void PrintArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Free2DArray(double** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}
int Task() {
    setlocale(LC_ALL, "RU");
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    double** array = Init2DArray(rows, cols);

    std::cout << "Введите элементы массива:\n";
    InputArray(array, rows, cols);

    std::cout << "Введенный массив:\n";
    PrintArray(array, rows, cols);

    std::pair<int**, int> zeroResult = FindZero(array, rows, cols);
    int** zeroPositions = zeroResult.first;
    int zeroCount = zeroResult.second;

    if (zeroCount > 0) {
        std::cout << "Нулевые элементы найдены на позициях:\n";
        for (int i = 0; i < zeroCount; ++i) {
            std::cout << "Строка: " << zeroPositions[0][i] << ", Столбец: " << zeroPositions[1][i] << '\n';
        }
        std::cout << "Общее количество нулевых элементов: " << zeroCount << std::endl;
    }
    else {
        std::cout << "Нулевые элементы отсутствуют.\n";
    }

    SwapArray(array, rows, cols);

    std::cout << "Массив после перестановки:\n";
    PrintArray(array, rows, cols);

    Free2DArray(array, rows);
    delete[] zeroPositions[0];
    delete[] zeroPositions[1];
    delete[] zeroPositions;

    return 0;

}

int main() {
    int num1;
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, определяющая, встречаются ли среди динамического массива элементы с нулевым значением. Если встречаются такие элементы, то определить их индексы и общее количество. Переставить элементы этого массива в обратном порядке и вывести на экран. \n";
    std::cout << "Выполнила Кебец Полина, группа 453502\n";
    do {
        std::cout << "Введите 1, если хотите перейти к решению. Введите 2, если хотите завершить работу программы\n";
        std::cin >> num1;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Неверный ввод. Пожалуйста, введите 1, чтобы перейти к решению ,или, 2, чтобы завершить работу программы." << std::endl;
            continue;
        }

        switch (num1)
        {
        case 1:
            Task();
            break;
        case 2:
            std::cout << "Программа завершена." << std::endl;
            break;
        default:
            std::cout << "Неверный ввод. Пожалуйста, введите 1, чтобы перейти к решению ,или, 2, чтобы завершить работу программы." << std::endl;
            break;
        }
    } while (num1 != 2);
    return 0;
}