#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;
    vector<int> anna(A), bruno(B);

    for (int i = 0; i < A; i++)
        cin >> anna[i];
    for (int i = 0; i < B; i++)
        cin >> bruno[i];

    const int MAXV = 1000;
    vector<vector<int>> nxt(A + 1, vector<int>(MAXV + 1, -1));

    for (int v = 1; v <= MAXV; v++)
    {
        nxt[A][v] = -1;
    }

    for (int i = A - 1; i >= 0; i--)
    {
        for (int v = 1; v <= MAXV; v++)
        {
            nxt[i][v] = nxt[i + 1][v];
        }
        nxt[i][anna[i]] = i;
    }

    auto check = [&](int L) -> bool
    {
        for (int start = 0; start <= B - L; start++)
        {
            int pos = 0;
            bool possible = true;

            for (int i = start; i < start + L; i++)
            {
                int card = bruno[i];
                if (pos > A)
                {
                    possible = false;
                    break;
                }
                int nextPos = nxt[pos][card];
                if (nextPos == -1)
                {
                    possible = false;
                    break;
                }
                pos = nextPos + 1;
            }

            if (possible)
                return true;
        }

        return false;
    };

    int lo = 0, hi = min(A, B), ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}