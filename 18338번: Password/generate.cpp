// gen_paths.cpp
// 사용법: ./gen_paths <L> [mode]
//   L     : 생성할 문자열 최대 길이 (1 ≤ L ≤ 11)
//   mode  : random | zigzag | edge (default = random)
// 출력을 "한 줄에 한 문자열" 형식으로 내보냅니다.

#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int L = atoi(argv[1]);
    string mode = (argc >= 3 ? string(argv[2]) : "random");
    ensuref(1 <= L && L <= 11, "L must be between 1 and 11");

    int len = rnd.next(1, L);
    string s;
    s.reserve(len);

    if (mode == "zigzag") {
        // R U L D 반복
        const char seq[4] = {'R','U','L','D'};
        for (int i = 0; i < len; ++i) s.push_back(seq[i % 4]);
    }
    else if (mode == "edge") {
        // 경계값: 길이 1, 11, 그리고 최대 연속 이동 시도
        if (L >= 11 && rnd.next(0,1)) {
            len = 11;
        } else if (rnd.next(0,1)) {
            len = 1;
        }
        s.reserve(len);
        // 모두 같은 방향 혹은 모두 번갈아가며
        if (rnd.next(0,1)) {
            char c = "RULD"[rnd.next(0,3)];
            s.assign(len, c);
        } else {
            const char alt[2] = {'R','L'};
            for (int i = 0; i < len; ++i) s.push_back(alt[i%2]);
        }
    }
    else {
        // random: 임의 방향
        const char moves[4] = {'R','U','L','D'};
        for (int i = 0; i < len; ++i)
            s.push_back(moves[rnd.next(0,3)]);
    }

    // 출력
    println(s);
    return 0;
}
