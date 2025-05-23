#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<long long, vector<long long>> groups;

    for (int i = 0; i < n; i++)
    {
        long long r = arr[i] % k;
        groups[r].push_back(arr[i]);
    }

    for (auto &g : groups)
    {
        sort(g.second.begin(), g.second.end());
    }

    vector<long long> sortedArr(n);

    unordered_map<long long, int> indexPtr;

    for (int i = 0; i < n; i++)
    {
        long long r = arr[i] % k;
        sortedArr[i] = groups[r][indexPtr[r]++];
    }

    if (is_sorted(sortedArr.begin(), sortedArr.end()))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}