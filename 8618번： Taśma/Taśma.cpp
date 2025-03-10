/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8618                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8618                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 12:51:35 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 0)
        {
            cout << "BRAK" << "\n";
            continue;
        }
        if (n == 1)
        {
            cout << "BRAK" << "\n";
            continue;
        }

        if (a.front() != a.back())
        {
            cout << n - 1 << "\n";
        }
        else
        {
            int firstDiff = -1;
            int lastDiff = -1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] != a[0])
                {
                    firstDiff = i;
                    break;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i] != a[n - 1])
                {
                    lastDiff = i;
                    break;
                }
            }
            if (firstDiff == -1 && lastDiff == -1)
            {
                cout << "BRAK" << "\n";
            }
            else
            {
                int dist1 = (firstDiff == -1 ? 0 : n - 1 - firstDiff);
                int dist2 = (lastDiff == -1 ? 0 : lastDiff);
                cout << max(dist1, dist2) << "\n";
            }
        }
    }

    return 0;
}