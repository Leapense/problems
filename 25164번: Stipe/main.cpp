#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> ages(N);
    for (int i = 0; i < N; i++) {
        int G, M, D;
        cin >> G >> M >> D;
        ages[i] = G * 400 + M * 30 + D;
    }

    vector<int> tmp = ages;
    sort(tmp.begin(), tmp.end(), greater<int>());

    int T = tmp[K - 1];
    int countGreater = 0;

    for (auto v : ages) {
        if (v > T) countGreater++;
    }

    int need = K - countGreater;
    int vaccCount = 0, rejectCount = 0, pos = 0;
    for (int i = 0; i < N && vaccCount < K; i++) {
        if (ages[i] > T) {
            vaccCount++;
            pos = i + 1;
            continue;
        }
        if (ages[i] == T) {
            if (need > 0) {
                vaccCount++;
                need--;
                pos = i + 1;
                continue;
            } else {
                rejectCount++;
            }
        } else {
            rejectCount++;
        }
    }
    cout << rejectCount;
    return 0;
}
