/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 8989                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/8989                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 21:05:24 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        vector<pair<double, pair<int, string>>> times;
        for (int i = 0; i < 5; i++)
        {
            string s;
            cin >> s;
            int hh = stoi(s.substr(0, 2));
            int mm = stoi(s.substr(3, 2));
            double hourAngle = (hh % 12) * 30 + mm * 0.5;
            double minuteAngle = mm * 6;
            double diff = abs(hourAngle - minuteAngle);
            double angle = min(diff, 360 - diff);
            int timeVal = hh * 60 + mm;
            times.push_back({angle, {timeVal, s}});
        }

        sort(times.begin(), times.end(), [](auto &a, auto &b)
             {
            if (a.first != b.first) return a.first < b.first;
            return a.second.first < b.second.first; });

        cout << times[2].second.second << "\n";
    }

    return 0;
}