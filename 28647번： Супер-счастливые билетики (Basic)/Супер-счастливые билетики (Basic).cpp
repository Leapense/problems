#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long total = pow(10, n);
    long long count = 0;

    for (long long i = 0; i < total; ++i) {
        string s = to_string(i);

        while(s.size() < n) s = "0" + s;

        int half = n / 2;
        int sum_front = 0, sum_back = 0;

        for (int j = 0; j < half; ++j) {
            sum_front += s[j] - '0';
            sum_back += s[j + half] - '0';
        }
        if (sum_front != sum_back) continue;

        int sum_odd = 0, sum_even = 0;

        for (int j = 0; j < n; ++j) {
            if ((j + 1) % 2 == 1) sum_odd += s[j] - '0';
            else sum_even += s[j] - '0';
        }

        if (sum_odd != sum_even) continue;

        count++;
    }

    cout << count << "\n";

    return 0;
}