/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8736                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8736                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 19:26:53 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    int *stairs = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
    }

    int pos = n;
    for (int i = 0; i < m; i++)
    {
        int h;
        cin >> h;
        while (pos > 0 && h <= stairs[pos])
        {
            pos--;
        }
        int ans = (pos < 0 ? 0 : pos);
        cout << ans << " ";
        pos = ans - 1;
    }

    delete[] stairs;
    return 0;
}