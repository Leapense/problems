/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8914                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8914                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 20:49:10 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;
        vector<string> grid1(6), grid2(6);
        for (int i = 0; i < 6; i++)
        {
            cin >> grid1[i];
        }
        for (int i = 0; i < 6; i++)
        {
            cin >> grid2[i];
        }

        vector<vector<char>> candidates(5);
        for (int j = 0; j < 5; j++)
        {
            set<char> col1, col2;
            for (int i = 0; i < 6; i++)
            {
                col1.insert(grid1[i][j]);
                col2.insert(grid2[i][j]);
            }

            vector<char> inter;
            for (auto ch : col1)
            {
                if (col2.find(ch) != col2.end())
                {
                    inter.push_back(ch);
                }
            }

            sort(inter.begin(), inter.end());
            candidates[j] = inter;
        }

        int total = 1;
        for (int j = 0; j < 5; j++)
        {
            total *= candidates[j].size();
        }
        if (k > total)
        {
            cout << "NO" << "\n";
            continue;
        }

        string password = "";
        vector<int> suffix(6, 1);
        for (int j = 4; j >= 0; j--)
        {
            suffix[j] = suffix[j + 1] * candidates[j].size();
        }

        int rem = k - 1;
        for (int j = 0; j < 5; j++)
        {
            int cnt = suffix[j + 1];
            int index = rem / cnt;
            password.push_back(candidates[j][index]);
            rem %= cnt;
        }

        cout << password << "\n";
    }

    return 0;
}