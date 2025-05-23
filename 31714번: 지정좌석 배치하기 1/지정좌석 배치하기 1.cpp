#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    long long D;
    cin >> N >> M >> D;

    vector<long long> last(M, 0);

    sort(last.begin(), last.end(), greater<long long>());
    bool possible = true;

    for (int i = 1; i <= N && possible; i++) {
        vector<long long> h(M);
        for (int j = 0; j < M; j++) cin >> h[j];

        sort(h.begin(), h.end(), greater<long long>());

        for (int j = 0; j < M; j++) {
            if(h[j] <= (last[j] - D * i)) {
                possible = false;
                break;
            }
        }

        if (!possible) break;
        for (int j = 0; j < M; j++) last[j] = D * i + h[j];
    }

    if (possible) cout << "YES";
    else cout << "NO";

    return 0;
}