#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<long long> snacks(N);

    for (auto &s : snacks)
    {
        cin >> s;
    }

    long long lo = 1, hi = *max_element(snacks.begin(), snacks.end()), ans = 0;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2, cnt = 0;

        for (auto s : snacks)
            cnt += s / mid;

        if (cnt >= M)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";

    return 0;
}