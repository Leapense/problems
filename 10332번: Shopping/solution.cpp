#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int left;
    int right;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, m;
    std::cin >> N >> m;

    if (m == 0) {
        std::cout << (N + 1) << "\n";
        return 0;
    }

    std::vector<Interval> intervals;
    intervals.reserve(m);

    for (int i = 0; i < m; i++)
    {
        int c, d;
        std::cin >> c >> d;
        intervals.push_back({c, d});
    }

    std::sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
        if (a.left != b.left) {
            return a.left < b.left;
        }
        return a.right < b.right;
    });

    long long merged_sum = 0;
    int curL = intervals[0].left;
    int curR = intervals[0].right;

    for (int i = 1; i < m; i++)
    {
        int L = intervals[i].left;
        int R = intervals[i].right;

        if (L <= curR) {
            if (R > curR) {
                curR = R;
            }
        } else {
            merged_sum += (curR - curL);
            curL = L;
            curR = R;
        }
    }

    merged_sum += (curR - curL);

    long long answer = static_cast<long long>(N + 1) + 2LL * merged_sum;
    std::cout << answer << "\n";

    return 0;
}