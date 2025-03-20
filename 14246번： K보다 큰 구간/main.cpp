#include <iostream>
#include <vector>
#include <ranges>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (auto &x : arr)
    {
        cin >> x;
    }

    long long k;
    cin >> k;

    long long count = 0, sum = 0;
    int end = 0;

    for (int start = 0; start < n; ++start)
    {
        while (end < n && sum <= k)
        {
            sum += arr[end++];
        }

        if (sum > k)
        {
            count += (n - end + 1);
        }

        sum -= arr[start];
    }

    cout << count << "\n";

    return 0;
}