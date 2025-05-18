#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        int n;
        if (!(cin >> n) || n == 0) {
            break;
        }

        vector<pair<int, int>> intervals;
        intervals.reserve(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            intervals.emplace_back(b, a);
        }

        sort(intervals.begin(), intervals.end());

        int count = 0;
        int last_end = -1;
        for (auto& [end, start] : intervals) {
            if (start > last_end) {
                ++count;
                last_end = end;
            }
        }

        cout << count << "\n";
    }

    return 0;
}