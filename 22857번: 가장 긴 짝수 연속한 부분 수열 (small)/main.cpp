#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> S(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int ans = 0;
    int left = 0, oddCount = 0;

    for (int right = 0; right < N; right++) {
        if (S[right] % 2 == 1) {
            oddCount++;
        }

        while (oddCount > K) {
            if (S[left] % 2 == 1) {
                oddCount--;
            }
            left++;
        }

        int evenCount = (right - left + 1) - oddCount;
        ans = max(ans, evenCount);
    }

    cout << ans << "\n";
    return 0;
}
