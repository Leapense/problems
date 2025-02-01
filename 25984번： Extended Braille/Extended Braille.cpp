#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> shapes;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<pair<int, int>> dots(m);
        for (int j = 0; j < m; j++)
        {
            cin >> dots[j].first >> dots[j].second;
        }

        pair<int, int> base = dots[0];
        for (int j = 1; j < m; j++)
        {
            if (dots[j] < base)
            {
                base = dots[j];
            }
        }

        for (int j = 0; j < m; j++)
        {
            dots[j].first -= base.first;
            dots[j].second -= base.second;
        }

        sort(dots.begin(), dots.end());

        ostringstream oss;

        for (auto &p : dots)
        {
            oss << p.first << ":" << p.second << ",";
        }

        string shapeStr = oss.str();
        shapes.insert(shapeStr);
    }

    cout << shapes.size() << endl;

    return 0;
}