#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

string stateToString(const map<int, int> &state)
{
    ostringstream oss;
    for (auto &p : state)
    {
        oss << p.first << ":" << p.second << ",";
    }

    return oss.str();
}

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

    map<int, int> state;
    unordered_set<string> visited;
    string s = stateToString(state);

    visited.insert(s);

    bool ok = true;
    for (int i = 0; i < M; i++)
    {
        int idx = indices[i];
        if (dirs[i] == '+')
        {
            state[idx]++;
        }
        else
        {
            state[idx]--;
            if (state[idx] == 0)
                state.erase(idx);
        }
        s = stateToString(state);
        if (visited.find(s) != visited.end())
        {
            ok = false;
            break;
        }

        visited.insert(s);
    }

    cout << (ok ? 1 : 0);
    delete[] indices;
    return 0;
}