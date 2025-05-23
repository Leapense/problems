#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, K;
    cin >> M >> N >> K;
    vector<int> rows(M, 0), cols(N, 0);
    for (int i = 0; i < K; i++)
    {
        char c;
        int idx;
        cin >> c >> idx;
        if (c == 'R')
        {
            rows[idx - 1] ^= 1;
        }
        else
        {
            cols[idx - 1] ^= 1;
        }
    }

    ll rOdd = 0;
    for (auto r : rows)
        rOdd += r;
    ll cOdd = 0;
    for (auto c : cols)
        cOdd += c;
    ll ans = rOdd * (N - cOdd) + (M - rOdd) * cOdd;

    cout << ans;
    return 0;
}