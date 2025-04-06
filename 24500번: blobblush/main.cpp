#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    // 1. N의 가장 높은 비트 위치 파악 -> L = floor(log2(N)) + 1
    //   C++17 이상 __lg()는 0이 아닌 값에 대해 floor(log2(x))를 반환함
    //   N>=1이므로 N=0인 경우는 고려 불필요
    int L = 64 - __builtin_clzll(N); // 혹은 (int)floor(log2(N)) + 1
    // 2. M = 2^L - 1
    unsigned long long M = (1ULL << L) - 1ULL;

    // 만약 M이 N 이하라면, 카드 1장으로 M을 낼 수 있음
    if (M <= (unsigned long long)N) {
        cout << 1 << "\n";
        cout << M << "\n";
    }
    else {
        // M이 N보다 큰 경우, 2장의 카드 x, y (x < y)로 M을 만들 수 있음
        // x는 [max(1, M-N) ... min(N, (M-1)/2)] 범위 내에서 가장 작은 값
        long long T = (long long)M - N;  // M - N (M, N은 1e18 근처이므로 long long 범위 안)
        long long x = max(1LL, T);
        // y = M - x
        long long y = (long long)M - x;
        cout << 2 << "\n";
        cout << x << "\n" << y << "\n";
    }
    return 0;
}
