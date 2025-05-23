#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    long long sum = 0;
    long long mn = 1e18;
    long long a;

    for (int i = 0; i < N; i++)
    {
        cin >> a;
        sum += a;
        mn = min(mn, a);
    }

    long long ans = max(sum, -mn);
    cout << ans << "\n";

    return 0;
}