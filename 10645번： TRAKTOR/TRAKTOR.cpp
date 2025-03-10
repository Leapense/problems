#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> countX(100001, 0), countY(100001, 0);
    vector<int> countDiag(200001, 0);
    vector<int> countAnti(200001, 0);

    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        countX[x]++;
        countY[y]++;
        countDiag[x - y + 100000]++;
        countAnti[x + y]++;

        if (countX[x] >= K || countY[y] >= K || countDiag[x - y + 100000] >= K || countAnti[x + y] >= K)
        {
            ans = i;
            cout << ans << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}