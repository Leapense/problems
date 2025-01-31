#include <iostream>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, vector<int>> divisors;

    void precomputeDivisors(int n)
    {
        if (divisors.find(n) != divisors.end())
            return;
        vector<int> d;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                d.push_back(i);
                if (i != n / i)
                    d.push_back(n / i);
            }
        }
        divisors[n] = d;
    }

    int countValidTuples(int a, int b, int c)
    {
        int count = 0;
        for (int x = 1; x <= a; ++x)
        {
            precomputeDivisors(x);
            for (int y : divisors[x])
            {
                if (y > b)
                    continue;
                for (int z : divisors[y])
                {
                    if (z > c)
                        continue;
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