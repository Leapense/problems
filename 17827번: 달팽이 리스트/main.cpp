#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, V;
    cin >> N >> M >> V;

    vector<int> values(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> values[i];
    }

    int prefix_length = V - 1;
    int cycle_length = N - V + 1;

    while (M--)
    {
        ll K;
        cin >> K;
        if (K < prefix_length)
        {
            cout << values[K + 1] << "\n";
        }
        else
        {
            ll offset = K - prefix_length;
            int index_in_cycle = offset % cycle_length;
            cout << values[V + index_in_cycle] << "\n";
        }
    }

    return 0;
}