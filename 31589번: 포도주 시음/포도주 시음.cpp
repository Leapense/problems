#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> wines(N);
    for (int i = 0; i < N; i++)
    {
        cin >> wines[i];
    }

    sort(wines.begin(), wines.end());

    if (K == 1)
    {
        cout << wines.back() << "\n";
        return 0;
    }

    int m = (K - 1) / 2;
    long long sumPositive = 0, sumNegative = 0;

    for (int i = N - (m + 1); i < N; i++)
    {
        sumPositive += wines[i];
    }

    for (int i = 0; i < m; i++)
    {
        sumNegative += wines[i];
    }

    long long answer = sumPositive - sumNegative;
    cout << answer << "\n";

    return 0;
}