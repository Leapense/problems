#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int k_max = min(M, (N + 1) / 2);

    sort(A.begin(), A.end(), greater<int>());

    long long totalScore = 0;
    for (int i = 0; i < k_max; i++)
    {
        if (A[i] > 0)
        {
            totalScore += A[i];
        }
        else
        {
            break;
        }
    }

    cout << totalScore << "\n";

    return 0;
}