/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9774                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9774                           #+#        #+#      #+#    */
/*   Solved: 2025/03/01 15:09:07 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
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
        long long fact = 1;
        for (int i = 1; i <= N; i++)
            fact *= i;
        long long k = fact / 3;

        vector<int> digits;
        for (int i = 1; i <= N; i++)
            digits.push_back(i);

        string ans = "";
        for (int i = N; i > 0; i--)
        {
            long long f = 1;
            for (int j = 1; j < i; j++)
                f *= j;

            int index = k / f;
            ans.push_back('0' + digits[index]);
            digits.erase(digits.begin() + index);
            k %= f;
        }

        cout << ans << "\n";
    }

    return 0;
}