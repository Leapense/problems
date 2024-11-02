#include <bits/stdc++.h>
using namespace std;

vector<int> getDistinctElements(vector<vector<int>>& matrix, int i, int j, int M) {
    set<int> elements;
    vector<int> submatrixElements;

    for (int x = i; x < i + M; ++x) {
        for (int y = j; y < j + M; ++y) {
            elements.insert(matrix[x][y]);
        }
    }

    for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
        submatrixElements.push_back(*it);
    }

    return submatrixElements;
}

int main(void) {
    
    while (true) {
        int N, M;

        if (!(cin >> N >> M)) {
            break;
        }

        vector<vector<int>> matrix(N, vector<int>(N));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }

        pair<int, int> resultPos = {-1, -1};
        vector<int> bestSubmatrixElements;
        int minDistinct = INT_MAX;

        for (int i = 0; i <= N - M; ++i) {
            for (int j = 0; j <= N - M; ++j) {
                vector<int> currentElements = getDistinctElements(matrix, i, j, M);
                int currentDistinctCount = currentElements.size();

                if (currentDistinctCount < minDistinct) {
                    minDistinct = currentDistinctCount;
                    bestSubmatrixElements = currentElements;
                    resultPos = {i + 1, j + 1};
                } else if (currentDistinctCount == minDistinct) {
                    if (currentElements > bestSubmatrixElements) {
                        bestSubmatrixElements = currentElements;
                        resultPos = {i + 1, j + 1};
                    }
                }
            }
        }

        cout << resultPos.first << " " << resultPos.second << endl;
    }
    return 0;
}