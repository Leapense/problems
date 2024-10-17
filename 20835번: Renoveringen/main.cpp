//=====================================================================
//   20835번:    Renoveringen                   
//   @date:   2024-10-17              
//   @link:   https://www.acmicpc.net/problem/20835  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXN = 30;
const int INF = 1e9;

int N, M;
vector<int> x, y;

int cost[MAXN][MAXN];
int u[MAXN], v[MAXN];
int p[MAXN], way[MAXN];

int main()
{
    cin >> N >> M;
    x.resize(N);
    y.resize(M);

    for (int i = 0; i < N; ++i) cin >> x[i];
    for (int i = 0; i < M; ++i) cin >> y[i];

    int n = N;
    int m = M + N;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M + N; ++j) {
            if (j <= M) {
                cost[i][j] = (y[j - 1] >= x[i - 1]) ? 0 : INF;
            } else {
                if (j - M == i) {
                    cost[i][j] = x[i - 1];
                } else {
                    cost[i][j] = INF;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        vector<int> minv(m + 1, INF);
        vector<char> used(m + 1, false);

        int j0 = 0;

        do
        {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            
            for (int j = 1; j <= m; ++j) {
                if (!used[j]) {
                    int cur = cost[i0][j] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }

                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }

            for (int j = 0; j <= m; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }

    vector<int> ans;

    for (int j = 1; j <= m; ++j) {
        if (p[j] > 0 && p[j] <= N && j > M) {
            ans.push_back(x[p[j] - 1]);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
    }

    return 0;
}