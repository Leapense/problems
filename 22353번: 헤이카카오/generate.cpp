// gen.cpp
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

static void printCase(int a, int d, int k) {
    cout << a << ' ' << d << ' ' << k << '\n';
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // argv[1]: mode (string)
    // argv[2]: optional seed or index depending on mode
    if (argc < 2) {
        println("Usage:");
        println("  gen <mode> [seed_or_index]");
        println("Modes: min, max, random, slow, fast, plateau, near1, near100, d100, k100, edge");
        println("edge 모드는 [1..12] 인덱스를 받습니다.");
        return 0;
    }
    string mode = argv[1];
    if (mode == "random") {
        if (argc >= 3) rnd.setSeed(stoull(string(argv[2])));
        int a = rnd.next(1, 100);
        int d = rnd.next(1, 100);
        int k = rnd.next(1, 100);
        printCase(a, d, k);
        return 0;
    }

    auto edgePool = [&]() -> vector<tuple<int,int,int>> {
        // 경계값·정밀도 유도·클램핑 직전/직후·루프길이 다양화
        vector<tuple<int,int,int>> v = {
            // 1) 최솟값
            {1, 1, 1},
            // 2) 최댓값
            {100, 100, 100},
            // 3) d=100 → 바로 종료
            {rnd.next(1,100), 100, rnd.next(1,100)},
            // 4) k=100, d=1 → 0.01 → 0.02 → ... 급상승 (거의 즉시 1 근처)
            {rnd.next(1,100), 1, 100},
            // 5) 매우 느리게 수렴(d=1,k=1)
            {rnd.next(1,100), 1, 1},
            // 6) 느리게 수렴(d=3,k=2) : g=1.02
            {rnd.next(1,100), 3, 2},
            // 7) 1 바로 넘는 클램프(d=67,k=50) : 0.67 -> 1.005 -> clamp
            {rnd.next(1,100), 67, 50},
            // 8) 1에 근접 시작(d=99,k=1)
            {rnd.next(1,100), 99, 1},
            // 9) 꽤 큰 d, 작은 k(d=90,k=1)
            {rnd.next(1,100), 90, 1},
            // 10) 중간값 일반형
            {50, 50, 50},
            // 11) a 최댓값에 루프 길어지는 조합
            {100, 2, 1},
            // 12) a 최솟값에 빠른 클램프 유도
            {1, 40, 100}
        };
        return v;
    };

    if (mode == "edge") {
        int idx = 1;
        if (argc >= 3) idx = stoi(argv[2]);
        auto v = edgePool();
        ensuref(1 <= idx && idx <= (int)v.size(), "edge index must be in [1..%d]", (int)v.size());
        auto [a,d,k] = v[idx-1];
        printCase(a,d,k);
        return 0;
    }

    if (mode == "min") { printCase(1,1,1); return 0; }
    if (mode == "max") { printCase(100,100,100); return 0; }
    if (mode == "d100") { printCase(rnd.next(1,100),100,rnd.next(1,100)); return 0; }
    if (mode == "k100") { printCase(rnd.next(1,100),rnd.next(1,100),100); return 0; }
    if (mode == "slow") { printCase(rnd.next(1,100),1,1); return 0; }        // 아주 느린 수렴
    if (mode == "fast") { printCase(rnd.next(1,100),1,100); return 0; }      // 매우 빠른 수렴
    if (mode == "plateau") { printCase(rnd.next(1,100),67,50); return 0; }   // 곱하자마자 1 초과
    if (mode == "near1") { printCase(rnd.next(1,100),2,1); return 0; }       // 1에 오래 머무는 접근
    if (mode == "near100") { printCase(rnd.next(1,100),99,1); return 0; }    // 거의 즉시 종료

    // 알 수 없는 모드면 랜덤
    if (argc >= 3) rnd.setSeed(stoull(string(argv[2])));
    printCase(rnd.next(1,100), rnd.next(1,100), rnd.next(1,100));
    return 0;
}
