#include <iostream>
#include <cmath>
#include <locale.h>
#include "../Functions/Header.h"


int main() {
    int num1;
    setlocale(LC_ALL, "RU");
    std::cout << "���������, ��������� ������������ ������ �� ���������, ������������� �� ������� ��������� ������� � ������� ������ ��������. ��������� ������������ ��������� ������������� �������. \n";
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

   
}
