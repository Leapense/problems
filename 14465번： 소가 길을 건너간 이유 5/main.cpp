#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, B;
    cin >> N >> K >> B;

    vector<int> broken(N + 1, 0);
    for (int i = 0; i < B; i++)
    {
        int x;
        cin >> x;
        broken[x] = 1;
    }

    int sum = 0;
    for (int i = 1; i <= K; i++)
    {
        sum += broken[i];
    }

    int ans = sum;
    for (int i = K + 1; i <= N; i++)
    {
        sum += broken[i] - broken[i - K];
        ans = min(ans, sum);
    }

    cout << ans << "\n";

    return 0;
}