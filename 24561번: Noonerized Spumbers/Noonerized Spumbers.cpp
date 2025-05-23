#include <bits/stdc++.h>
using namespace std;

class NoonerizedSpumbers
{
public:
    long long x, y, z;
    char op;

    void parseInput(string s)
    {
        int plus = s.find('+');
        int mult = s.find('*');
        int eq = s.find('=');

        if (plus != string::npos)
        {
            op = '+';
            x = stoll(s.substr(0, plus - 1));
            y = stoll(s.substr(plus + 2, eq - plus - 3));
            z = stoll(s.substr(eq + 2));
        }
        else
        {
            op = '*';
            x = stoll(s.substr(0, mult - 1));
            y = stoll(s.substr(mult + 2, eq - mult - 3));
            z = stoll(s.substr(eq + 2));
        }
    }

    vector<pair<string, string>> getPrefixes(long long num)
    {
        string s = to_string(num);
        vector<pair<string, string>> prefixes;

        for (int i = 1; i < s.size(); i++)
        {
            prefixes.emplace_back(make_pair(s.substr(0, i), s.substr(i)));
        }

        return prefixes;
    }

    void solve()
    {
        vector<long long> nums = {x, y, z};
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 3; j++)
            {
                auto prefixes_i = getPrefixes(nums[i]);
                auto prefixes_j = getPrefixes(nums[j]);
                for (auto &p_i : prefixes_i)
                {
                    for (auto &p_j : prefixes_j)
                    {
                        string new_i = p_j.first + p_i.second;
                        string new_j = p_i.first + p_j.second;
                        long long ni = stoll(new_i);
                        long long nj = stoll(new_j);
                        vector<long long> new_nums = nums;
                        new_nums[i] = ni;
                        new_nums[j] = nj;
                        if (new_nums[0] < (1LL << 31) && new_nums[1] < (1LL << 31) && new_nums[2] < (1LL << 31))
                        {
                            bool valid = false;
                            if (op == '+')
                            {
                                valid = (new_nums[0] + new_nums[1] == new_nums[2]);
                            }
                            else
                            {
                                valid = (new_nums[0] * new_nums[1] == new_nums[2]);
                            }

                            if (valid)
                            {
                                cout << new_nums[0] << " " << op << " " << new_nums[1] << " = " << new_nums[2];
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    string s;
    getline(cin, s);
    NoonerizedSpumbers solver;
    solver.parseInput(s);
    solver.solve();

    return 0;
}