/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8094                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8094                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 09:29:42 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, n;
    cin >> w >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    int left = 0, right = n - 1, canoes = 0;

    while (left <= right)
    {
        if (left == right)
        {
            canoes++;
            break;
        }

        if (weights[left] + weights[right] <= w)
        {
            left++;
            right--;
        }
        else
        {
            right--;
        }
        canoes++;
    }

    cout << canoes;

    return 0;
}