/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8578                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8578                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 09:56:08 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    cin.ignore();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        string a, b;
        for (char c : s1)
            if (c != ' ')
                a.push_back(c);
        for (char c : s2)
            if (c != ' ')
                b.push_back(c);

        if (a.size() < k || b.size() < k)
            continue;

        int vowelsA = 0, vowelsB = 0;
        for (char c : a)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
                vowelsA++;
        }
        for (char c : b)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
                vowelsB++;
        }

        if (vowelsA != vowelsB)
            continue;

        string endA = a.substr(a.size() - k);
        string endB = b.substr(b.size() - k);

        if (endA == endB)
            ans++;
    }

    cout << ans;
    return 0;
}