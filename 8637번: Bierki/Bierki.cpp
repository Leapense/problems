/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8637                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8637                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 18:27:08 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> sticks(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sticks[i];
    }

    ranges::sort(sticks);

    int l = 0, ans = 0;
    for (int r = 0; r < N; r++)
    {
        while (r - l + 1 >= 3 && sticks[l] + sticks[l + 1] <= sticks[r])
        {
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    if (ans < 3)
        ans = max(ans, 2);

    cout << ans << "\n";
    return 0;
}