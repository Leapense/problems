#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i, L;
    cin >> i >> L;

    vector<pair<int, int>> intervals;

    // 이진 탐색에서 L번의 비교로 인덱스 i를 찾을 수 있는 모든 N 값 검사
    for (int n = i + 1; n <= 10000; n++)
    {
        bool possible = false;

        // 이진 탐색 시뮬레이션
        int low = 0, high = n - 1;
        int steps = 0;

        while (low <= high && steps < L)
        {
            int mid = (low + high) / 2;
            steps++;

            if (mid == i)
            {
                possible = (steps == L);
                break;
            }

            if (i < mid)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        // N 값이 조건을 만족하면 인터벌에 추가
        if (possible)
        {
            if (intervals.empty() || intervals.back().second + 1 < n)
            {
                intervals.push_back({n, n});
            }
            else
            {
                intervals.back().second = n;
            }
        }
    }

    cout << intervals.size() << endl;
    for (const auto &interval : intervals)
    {
        cout << interval.first << " " << interval.second << endl;
    }

    return 0;
}