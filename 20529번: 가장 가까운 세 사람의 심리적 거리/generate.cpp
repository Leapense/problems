#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static const array<string, 16> MBTI = {
    "ESTJ", "ESTP", "ESFJ", "ESFP",
    "ENTJ", "ENTP", "ENFJ", "ENFP",
    "ISTJ", "ISTP", "ISFJ", "ISFP",
    "INTJ", "INTP", "INFJ", "INFP"
};

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int T = atoi(argv[1]);
    int maxN = atoi(argv[2]);
    if (argc > 3) rnd.setSeed((unsigned) strtoul(argv[3], nullptr, 10));

    println(T);

    for (int tc = 0; tc < T; ++tc) {
        int N;
        if (tc == 0) N = 3;
        else if (tc == 1) N = 4;
        else if (tc == 2) N = maxN;
        else N = rnd.next(1, maxN);

        println(N);

        int clusterCnt = min<int>(N, 12);
        for (int i = 0; i < clusterCnt; ) {
            int type = rnd.next(0, 15);
            int copies = rnd.next(1, 3);
            copies = min(copies, N - i);
            for (int c = 0; c < copies; ++c) {
                println(MBTI[type]);
            }
            i += copies;
        }

        for (int i = clusterCnt; i < N; ++i) {
            println(MBTI[rnd.next(0, 15)]);
        }
    }

    return 0;
}