#ifndef MAIN_H
#define MAIN_H

#include <cstdint>

/// \brief Решает задачу калькулятора.
/// \param n исходное число
/// \param a количество операций A
/// \param b количество операций B
/// \param c количество операций C
/// \return минимальное число, которое может получиться
uint64_t solve(uint64_t n, int a, int b, int c);

#endif // MAIN_H