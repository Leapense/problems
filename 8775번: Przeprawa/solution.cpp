// C++26
#include <bits/stdc++.h>
using namespace std;

/**
 * 모든 참가자를 최소 비용으로 이동시키는 함수.
 */
long long compute_min_cost(vector<long long>& w,
                           long long A,
                           long long B,
                           long long M) {
    sort(w.begin(), w.end());
    long long cost = 0;
    size_t i = 0, j = w.size() - 1;

    // “쌍배를 쓰는 게 2번 단독배보다 싸다”일 때만 고려
    bool can_pair = (A < 2 * B);

    while (i < j) {
        // 1) 두 사람을 함께 보낼 수 있고, 쌍배 이용이 이득일 때
        if (can_pair && w[i] + w[j] <= M) {
            cost += A;
            ++i;
            --j;
        }
        else {
            // 2) 한 사람만 보낼 때: 물리적으로 2인용 배 사용 가능하고 A < B일 때만 A원
            if (w[j] <= M && A < B) {
                cost += A;
            } else {
                cost += B;
            }
            --j;
        }
    }

    // 남은 한 명 처리
    if (i == j) {
        if (w[i] <= M && A < B) cost += A;
        else                                  cost += B;
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Z;
    cin >> Z;
    while (Z--) {
        int N;
        long long A, B, M;
        cin >> N >> A >> B >> M;

        vector<long long> weights(N);
        for (auto& x : weights) {
            cin >> x;
        }

        cout << compute_min_cost(weights, A, B, M) << "\n";
    }
    return 0;
}
