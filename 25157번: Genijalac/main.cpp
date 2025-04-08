#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> pub(N);
    for (int i = 0; i < N; i++) cin >> pub[i];

    int K; cin >> K;
    vector<vector<int>> jury(K, vector<int>(N));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> jury[i][j];
        }
    }

    int maxVotes = -1, part1 = -1;
    for (int i = 0; i < N; i++) {
        if (pub[i] > maxVotes) {
            maxVotes = pub[i];
            part1 = i + 1;
        }
    }

    vector<int> pubScore(N);
    vector<int> sortedPub = pub;
    sort(sortedPub.begin(), sortedPub.end(), greater<int>());
    vector<int> uniqueVotes;

    uniqueVotes.push_back(sortedPub[0]);
    for (int i = 1; i < N; i++) {
        if (sortedPub[i] != sortedPub[i - 1]) uniqueVotes.push_back(sortedPub[i]);
    }

    int currentScore = N;
    vector<int> voteToScore(1001, 0);
    for (auto v : uniqueVotes) {
        voteToScore[v] = currentScore;
        currentScore--;
    }
    for (int i = 0; i < N; i++) {
        pubScore[i] = voteToScore[pub[i]];
    }

    int minPubScore = N + 1;
    for (auto s : pubScore) minPubScore = min(minPubScore, s);
    vector<int> jurySum(N, 0);
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < K; i++) {
            jurySum[j] += jury[i][j];
        }
    }

    vector<int> juryScore(N);
    vector<int> sortedJury = jurySum;
    sort(sortedJury.begin(), sortedJury.end(), greater<int>());
    vector<int> uniqueJury;
    uniqueJury.push_back(sortedJury[0]);
    for (int i = 1; i < N; i++) {
        if (sortedJury[i] != sortedJury[i - 1]) uniqueJury.push_back(sortedJury[i]);
    }

    currentScore = N;
    vector<int> jurySumToScore(1001, 0);

    for (auto v : uniqueJury) {
        jurySumToScore[v] = currentScore;
        currentScore--;
    }

    for (int i = 0; i < N; i++) {
        juryScore[i] = jurySumToScore[jurySum[i]];
    }

    vector<int> totalScore(N);
    for (int i = 0; i < N; i++) {
        totalScore[i] = pubScore[i] + juryScore[i];
    }

    int part3 = -1, bestTotal = -1;
    for (int i = 0; i < N; i++) {
        if (totalScore[i] > bestTotal) {
            bestTotal = totalScore[i];
            part3 = i + 1;
        }
    }

    vector<int> officialPos(N);
    vector<pair<int, int>> stars;

    for (int i = 0; i < N; i++) {
        stars.push_back({totalScore[i], i});
    }

    sort(stars.begin(), stars.end(), [&](auto a, auto b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    for (int pos = 0; pos < N; pos++) {
        officialPos[stars[pos].second] = pos + 1;
    }

    int bestJury = -1, bestSumDiff = 1e9;
    for (int j = 0; j < K; j++) {
        vector<pair<int, int>> juryOrder;
        for (int i = 0; i < N; i++) {
            juryOrder.push_back({jury[j][i], i});
        }

        sort(juryOrder.begin(), juryOrder.end(), [&](auto a, auto b) {
                return a.first > b.first;
        });

        vector<int> juryPos(N);
        for (int pos = 0; pos < N; pos++) {
            juryPos[juryOrder[pos].second] = pos + 1;
        }

        int sumDiff = 0;
        for (int i = 0; i < N; i++) {
            sumDiff += abs(officialPos[i] - juryPos[i]);
        }

        if (sumDiff < bestSumDiff) {
            bestSumDiff = sumDiff;
            bestJury = j + 1;
        }
    }

    cout << part1 << "\n" << minPubScore << "\n" << part3 << "\n" << bestJury;
    return 0;
}
