#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N, r, c, d1, d2;
    cin >> N;
    cin >> r >> c >> d1 >> d2;

    ll row_total = N;
    ll row_grey, row_white;

    if (r % 2 == 1)
    {
        row_grey = (N + 1) / 2;
        row_white = N - row_grey;
    }
    else
    {
        row_grey = N / 2;
        row_white = N - row_grey;
    }

    ll col_total = N;
    ll col_grey, col_white;

    if (c % 2 == 1)
    {
        col_grey = (N + 1) / 2;
        col_white = N - col_grey;
    }
    else
    {
        col_grey = N / 2;
        col_white = N - col_grey;
    }

    ll L1 = min(d1, 2 * N - d1);
    ll diag1_grey = 0, diag1_white = 0;
    if ((d1 + 1) % 2 == 0)
    {
        diag1_grey = L1;
    }
    else
    {
        diag1_white = L1;
    }

    ll L2 = N - abs(d2 - N);
    ll diag2_grey = 0, diag2_white = 0;

    if (((d2 - N) % 2 + 2) % 2 == 0)
    {
        diag2_grey = L2;
    }
    else
    {
        diag2_white = L2;
    }

    ll total_white = row_white + col_white + diag1_white + diag2_white;
    ll total_grey = row_grey + col_grey + diag1_grey + diag2_grey;

    set<pair<ll, ll>> candidates;
    auto addCandidate = [&](ll i, ll j)
    {
        if (i >= 1 && i <= N && j >= 1 && j <= N)
            candidates.insert({i, j});
    };

    addCandidate(r, c);
    addCandidate(r, d1 - r + 1);
    addCandidate(r, d2 - N + r);
    addCandidate(d1 - c + 1, c);
    addCandidate(N + c - d2, c);

    if ((d1 - d2 + N + 1) % 2 == 0)
    {
        ll i = (d1 - d2 + N + 1) / 2;
        ll j = (d1 + d2 - N + 1) / 2;
        addCandidate(i, j);
    }

    for (auto &p : candidates)
    {
        ll i = p.first, j = p.second;
        int mult = 0;

        if (i == r)
            mult++;
        if (j == c)
            mult++;
        if (i + j - 1 == d1)
            mult++;
        if (j - i + N == d2)
            mult++;

        int subtract = mult - 1;
        if ((i + j) % 2 == 0)
        {
            total_grey -= subtract;
        }
        else
        {
            total_white -= subtract;
        }
    }

    ll total = total_white + total_grey;
    cout << total << "\n"
         << total_grey << " " << total_white << "\n";
    return 0;
}