#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Challenge
{
    int cost, reward;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;
    vector<Challenge> challenges(N);
    for (int i = 0; i < N; i++)
    {
        cin >> challenges[i].cost;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> challenges[i].reward;
    }

    // 비용(A)에 따라 도전 과제를 정렬합니다.
    sort(challenges.begin(), challenges.end(), [](const Challenge &a, const Challenge &b)
         { return a.cost < b.cost; });

    // 최대 이득 (B - A)를 기준으로 하는 최대 힙 (자료형 변경 주의)
    priority_queue<long long> pq;
    int index = 0;
    long long currentMoney = M;

    while (index < N || !pq.empty())
    {
        // 현재 보유 금액으로 시도 가능한 모든 도전 과제를 큐에 추가
        while (index < N && challenges[index].cost <= currentMoney)
        {
            long long profit = (long long)challenges[index].reward - challenges[index].cost;
            pq.push(profit);
            index++;
        }
        // 큐가 비어있다면 더 이상 도전할 수 있는 과제가 없으므로 종료
        if (pq.empty())
            break;

        // 가장 수익성이 좋은 도전 과제를 수행
        long long profit = pq.top();
        pq.pop();

        // 수익성이 음수라면 더 이상 진행할 필요가 없음
        if (profit < 0)
            break;

        currentMoney += profit;
    }

    cout << currentMoney << "\n";
    return 0;
}
