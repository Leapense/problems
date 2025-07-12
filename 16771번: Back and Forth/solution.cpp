#include <bits/stdc++.h>
using namespace std;

set<int> possible;

void dfs(int step, int milk, vector<int>& c1, vector<int>& c2) {
    if (step == 5) {
        possible.insert(milk);
        return;
    }

    if (step == 1 || step == 3) {
        for (int s = 1; s <= 100; ++s) {
            if (c1[s] > 0) {
                c1[s]--;
                c2[s]++;
                dfs(step + 1, milk - s, c1, c2);
                c1[s]++;
                c2[s]--;
            }
        }
    } else {
        for (int s = 1; s <= 100; ++s) {
            if (c2[s] > 0) {
                c2[s]--;
                c1[s]++;
                dfs(step + 1, milk + s, c1, c2);
                c2[s]++;
                c1[s]--;
            }
        }
    }
}

int main()
{
    vector<int> c1(101, 0), c2(101, 0);
    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        c1[x]++;
    }
    for (int i = 0; i < 10; ++i) {
        int x;
        cin >> x;
        c2[x]++;
    }
    dfs(1, 1000, c1, c2);
    cout << possible.size() << "\n";
    return 0;
}