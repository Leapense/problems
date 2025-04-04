#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    const int MAX_BIT = 20;
    vector<int> bitCount(MAX_BIT, 0);

    for (int x : A) {
        for (int bit = 0; bit < MAX_BIT; bit++) {
            if (x & (1 << bit)) {
                bitCount[bit]++;
            }
        }
    }

    int ans = 0;
    for (int cnt : bitCount) {
        ans = max(ans, cnt);
    }

    cout << ans << "\n";
    return 0;
}
