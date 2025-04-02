#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long K;
    cin >> K;

    if (K == 0) {
        cout << 0;
        return 0;
    }

    if (K % 2 == 0) {
        cout << -1;
        return 0;
    }

    K = abs(K);

    int jumps = 0;
    long long sum = 0;

    while (sum < K) {
        jumps++;
        sum = (1LL << jumps) - 1;
    }

    cout << jumps;

    return 0;
}
