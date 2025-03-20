#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long d;

    cin >> n >> d;

    unordered_map<long long, long long> groupCount;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        long long quotient = a / d;
        groupCount[quotient]++;
    }

    long long result = 0;

    for (auto &pair : groupCount)
    {
        long long count = pair.second;
        if (count > 1)
        {
            result += (count * (count - 1)) / 2;
        }
    }

    cout << result << "\n";

    return 0;
}