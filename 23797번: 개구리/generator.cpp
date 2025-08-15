#include "testlib.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

static const int MAX_N = 1000000;

string genUniform(int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        s.push_back(rnd.next(0, 1) == 0 ? 'K' : 'P');
    }
    return s;
}

string genAlt(int n, char start) {
    string s;
    s.reserve(n);
    char a = start;
    char b = (start == 'K') ? 'P' : 'K';
    for (int i = 0; i < n; i++) {
        s.push_back((i % 2 == 0) ? a : b);
    }
    return s;
}

string genBlocks(int n, int maxBlock) {
    string s;
    s.reserve(n);
    while ((int)s.size() < n) {
        char c = rnd.next(0, 1) == 0 ? 'K' : 'P';
        int len = rnd.next(1, maxBlock);
        int add = min(len, n - (int)s.size());
        s.append(add, c);
    }

    return s;
}

string genAll(int n, char ch) {
    return string(n, ch);
}

string genPeak(int n, int f, char ch) {
    string s;
    s.reserve(n);
    s.append(min(f, n), ch);
    if ((int)s.size() < n) {
        char other = (ch == 'K') ? 'P' : 'K';
        bool turnOther = true;
        while ((int)s.size() < n) {
            s.push_back(turnOther ? other : ch);
            turnOther = !turnOther;
        }
    }

    return s;
}

string genBiased(int n, int pK) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) {
        int v = rnd.next(0, 99);
        s.push_back(v < pK ? 'K' : 'P');
    }

    return s;
}

string genRuns(int n, int minRun, int maxRun) {
    string s;
    s.reserve(n);
    while ((int)s.size() < n) {
        char c = rnd.next(0, 1) == 0 ? 'K' : 'P';
        int len = rnd.next(minRun, maxRun);
        int add = min(len, n - (int)s.size());
        s.append(add, c);
    }

    return s;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int last = argc - 1;
    ensuref(argc >= 3, "usage: ./gen <mode> <params...> <seed>");
    string mode = argv[1];

    if (mode == "uniform") {
        ensuref(argc >= 4, "uniform: ./gen uniform n seed");
        int n = atoi(argv[2]);
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        cout << genUniform(n) << "\n";
    } else if (mode == "alt") {
        ensuref(argc >= 5, "alt: ./gen alt n start(K|P) seed");
        int n = atoi(argv[2]);
        string st = argv[3];
        ensuref(st.size() == 1 && (st[0] == 'K' || st[0] == 'P'), "start must be K or P");
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        cout << genAlt(n, st[0]) << "\n";
    } else if (mode == "blocks") {
        ensuref(argc >= 5, "blocks: ./gen blocks n maxBlock seed");
        int n = atoi(argv[2]);
        int maxBlock = atoi(argv[3]);
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        ensuref(1 <= maxBlock && maxBlock <= n, "maxBlock must be in [1, n]");
        cout << genBlocks(n, maxBlock) << "\n";
    } else if (mode == "all") {
        ensuref(argc >= 5, "all: ./gen all n ch(K|P) seed");
        int n = atoi(argv[2]);
        string ch = argv[3];
        ensuref(ch.size() == 1 && (ch[0] == 'K' || ch[0] == 'P'), "ch must be K or P");
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        cout << genAll(n, ch[0]) << "\n";
    } else if (mode == "peak") {
        ensuref(argc >= 6, "peak: ./gen peak n f ch(K|P) seed");
        int n = atoi(argv[2]);
        int f = atoi(argv[3]);
        string ch = argv[4];
        ensuref(ch.size() == 1 && (ch[0] == 'K' || ch[0] == 'P'), "ch must be K or P");
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        ensuref(1 <= f && f <= n, "f must be in [1, n]");
        cout << genPeak(n, f, ch[0]) << "\n";
    } else if (mode == "biased") {
        ensuref(argc >= 5, "biased: ./gen biased n pK(0..100) seed");
        int n = atoi(argv[2]);
        int pK = atoi(argv[3]);
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        ensuref(0 <= pK && pK <= 100, "pK must be in [0, 100]");
        cout << genBiased(n, pK) << "\n";
    } else if (mode == "runs") {
        ensuref(argc >= 6, "runs: ./gen runs n minRun maxRun seed");
        int n = atoi(argv[2]);
        int minRun = atoi(argv[3]);
        int maxRun = atoi(argv[4]);
        ensuref(1 <= n && n <= MAX_N, "n must be in [1, 1000000]");
        ensuref(1 <= minRun && minRun <= maxRun, "1 <= minRun <= maxRun");
        ensuref(minRun <= n, "minRun must be <= n");
        cout << genRuns(n, minRun, maxRun) << "\n";
    } else {
        ensuref(false, "unknown code");
    }

    return 0;
}