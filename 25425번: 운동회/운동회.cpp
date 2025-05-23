#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin.exceptions(ios_base::failbit);

    long long N, M, a, K;
    cin >> N >> M >> a >> K;

    long long T = N - 1;
    long long S = a - K;

    long long MaxTeamsRemaining, MinTeamsRemaining;

    if (S <= 0) {
        MaxTeamsRemaining = MinTeamsRemaining = 0;
    } else {
        MaxTeamsRemaining = min(T, S);
        MinTeamsRemaining = min(T, (S + M - 1) / M);
    }

    long long MaxRank = MaxTeamsRemaining + 1;
    long long MinRank = MinTeamsRemaining + 1;

    cout << MaxRank << " " << MinRank << endl;
    return 0;
}