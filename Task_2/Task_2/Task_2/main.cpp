#include <limits>
#include <Windows.h>
#include <iostream>
#include <cmath>  
#include "..\DynamicLib\Header.h"

#undef max

int main() {
    HINSTANCE load;
    load = LoadLibrary(L"C:\\Users\\USER\\OneDrive\\���������\\OAIP\\LR5\\Task_2\\Task_2\\x64\\Debug\\DynamicLib.dll");
    
    typedef int(__stdcall* cntEl)();
    cntEl countElements;

    typedef int(__stdcall* Tsk)();
    Tsk Task;

    countElements = (cntEl)GetProcAddress(load, "countElements");
    Task = (Tsk)GetProcAddress(load, "Task");

    setlocale(LC_ALL, "Russian");
    int num1;
    setlocale(LC_ALL, "RU");
    std::cout << "���������, ��� ��������� ����������� ������� B �� N ��������� ������� ���������� ��������� �������, ��� ������� ����������� ��������� �������, � ����������� ����������� �������. \n";
    std::cout << "��������� ����� ������, ������ 453502\n";

    do {
        std::cout << "������� 1, ���� ������ ������� � �������. ������� 2, ���� ������ ��������� ������ ���������\n";
        std::cin >> num1;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�������� ����. ����������, ������� 1, ����� ������� � ������� ,���, 2, ����� ��������� ������ ���������." << std::endl;
            continue;
        }

        switch (num1)
        {
        case 1:
            Task();
            break;
        case 2:
            std::cout << "��������� ���������." << std::endl;
            break;
        default:
            std::cout << "�������� ����. ����������, ������� 1, ����� ������� � ������� ,���, 2, ����� ��������� ������ ���������." << std::endl;
            break;
        }
    } while (num1 != 2);
    return 0;

    FreeLibrary(load);
}
