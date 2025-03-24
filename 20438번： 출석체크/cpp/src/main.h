#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <utility>
using namespace std;

// solve 함수는 문제의 입력을 받아 각 쿼리의 결과를 반환합니다.
vector<int> solve(
    int N, int K, int Q, int M,
    const vector<int> &sleeping,
    const vector<int> &initialRecipients,
    const vector<pair<int, int>> &queries);

#endif // MAIN_H