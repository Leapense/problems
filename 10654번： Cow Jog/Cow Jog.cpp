#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    ll T;
    cin >> N >> T;
    vector<ll> positions(N), speeds(N);
    for (int i = 0; i < N; i++)
    {
        cin >> positions[i] >> speeds[i];
    }
    int groups = 0;
    ll current_min = 1LL << 60;
    for (int i = N - 1; i >= 0; i--)
    {
        ll finalPos = positions[i] + speeds[i] * T;
        if (finalPos < current_min)
        {
            groups++;
            current_min = finalPos;
        }
    }
    cout << groups;
    return 0;
}
