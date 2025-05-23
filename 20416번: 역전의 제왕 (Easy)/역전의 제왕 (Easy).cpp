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
    int time; // in minutes
    int subCount;
};

struct Participant
{
    int id;
    int solved = 0;
    int penalty = 0;
    int lastTime = 0; // last accepted submission time in minutes
    int reversalPoints = 0;
    bool fixed = false;
    vector<Frozen> frozenSubs;
};

int timeToMinutes(const string &timeStr)
{
    // timeStr format "hh:mm"
    int hh, mm;
    char colon;
    stringstream ss(timeStr);
    ss >> hh >> colon >> mm;
    return hh * 60 + mm;
}

bool rankingComparator(const Participant &a, const Participant &b)
{
    if (a.solved != b.solved)
        return a.solved > b.solved; // More solved is better.
    if (a.penalty != b.penalty)
        return a.penalty < b.penalty; // Lower penalty is better.
    return a.lastTime < b.lastTime;   // Earlier last submission is better.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // Create participants indexed 0..N-1; id is 1-indexed.
    vector<Participant> parts(N);
    for (int i = 0; i < N; i++)
    {
        parts[i].id = i + 1;
    }

    // Process each submission.
    // Pre-freeze submissions: time <= 03:00 (i.e. <= 180 minutes).
    // Frozen submissions: time > 03:00.
    for (int i = 0; i < M; i++)
    {
        string timeStr;
        int id, prob, s;
        cin >> timeStr >> id >> prob >> s;
        int t = timeToMinutes(timeStr);
        // id is 1-indexed; convert to 0-indexed.
        Participant &p = parts[id - 1];
        if (t <= 180)
        {
            // Pre-freeze submission: update stats.
            p.solved += 1;
            p.penalty += t + (s - 1) * 20;
            // Update last accepted time: maximum among submissions.
            p.lastTime = max(p.lastTime, t);
        }
        else
        {
            // Frozen submission: store it.
            p.frozenSubs.push_back({prob, t, s});
        }
    }

    // For each participant, sort frozen submissions by problem number (ascending)
    for (auto &p : parts)
    {
        sort(p.frozenSubs.begin(), p.frozenSubs.end(), [](const Frozen &a, const Frozen &b)
             { return a.problem < b.problem; });
        // Mark participant as fixed if no frozen submissions.
        if (p.frozenSubs.empty())
        {
            p.fixed = true;
        }
    }

    // Function to compute the current ranking order.
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

    // Simulation of the unfreeze process.
    while (true)
    {
        // Check if any participant still has pending frozen submissions.
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

        // Compute current ranking order.
        vector<int> rankOrder = computeRanking();
        // Find the candidate: the worst-ranked among participants who are not fixed.
        int candidate = -1;
        int candidateRank = -1; // 1-indexed rank.
        for (int i = (int)rankOrder.size() - 1; i >= 0; i--)
        {
            int idx = rankOrder[i];
            if (!parts[idx].fixed)
            {
                candidate = idx;
                candidateRank = i + 1; // since i is 0-indexed.
                break;
            }
        }
        assert(candidate != -1);
        int r_old = candidateRank;

        // Reveal candidate's next frozen submission (in order by problem number).
        Frozen currentSub = parts[candidate].frozenSubs.front();
        parts[candidate].frozenSubs.erase(parts[candidate].frozenSubs.begin());

        // Update candidate's stats.
        parts[candidate].solved += 1;
        parts[candidate].penalty += currentSub.time + (currentSub.subCount - 1) * 20;
        // Update last accepted submission time:
        parts[candidate].lastTime = max(parts[candidate].lastTime, currentSub.time);

        // Recompute ranking after the reveal.
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

        // If candidate has no more pending frozen submissions, mark as fixed.
        if (parts[candidate].frozenSubs.empty())
        {
            parts[candidate].fixed = true;
        }
    }

    // After all reveals, compute final ranking.
    vector<int> finalRankOrder = computeRanking();
    // Create an array to store final rank positions.
    vector<int> finalRank(parts.size());
    for (int i = 0; i < (int)finalRankOrder.size(); i++)
    {
        finalRank[finalRankOrder[i]] = i + 1; // 1-indexed rank.
    }

    // Determine the winner: maximum reversal points; if tie, the one with best final rank.
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
            // Tie-break: choose the one with better (lower) final rank.
            if (finalRank[p.id - 1] < bestFinalRank)
            {
                bestFinalRank = finalRank[p.id - 1];
                bestId = p.id;
            }
        }
    }

    cout << bestId << "\n";
    return 0;
}