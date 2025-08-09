#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return (static_cast<size_t>(p.first) << 6) ^ static_cast<size_t>(p.second);
    }
};

static void add_case(unordered_set<pair<int, int>, PairHash>& S, int N, int M) {
    if (N < 2 || N > 20) return;
    if (M < 1 || M >= N) return;
    S.emplace(N, M);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const bool doBoundary = !has_opt("no-boundary");
    const bool doStructured = !has_opt("no-structured");
    const int Krandom = opt<int>("rand", 60);

    if (!has_opt("seed")) {
        int timeSeed = (int)time(nullptr) ^ (getpid() << 16);
        rnd.setSeed(timeSeed);
    }

    unordered_set<pair<int,int>, PairHash> S;
    S.reserve(512);

    if (doBoundary) {
        for (int N = 2; N <= 20; ++N) {
            add_case(S, N, 1);
            add_case(S, N, N - 1);
        }

        for (int N = 3; N <= 20; ++N) add_case(S, N, 2);
        for (int N = 4; N <= 20; ++N) add_case(S, N, N - 2);

        add_case(S, 2, 1);
        add_case(S, 20, 1);
        add_case(S, 20, 19);
    }

    if (doStructured) {
        for (int N = 2; N <= 20; ++N) {
            auto mid1 = max(1, N / 2);
            auto mid2 = max(1, (N + 2) / 3);
            auto mid3 = max(1, (2 * N) / 3);
            if (mid1 >= N) mid1 = N - 1;
            if (mid2 >= N) mid2 = N - 1;
            if (mid3 >= N) mid3 = N - 1;
            add_case(S, N, mid1);
            add_case(S, N, mid2);
            add_case(S, N, mid3);

            if (N >= 5) add_case(S, N, 3);
            if (N >= 6) add_case(S, N, N - 3);
        }
    }

    for (int t = 0; t < Krandom; ++t) {
        int N = rnd.next(2, 20);
        int M = rnd.next(1, N - 1);
        add_case(S, N, M);
    }

    vector<pair<int,int>> cases(S.begin(), S.end());
    ::shuffle(cases.begin(), cases.end());
    
    for (auto [N, M] : cases) {
        printf("%d %d\n", N, M);
    }
    println("0 0");

    return 0;
}