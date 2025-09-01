#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int capacity;
        ss >> capacity;

        vector<int> debris;
        int x;
        while (ss >> x) debris.push_back(x);

        sort(debris.rbegin(), debris.rend());

        vector<int> bins;
        for (int w : debris) {
            bool placed = false;
            for (int &b : bins) {
                if (b >= w) {
                    b -= w;
                    placed = true;
                    break;
                }
            }
            if (!placed) bins.push_back(capacity - w);
        }

        cout << bins.size() << "\n";
    }
}