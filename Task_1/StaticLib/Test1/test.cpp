// task_test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "pch.h"

// Прототипы функций для использования в тестах
int Task();

// Класс для тестирования Task
class TaskTest : public ::testing::Test {
protected:
    // Этот метод вызывается до каждого теста
    void SetUp() override {
        // Переопределяем стандартные потоки ввода и вывода
        oldCinBuf = std::cin.rdbuf(input.rdbuf());
        oldCoutBuf = std::cout.rdbuf(output.rdbuf());
    }

    // Этот метод вызывается после каждого теста
    void TearDown() override {
        // Восстанавливаем стандартные потоки ввода и вывода
        std::cin.rdbuf(oldCinBuf);
        std::cout.rdbuf(oldCoutBuf);
    }

    // Потоки для переопределения ввода/вывода
    std::istringstream input;
    std::ostringstream output;

    // Указатели для сохранения стандартных потоков ввода/вывода
    std::streambuf* oldCinBuf;
    std::streambuf* oldCoutBuf;
};

// Тест на правильность работы функции Task
TEST_F(TaskTest, HandlesInputAndOutput) {
    input.str("3\n1\n2\n3\n");

    Task();

    std::string expectedOutput = "Введите размерность массива: "
        "Введите элемент x0: "
        "Введите элемент x1: "
        "Введите элемент x2: "
        "Исходный массив: -0.0432139 -0.105421 0.099574 \n"
        "Преобразованный массив: 0.456786 0.394579 0.1 \n";

    EXPECT_EQ(output.str().substr(0, expectedOutput.size()), expectedOutput);
}

// Главная функция для выполнения тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
