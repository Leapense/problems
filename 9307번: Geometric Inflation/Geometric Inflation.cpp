/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9307                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: cjhool <boj.kr/u/cjhool>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9307                           #+#        #+#      #+#    */
/*   Solved: 2025/02/28 10:12:01 by cjhool        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

string formatMoney(double amount)
{
    ostringstream oss;
    oss << fixed << setprecision(2) << amount;
    string s = oss.str();
    size_t dotPos = s.find('.');
    string intPart = s.substr(0, dotPos);
    string decPart = s.substr(dotPos);
    int insertPosition = intPart.length() - 3;
    while (insertPosition > 0)
    {
        intPart.insert(insertPosition, ",");
        insertPosition -= 3;
    }
    return intPart + decPart;
}

int main()
{
    while (true)
    {
        double a, b, c;
        int N;
        if (!(cin >> a))
            break;
        if (a == -1)
            break;
        cin >> b >> c >> N;
        vector<double> cost = {a, b, c};
        if (N > 3)
        {
            for (int i = 3; i < N; i++)
            {
                double next = (cost[i - 3] * cost[i - 2]) / cost[i - 1];
                next = round(next * 100.0) / 100.0;
                cost.push_back(next);
            }
        }
        double result = cost[N - 1];
        cout << "Month " << N << " cost: $" << formatMoney(result) << "\n";
    }

    return 0;
}