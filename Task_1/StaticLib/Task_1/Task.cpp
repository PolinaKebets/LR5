#include <iostream>
#include <cmath>

int Task() {
        std::cout << "Введите размерность массива: ";
        int n;
        std::cin >> n;

        double* array = new double[n];

        for (int i = 0; i < n; ++i) {
            std::cout << "Введите элемент x" << i << ": ";
            std::cin >> array[i];
        }

        int M_Pi = 3.141592653589793238462643;
        for (int i = 0; i < n; ++i) {
            array[i] = exp(-0.5 * i - 2 * M_Pi) - atan(i + 0.1);
        }
        
        std::cout << "Исходный массив: ";
        for (int i = 0; i < n; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < n; ++i) {
            if (array[i] < 0) {
                array[i] += 0.5;
            }
            else {
                array[i] = 0.1;
            }
        }

        std::cout << "Преобразованный массив: ";
        for (int i = 0; i < n; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;

        delete[] array;

        return 0;

}
