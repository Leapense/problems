/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9335                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9335                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 10:40:15 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<unsigned int> cover(n, 0);
        for (int i = 0; i < n; i++)
        {
            int d;
            cin >> d;
            cover[i] |= (1u << i);
            for (int j = 0; j < d; j++)
            {
                int friendId;
                cin >> friendId;
                friendId--;
                cover[i] |= (1u << friendId);
            }
        }

        unsigned int all = (n == 32) ? ~0u : ((1u << n) - 1);
        int ans = INT_MAX;
        for (unsigned int mask = 0; mask < (1u << n); mask++)
        {
            unsigned int cur = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1u << i))
                {
                    cur |= cover[i];
                    cnt++;
                }
            }
            if (cur == all)
                ans = min(ans, cnt);
        }

        cout << ans << "\n";
    }

    return 0;
}