#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static const string MIRROR_KEYS = 
    "AHIMOTUVWXY"
    "018"
    "nouvwxilm"
    "bdpq"
    "S2E3Z5"
    "7r";

bool hasMirrorVariant(char c) {
    char lo = (char)tolower((unsigned char) c);
    char up = (char)toupper((unsigned char) c);
    return MIRROR_KEYS.find(lo) != string::npos ||
           MIRROR_KEYS.find(up) != string::npos;
}

char randomGoodChar() {
    while (true) {
        char c = (char)rnd.next('A', 'z');
        if (hasMirrorVariant(c)) return c;
    }
}

char randomBadChar() {
    while (true) {
        char c = (char)rnd.next(32, 126);
        if (!hasMirrorVariant(c)) return c;
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    rnd.setSeed(time(NULL));
    int minLen = opt<int>("min_len", 1);
    int maxLen = opt<int>("max_len", 1000);
    int badProb = opt<int>("bad_prob", 0);

    ensure(1 <= minLen && minLen <= maxLen);
    ensure(0 <= badProb && badProb <= 100);

    int n = rnd.next(minLen, maxLen);

    string s;
    s.reserve(n);
    for (int i = 0; i < n; ++i) {
        bool makeBad = rnd.next(0, 99) < badProb;
        s += makeBad ? randomBadChar() : randomGoodChar();
    }

    cout << s << "\n";
    return 0;
}