#include <bits/stdc++.h>
using namespace std;

static constexpr int STOW_TIME = 5;

string solve_once(istream &in)
{
    int N;
    if (!(in >> N)) return "";
    vector<int> dest(N);

    int Rmax = 0;
    for (int i = 0; i < N; ++i) {
        in >> dest[i];
        Rmax = max(Rmax, dest[i]);
    }

    vector<int> aisle(Rmax + 1, -1);
    vector<int> pos(N, 0);
    vector<int> remain(N, 0);

    int nextIdx = 0, finished = 0;

    long long time = 0;
    while (finished < N) {
        for (int r = 1; r <= Rmax; ++r)
        {
            int id = aisle[r];
            if (id == -1) continue;
            if (remain[id] > 0) {
                if (--remain[id] == 0) {
                    aisle[r] = -1;
                    ++finished;
                    pos[id] = -1;
                }
            }
        }

        if (finished == N) break;

        for (int r = Rmax - 1; r >= 1; --r) {
            int id = aisle[r];
            if (id == -1) continue;
            if (remain[id] > 0) continue;
            if (dest[id] > r && aisle[r + 1] == -1) {
                aisle[r] = -1;
                aisle[r + 1] = id;
                pos[id] = r + 1;
            }
        }

        for (int r = 1; r <= Rmax; ++r) {
            int id = aisle[r];
            if (id == -1) continue;
            if (remain[id] == 0 && pos[id] == dest[id]) {
                remain[id] = STOW_TIME;
            }
        }

        if (nextIdx < N && aisle[1] == -1) {
            int id = nextIdx++;
            aisle[1] = id;
            pos[id] = 1;
            if (dest[id] == 1) remain[id] = STOW_TIME;
        }

        ++time;
    }

    return to_string(time) + '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve_once(cin);
    return 0;
}