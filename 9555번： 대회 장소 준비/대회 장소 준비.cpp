#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (T--) {
        int N, M; cin >> N >> M;
        vector<vector<int>> hall(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> hall[i][j];
            }
        }

        unordered_set<int> violatingSchools;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int id = hall[i][j];
                if (id == -1) continue;

                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    int nid = hall[nx][ny];

                    if (nid == id && id != -1) {
                        violatingSchools.insert(id);
                        break;
                    }
                }
            }
        }

        cout << (int)violatingSchools.size() << "\n";
    }

    return 0;
}