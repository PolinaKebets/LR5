#include <iostream>
#include <cmath>
#include <locale.h>
#include "../Functions/Header.h"


int main() {
    int num1;
    setlocale(LC_ALL, "RU");
    std::cout << "Программа, создающая динамический массив из элементов, расположенных на главной диагонали матрицы и имеющих четное значение. Вычисляет произведение элементов динамического массива. \n";
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
