/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9319                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9319                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 10:22:41 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

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
        double B;
        cin >> B;
        double lx, ly;
        cin >> lx >> ly;

        vector<double> r(n);
        double R = 0.0;

        vector<tuple<double, double, double>> devices(n);
        for (int i = 0; i < n; i++)
        {
            double x, y, s;
            cin >> x >> y >> s;
            devices[i] = {x, y, s};
        }

        for (int i = 0; i < n; i++)
        {
            double x, y, s;
            tie(x, y, s) = devices[i];
            double dx = x - lx, dy = y - ly;
            double d2 = dx * dx + dy * dy;
            r[i] = s / d2;
            R += r[i];
        }

        int ans = -1;
        double thresh;

        if (n > 0)
        {
            thresh = (6.0 / 7.0) * (B + R);
        }
        for (int i = 0; i < n; i++)
        {
            if (r[i] > thresh)
            {
                ans = i + 1;
                break;
            }
        }

        if (ans == -1)
        {
            cout << "NOISE" << "\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }

    return 0;
}