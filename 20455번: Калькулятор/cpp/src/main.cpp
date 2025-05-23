#include "main.h"
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

// Структура ключа для мемоизации
struct Key
{
    int a, b, c;
    uint64_t x;

    bool operator==(const Key &other) const
    {
        return a == other.a && b == other.b && c == other.c && x == other.x;
    }
};

// Хеш-функция для структуры Key
struct KeyHash
{
    size_t operator()(const Key &k) const
    {
        size_t res = 17;
        res = res * 31 + std::hash<int>()(k.a);
        res = res * 31 + std::hash<int>()(k.b);
        res = res * 31 + std::hash<int>()(k.c);
        res = res * 31 + std::hash<uint64_t>()(k.x);
        return res;
    }
};

namespace
{
    // Локальная мемоизация, которая будет сбрасываться при каждом вызове solve.
    unordered_map<Key, uint64_t, KeyHash> memo;

    // Рекурсивная функция динамического программирования
    uint64_t dp(int a, int b, int c, uint64_t x)
    {
        // Если x уже 0, дальнейшие операции не изменят результат.
        if (x == 0)
            return 0;
        // Если операций не осталось, возвращаем x.
        if (a == 0 && b == 0 && c == 0)
            return x;

        Key key{a, b, c, x};
        if (memo.find(key) != memo.end())
            return memo[key];

        uint64_t best = numeric_limits<uint64_t>::max();

        // Операция A: x -> floor(x/2)
        if (a > 0)
        {
            uint64_t nx = x / 2;
            best = min(best, dp(a - 1, b, c, nx));
        }
        // Операция B: x -> floor((x+1)/2)
        if (b > 0)
        {
            uint64_t nx = (x + 1) / 2;
            best = min(best, dp(a, b - 1, c, nx));
        }
        // Операция C: если x > 0, x -> floor((x-1)/2), иначе 0.
        if (c > 0)
        {
            uint64_t nx = (x > 0 ? (x - 1) : x) / 2;
            best = min(best, dp(a, b, c - 1, nx));
        }

        memo[key] = best;
        return best;
    }
} // end anonymous namespace

uint64_t solve(uint64_t n, int a, int b, int c)
{
    memo.clear(); // Сброс мемоизации для повторных вызовов
    return dp(a, b, c, n);
}

#ifndef UNIT_TESTS
// Функция main для запуска решения при обычном запуске программы
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint64_t n;
    int a, b, c;
    cin >> n >> a >> b >> c;

    cout << solve(n, a, b, c) << "\n";
    return 0;
}
#endif