//=====================================================================
//   16450번:    Interruptores                   
//   @date:   2024-10-13              
//   @link:   https://www.acmicpc.net/problem/16450  
//   @Motd:   폴더 내부에 있는 파일을 삭제하거나 변경하지 말아주세요.
//   @Test:   코드를 작성 후 "BOJ: 테스트"통해서 테스트를 해보세요.
//=====================================================================

#include <bits/stdc++.h>
using namespace std;

int N, M, L;
vector<int> initial;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    initial.resize(M + 1, 0);

    cin >> L;

    for (int i = 0; i < L; i++) {
        int x;
        cin >> x;
        initial[x] = 1;
    }

    vector<vector<int>> lamp_switches(M + 1, vector<int>());
    for (int s = 1; s <= N; s++) {
        int Ki;
        cin >> Ki;

        for (int i = 0; i < Ki; i++) {
            int y;
            cin >> y;
            lamp_switches[y].push_back(s);
        }
    }
    vector<int> S(M+1, 0);
    for (int j = 1; j <= M; j++) S[j] = lamp_switches[j].size();

    vector<vector<char>> c(M + 1, vector<char>(N + 1, 0));

    for (int j = 1; j <= M; j++) {
        for (int r = 1; r <= N; r++) {
            c[j][r] = c[j][r - 1];
            if (binary_search(lamp_switches[j].begin(), lamp_switches[j].end(), r)) {
                c[j][r] ^= 1;
            }
        }
    }

    long long min_t = LLONG_MAX;
    for (int r = 0; r < N; r++) {
        bool flag = true;

        int C = -1;
        for (int j = 1; j <= M; j++) {
            if (S[j] % 2 == 0) {
                if (c[j][r] != initial[j]) {
                    flag = false;
                    break;
                }
            } else {
                int val = initial[j] ^ c[j][r];

                if (C == -1) {
                    C = val;
                } else {
                    if (C != val) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag) {
            int k = 0;
            if (C != -1) {
                k = C;
            }

            long long t = (long long)k * N + r;
            bool all_off = true;

            for (int j = 1; j <= M; j++) {
                if (initial[j]) {
                    all_off = false;
                    break;
                }
            }

            if (t == 0) {
                if (all_off) {
                    min_t = min(min_t, t);
                }
            } else {
                min_t = min(min_t, t);
            }
        }
    }

    bool initial_all_off = true;

    for (int j = 1; j <= M; j++) {
        if (initial[j]) {
            initial_all_off = false;
            break;
        }
    }

    if (initial_all_off) {
        min_t = min(min_t, (long long)0);
    }

    if (min_t != LLONG_MAX) {
        cout << min_t << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
