/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9143                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9143                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 22:05:05 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int Z;
    cin >> Z;

    while (Z--)
    {
        int N, M;
        cin >> N >> M;

        int x = (N - 1) / M;
        if (x < 2)
        {
            cout << "Reseni neexistuje." << "\n";
        }
        else
        {
            cout << M * x << " " << M * (x - 1) << "\n";
        }
    }

    return 0;
}