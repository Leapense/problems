/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8786                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8786                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 20:28:28 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>

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
        vector<int> c(N + 1);
        vector<int> req(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            cin >> c[i];
            if (c[i] == 0)
                req[i] = 0;
            else
            {
                int r = 0;
                int x = c[i];
                while (x > 0)
                {
                    r++;
                    x /= 2;
                }
                req[i] = r;
            }
        }

        vector<int> cover(N + 3, 0);
        long long ans = 0;

        for (int i = 1; i <= N; i++)
        {
            if (cover[i] < req[i])
            {
                int diff = req[i] - cover[i];
                ans += diff;
                cover[i] += diff;
                cover[i + 1] += diff;
                cover[i + 2] += diff;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}