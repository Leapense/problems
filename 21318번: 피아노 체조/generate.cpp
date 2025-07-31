#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

const int N_MIN = 1, N_MAX = 100000;
const int Q_MIN = 1, Q_MAX = 100000;
const long long SCORE_MIN = 1, SCORE_MAX = 1e9;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int pattern = -1;
    if (argc > 1) pattern = atoi(argv[1]);

    int N = rnd.next(N_MIN, N_MAX);
    int Q = rnd.next(Q_MIN, Q_MAX);
    if (argc > 2) {
        N = atoi(argv[2]);
        ensure(N_MIN <= N && N <= N_MAX);
    }
    if (argc > 3) {
        Q = atoi(argv[3]);
        ensure(Q_MIN <= Q && Q <= Q_MAX);
    }

    vector<long long> a(N);

    auto make_random_vals = [&](long long low, long long high) {
        for (int i = 0; i < N; ++i) a[i] = rnd.next(low, high);
    };

    if (pattern == 0) {
        for (int i = 0; i < N; ++i) a[i] = SCORE_MIN + i;
    } else if (pattern == 1) {
        for (int i = 0; i < N; ++i) a[i] = SCORE_MAX - i;
    } else if (pattern == 2) {
        long long v = rnd.next(SCORE_MIN, SCORE_MAX);
        fill(a.begin(), a.end(), v);
    } else if (pattern == 3) {
        long long big = SCORE_MAX;
        long long small = SCORE_MIN;

        for (int i = 0; i < N; ++i) {
            a[i] = (i & 1) ? small + i : big - i;
        }
    } else if (pattern == 4) {
        make_random_vals(SCORE_MIN, SCORE_MAX);
    } else {
        pattern = rnd.next(0, 4);

        if (pattern == 0) {
            for (int i = 0; i < N; ++i) a[i] = SCORE_MIN + i;
        } else if (pattern == 1) {
            for (int i = 0; i < N; ++i) a[i] = SCORE_MAX - i;
        } else if (pattern == 2) {
            long long v = rnd.next(SCORE_MIN, SCORE_MAX);
            fill(a.begin(), a.end(), v);
        } else if (pattern == 3) {
            long long big = SCORE_MAX;
            long long small = SCORE_MIN;
            for (int i = 0; i < N; ++i) {
                a[i] = (i & 1) ? small + i : big - i;
            }
        } else {
            make_random_vals(SCORE_MIN, SCORE_MAX);
        }
    }

    vector<pair<int,int>> qs;
    qs.reserve(Q);

    auto push = [&](int x, int y) {
        ensure(1 <= x && x <= y && y <= N);
        qs.emplace_back(x, y);
    };

    if (Q >= 4) {
        push(1, 1);
        push(N, N);
        push(1, N);
        push(N / 2 + 1, N);
    }

    while ((int)qs.size() < Q) {
        int x = rnd.next(1, N);
        int y = rnd.next(x, N);
        push(x, y);
    }

    println(N);
    for (int i = 0; i < N; ++i) {
        if (i) printf(" ");
        printf("%lld", a[i]);
    }
    printf("\n");
    println(Q);
    for (auto [x, y] : qs) println(x, y);
    return 0;
}