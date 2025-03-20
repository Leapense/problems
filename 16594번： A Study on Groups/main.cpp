#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    if (M > N)
    {
        long long sum = 0;
        for (auto v : arr)
        {
            sum += v;
        }

        cout << sum << " " << sum;

        return 0;
    }

    sort(arr.begin(), arr.end());

    long long minCost = 0;
    for (int i = 0; i < M; i++)
    {
        minCost += arr[i];
    }

    int L = N / M;
    int r = N % M;

    vector<long long> desc(arr.rbegin(), arr.rend());
    long long maxCost = 0;
    int idx = 0;

    int groupsSizeL = M - r;
    for (int i = 0; i < groupsSizeL; i++)
    {
        maxCost += desc[idx + L - 1];
        idx += L;
    }

    for (int i = 0; i < r; i++)
    {
        maxCost += desc[idx + L];
        idx += (L + 1);
    }

    cout << minCost << " " << maxCost;

    return 0;
}