#include "testlib.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

static const int MAX_N = 100000;
static const int MAX_K = 100000;
static const int MAX_S = 50;
static const int MAX_P = 10000;

int clampInt(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

int parseIntOrRandom(const std::string& s, int lo, int hi) {
    if (s == "rand" || s == "auto") return rnd.next(lo, hi);
    int v = std::stoi(s);
    return clampInt(v, lo, hi);
}

enum class Dist {
    Uniform,
    Inc,
    Dec,
    Blocks,
    Spikes,
    SkewSmall,
    SkewLarge
};

Dist parseDist(const std::string& s) {
    if (s == "uniform") return Dist::Uniform;
    if (s == "inc") return Dist::Inc;
    if (s == "dec") return Dist::Dec;
    if (s == "blocks") return Dist::Blocks;
    if (s == "spikes") return Dist::Spikes;
    if (s == "skewSmall") return Dist::SkewSmall;
    if (s == "skewLarge") return Dist::SkewLarge;
    return Dist::Uniform;
}

std::vector<int> genUniform(int n, int lo, int hi) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd.next(lo, hi);
    return a;
}

std::vector<int> genBlocks(int n, int lo, int hi) {
    std::vector<int> a;
    a.reserve(n);
    int maxBlocks = std::min(n, 50);
    int blocks = rnd.next(1, std::max(1, maxBlocks));
    int remaining = n;
    for (int i = 0; i < blocks; ++i) {
        int remainBlocks = blocks - i - 1;
        int maxLen = remaining - remainBlocks;
        int len = (i == blocks - 1) ? remaining : rnd.next(1, std::max(1, maxLen));
        int val = rnd.next(lo, hi);
        for (int j = 0; j < len; ++j) a.push_back(val);
        remaining -= len;
    }

    if ((int)a.size() > n) a.resize(n);
    return a;
}

std::vector<int> genSpikes(int n, int lo, int hi) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        bool bigSpike = rnd.next(0, 99) < 12;
        if (bigSpike) {
            a[i] = rnd.wnext(lo, hi, +9);
        } else {
            a[i] = rnd.wnext(lo, hi, -9);
        }
    }

    return a;
}

std::vector<int> genSkewSmall(int n, int lo, int hi) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd.wnext(lo, hi, -7);
    return a;
}

std::vector<int> genSkewLarge(int n, int lo, int hi) {
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rnd.wnext(lo, hi, +7);
    return a;
}

std::vector<int> generatePops(int n, int lo, int hi, Dist dist) {
    if (dist == Dist::Uniform) {
        return genUniform(n, lo, hi);
    } else if (dist == Dist::Blocks) {
        return genBlocks(n, lo, hi);
    } else if (dist == Dist::Spikes) {
        return genSpikes(n, lo, hi);
    } else if (dist == Dist::SkewSmall) {
        return genSkewSmall(n, lo, hi);
    } else if (dist == Dist::SkewLarge) {
        return genSkewLarge(n, lo, hi);
    } else if (dist == Dist::Inc) {
        std::vector<int> a = genUniform(n, lo, hi);
        std::sort(a.begin(), a.end());
        return a;
    } else if (dist == Dist::Dec) {
        std::vector<int> a = genUniform(n, lo, hi);
        std::sort(a.begin(), a.end(), std::greater<int>());
        return a;
    }
    return genUniform(n, lo, hi);
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = (argc > 2) ? parseIntOrRandom(argv[2], 1, MAX_N) : rnd.next(1, MAX_N);
    int k = (argc > 3) ? parseIntOrRandom(argv[3], 1, MAX_K) : rnd.next(1, MAX_K);
    int s = (argc > 4) ? parseIntOrRandom(argv[4], 1, MAX_S) : rnd.next(1, MAX_S);
    std::string distStr = (argc > 5) ? std::string(argv[5]) : std::string("uniform");
    int minP = (argc > 6) ? parseIntOrRandom(argv[6], 1, MAX_P) : 1;
    int maxP = (argc > 7) ? parseIntOrRandom(argv[7], 1, MAX_P) : MAX_P;
    if (minP > maxP) std::swap(minP, maxP);
    Dist dist = parseDist(distStr);
    std::vector<int> pops = generatePops(n, minP, maxP, dist);
    std::cout << n << " " << k << " " << s << "\n";
    for (int i = 0; i < n; ++i) {
        if (i > 0) std::cout << " ";
        std::cout << pops[i];
    }

    std::cout << "\n";
    return 0;
}