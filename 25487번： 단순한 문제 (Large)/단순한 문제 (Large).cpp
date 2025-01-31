#include <iostream>
#include <vector>

using namespace std;

class ModuloCounter
{
public:
    ModuloCounter(int testCases) : T(testCases) {}

    void addTestCase(int a, int b, int c)
    {
        testCases.push_back({a, b, c});
    }

    void processTestCases()
    {
        for (const auto &testCase : testCases)
        {
            cout << countValidTuples(testCase[0], testCase[1], testCase[2]) << "\n";
        }
    }

private:
    int T;
    vector<vector<int>> testCases;

    int countValidTuples(int a, int b, int c)
    {
        int count = 0;
        for (int x = 1; x <= a; ++x)
        {
            for (int y = 1; y <= b; ++y)
            {
                for (int z = 1; z <= c; ++z)
                {
                    if ((x % y == y % z) && (y % z == z % x))
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    ModuloCounter moduloCounter(T);

    for (int i = 0; i < T; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        moduloCounter.addTestCase(a, b, c);
    }

    moduloCounter.processTestCases();

    return 0;
}