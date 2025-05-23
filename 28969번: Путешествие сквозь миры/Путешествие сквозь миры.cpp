#pragma GCC optimize("O3")
#define FAST_IO cin.tie(0) -> sync_with_stdio(0); cin.exceptions(ios::badbit | ios::failbit);

#include <bits/stdc++.h>

using namespace std;

int main()
{
    FAST_IO;
    long long l, r;
    cin >> l >> r;

    int count = 0;

    for (int length = 1; length <= 18; ++length) {
        for (char digit = '1'; digit <= '9'; ++digit) {
            string num_str(length, digit);
            long long num = stoll(num_str);

            if (num >= l && num <= r) ++count;
        }
    }

    cout << count << endl;

    return 0;
}