#include "main.h"
#include <iostream>
#include <vector>
using namespace std;

// 문제의 로직을 구현한 함수
vector<int> solve(
    int N, int K, int Q, int M,
    const vector<int> &sleeping,
    const vector<int> &initialRecipients,
    const vector<pair<int, int>> &queries)
{
    // 학생 번호는 3부터 N+2까지 사용하므로, 배열 크기는 N+3 (인덱스 0 ~ N+2)
    int total = N + 3;
    vector<bool> isSleeping(total, false);
    vector<bool> attended(total, false);

    // 졸고 있는 학생 체크
    for (auto num : sleeping)
    {
        if (num < total)
            isSleeping[num] = true;
    }

    // 선생님이 직접 보낸 출석 코드 (잠들지 않은 학생만 처리)
    for (auto num : initialRecipients)
    {
        if (num < total && !isSleeping[num])
            attended[num] = true;
    }

    // 전파: 각 학생 i가 출석이 되었고 깨어 있다면, i의 배수인 학생들에게 출석 처리를 합니다.
    for (int i = 3; i <= N + 2; i++)
    {
        if (attended[i] && !isSleeping[i])
        {
            for (int j = i * 2; j <= N + 2; j += i)
            {
                if (!isSleeping[j])
                    attended[j] = true;
            }
        }
    }

    // 구간별 미출석 학생 수를 빠르게 계산하기 위한 prefix sum 배열 (인덱스 3부터 N+2)
    vector<int> prefix(total, 0);
    for (int i = 3; i <= N + 2; i++)
    {
        prefix[i] = prefix[i - 1] + (attended[i] ? 0 : 1);
    }

    // 각 쿼리에 대해 미출석 학생 수를 구합니다.
    vector<int> results;
    for (auto &pr : queries)
    {
        int S = pr.first, E = pr.second;
        results.push_back(prefix[E] - prefix[S - 1]);
    }
    return results;
}

#ifndef UNIT_TESTS
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, Q, M;
    cin >> N >> K >> Q >> M;

    vector<int> sleeping(K);
    vector<int> initialRecipients(Q);

    for (int i = 0; i < K; i++)
    {
        cin >> sleeping[i];
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> initialRecipients[i];
    }

    vector<pair<int, int>> queries(M);
    for (int i = 0; i < M; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> ans = solve(N, K, Q, M, sleeping, initialRecipients, queries);
    for (auto res : ans)
        cout << res << "\n";

    return 0;
}
#endif