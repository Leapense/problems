/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9265                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9265                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 23:22:53 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    fread(&n, sizeof(int), 1, stdin);
    fread(&m, sizeof(int), 1, stdin);

    int total = n * m;
    vector<int> mat(total);
    fread(mat.data(), sizeof(int), total, stdin);

    auto countLE = [&](int T) -> long long
    {
        long long cnt = 0;
        int row = 0, col = m - 1;
        while (row < n && col >= 0)
        {
            if (mat[row * m + col] <= T)
            {
                cnt += col + 1;
                row++;
            }
            else
            {
                col--;
            }
        }

        return cnt;
    };

    int X, Y;
    while (fread(&X, sizeof(int), 1, stdin) == 1 && fread(&Y, sizeof(int), 1, stdin) == 1)
    {
        long long ans = countLE(Y) - countLE(X - 1);
        printf("%lld\n", ans);
    }

    return 0;
}