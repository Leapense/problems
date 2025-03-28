#include "main.h"
#include <bits/stdc++.h>
using namespace std;

static vector<int> normalize(const vector<int> &v)
{
    int n = v.size(), idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            idx = i;
            break;
        }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
        res.push_back(v[(idx + i) % n]);
    return res;
}

static int sortedPrefix(const vector<int> &v)
{
    int n = v.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == i + 1)
            cnt++;
        else
            break;
    }
    return cnt;
}

static vector<int> doMove(const vector<int> &v, int a, int b)
{
    int n = v.size();
    vector<int> tmp = v;
    int posA = -1, posB = -1;
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] == a)
        {
            posA = i;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] == b)
        {
            posB = i;
            break;
        }
    }
    tmp.erase(tmp.begin() + posA);
    if (posA < posB)
        posB--;
    tmp.insert(tmp.begin() + posB + 1, a);
    return normalize(tmp);
}

std::string solveNecklaceProblem(const std::string &input)
{
    stringstream ss(input);
    int N;
    ss >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        ss >> v[i];
    v = normalize(v);
    if (sortedPrefix(v) == N)
        return "0\n";
    vector<pair<int, int>> moves;
    unordered_set<string> visited;
    auto stateToString = [&](const vector<int> &state) -> string
    {
        string s;
        for (auto x : state)
            s += to_string(x) + ",";
        return s;
    };
    visited.insert(stateToString(v));
    int cnt = 0;
    while (sortedPrefix(v) < N && cnt < 50000)
    {
        int bestScore = sortedPrefix(v);
        pair<int, int> bestMove = {-1, -1};
        vector<int> bestState;
        bool foundImprovement = false;
        for (int a = 1; a <= N; a++)
        {
            for (int b = 1; b <= N; b++)
            {
                if (a == b)
                    continue;
                if (abs(a - b) <= 1)
                    continue;
                vector<int> nv = doMove(v, a, b);
                int sc = sortedPrefix(nv);
                if (sc > bestScore)
                {
                    bestScore = sc;
                    bestMove = {a, b};
                    bestState = nv;
                    foundImprovement = true;
                }
            }
        }
        if (!foundImprovement)
        {
            bool moved = false;
            for (int a = 1; a <= N && !moved; a++)
            {
                for (int b = 1; b <= N && !moved; b++)
                {
                    if (a == b)
                        continue;
                    if (abs(a - b) <= 1)
                        continue;
                    vector<int> nv = doMove(v, a, b);
                    string st = stateToString(nv);
                    if (visited.find(st) == visited.end())
                    {
                        bestMove = {a, b};
                        bestState = nv;
                        moved = true;
                    }
                }
            }
            if (!moved)
                break;
        }
        moves.push_back(bestMove);
        v = bestState;
        visited.insert(stateToString(v));
        cnt++;
    }
    ostringstream oss;
    if (sortedPrefix(v) == N)
    {
        for (auto &p : moves)
            oss << p.first << " " << p.second << "\n";
        oss << "0\n";
    }
    else
    {
        oss << "-1\n";
    }
    return oss.str();
}

bool validateSolution(const std::string &input, const std::string &output)
{
    stringstream ss(input);
    int N;
    if (!(ss >> N))
        return false;
    vector<int> init(N);
    for (int i = 0; i < N; i++)
        if (!(ss >> init[i]))
            return false;
    auto normalizeLocal = [&](const vector<int> &state)
    {
        int n = state.size(), idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (state[i] == 1)
            {
                idx = i;
                break;
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            res.push_back(state[(idx + i) % n]);
        return res;
    };
    vector<int> state = normalizeLocal(init);
    stringstream oss(output);
    vector<string> lines;
    string line;
    while (getline(oss, line))
        if (!line.empty())
            lines.push_back(line);
    if (lines.empty())
        return false;
    if (lines.size() == 1 && lines[0] == "-1")
    {
        if (N == 2)
        {
            bool sortedAlready = true;
            for (int i = 0; i < N; i++)
            {
                if (state[i] != i + 1)
                {
                    sortedAlready = false;
                    break;
                }
            }
            return !sortedAlready;
        }
        return false;
    }
    if (lines.back() != "0")
        return false;
    for (size_t i = 0; i < lines.size() - 1; i++)
    {
        int a, b;
        stringstream ls(lines[i]);
        if (!(ls >> a >> b))
            return false;
        if (abs(a - b) <= 1)
            return false;
        int posA = -1, posB = -1;
        for (int j = 0; j < N; j++)
        {
            if (state[j] == a)
            {
                posA = j;
                break;
            }
        }
        for (int j = 0; j < N; j++)
        {
            if (state[j] == b)
            {
                posB = j;
                break;
            }
        }
        if (posA == -1 || posB == -1)
            return false;
        if (posA < posB)
            posB--;
        state.erase(state.begin() + posA);
        if (posB < 0 || posB >= (int)state.size())
            state.push_back(a);
        else
            state.insert(state.begin() + posB + 1, a);
        state = normalizeLocal(state);
    }
    for (int i = 0; i < N; i++)
        if (state[i] != i + 1)
            return false;
    return true;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string input, line;
    while (getline(cin, line))
        input += line + "\n";
    cout << solveNecklaceProblem(input);
    return 0;
}
#endif
