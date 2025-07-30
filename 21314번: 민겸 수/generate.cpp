#include "testlib.h"
#include <vector>
#include <string>

using namespace std;

string genString(int n) {
    int pattern = rnd.next(1, 5);
    string s;
    s.reserve(n);

    if (pattern == 1) {
        for (int i = 0; i < n; i++) s.push_back(rnd.next(0, 1) ? 'M' : 'K');
    } else if (pattern == 2) {
        char c = rnd.next(0, 1) ? 'M' : 'K';
        s.assign(n, c);
    } else if (pattern == 3) {
        char start = rnd.next(0, 1) ? 'M' : 'K';
        for (int i = 0; i < n; i++) s.push_back((i % 2 == 0) ? start : (start == 'M' ? 'K' : 'M'));
    } else if (pattern == 4) {
        int run = rnd.next(1, n - 1);
        char first = rnd.next(0, 1) ? 'M' : 'K';
        char second = (first == 'M' ? 'K' : 'M');
        s.append(run, first);
        s.append(n - run, second);
    } else {
        int i = 0;
        while (i < n) {
            int blk = rnd.next(1, max(1, n / 10));
            blk = min(blk, n - i);
            char c = rnd.next(0, 1) ? 'M' : 'K';
            s.append(blk, c);
            i += blk;
        }
    }

    return s;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int maxLen = 3000;
    if (argc > 1) {
        maxLen = atoi(argv[1]);
    }

    int n = rnd.next(1, maxLen);

    string s = genString(n);
    println(s);

    return 0;
}