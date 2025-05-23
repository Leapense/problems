#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int z;
    cin >> z;

    while (z--) {
        int n;
        cin >> n;

        vector<long long> l(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        sort(l.begin(), l.end(), greater<long long>());
        
        long long sum = 0;
        for (auto s : l) {
            sum += s;
        }

        int current_n = n;
        long long current_sum = sum;

        while (current_n >= 3) {
            long long longest_s = l[0];
            long long tmp_sum = current_sum - longest_s;

            if (longest_s < tmp_sum) {
                cout << current_sum << "\n";
                break;
            } else {
                current_sum -= l[0];
                l.erase(l.begin());
                current_n--;
            }
        }

        if (current_n < 3) {
            cout << "0\n";
        }
    }

    return 0;
}