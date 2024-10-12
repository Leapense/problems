#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N; // M: 최대 인원, N: 최대 무게

    vector<int> weights(4);
    for (int i = 0; i < 4; i++) {
        cin >> weights[i];
    }

    // 만약 4명의 총 무게가 N 이하이고, M이 4 이상이면 모든 사람이 한 번에 탈 수 있습니다.
    int totalWeight = accumulate(weights.begin(), weights.end(), 0);
    if (totalWeight <= N && M >= 4) {
        cout << 1 << endl;
        return 0;
    }

    int minTrips = 4; // 최악의 경우, 각 사람이 따로 타야 하는 경우

    // 모든 사람 조합에 대해 테스트합니다. (1부터 15까지의 비트마스크)
    for (int mask = 1; mask < (1 << 4); mask++) {
        vector<int> group1, group2;

        // mask를 사용하여 두 그룹으로 분리합니다.
        for (int i = 0; i < 4; i++) {
            if (mask & (1 << i)) {
                group1.push_back(weights[i]);
            } else {
                group2.push_back(weights[i]);
            }
        }

        // 각 그룹의 무게를 계산합니다.
        int weight1 = accumulate(group1.begin(), group1.end(), 0);
        int weight2 = accumulate(group2.begin(), group2.end(), 0);

        // 두 그룹 모두 조건을 만족하면 두 번의 여행으로 충분합니다.
        if (weight1 <= N && weight2 <= N && group1.size() <= M && group2.size() <= M) {
            minTrips = min(minTrips, 2);
        }
    }

    cout << minTrips << endl;
    return 0;
}
