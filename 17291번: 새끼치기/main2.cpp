#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>
using namespace std;

struct Bug
{
    int birthYear;
    int divisions;
};

int simulateBugPopulation(int N)
{
    vector<Bug> bugs;
    bugs.push_back({1, 0});

    for (int year = 2; year <= N; ++year)
    {
        int size = bugs.size();
        vector<Bug> newBugs;
        for (int i = 0; i < size; i++)
        {
            bugs[i].divisions++;
            newBugs.push_back({year, 0});
        }

        bugs.insert(bugs.end(), newBugs.begin(), newBugs.end());

        vector<Bug> alive;
        for (auto &bug : bugs)
        {
            if ((bug.birthYear % 2 == 1 && bug.divisions == 3) || (bug.birthYear % 2 == 0 && bug.divisions == 4))
            {
                continue;
            }
            alive.push_back(bug);
        }

        bugs = alive;
    }

    return bugs.size();
}

#ifdef UNIT_TEST
void runTests()
{
    {
        int result = simulateBugPopulation(1);
        assert(result == 1);
        cout << "Test case N=1 passed. Output: " << result << "\n";
    }
    {
        int result = simulateBugPopulation(2);
        assert(result == 2);
        cout << "Test case N=2 passed. Output: " << result << "\n";
    }
    {
        int result = simulateBugPopulation(3);
        assert(result == 4);
        cout << "Test case N=3 passed. Output: " << result << "\n";
    }
    {
        int result = simulateBugPopulation(4);
        assert(result == 7);
        cout << "Test case N=4 passed. Output: " << result << "\n";
    }

    cout << "All tests passed.\n";
}
#endif

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef UNIT_TEST
    runTests();
#else
    int N;
    cin >> N;
    cout << simulateBugPopulation(N) << "\n";
#endif

    return 0;
}