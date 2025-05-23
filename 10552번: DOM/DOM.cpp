#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, P;
    cin >> N >> M >> P;
    vector<int> nextChannel(M + 1, 0);
    int fav, hate;
    for (int i = 0; i < N; i++)
    {
        cin >> fav >> hate;
        if (nextChannel[hate] == 0)
            nextChannel[hate] = fav;
    }

    vector<bool> visited(M + 1, false);

    int count = 0;
    int cur = P;

    while (true)
    {
        if (visited[cur])
        {
            cout << -1 << "\n";
            break;
        }
        visited[cur] = true;
        if (nextChannel[cur] == 0)
        {
            cout << count << "\n";
            break;
        }

        cur = nextChannel[cur];
        count++;
    }

    return 0;
}