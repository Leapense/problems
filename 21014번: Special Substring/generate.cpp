#include "testlib.h"
#include <string>

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = rnd.next(1, 100000);
    int K = rnd.next(1, N);
    println(N, " ", K);

    std::string S;
    S.reserve(N);

    int mode = rnd.next(0, 3);
    char heavy_char = rnd.next('A', 'Z');

    for (int i = 0; i < N; ++i) {
        char c;
        switch (mode) {
            case 0:
            c = heavy_char;
            break;
            case 1:
            c = char('A' + (i % 26));
            break;
            case 2:
            if (rnd.next(1, 100) <= 70)
                c = heavy_char;
            else
                c = rnd.next('A', 'Z');
            break;
            case 3:
            default:
            c = rnd.next('A', 'Z');
        }
        S.push_back(c);
    }

    println(S);
    return 0;
}