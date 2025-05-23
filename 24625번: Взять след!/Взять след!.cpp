#include <bits/stdc++.h>
using namespace std;

class MatrixTraceMaximizer
{
public:
    int n;
    vector<long long> a;
    long long maxTrace;

    void readInput()
    {
        cin >> n;
        a.resize(n);
        for (auto &x : a)
            cin >> x;
    }

    void computeMaxTrace()
    {
        sort(a.begin(), a.end(), greater<long long>());
        int mMax = floor(sqrt(n));
        maxTrace = LLONG_MIN;
        long long currentSum = 0;
        for (int m = 1; m <= mMax; m++)
        {
            currentSum += a[m - 1];
            if (1LL * m * m > n)
                continue;
            maxTrace = max(maxTrace, currentSum);
        }
    }

    void printResult()
    {
        cout << maxTrace;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    MatrixTraceMaximizer mtm;
    mtm.readInput();
    mtm.computeMaxTrace();
    mtm.printResult();

    return 0;
}