#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;

    vector<long long> happy_numbers;

    for (int digit = 1; digit <= 9; digit++) {
        long long num = 0;

        for (int length = 1; length <= 9; length++) {
            num = num * 10 + digit;
            happy_numbers.push_back(num);
        }
    }

    sort(happy_numbers.begin(), happy_numbers.end());

    long long L = N - M;
    long long R = N - 1;

    if (L < 1) L = 1;

    if (M == 0) {
        cout << "0";
        return 0;
    }

    int count = upper_bound(happy_numbers.begin(), happy_numbers.end(), R) - lower_bound(happy_numbers.begin(), happy_numbers.end(), L);

    cout << count << "\n";

    return 0;
}