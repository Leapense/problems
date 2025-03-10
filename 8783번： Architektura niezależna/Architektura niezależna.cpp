#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<string> grid(N);
        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        stack<pair<int, int>> st;
        for (int i = 0; i < N; i++)
        {
            if (grid[i][0] == '.' && !visited[i][0])
            {
                st.push({i, 0});
                visited[i][0] = true;
            }
            if (grid[i][N - 1] == '.' && !visited[i][N - 1])
            {
                st.push({i, N - 1});
                visited[i][N - 1] = true;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (grid[0][j] == '.' && !visited[0][j])
            {
                st.push({0, j});
                visited[0][j] = true;
            }
            if (grid[N - 1][j] == '.' && !visited[N - 1][j])
            {
                st.push({N - 1, j});
                visited[N - 1][j] = true;
            }
        }
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        while (!st.empty())
        {
            auto [x, y] = st.top();
            st.pop();
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] == '.')
                {
                    visited[nx][ny] = true;
                    st.push({nx, ny});
                }
            }
        }
        long long area = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == '#')
                    area++;
                else if (!visited[i][j])
                    area++;
            }
        }
        cout << area << "\n";
    }
    return 0;
}
