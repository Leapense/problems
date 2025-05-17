#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int dp[26][235];
string s;

int solve(int pos, int prev_sum)
{
    if (pos == s.size()) return 1;
    int &ret = dp[pos][prev_sum];
    if (ret != -1) return ret;
    ret = 0;
    int curr_sum = 0;
    for (int i = pos; i < s.size(); ++i)
    {
        curr_sum += s[i] - '0';
        if (curr_sum >= prev_sum) {
            ret += solve(i + 1, curr_sum);
        }
    }

    return ret;
}

int main()
{
    string input;
    int tc = 1;
    while (cin >> input)
    {
        if (input == "bye") break;
        s = input;
        memset(dp, -1, sizeof(dp));
        int result = solve(0, 0);
        cout << tc++ << ". " << result << "\n";
    }

    return 0;
}