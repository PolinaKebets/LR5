#include <limits>
#include <Windows.h>
#include <iostream>
#include <cmath>  
#include "..\DynamicLib\Header.h"

#undef max

int main() {
    HINSTANCE load;
    load = LoadLibrary(L"C:\\Users\\USER\\OneDrive\\Документы\\OAIP\\LR5\\Task_2\\Task_2\\x64\\Debug\\DynamicLib.dll");
    
    typedef int(__stdcall* cntEl)();
    cntEl countElements;

    typedef int(__stdcall* Tsk)();
    Tsk Task;

    countElements = (cntEl)GetProcAddress(load, "countElements");
    Task = (Tsk)GetProcAddress(load, "Task");

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

    FreeLibrary(load);
}
