#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

// 두 문자열이 겹쳐서 쌓을 수 있는지 확인하는 함수
bool can_stack(const string& s1, const string& s2) {
    int M = s1.size();
    // 가능한 모든 시프트에 대해 검사 (-M+1부터 M-1까지)
    for (int shift = -M + 1; shift < M; ++shift) {
        bool match = true;
        bool has_overlap = false;
        // 겹치는 부분 검사
        for (int i = 0; i < M; ++i) {
            int j = i + shift;
            if (j >= 0 && j < M) {
                has_overlap = true; // 겹치는 부분이 존재함을 표시
                if (s1[i] != s2[j]) {
                    match = false;
                    break;
                }
            }
        }
        if (match && has_overlap) {
            return true; // 겹치는 부분이 있고 문자가 동일한 경우
        }
    }
    return false; // 겹칠 수 없는 경우
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    bool possible = true;
    for (int i = 1; i < N; ++i) {
        if (!can_stack(s[i - 1], s[i])) {
            possible = false;
            break;
        }
    }

    cout << (possible ? 1 : 0) << endl;
    return 0;
}