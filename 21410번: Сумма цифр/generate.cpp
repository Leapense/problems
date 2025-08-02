#include "testlib.h"
#include <bits/stdc++.h>

using int64 = long long;
using u64 = unsigned long long;
const u64 LIM = 1000000000000000000ULL;

std::vector<u64> buildCornerCases() {
    std::vector<u64> v = {1, LIM};
    for (int d = 1; d < 18; ++d) {
        u64 nine = 1;
        for (int i = 0; i < d; ++i) nine = nine * 10 + 9;
        v.push_back(nine);
        v.push_back(nine + 1);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

std::vector<u64> buildPatternCases() {
    std::vector<u64> v;
    {
        u64 x = 0;
        for (int i = 0; i < 18; ++i) {
            x = x * 10 + (i & 1 ? 0 : 1);
            v.push_back(x);
        }
    }

    for (int len = 2; len <= 18; ++len) {
        u64 x = 1;
        for (int i = 1; i < len; ++i) x += 9 * (u64)std::pow(10, i);
        v.push_back(x);
    }

    v.push_back(123456789012345678ULL);
    v.push_back(987654321098765432ULL);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 3) {
        quitf(_fail, "Usage: %s <mode:[corner|random|pattern]> <cnt>", argv[0]);
    }

    std::string mode = argv[1];
    int cnt = atoi(argv[2]);
    ensuref(cnt > 0, "cnt must be positive");

    if (mode == "corner") {
        auto cases = buildCornerCases();
        ensuref(cnt <= (int)cases.size(), "cnt=%d exceeds available corner cases=%zu", cnt, cases.size());
        shuffle(cases.begin(), cases.end());
        for (int i = 0; i < cnt; ++i) {
            println(cases[i]);
        }
    } else if (mode == "pattern") {
        auto cases = buildPatternCases();
        ensuref(cnt <= (int)cases.size(), "cnt=%d exceeds available pattern cases=%zu", cnt, cases.size());
        shuffle(cases.begin(), cases.end());
        for (int i = 0; i < cnt; ++i) {
            println(cases[i]);
        }
    } else if (mode == "random") {
        for (int i = 0; i < cnt; ++i) {
            println(rnd.next((u64)1, LIM));
        }
    } else {
        quitf(_fail, "Unknown mode '%s'", mode.c_str());
    }
    return 0;
}