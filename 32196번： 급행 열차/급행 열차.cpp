#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    long long K, X, Y;
    cin >> N >> M >> K >> X >> Y;

    vector<long long> cost(N);
    for (int i = 0; i < N; i++)
    {
        long long A, B;
        cin >> A >> B;
        cost[i] = X * A - Y * B;
    }

    sort(cost.begin(), cost.end());

    long long total = K * (X + Y);
    for (int i = 0; i < M; i++)
    {
        total += cost[i];
    }

    cout << total << "\n";
    return 0;
}