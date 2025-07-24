#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    rnd.setSeed(time(0));

    // N의 범위는 [2, 2^{20}] 이고, Q의 범위는 [1, 200,000] 이어야 한다.
    // 그리고, 만약 argv에서 받은 [max_n, max_q] 가 받았을 경우, 다음과 같은 범위를 지정한다.
    // N의 범위는 [2, max_n], Q의 범위는 [1, max_q]
    // 가급적이면 opt로 쓰는 것이 낫다.
    int max_n = opt<int>("max_n");
    int max_q = opt<int>("max_q");

    // max_n는 [2, 2^{20}] 사이에 있는지 확인한다.
    ensuref(max_n >= 2 && max_n <= (1 << 20), "max_n must be in [2, 2^20]");
    // max_q는 [1, 200,000] 사이에 있는지 확인한다.
    ensuref(max_q >= 1 && max_q <= 200000, "max_q must be in [1, 200000]");

    int n = rnd.next(2, max_n);
    int q = rnd.next(1, max_q);

    println(n, q);
    for (int i = 0; i < q; i++) {
        println(rnd.next(2, n));
    }

    return 0;
}