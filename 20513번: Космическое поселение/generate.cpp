#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using u64   = unsigned long long;

static int64 rand_ll(int64 lo, int64 hi) { return rnd.next(lo, hi); }

struct Limits {
    int64 maxN     = 1'000'000'000'000LL;  // 1e12
    int64 maxWH    = 1'000'000'000LL;      // 1e9
    int64 maxField = 1'000'000'000'000LL;  // 1e12
};

void emit_tiny() {
    int64 n = rand_ll(1, 10);
    int64 w = rand_ll(1, 10);
    int64 h = rand_ll(1, 10);
    int64 W = rand_ll(w, 10);
    int64 H = rand_ll(h, 10);
    println(n, w, h, W, H);
}

void emit_thin_field(const Limits &L) {
    int64 n = rand_ll(1, L.maxN);
    int64 w = rand_ll(1, L.maxWH);
    int64 h = rand_ll(1, L.maxWH);
    bool row  = rnd.next(0, 1);
    int64 W = row ? L.maxField : rand_ll(max<int64>(1, w >> 1), L.maxField);
    int64 H = row ? rand_ll(max<int64>(1, h >> 1), L.maxField) : 1;
    println(n, w, h, W, H);
}

void emit_rotation_sensitive(const Limits &L) {
    // Make w ≫ h so rotation matters.
    int64 h = rand_ll(1, min<int64>(1'000'000LL, L.maxWH));
    int64 w = rand_ll(h * 5, L.maxWH);           // elongated
    int64 n = rand_ll(1, L.maxN);

    // Field that barely accommodates one orientation.
    bool feasible = rnd.next(0, 1);              // 50 % chance each side
    int64 W, H;
    if (feasible) {
        W = w * rand_ll(1, 3);
        H = h * rand_ll((int64)ceil(sqrt((double)n)), 5);
    } else {
        W = h * rand_ll(1, 3);
        H = w * rand_ll(1, 3);
    }
    W = min(W, L.maxField);
    H = min(H, L.maxField);
    println(n, w, h, W, H);
}

void emit_random(const Limits &L) {
    int64 n = rand_ll(1, L.maxN);
    int64 w = rand_ll(1, L.maxWH);
    int64 h = rand_ll(1, L.maxWH);
    int64 W = rand_ll(max<int64>(w, 1), L.maxField);
    int64 H = rand_ll(max<int64>(h, 1), L.maxField);
    println(n, w, h, W, H);
}

void emit_near_limits(const Limits &L) {
    int64 n = rand_ll(L.maxN - 10, L.maxN);
    int64 w = rand_ll(L.maxWH - 10, L.maxWH);
    int64 h = rand_ll(L.maxWH - 10, L.maxWH);
    int64 W = rand_ll(L.maxField - 10, L.maxField);
    int64 H = rand_ll(L.maxField - 10, L.maxField);
    println(n, w, h, W, H);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int idx = 1;
    int T = (argc > ++idx ? atoi(argv[idx]) : 100);
    Limits L;
    if (argc > ++idx) L.maxN     = atoll(argv[idx]);
    if (argc > ++idx) L.maxWH    = atoll(argv[idx]);
    if (argc > ++idx) L.maxField = atoll(argv[idx]);

    for (int t = 0; t < T; ++t) {
        double dice = rnd.next(0.0, 1.0);   // uniform [0,1)
        if (dice < 0.10)           emit_tiny();
        else if (dice < 0.20)      emit_thin_field(L);
        else if (dice < 0.40)      emit_rotation_sensitive(L);
        else if (dice < 0.90)      emit_random(L);
        else                       emit_near_limits(L);
    }
    return 0;
}