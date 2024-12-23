// task.cpp
#include <iostream>
#include <cmath>
#include <limits>
#include "pch.h"

int countElements(int* B, int start, int end) {
    if (end - start <= 1) {
        int count = 0;
        for (int i = start; i <= end; ++i) {
            if (cos(B[i] * B[i]) > 0 && B[i] < 0) {
                count++;
            }
        }
        return count;
    }

    int third = (end - start + 1) / 3 + start;

    int count1 = countElements(B, start, third - 1);

    int count2 = countElements(B, third, end);

    return count1 + count2;
}
 int Task() {
    int N;
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> N;

    int* B = new int[N];
    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int result = countElements(B, 0, N - 1);
    std::cout << "Количество элементов, удовлетворяющих условию: " << result << std::endl;

    // Освобождаем память
    delete[] B;

    return 0;
}

int main() {
  
    setlocale(LC_ALL, "Russian");
    int num1;
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, для заданного одномерного массива B из N элементов находит количество элементов массива, для которых выполняется некоторое условие, с применением рекурсивной функции. \n";
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
