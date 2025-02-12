#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    long long invAsc = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (A[i] > A[j])
            {
                invAsc++;
            }
        }
    }

    long long total = (long long)N * (N - 1) / 2;
    long long invDesc = total - invAsc;
    long long costWithReverse = 1 + invDesc;

    long long answer = min(invAsc, costWithReverse);

    cout << answer << "\n";
    return 0;
}