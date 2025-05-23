/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8774                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8774                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 19:37:02 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int Z;
    cin >> Z;

    while (Z--)
    {
        int N;
        cin >> N;

        vector<int> prices(N);
        for (int i = 0; i < N; i++)
        {
            cin >> prices[i];
        }

        vector<int> ans(N, -1);
        stack<int> s;
        for (int i = 0; i < N; i++)
        {
            while (!s.empty() && prices[i] > prices[s.top()])
            {
                ans[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < N; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}