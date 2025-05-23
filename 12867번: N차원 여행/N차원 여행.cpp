#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    int M;
    cin >> N >> M;
    int *indices = new int[M];
    for (int i = 0; i < M; i++)
    {
        cin >> indices[i];
    }
    string dirs;
    cin >> dirs;
    map<int, long long> state;
    auto getStateKey = [&](const map<int, long long> &st) -> string
    {
        ostringstream oss;
        for (auto &p : st)
        {
            oss << p.first << ":" << p.second << ";";
        }
        return oss.str();
    };
    set<string> visited;
    string key = getStateKey(state);
    visited.insert(key);
    for (int i = 0; i < M; i++)
    {
        int idx = indices[i];
        if (dirs[i] == '+')
            state[idx] += 1;
        else
            state[idx] -= 1;
        if (state[idx] == 0)
            state.erase(idx);
        key = getStateKey(state);
        if (visited.find(key) != visited.end())
        {
            cout << 0;
            delete[] indices;
            return 0;
        }
        visited.insert(key);
    }
    cout << 1;
    delete[] indices;
    return 0;
}
