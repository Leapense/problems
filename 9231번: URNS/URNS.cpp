/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9231                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9231                           #+#        #+#      #+#    */
/*   Solved: 2025/02/27 22:56:00 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string trial;

    bool firstTrial = true;

    while (getline(cin, trial))
    {
        if (trial == "#")
            break;
        if (trial == "")
            continue;
        vector<vector<int>> urns(5, vector<int>(5, 0));
        int init[5];
        {
            string line;
            getline(cin, line);
            istringstream iss(line);
            for (int i = 0; i < 5; i++)
            {
                iss >> init[i];
            }
        }

        urns[0][0] = init[0];
        urns[1][1] = init[1];
        urns[2][2] = init[2];
        urns[3][3] = init[3];
        urns[4][4] = init[4];

        while (true)
        {
            int k, s, t;
            cin >> k >> s >> t;
            if (k == 0 && s == 0 && t == 0)
                break;
            int src = s - 1, tgt = t - 1;
            int total = 0;

            for (int i = 0; i < 5; i++)
            {
                total += urns[src][i];
            }

            int moveCount = min(k, total);
            if (total == 0)
                continue;
            vector<double> ideal(5, 0.0);
            vector<int> assign(5, 0);
            for (int i = 0; i < 5; i++)
            {
                ideal[i] = (urns[src][i] * (double)moveCount) / total;
                assign[i] = (int)floor(ideal[i]);
            }

            int sumAssign = 0;
            for (int i = 0; i < 5; i++)
            {
                sumAssign += assign[i];
            }

            int r = moveCount - sumAssign;
            vector<int> indices;
            for (int i = 0; i < 5; i++)
            {
                if (assign[i] < urns[src][i])
                {
                    indices.push_back(i);
                }
            }

            sort(indices.begin(), indices.end(), [&](int a, int b)
                 {
                double fa = ideal[a] - floor(ideal[a]);
                double fb = ideal[b] - floor(ideal[b]);
                if (fabs(fa - fb) > 1e-12) return fa > fb;
                return a < b ? false : true; });

            for (auto i : indices)
            {
                if (r <= 0)
                    break;
                assign[i]++;
                r--;
            }

            for (int i = 0; i < 5; i++)
            {
                urns[src][i] -= assign[i];
                urns[tgt][i] += assign[i];
            }
        }
        cin.ignore();
        if (!firstTrial)
            cout << "\n";
        firstTrial = false;
        cout << trial << "\n";
        cout << "URN        R      O      Y      G      B\n";
        for (int i = 0; i < 5; i++)
        {
            cout << (i + 1) << "    ";
            for (int j = 0; j < 5; j++)
            {
                cout << right << setw(7) << urns[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}