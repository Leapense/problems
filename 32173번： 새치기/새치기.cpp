#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> s(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> s[i];
    }

    if (N == 1)
    {
        cout << s[1] << "\n";
        return 0;
    }

    long long ans = s[1];
    long long prefix = s[1];

    for (int m = 2; m <= N; m++)
    {
        long long candidate = s[m] - prefix;
        ans = max(ans, candidate);
        prefix += s[m];
    }

    cout << ans << "\n";

    return 0;
}