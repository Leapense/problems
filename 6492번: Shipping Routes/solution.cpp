#include <bits/stdc++.h>
using namespace std;

constexpr int COST_UNIT = 100;

int findMinLegs(const vector<vector<int>>& adjacency, int srcIndex, int dstIndex) {
    int nodeCount = static_cast<int>(adjacency.size());
    vector<int> distance(nodeCount, -1);
    queue<int> bfsQueue;

    distance[srcIndex] = 0;
    bfsQueue.push(srcIndex);

    while (!bfsQueue.empty()) {
        int current = bfsQueue.front();
        bfsQueue.pop();

        if (current == dstIndex) {
            return distance[current];
        }

        for (int neighbor : adjacency[current])
        {
            if (distance[neighbor] < 0) {
                distance[neighbor] = distance[current] + 1;
                bfsQueue.push(neighbor);
            }
        }
    }

    return -1;
}

void processDataSet(int dataSetNumber)
{
    int warehouseCount, legCount, requestCount;
    cin >> warehouseCount >> legCount >> requestCount;

    unordered_map<string, int> codeToIndex;
    codeToIndex.reserve(warehouseCount);

    for (int i = 0; i < warehouseCount; ++i) {
        string code;
        cin >> code;
        codeToIndex[code] = i;
    }

    vector<vector<int>> adjacency(warehouseCount);
    for (int i = 0; i < legCount; ++i) {
        string codeA, codeB;
        cin >> codeA >> codeB;
        int idxA = codeToIndex[codeA];
        int idxB = codeToIndex[codeB];
        adjacency[idxA].push_back(idxB);
        adjacency[idxB].push_back(idxA);
    }

    cout << "DATA SET " << dataSetNumber << "\n\n";

    for (int i = 0; i < requestCount; ++i) {
        int size;
        string srcCode, dstCode;
        cin >> size >> srcCode >> dstCode;

        int srcIndex = codeToIndex[srcCode];
        int dstIndex = codeToIndex[dstCode];

        int minLegs = findMinLegs(adjacency, srcIndex, dstIndex);
        if (minLegs < 0) {
            cout << "NO SHIPMENT POSSIBLE\n";
        } else {
            long long totalCost = static_cast<long long>(size) * minLegs * COST_UNIT;
            cout << '$' << totalCost << '\n';
        }
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalDataSets;
    cin >> totalDataSets;

    for (int ds = 1; ds <= totalDataSets; ++ds) {
        processDataSet(ds);
    }

    return 0;
}