#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int total = 3 * N;
    vector<long long> ages(total);

    for (int i = 0; i < total; i++) {
        cin >> ages[i];
    }

    sort(ages.begin(), ages.end());

    long long ans = numeric_limits<long long>::max();

    for (int k = N; k <= 2 * N; k++) {
        long long diff = ages[k + N - 1] - ages[k];
        ans = min(ans, diff);
    }

    cout << ans << "\n";
    return 0;
}
