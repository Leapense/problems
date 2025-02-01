#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution
{
public:
    long long solve()
    {
        long long N;
        cin >> N;

        long long steps = 0;

        while (N > 0)
        {
            string s = to_string(N);
            if (s.find('1') != string::npos)
            {
                long long candidate = LLONG_MAX;
                for (int i = 0; i < s.size(); i++)
                {
                    if (s[i] == '1')
                    {
                        string tmp = s.substr(0, i) + s.substr(i + 1);
                        long long num = (tmp == "" ? 0 : stoll(tmp));
                        if (num < candidate)
                            candidate = num;
                    }
                }
                N = candidate;
                steps++;
            }
            else
            {
                long long d = 1;
                while (true)
                {
                    long long next = N - d;
                    if (next == 0)
                        break;
                    if (to_string(next).find('1') != string::npos)
                    {
                        break;
                    }
                    d++;
                }
                N -= d;
                steps += d;
            }
        }

        return steps;
    }
};

int main()
{
    Solution sol;
    cout << sol.solve();

    return 0;
}