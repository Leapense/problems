#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static constexpr int ASCII_MIN = 32;
static constexpr int ASCII_MAX = 126;

char nonSpace() {
    return (char)rnd.next(ASCII_MIN + 1, ASCII_MAX);
}

char anyPrintable() {
    return (char)rnd.next(ASCII_MIN, ASCII_MAX);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int maxN = opt<int>("max_n", 50);
    int minN = opt<int>("min_n", 1);
    int maxQ = opt<int>("max_q", maxN);
    int minQ = opt<int>("min_q", 1);
    int seed = opt<int>("seed", 42);

    rnd.setSeed(seed);

    int N = rnd.next(minN, maxN);
    int Q = rnd.next(minQ, maxQ);

    cout << N << '\n';

    vector<string> grid(N, string(N, ' '));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            char ch = (c == N - 1)
                      ? nonSpace()
                      : anyPrintable();
            grid[r][c] = ch;
        }

        cout << grid[r] << '\n';
    }

    for (int i = 0; i < Q; ++i)
    {
        int len = rnd.next(1, N);
        string s(len, '?');
        for (int j = 0; j < len; ++j) s[j] = nonSpace();
        cout << s << '\n';
    }
}