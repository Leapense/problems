#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;

    while (L--) {
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        int left = 0, right = 0, cnt = 0, ans = 0;

        for (right = 0; right < N; right++) {
            if (S[right] == 'K') cnt++;
            while(cnt > K) {
                if (S[left] == 'K') cnt--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }

        cout << ans << "\n";
    }

    return 0;
}