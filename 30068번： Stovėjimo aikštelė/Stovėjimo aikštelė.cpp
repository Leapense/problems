#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int M;
    cin >> M;

    map<int, int> entryTimes;
    vector<pair<int, int>> results;

    for (int i = 0; i < M; ++i) {
        int T, N;
        cin >> T >> N;

        if (entryTimes.find(N) == entryTimes.end()) {
            entryTimes[N] = T;
        } else {
            int entryTime = entryTimes[N];
            int timeSpent = T - entryTime;
            results.emplace_back(N, timeSpent);
            entryTimes.erase(N);
        }
    }

    for (const auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}