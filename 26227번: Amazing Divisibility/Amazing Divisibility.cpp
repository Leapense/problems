#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MOD = 7;

vector<int> modPow = {0, 3, 2, 6, 4, 5, 1, 3, 2, 6, 4};
vector<int> invModPow = {0, 5, 4, 6, 2, 3, 1, 5, 4, 6, 2};

int digitCount (int num) {
    int cnt = 0;
    while (num) {
        cnt++;
        num /= 10;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> freq(7, 0);
    vector<int> mods(N, 0);

    for (int i = 0; i < N; ++i) {
        mods[i] = nums[i] % MOD;
        freq[mods[i]]++;
    }

    long long ans = 0;

    for (int i = 0; i < N; ++i) {
        int b = nums[i];
        int rem_b = b % MOD;
        int d = digitCount(b);
        int p = modPow[d];
        int inv_p = invModPow[d];
        int target = ((-rem_b) % MOD + MOD) % MOD;
        target = (target * inv_p) % MOD;
        int addCount = freq[target];

        if (mods[i] == target) addCount--;
        ans += addCount;
    }

    cout << ans << "\n";
    return 0;
}
