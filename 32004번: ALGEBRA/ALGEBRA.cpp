#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int size1 = arr1.size();
    int size2 = arr2.size();
    int maxSize = max(size1, size2);

    for (int i = 0; i < maxSize; ++i) {
        if (i < size1 && i < size2) {
            merged.push_back(max(arr1[i], arr2[i]));
        } else if (i < size1) {
            merged.push_back(arr1[i]);
        } else {
            merged.push_back(arr2[i]);
        }
    }

    return merged;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int A, B;
    cin >> A >> B;

    vector<vector<int>> arrays(N + 1, vector<int>());

    for (int i = 1; i <= N; ++i) {
        int M;
        cin >> M;
        arrays[i].resize(M);

        for (int j = 0; j < M; ++j) {
            cin >> arrays[i][j];
        }
    }

    int totalNumbers = 0;
    for (int i = 1; i <= N; ++i) {
        totalNumbers += arrays[i].size();
    }

    set<int> setA(arrays[A].begin(), arrays[A].end());
    set<int> setB(arrays[B].begin(), arrays[B].end());

    vector<int> intersection;

    for (auto num : setA) {
        if (setB.find(num) != setB.end()) {
            intersection.push_back(num);
        }
    }

    int sumIntersection = 0;
    for (auto num : intersection) {
        sumIntersection += num;
    }

    vector<vector<int>> currentArrays = arrays;

    while(currentArrays.size() > 2) {
        vector<vector<int>> temp;

        for (int i = 1; i < currentArrays.size(); i += 2) {
            vector<int> merged = mergeArrays(currentArrays[i], currentArrays[i + 1]);

            temp.push_back(merged);
        }

        currentArrays = vector<vector<int>>(1, vector<int>());

        for(auto &arr : temp) {
            currentArrays.push_back(arr);
        }
    }

    vector<int> finalArray = currentArrays[1];

    cout << totalNumbers << "\n";
    cout << sumIntersection << "\n";

    for (int i = 0; i < finalArray.size(); ++i) {
        if (i > 0) cout << " ";
        cout << finalArray[i];
    }

    cout << "\n";

    return 0;
}