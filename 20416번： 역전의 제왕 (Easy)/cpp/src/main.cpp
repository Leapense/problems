#include "main.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

struct Frozen
{
    int problem;
    int time; // 분 단위
    int subCount;
};

struct Participant
{
    int id;
    int solved = 0;
    int penalty = 0;
    int lastTime = 0; // 마지막 정답 제출 시간 (분)
    int reversalPoints = 0;
    bool fixed = false; // 모든 프리징 제출이 공개되었으면 true
    vector<Frozen> frozenSubs;
};

int timeToMinutes(const string &timeStr)
{
    int hh, mm;
    char colon;
    stringstream ss(timeStr);
    ss >> hh >> colon >> mm;
    return hh * 60 + mm;
}

bool rankingComparator(const Participant &a, const Participant &b)
{
    if (a.solved != b.solved)
        return a.solved > b.solved; // 문제 수가 많은 것이 우선
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty; // 패널티가 적은 것이 우선
    return a.lastTime < b.lastTime;   // 마지막 제출 시간이 빠른 것이 우선
}

void solve(istream &in, ostream &out)
{
    int N, M;
    in >> N >> M;

    vector<Participant> parts(N);
    for (int i = 0; i < N; i++)
    {
        parts[i].id = i + 1;
    }

    // 제출 이력을 읽어 처리
    // 03:00 (180분) 이전: 프리징 이전, 이후: 프리징 제출로 분리
    for (int i = 0; i < M; i++)
    {
        string timeStr;
        int id, prob, s;
        in >> timeStr >> id >> prob >> s;
        int t = timeToMinutes(timeStr);
        Participant &p = parts[id - 1];
        if (t <= 180)
        {
            // 프리징 전 제출: 즉시 반영
            p.solved += 1;
            p.penalty += t + (s - 1) * 20;
            p.lastTime = max(p.lastTime, t);
        }
        else
        {
            // 프리징 제출: 저장
            p.frozenSubs.push_back({prob, t, s});
        }
    }

    // 각 참가자의 프리징 제출은 문제 번호 오름차순으로 공개됨
    for (auto &p : parts)
    {
        sort(p.frozenSubs.begin(), p.frozenSubs.end(), [](const Frozen &a, const Frozen &b)
             { return a.problem < b.problem; });
        if (p.frozenSubs.empty())
        {
            p.fixed = true;
        }
    }

    // 현재 순위를 계산하는 람다 함수
    auto computeRanking = [&]() -> vector<int>
    {
        vector<int> order(parts.size());
        for (int i = 0; i < (int)parts.size(); i++)
        {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](int a, int b)
             { return rankingComparator(parts[a], parts[b]); });
        return order;
    };

    // 언프리징 과정을 시뮬레이션
    while (true)
    {
        bool pending = false;
        for (const auto &p : parts)
        {
            if (!p.fixed)
            {
                pending = true;
                break;
            }
        }
        if (!pending)
            break;

        vector<int> rankOrder = computeRanking();
        int candidate = -1;
        int candidateRank = -1;
        // 아직 프리징 제출이 남은 참가자 중 가장 하위 등수를 찾음
        for (int i = (int)rankOrder.size() - 1; i >= 0; i--)
        {
            int idx = rankOrder[i];
            if (!parts[idx].fixed)
            {
                candidate = idx;
                candidateRank = i + 1; // 1-indexed rank
                break;
            }
        }
        assert(candidate != -1);
        int r_old = candidateRank;

        // 후보자의 다음 프리징 제출 공개 (문제 번호가 가장 낮은 제출)
        Frozen currentSub = parts[candidate].frozenSubs.front();
        parts[candidate].frozenSubs.erase(parts[candidate].frozenSubs.begin());

        // 해당 제출 반영
        parts[candidate].solved += 1;
        parts[candidate].penalty += currentSub.time + (currentSub.subCount - 1) * 20;
        parts[candidate].lastTime = max(parts[candidate].lastTime, currentSub.time);

        // 반영 후 새로운 순위 계산
        vector<int> newRankOrder = computeRanking();
        int r_new = 0;
        for (int i = 0; i < (int)newRankOrder.size(); i++)
        {
            if (newRankOrder[i] == candidate)
            {
                r_new = i + 1;
                break;
            }
        }
        if (r_new < r_old)
        {
            parts[candidate].reversalPoints += (r_old - r_new);
        }

        if (parts[candidate].frozenSubs.empty())
        {
            parts[candidate].fixed = true;
        }
    }

    // 최종 순위 계산
    vector<int> finalRankOrder = computeRanking();
    vector<int> finalRank(parts.size());
    for (int i = 0; i < (int)finalRankOrder.size(); i++)
    {
        finalRank[finalRankOrder[i]] = i + 1;
    }

    // 역전 포인트가 가장 높은 참가자를 결정 (동점이면 최종 순위가 더 높은 참가자)
    int bestId = -1;
    int bestReversal = -1;
    int bestFinalRank = 1e9;
    for (const auto &p : parts)
    {
        if (p.reversalPoints > bestReversal)
        {
            bestReversal = p.reversalPoints;
            bestFinalRank = finalRank[p.id - 1];
            bestId = p.id;
        }
        else if (p.reversalPoints == bestReversal)
        {
            if (finalRank[p.id - 1] < bestFinalRank)
            {
                bestFinalRank = finalRank[p.id - 1];
                bestId = p.id;
            }
        }
    }

    out << bestId << "\n";
}

#ifndef UNIT_TESTS
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve(std::cin, std::cout);
    return 0;
}
#endif