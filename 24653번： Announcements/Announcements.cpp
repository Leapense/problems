#include <bits/stdc++.h>
using namespace std;

class Billboard
{
public:
    long long S;
    long long remove_i;
    Billboard(long long s, long long T) : S(s)
    {
        remove_i = ((s / T) + 1) * T;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;

    long long T;
    vector<long long> S(N);
    for (auto &x : S)
        cin >> x;
    cin >> T;
    vector<Billboard> billboards;
    billboards.reserve(N);

    for (auto s : S)
        billboards.emplace_back(s, T);
    sort(billboards.begin(), billboards.end(), [&](const Billboard &a, const Billboard &b) -> bool
         { return a.remove_i < b.remove_i; });

    long long visits = 0;
    long long last_visit = -1;
    for (auto &b : billboards)
    {
        if (b.S > last_visit)
        {
            visits++;
            last_visit = b.remove_i - 1;
        }
    }
    cout << visits;

    return 0;
}