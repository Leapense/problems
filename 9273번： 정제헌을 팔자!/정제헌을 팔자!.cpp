/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9273                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9273                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 23:49:49 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;

    while (getline(cin, s))
    {
        if (s.empty())
            continue;
        int n;
        char slash;
        istringstream iss(s);
        int dummy;
        iss >> dummy >> slash >> n;

        int temp = n;

        int divisors = 1;
        for (int i = 2; i * i <= temp; i++)
        {
            int cnt = 0;
            while (temp % i == 0)
            {
                cnt++;
                temp /= i;
            }
            if (cnt > 0)
                divisors *= (2 * cnt + 1);
        }
        if (temp > 1)
            divisors *= 3;
        cout << (divisors + 1) / 2 << "\n";
    }

    return 0;
}