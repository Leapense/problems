/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9180                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9180                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 22:41:49 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int N, caseNo = 1;
    while (cin >> N && N != -1)
    {
        int F;
        double amount;
        int months[15];
        double investments[15];
        for (int i = 0; i < N; i++)
        {
            cin >> months[i] >> investments[i];
        }

        cin >> F >> amount;
        double lo = 0.0, hi = 1.0, mid;
        for (int iter = 0; iter < 100; iter++)
        {
            mid = (lo + hi) / 2;
            double total = 0.0;
            for (int i = 0; i < N; i++)
            {
                total += investments[i] * pow(1 + mid, F - months[i] + 1);
            }

            if (total > amount)
                hi = mid;
            else
                lo = mid;
        }

        cout << "Case " << caseNo++ << ": " << fixed << setprecision(5) << mid << "\n\n";
    }

    return 0;
}