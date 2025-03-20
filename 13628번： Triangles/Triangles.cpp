#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }

    long long S = accumulate(X.begin(), X.end(), 0LL);
    if (S % 3 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    long long d = S / 3;

    vector<long long> A(N);
    A[0] = 0;
    for (int i = 1; i < N; i++)
    {
        A[i] = A[i - 1] + X[i - 1];
    }

    unordered_set<long long> points(A.begin(), A.end());

    int count = 0;

    for (long long p : A)
    {
        long long target1 = (p + d) % S;
        long long target2 = (p + 2 * d) % S;
        if (points.count(target1) && points.count(target2))
        {
            count++;
        }
    }

    cout << count / 3 << "\n";
    return 0;
}