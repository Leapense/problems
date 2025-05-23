#include "gtest/gtest.h"
#include "../cpp/src/main.h"

TEST(CalculatorTest, SampleTest)
{
    // Пример из условия: 72 2 1 1 -> 4
    EXPECT_EQ(solve(72, 2, 1, 1), 4u);
}

TEST(CalculatorTest, NoOperations)
{
    // Если операций нет, результат равен исходному числу.
    EXPECT_EQ(solve(1, 0, 0, 0), 1u);
    EXPECT_EQ(solve(100, 0, 0, 0), 100u);
}

TEST(CalculatorTest, OperationAOnly)
{
    // Только операция A
    // Пример: n = 80, a = 1 -> 80 / 2 = 40
    EXPECT_EQ(solve(80, 1, 0, 0), 40u);
    // Несколько операций A: n = 100, a = 3 -> floor(floor(floor(100/2)/2)/2) = floor(floor(50/2)/2)= floor(25/2)=12
    EXPECT_EQ(solve(100, 3, 0, 0), 12u);
}

TEST(CalculatorTest, OperationBOnly)
{
    // Только операция B
    // Пример: n = 239, b = 1 -> floor((239+1)/2) = 120
    EXPECT_EQ(solve(239, 0, 1, 0), 120u);
}

TEST(CalculatorTest, OperationCOnly)
{
    // Только операция C
    // Пример: n = 239, c = 1 -> floor((239-1)/2) = 119
    EXPECT_EQ(solve(239, 0, 0, 1), 119u);
    // При n = 0, операция C не изменяет число.
    EXPECT_EQ(solve(0, 0, 0, 5), 0u);
}

TEST(CalculatorTest, MixedOperations)
{
    // Смешанный набор операций
    // Пример: n = 50, a = 1, b = 1, c = 1.
    // Возможные варианты применения операций.
    uint64_t result = solve(50, 1, 1, 1);
    // Проверяем, что результат не превышает исходное число и является логичным.
    EXPECT_LE(result, 50u);

    // Дополнительный тест: n = 1000, a = 2, b = 3, c = 1.
    result = solve(1000, 2, 3, 1);
    EXPECT_LE(result, 1000u);
}

TEST(CalculatorTest, EdgeCases)
{
    // Граничные случаи
    // n = 1, а, b, c ненулевые
    EXPECT_EQ(solve(1, 1, 1, 1), 0u);

    // Максимальные значения для a, b, c (но маленькое n для скорости теста)
    EXPECT_LE(solve(100, 60, 60, 60), 100u);
}