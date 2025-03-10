/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8642                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8642                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 18:45:21 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long ans = n;
    long long temp = n;

    for (long long i = 2; i * i <= temp; i++)
    {
        if (temp % i == 0)
        {
            int cnt = 0;
            while (temp % i == 0)
            {
                cnt++;
                temp /= i;
            }
            if (cnt % 2 == 1)
            {
                ans *= i;
            }
        }
    }
    if (temp > 1)
    {
        ans *= temp;
    }

    cout << ans;
    return 0;
}