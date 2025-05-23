#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;
using ll = long long;

// The solve() function containing the solution logic
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> positions(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> positions[i];
    }

    // Group the mosquitoes by their positions.
    // Since positions are given in non-decreasing order, we can group from the end.
    vector<pair<ll, ll>> groups; // {position, count}
    ll count = 1;
    for (int i = n - 2; i >= 0; --i)
    {
        if (positions[i] == positions[i + 1])
        {
            ++count;
        }
        else
        {
            groups.push_back({positions[i + 1], count});
            count = 1;
        }
    }
    groups.push_back({positions[0], count});

    // Process groups in descending order (groups are built in descending order)
    ll shift = 0;
    ll energy = 0;
    for (auto &group : groups)
    {
        ll pos = group.first;
        ll cnt = group.second;
        // Calculate effective position: original position minus the shift from previous actions
        ll effectivePos = pos - shift;
        if (effectivePos > 0)
        {
            energy += effectivePos * cnt;
            shift += cnt; // Only mosquitoes eaten with energy contribute to further shifts.
        }
    }

    cout << energy << "\n";
}

#ifdef UNIT_TEST
// Utility function to run a test case
string runTestCase(const string &input)
{
    // Backup stream buffers
    streambuf *cinbuf = cin.rdbuf();
    streambuf *coutbuf = cout.rdbuf();

    // Redirect input and output
    istringstream iss(input);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());

    // Run the solution
    solve();

    // Restore original stream buffers
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    return oss.str();
}

void runTests()
{
    {
        // Sample test case from the problem statement.
        string input = "4\n2 2 4 4\n";
        string expected = "8\n";
        string output = runTestCase(input);
        assert(output == expected);
    }
    {
        // Single mosquito.
        string input = "1\n1\n";
        string expected = "1\n";
        string output = runTestCase(input);
        assert(output == expected);
    }
    {
        // All mosquitoes at the same position.
        string input = "3\n10 10 10\n";
        // Energy = (10-0)*3 = 30
        string expected = "30\n";
        string output = runTestCase(input);
        assert(output == expected);
    }
    {
        // Mosquitoes that become free.
        // Positions: 1, 2, 3.
        // Groups: (3,1), (2,1), (1,1).
        // Process:
        //   Group (3,1): effective pos = 3, energy = 3, shift becomes 1.
        //   Group (2,1): effective pos = 2-1 = 1, energy becomes 3+1=4, shift becomes 2.
        //   Group (1,1): effective pos = 1-2 = -1 (free, no energy cost).
        // Total energy = 4.
        string input = "3\n1 2 3\n";
        string expected = "4\n";
        string output = runTestCase(input);
        assert(output == expected);
    }
    {
        // Mixed positions.
        // Positions: 2, 3, 3, 7, 7.
        // Groups: (7,2), (3,2), (2,1).
        // Process:
        //   Group (7,2): effective pos = 7, energy = 7*2 = 14, shift becomes 2.
        //   Group (3,2): effective pos = 3-2 = 1, energy becomes 14+1*2 = 16, shift becomes 4.
        //   Group (2,1): effective pos = 2-4 = -2 (free).
        // Total energy = 16.
        string input = "5\n2 3 3 7 7\n";
        string expected = "16\n";
        string output = runTestCase(input);
        assert(output == expected);
    }
    // You can add additional test cases as needed.
    cout << "All tests passed.\n";
}

int main()
{
    runTests();
    return 0;
}

#else

int main()
{
    solve();
    return 0;
}

#endif
