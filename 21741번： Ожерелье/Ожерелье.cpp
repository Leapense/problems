#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

vi normalize(const vi &v)
{
    int n = v.size();
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 1)
        {
            idx = i;
            break;
        }
    }
    vi res;
    for (int i = 0; i < n; i++)
    {
        res.push_back(v[(idx + i) % n]);
    }
    return res;
}

int sortedPrefix(const vi &v)
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

vi doMove(const vi &v, int a, int b)
{
    int n = v.size();
    vi tmp = v;
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

string vecToStr(const vi &v)
{
    string s;
    for (auto x : v)
    {
        s += to_string(x) + ",";
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vi v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    v = normalize(v);
    int init = sortedPrefix(v);
    if (init == N)
    {
        cout << 0 << "\n";
        return 0;
    }
    vector<pair<int, int>> moves;
    unordered_set<string> visited;
    visited.insert(vecToStr(v));
    int cnt = 0;
    while (sortedPrefix(v) < N && cnt < 50000)
    {
        int bestScore = sortedPrefix(v);
        pair<int, int> bestMove = {-1, -1};
        vi bestState;
        bool foundImprovement = false;
        for (int a = 1; a <= N; a++)
        {
            for (int b = 1; b <= N; b++)
            {
                if (a == b)
                    continue;
                if (abs(a - b) <= 1)
                    continue;
                vi nv = doMove(v, a, b);
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
                    vi nv = doMove(v, a, b);
                    string st = vecToStr(nv);
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
        visited.insert(vecToStr(v));
        cnt++;
    }
    if (sortedPrefix(v) == N)
    {
        for (auto &p : moves)
        {
            cout << p.first << " " << p.second << "\n";
        }
        cout << 0 << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    return 0;
}
