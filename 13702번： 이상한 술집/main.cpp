#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<long long> volumes(N);

    for (int i = 0; i < N; i++)
    {
        cin >> volumes[i];
    }

    long long left = 1, right = *max_element(volumes.begin(), volumes.end());
    long long answer = 0;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        long long count = 0;

        for (const auto &vol : volumes)
        {
            count += vol / mid;
        }

        if (count >= K)
        {
            answer = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << answer << "\n";

    return 0;
}