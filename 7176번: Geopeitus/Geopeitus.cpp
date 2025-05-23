#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void dfs(int idx, const vector<char> &vars, map<char, vector<string>> &varValues, map<char, string> &cur, vector<string> &results, const string &formula)
{
    if (idx == vars.size())
    {
        string res;
        for (char ch : formula)
        {
            if (cur.find(ch) != cur.end())
            {
                res += cur[ch];
            }
            else
            {
                res.push_back(ch);
            }
        }

        results.push_back(res);
        return;
    }

    char var = vars[idx];
    for (auto &val : varValues[var])
    {
        cur[var] = val;
        dfs(idx + 1, vars, varValues, cur, results, formula);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string formula;
    getline(cin, formula);

    int N;
    cin >> N;

    map<char, vector<string>> varValues;
    vector<char> vars;

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> ws;
        getline(cin, line);
        char var = line[0];
        vars.push_back(var);

        string valuesPart = line.substr(2);
        vector<string> parts;
        stringstream ss(valuesPart);
        string token;

        while (getline(ss, token, ','))
        {
            parts.push_back(token);
        }
        for (auto &part : parts)
        {
            size_t pos = part.find("..");
            if (pos != string::npos)
            {
                int start = stoi(part.substr(0, pos));
                int end = stoi(part.substr(pos + 2));
                for (int j = start; j <= end; j++)
                {
                    varValues[var].push_back(to_string(j));
                }
            }
            else
            {
                varValues[var].push_back(part);
            }
        }
    }

    vector<string> results;
    map<char, string> cur;
    dfs(0, vars, varValues, cur, results, formula);

    for (auto &res : results)
        cout << res << "\n";

    return 0;
}