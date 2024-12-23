#include <iostream>
#include <cmath>  
extern "C" __declspec(dllexport) int countElements(int* B, int start, int end) {
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

extern "C" __declspec(dllexport) int Task() {
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