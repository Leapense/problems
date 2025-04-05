#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<vector<int>> apples(2);
int maxSum = 0;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};

void dfs(int r, int c, int count, int sum, vector<vector<bool>> &visited)
{
    if (count <= K)
    {
        maxSum = max(maxSum, sum);
    }

    if (count == K)
        return;

    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= 2 || nc < 0 || nc >= N)
            continue;
        if (visited[nr][nc])
            continue;
        visited[nr][nc] = true;
        dfs(nr, nc, count + 1, sum + apples[nr][nc], visited);
        visited[nr][nc] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    apples[0].resize(N);
    apples[1].resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> apples[0][i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> apples[1][i];
    }

    vector<vector<bool>> visited(2, vector<bool>(N, false));

    visited[1][0] = true;
    dfs(1, 0, 1, apples[1][0], visited);

    cout << maxSum << "\n";

    return 0;
}
