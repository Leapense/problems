#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios::badbit | ios::failbit);
    
    long long N;
    cin >> N;

    long long min_area = LLONG_MAX;
    long long limit = sqrt(N) + 10;

    for (long long c = 1; c <= limit; c++) {
        long long r = (N + c - 1) / c;
        long long area = (c + 1) * (r + 1);

        if (area < min_area) {
            min_area = area;
        }
    }

    for (long long r = 1; r <= limit; r++) {
        long long c = (N + r - 1) / r;
        long long area = (c + 1) * (r + 1);
        if (area < min_area) {
            min_area = area;
        }
    }

    cout << min_area << "\n";

    return 0;
}