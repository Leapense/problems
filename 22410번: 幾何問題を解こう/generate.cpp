// gen.cpp — C++26 test generator (testlib.h)
// Generates ONE pair "p q" per run, respecting: 0 < p < q < 1e9
// Usage examples:
//   ./gen type=min seed=1
//   ./gen type=r_big_prime seed=42
//   ./gen type=random seed=20250808
//
// Compile: g++ -std=c++2c -O2 -pipe -static -s -o gen gen.cpp
#include <bits/stdc++.h>
#include "testlib.h"

using u64 = uint64_t;
using u128 = unsigned __int128;

static constexpr u64 MAXQ = 1'000'000'000ULL - 1; // q < 1e9

// --- Miller-Rabin for 32-bit range (deterministic bases) ---
static u64 mulmod(u64 a, u64 b, u64 m) {
    return (u128)a * b % m;
}
static u64 powmod(u64 a, u64 e, u64 m) {
    u64 r = 1 % m;
    while (e) {
        if (e & 1) r = mulmod(r, a, m);
        a = mulmod(a, a, m);
        e >>= 1;
    }
    return r;
}
static bool isPrime(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}) {
        if (n % p == 0) return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    // Deterministic for 32-bit using small bases; these also work quickly up to 1e12+.
    const u64 bases[] = {2, 3, 5, 7, 11};
    for (u64 a : bases) {
        if (a % n == 0) continue;
        u64 x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool comp = true;
        for (u64 r = 1; r < s; ++r) {
            x = mulmod(x, x, n);
            if (x == n - 1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}
static u64 prevPrimeLE(u64 n) {
    if (n < 2) return 0;
    if (n % 2 == 0) --n;
    for (; n >= 2; n -= 2) {
        if (isPrime(n)) return n;
        if (n == 3) return 3;
    }
    return 0;
}
static u64 nextPrimeGE(u64 n) {
    if (n <= 2) return 2;
    if ((n & 1) == 0) ++n;
    for (;; n += 2) if (isPrime(n)) return n;
}

// Pick t in [1, r-1] with gcd(t,r)=1 so that gcd(g*t, g*r) == g.
static u64 randomCoprimeBelow(u64 r) {
    // r >= 2 expected
    for (int tries = 0; tries < 1000; ++tries) {
        u64 t = rnd.next(1U, (unsigned)r - 1U);
        if (std::gcd(t, r) == 1) return t;
    }
    // Fallback: find deterministically
    for (u64 t = 1; t < r; ++t) if (std::gcd(t, r) == 1) return t;
    // Should never happen for r>=2
    return 1;
}

static void emit(u64 r, u64 g) {
    ensuref(r >= 2, "r must be >= 2 (since 0<p<q)");
    ensuref(g >= 1, "g must be >= 1");
    // Enforce q < 1e9
    ensuref(g <= MAXQ / r, "g too large: g*r must be < 1e9");
    u64 q = g * r;
    u64 t = randomCoprimeBelow(r);
    u64 p = g * t;
    ensuref(0 < p && p < q && q < 1'000'000'000ULL, "0 < p < q < 1e9 violated");
    printf("%" PRIu64 " %" PRIu64 "\n", p, q);
}

// Build a very smooth r by stuffing small primes with random exponents.
static u64 buildSmoothR() {
    static const int primes[] = {2,3,5,7,11,13};
    u64 r = 1;
    // Randomize order a bit
    std::vector<int> ps(std::begin(primes), std::end(primes));
    shuffle(ps.begin(), ps.end());
    for (int p : ps) {
        int eMax = (p == 2) ? 29 : (p == 3 ? 18 : 12); // loose caps, we’ll stop early by limit
        int e = rnd.next(1, std::min(5, eMax)); // moderate exponents to keep r sizable but <1e9
        while (e-- > 0 && r <= MAXQ / p) r *= p;
    }
    if (r < 2) r = 6; // ensure >=2
    return r;
}

// Build semiprime near sqrt boundary.
static u64 buildSemiprimeClose() {
    // Target around sqrt(1e9) ~ 31623
    int base1 = 31643 + rnd.next(-500, 500);
    int base2 = 31607 + rnd.next(-500, 500);
    u64 p1 = prevPrimeLE(std::max(2, base1));
    u64 p2 = prevPrimeLE(std::max(2, base2));
    if (p1 == 0) p1 = 31627;
    if (p2 == 0) p2 = 31627;
    // Ensure product <= MAXQ; if not, step down p2.
    while (p1 * p2 > MAXQ) {
        p2 = prevPrimeLE((u64)std::max(2, (int)p2 - 2));
        if (p2 < 2) { p1 = prevPrimeLE(p1 - 2); p2 = prevPrimeLE(31627); }
    }
    u64 r = p1 * p2;
    if (r < 2) r = 30011ULL * 30013ULL; // safe fallback
    return r;
}

// Largest power of two < 1e9 (2^29)
static u64 largestPow2() {
    return 1ULL << 29; // 536,870,912
}

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    std::string type = opt<std::string>("type", "random");
    // rnd is already seeded by registerGen via 'seed='. Nothing to do.

    if (type == "min") {
        // Smallest legal input.
        emit(/*r=*/2, /*g=*/1);
    } else if (type == "near_limit") {
        // q very close to 1e9-1; choose r as a large prime <= MAXQ, g=1.
        u64 start = MAXQ - (u64)rnd.next(0, 1000);
        u64 r = prevPrimeLE(start);
        if (r < 2) r = prevPrimeLE(MAXQ);
        emit(r, /*g=*/1);
    } else if (type == "gcd_heavy") {
        // Make gcd almost as big as q: r=2, pick big g so q ~ 1e9.
        u64 r = 2;
        u64 g = MAXQ / r; // largest possible
        // But ensure p<q with t=1 (coprime to r), p=g, q=2g works.
        emit(r, g);
    } else if (type == "r_power2") {
        u64 r = largestPow2();
        // Pick g small enough (often 1) to keep q < 1e9.
        u64 g = rnd.next(1U, (unsigned)(MAXQ / r));
        emit(r, g);
    } else if (type == "r_smooth") {
        u64 r = buildSmoothR();
        u64 gmax = MAXQ / r;
        u64 g = rnd.next(1U, (unsigned)std::max<u64>(1, gmax));
        emit(r, g);
    } else if (type == "r_semiprime_close") {
        u64 r = buildSemiprimeClose();
        u64 gmax = MAXQ / r;
        u64 g = rnd.next(1U, (unsigned)std::max<u64>(1, gmax));
        emit(r, g);
    } else if (type == "r_big_prime") {
        // Find a large prime r near MAXQ; g must be 1 (else q would overflow).
        u64 r = prevPrimeLE(MAXQ - rnd.next(0, 2000));
        if (r < 2) r = prevPrimeLE(MAXQ);
        emit(r, /*g=*/1);
    } else if (type == "q_prime") {
        // Choose a prime q and random 1<=p<q.
        u64 q = prevPrimeLE(MAXQ - rnd.next(0, 5000));
        if (q < 3) q = 3;
        u64 p = rnd.next(1U, (unsigned)q - 1U);
        printf("%" PRIu64 " %" PRIu64 "\n", p, q);
    } else if (type == "random") {
        // Blend of patterns; bias toward tricky r.
        int pick = rnd.next(1, 7);
        if (pick == 1) {
            u64 r = buildSmoothR(); u64 g = rnd.next(1U, (unsigned)(MAXQ / r)); emit(r, g);
        } else if (pick == 2) {
            u64 r = largestPow2(); u64 g = rnd.next(1U, (unsigned)(MAXQ / r)); emit(r, g);
        } else if (pick == 3) {
            u64 r = buildSemiprimeClose(); u64 g = rnd.next(1U, (unsigned)std::max<u64>(1, MAXQ / r)); emit(r, g);
        } else if (pick == 4) {
            u64 r = prevPrimeLE(MAXQ - rnd.next(0, 2000)); if (r < 2) r = 2; emit(r, 1);
        } else if (pick == 5) {
            // Generic random q,p; still valid and often coprime.
            u64 q = rnd.next(2U, (unsigned)MAXQ);
            u64 p = rnd.next(1U, (unsigned)q - 1U);
            printf("%" PRIu64 " %" PRIu64 "\n", p, q);
        } else if (pick == 6) {
            // gcd-heavy
            emit(2, MAXQ / 2);
        } else {
            // near_limit
            u64 r = prevPrimeLE(MAXQ - rnd.next(0, 1000)); if (r < 2) r = 2; emit(r, 1);
        }
    } else {
        // Fallback: treat as random
        u64 q = rnd.next(2U, (unsigned)MAXQ);
        u64 p = rnd.next(1U, (unsigned)q - 1U);
        printf("%" PRIu64 " %" PRIu64 "\n", p, q);
    }
}