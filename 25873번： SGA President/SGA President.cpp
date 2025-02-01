#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class SGACandidate
{
public:
    void solve()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n;
        cin >> n;

        unordered_map<char, unordered_map<string, long long>> groups;
        for (int i = 0; i < n; i++)
        {
            string name;
            cin >> name;
            groups[name[0]][name]++;
        }

        long long result = 0;
        for (auto &group : groups)
        {
            long long total = 0, sumSquares = 0;
            for (auto &entry : group.second)
            {
                total += entry.second;
                sumSquares += entry.second * entry.second;
            }

            result += total * total - sumSquares;
        }

        cout << result << "\n";
    }
};

int main()
{
    SGACandidate solver;
    solver.solve();
    return 0;
}