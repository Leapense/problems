#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;

void solve(istream &in, ostream &out)
{
    int N;
    in >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    ll total = 0;
    int maxHeight = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            in >> grid[i][j];
            total += grid[i][j];
            maxHeight = max(maxHeight, grid[i][j]);
        }
    }

    ll required = (total + 1) / 2;

    int lo = 0, hi = maxHeight;
    int ans = hi;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        ll cooled = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cooled += min(mid, grid[i][j]);
            }
        }

        if (cooled >= required)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    out << ans << "\n";
}

#ifdef DEBUG

void runTests()
{
    {
        stringstream input("5\n1 4 0 2 1\n0 0 5 6 3\n8 4 7 2 0\n7 1 0 5 3\n4 5 7 9 1\n");
        stringstream output;
        solve(input, output);
        string expected = "3\n";
        assert(output.str() == expected);
        cout << "Test Case 1 passed.\n";
    }
    {
        stringstream input("1\n10\n");
        stringstream output;
        solve(input, output);
        // Total = 10, so required = 5. With T = 5, cooled = min(5, 10) = 5.
        string expected = "5\n";
        assert(output.str() == expected);
        cout << "Test Case 2 passed.\n";
    }
    {
        stringstream input("3\n3 3 3\n2 1 4\n0 5 2\n");
        stringstream output;
        solve(input, output);
        // We don't state the expected answer here explicitly.
        cout << "Test Case 3 output: " << output.str();
    }
}

#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    runTests();
#else
    solve(cin, cout);
#endif
    return 0;
}