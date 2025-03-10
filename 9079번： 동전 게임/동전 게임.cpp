/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9079                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9079                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 21:35:33 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int op[8] = {0};
    op[0] = (1 << 0) | (1 << 1) | (1 << 2);
    op[1] = (1 << 3) | (1 << 4) | (1 << 5);
    op[2] = (1 << 6) | (1 << 7) | (1 << 8);
    op[3] = (1 << 0) | (1 << 3) | (1 << 6);
    op[4] = (1 << 1) | (1 << 4) | (1 << 7);
    op[5] = (1 << 2) | (1 << 5) | (1 << 8);
    op[6] = (1 << 0) | (1 << 4) | (1 << 8);
    op[7] = (1 << 2) | (1 << 4) | (1 << 6);
    while (T--)
    {
        int start = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                string s;
                cin >> s;
                int bit = (s == "T");
                start = start | (bit << (i * 3 + j));
            }
        }
        if (start == 0 || start == 511)
        {
            cout << 0 << "\n";
            continue;
        }
        int dist[512];
        for (int i = 0; i < 512; i++)
            dist[i] = -1;
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        int ans = -1;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == 0 || cur == 511)
            {
                ans = dist[cur];
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int nxt = cur ^ op[i];
                if (dist[nxt] == -1)
                {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
