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
    std::cout << "������� ���������� ��������� � �������: ";
    std::cin >> N;

    int* B = new int[N];
    std::cout << "������� �������� �������: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> B[i];
    }

    int result = countElements(B, 0, N - 1);
    std::cout << "���������� ���������, ��������������� �������: " << result << std::endl;

    // ����������� ������
    delete[] B;

    return 0;
}

int main() {
  
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

}
