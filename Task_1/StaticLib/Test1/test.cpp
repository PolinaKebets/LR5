// task_test.cpp
#include <gtest/gtest.h>
#include <sstream>
#include "pch.h"

// ��������� ������� ��� ������������� � ������
int Task();

// ����� ��� ������������ Task
class TaskTest : public ::testing::Test {
protected:
    // ���� ����� ���������� �� ������� �����
    void SetUp() override {
        // �������������� ����������� ������ ����� � ������
        oldCinBuf = std::cin.rdbuf(input.rdbuf());
        oldCoutBuf = std::cout.rdbuf(output.rdbuf());
    }

    // ���� ����� ���������� ����� ������� �����
    void TearDown() override {
        // ��������������� ����������� ������ ����� � ������
        std::cin.rdbuf(oldCinBuf);
        std::cout.rdbuf(oldCoutBuf);
    }

    // ������ ��� ��������������� �����/������
    std::istringstream input;
    std::ostringstream output;

    // ��������� ��� ���������� ����������� ������� �����/������
    std::streambuf* oldCinBuf;
    std::streambuf* oldCoutBuf;
};

// ���� �� ������������ ������ ������� Task
TEST_F(TaskTest, HandlesInputAndOutput) {
    input.str("3\n1\n2\n3\n");

    Task();

    std::string expectedOutput = "������� ����������� �������: "
        "������� ������� x0: "
        "������� ������� x1: "
        "������� ������� x2: "
        "�������� ������: -0.0432139 -0.105421 0.099574 \n"
        "��������������� ������: 0.456786 0.394579 0.1 \n";

    EXPECT_EQ(output.str().substr(0, expectedOutput.size()), expectedOutput);
}

// ������� ������� ��� ���������� ������
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
