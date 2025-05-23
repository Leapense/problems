/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9294                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9294                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 08:36:14 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

void dfs(int idx, int last, int sum, int n, int m, int s, vector<int> &curr)
{
    if (idx == n)
    {
        if (sum == s)
        {
            cout << "(";
            for (int i = 0; i < n; i++)
            {
                cout << curr[i] << (i == n - 1 ? "" : ",");
            }

            cout << ")\n";
        }

        return;
    }

    for (int i = last; i <= m; i++)
    {
        if (sum + i > s)
            break;
        if (sum + i + (n - idx - 1) * i > s)
        {
        }
        int min_possible = sum + i * (n - idx);
        if (min_possible > s)
            break;
        curr[idx] = i;
        dfs(idx + 1, i, sum + i, n, m, s, curr);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;

    for (int i = 1; i <= c; i++)
    {
        int n, m, s;
        cin >> n >> m >> s;
        cout << "Case " << i << ":\n";
        vector<int> curr(n, 0);
        dfs(0, 1, 0, n, m, s, curr);
    }

    return 0;
}