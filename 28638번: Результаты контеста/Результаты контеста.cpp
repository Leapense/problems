#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 버퍼에 남은 개행 문자 제거

    unordered_map<char, int> incorrectAttempts; // 각 문제의 오답 시도 횟수 (CE 제외)
    unordered_map<char, bool> solved; // 각 문제가 해결되었는지 여부
    unordered_map<char, int> solvedTime; // 각 문제의 첫 번째 성공 제출 시간

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string timeStr, problemStr, verdict;
        ss >> timeStr >> problemStr >> verdict;

        int HH, MM;
        sscanf(timeStr.c_str(), "%d:%d", &HH, &MM);
        int time = HH * 60 + MM; // 시간을 분으로 변환

        char problemID = problemStr[0];

        // 이미 해결된 문제는 무시
        if (solved[problemID]) {
            continue;
        }

        if (verdict == "OK") {
            solved[problemID] = true;
            solvedTime[problemID] = time;
        } else if (verdict != "CE") {
            incorrectAttempts[problemID]++;
        }
    }

    int numSolved = 0;
    int totalPenalty = 0;

    for (auto &p : solved) {
        if (p.second) {
            char problemID = p.first;
            numSolved++;
            int t = solvedTime[problemID];
            int k = incorrectAttempts[problemID];
            int penalty = t + 20 * k;
            totalPenalty += penalty;
        }
    }

    cout << numSolved << " " << totalPenalty << endl;

    return 0;
}
