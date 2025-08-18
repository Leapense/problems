#include "testlib.h"
#include <string>
#include <random>

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int maxLen = opt<int>("maxlen", 50);
    int maxN = opt<int>("maxn", 26);

    int n = rnd.next(0, maxN);
    int len = rnd.next(1, maxLen);

    std::string s;
    s.reserve(len);
    for (int i = 0; i < len; ++i) {
        char d = '0' + rnd.next(0, 9);
        s.push_back(d);
    }

    std::cout << n << '\n' << s << '\n';
    return 0;
}