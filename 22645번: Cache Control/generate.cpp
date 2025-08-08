#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// -------------------------
// Helpers: parsing & clamps
// -------------------------
struct Args {
    string type = "auto";     // scenario
    int n = -1;               // N
    int m = -1;               // M
    int k = -1;               // hotset size (if relevant)
    long long maxId = 1'000'000'000LL; // ID upper bound
};

static bool starts_with(const string& s, const string& p) {
    return s.size() >= p.size() && equal(p.begin(), p.end(), s.begin());
}

static long long clamp_ll(long long x, long long lo, long long hi) {
    return max(lo, min(hi, x));
}

static int pick_boundary_aware_int(int lo, int hi) {
    // Bias: 35% exact ends, 25% near ends, 40% uniform
    ensuref(lo <= hi, "pick_boundary_aware_int: lo>hi");
    int span = hi - lo + 1;
    int t = rnd.next(0, 99);
    if (t < 35) { // exact bounds
        return (rnd.next(0, 1) ? lo : hi);
    } else if (t < 60) { // near bounds
        int window = min(10, span);
        if (rnd.next(0, 1)) {
            return lo + rnd.next(0, window - 1);
        } else {
            return hi - rnd.next(0, window - 1);
        }
    }
    // uniform
    return rnd.next(lo, hi);
}

static long long pick_id(long long maxId) {
    // Favor boundaries and large numbers (consistent long long everywhere)
    int t = rnd.next(0, 99);
    if (t < 30) return 1;                         // min
    if (t < 60) return maxId;                     // max
    if (t < 75) {
        long long hi = std::min<long long>(1000LL, maxId);
        return rnd.next(1LL, hi);
    }
    return rnd.next(1LL, maxId);
}

// ------------------------------------
// Emit: prints header and all the IDs
// ------------------------------------
static void emit_case(int N, int M, const vector<long long>& a) {
    cout << N << " " << M << "\n";
    for (int i = 0; i < N; ++i) cout << a.at(i) << "\n";
}

// ------------------------------------
// Scenarios
// ------------------------------------
static vector<long long> gen_min(int& N, int& M, long long /*maxId*/) {
    N = 1; M = 1;
    return {1};
}

static vector<long long> gen_max_limits(int& N, int& M, long long maxId) {
    N = 100000; M = 100000;
    vector<long long> a; a.reserve(N);
    int block = 25000;

    // 1) Unique ascending
    for (int i = 1; i <= block; ++i) a.push_back(i);

    // 2) Hot set size M-1
    int K = max(1, M - 1);
    vector<long long> hot; hot.reserve(K);
    for (int i = 0; i < K; ++i) hot.push_back(500000000LL - i);
    for (int i = 0; i < block; ++i) a.push_back(hot[rnd.next(0, K - 1)]);

    // 3) Alternating two huge IDs
    long long A = maxId - 5, B = maxId - 4;
    for (int i = 0; i < block; ++i) a.push_back((i & 1) ? A : B);

    // 4) Thrash: unique near maxId
    for (int i = 0; i < block; ++i) a.push_back(maxId - i);

    return a;
}

static vector<long long> gen_all_same(int N, int /*M*/, long long /*maxId*/) {
    return vector<long long>(N, 123456789LL);
}

static vector<long long> gen_unique_gt_m(int N, int /*M*/, long long maxId) {
    vector<long long> a; a.reserve(N);
    long long hiBase = max(1LL, maxId - (long long)N);
    long long base = rnd.next(1LL, hiBase);
    for (int i = 0; i < N; ++i) a.push_back(base + i);
    return a;
}

static vector<long long> gen_unique_le_m(int N, int M, long long maxId) {
    N = min(N, M);
    vector<long long> a; a.reserve(N);
    long long hiBase = max(1LL, maxId - (long long)N);
    long long base = rnd.next(1LL, hiBase);
    for (int i = 0; i < N; ++i) a.push_back(base + i);
    return a;
}

static vector<long long> gen_alternating(int N, long long x, long long y) {
    vector<long long> a; a.reserve(N);
    for (int i = 0; i < N; ++i) a.push_back((i & 1) ? x : y);
    return a;
}

static vector<long long> gen_hotset(int N, int /*M*/, int K, long long maxId) {
    vector<long long> hot; hot.reserve(K);
    long long hiBase = max(1LL, maxId - (long long)K);
    long long start = rnd.next(1LL, hiBase);
    for (int i = 0; i < K; ++i) hot.push_back(start + i);

    vector<long long> a; a.reserve(N);
    for (int i = 0; i < N; ++i) {
        if (rnd.next(0, 99) < 80) a.push_back(hot[rnd.next(0, K - 1)]);
        else a.push_back(pick_id(maxId));
    }
    return a;
}

static vector<long long> gen_zipf(int N, int M, long long maxId) {
    int K = (int)clamp_ll(max(3, min(50000, max(2*M, 1000))), 3, 50000);
    vector<long double> pref(K + 1, 0.0L);
    long double s = 1.07L; // exponent
    for (int i = 1; i <= K; ++i) pref[i] = pref[i-1] + 1.0L / pow((long double)i, s);
    long double tot = pref[K];

    long long hiBase = max(1LL, maxId - (long long)K);
    long long base = rnd.next(1LL, hiBase);
    vector<long long> hot(K);
    for (int i = 0; i < K; ++i) hot[i] = base + i;

    vector<long long> a; a.reserve(N);
    for (int i = 0; i < N; ++i) {
        // testlib has rnd.next(double,double), not long double: use double then cast
        long double x = (long double)rnd.next(0.0, (double)tot);
        int idx = int(lower_bound(pref.begin(), pref.end(), x) - pref.begin());
        if (idx <= 0) idx = 1;
        if (idx > K) idx = K;

        if (rnd.next(0, 99) < 3) a.push_back(maxId - rnd.next(0, 999));
        else a.push_back(hot[idx - 1]);
    }
    return a;
}

static vector<long long> gen_random_uniform(int N, long long maxId) {
    vector<long long> a; a.reserve(N);
    for (int i = 0; i < N; ++i) a.push_back(pick_id(maxId));
    return a;
}

// -------------------------
// Main: parse, pick, emit
// -------------------------
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    Args A;
    // Parse key=value pairs
    for (int i = 1; i < argc; ++i) {
        string s = argv[i];
        if (starts_with(s, "type="))       A.type = s.substr(5);
        else if (starts_with(s, "n="))     A.n = atoi(s.substr(2).c_str());
        else if (starts_with(s, "m="))     A.m = atoi(s.substr(2).c_str());
        else if (starts_with(s, "k="))     A.k = atoi(s.substr(2).c_str());
        else if (starts_with(s, "maxId=")) A.maxId = atoll(s.substr(6).c_str());
        else if (starts_with(s, "seed="))  rnd.setSeed(atoll(s.substr(5).c_str()));
    }

    // Choose N, M with boundary bias if not provided
    int N = (A.n == -1) ? pick_boundary_aware_int(1, 100000) : A.n;
    int M = (A.m == -1) ? pick_boundary_aware_int(1, 100000) : A.m;

    // Clamp & validate
    N = (int)clamp_ll(N, 1, 100000);
    M = (int)clamp_ll(M, 1, 100000);
    A.maxId = clamp_ll(A.maxId, 1, 1'000'000'000LL);

    // If auto, pick a scenario with boundary-leaning probabilities
    if (A.type == "auto") {
        int r = rnd.next(0, 99);
        if (r < 8)       A.type = "min";
        else if (r < 18) A.type = "max_limits";
        else if (r < 30) A.type = "unique_gt_m";
        else if (r < 42) A.type = "alternating_m1";
        else if (r < 54) A.type = "hotset_gt";
        else if (r < 66) A.type = "hotset_eq";
        else if (r < 78) A.type = "hotset_lt";
        else if (r < 88) A.type = "zipf";
        else if (r < 94) A.type = "all_same";
        else if (r < 97) A.type = "unique_le_m";
        else             A.type = "random";
    }

    vector<long long> a;

    if (A.type == "min") {
        a = gen_min(N, M, A.maxId);
    } else if (A.type == "max_limits") {
        a = gen_max_limits(N, M, A.maxId);
    } else if (A.type == "all_same") {
        if (A.n == -1) N = 100000;
        if (A.m == -1) M = pick_boundary_aware_int(1, 10);
        a = gen_all_same(N, M, A.maxId);
    } else if (A.type == "unique_gt_m") {
        if (A.m == -1) M = pick_boundary_aware_int(1, 5);
        if (A.n == -1) N = 100000;
        a = gen_unique_gt_m(N, M, A.maxId);
    } else if (A.type == "unique_le_m") {
        if (A.n == -1) N = pick_boundary_aware_int(1, 100000);
        if (A.m == -1) M = max(N, 10);
        a = gen_unique_le_m(N, M, A.maxId);
    } else if (A.type == "alternating_m1") {
        M = 1;
        if (A.n == -1) N = pick_boundary_aware_int(2, 100000);
        long long x = pick_id(A.maxId), y = (x == 1 ? 2 : x - 1);
        a = gen_alternating(N, x, y);
    } else if (A.type == "alternating_m2") {
        M = 2;
        if (A.n == -1) N = pick_boundary_aware_int(2, 100000);
        long long x = pick_id(A.maxId), y = (x == A.maxId ? A.maxId - 1 : x + 1);
        a = gen_alternating(N, x, y);
    } else if (A.type == "hotset_lt" || A.type == "hotset_eq" || A.type == "hotset_gt") {
        if (A.n == -1) N = 100000;
        if (A.m == -1) M = pick_boundary_aware_int(1, 100000);
        int K;
        if (A.k != -1) K = A.k;
        else if (A.type == "hotset_lt") K = max(1, M - 1);
        else if (A.type == "hotset_eq") K = M;
        else                            K = min(100000, M + 1);
        K = (int)clamp_ll(K, 1, 100000);
        a = gen_hotset(N, M, K, A.maxId);
    } else if (A.type == "zipf") {
        if (A.n == -1) N = 100000;
        if (A.m == -1) M = pick_boundary_aware_int(1, 100000);
        a = gen_zipf(N, M, A.maxId);
    } else if (A.type == "random") {
        if (A.n == -1) N = pick_boundary_aware_int(1, 100000);
        if (A.m == -1) M = pick_boundary_aware_int(1, 100000);
        a = gen_random_uniform(N, A.maxId);
    } else {
        a = gen_random_uniform(N, A.maxId);
    }

    // Safety: ensure sizes and ranges
    ensuref(1 <= N && N <= 100000, "N out of bounds");
    ensuref(1 <= M && M <= 100000, "M out of bounds");
    ensuref((int)a.size() == N, "Generated sequence size mismatch");

    for (auto v : a)
        ensuref(1 <= v && v <= A.maxId, "ID out of range");

    emit_case(N, M, a);
    return 0;
}
