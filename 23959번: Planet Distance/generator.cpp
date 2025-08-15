#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int T = rnd.wnext(1, 5);
    cout << T << "\n";

    for (int tc = 0; tc < T; tc++) {
        int N = rnd.wnext(3, 20);
        cout << N << "\n";

        vector<pair<int, int>> edges;
        vector<int> cycleNodes;

        int cycleSize = rnd.wnext(3, N);
        cycleNodes.resize(cycleSize);
        iota(cycleNodes.begin(), cycleNodes.end(), 1);

        for (int i = 0; i < cycleSize; i++) {
            int u = cycleNodes[i];
            int v = cycleNodes[(i + 1) % cycleSize];
            edges.push_back({u, v});
        }

        int currentNode = cycleSize + 1;
        while (currentNode <= N) {
            int attachTo = rnd.next(1, currentNode - 1);
            edges.push_back({attachTo, currentNode});
            currentNode++;
        }

        shuffle(edges.begin(), edges.end());

        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    }

    return 0;
}