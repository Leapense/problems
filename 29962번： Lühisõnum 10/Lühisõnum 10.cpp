#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 두 문자열의 최대 겹침 부분을 찾고 결합된 결과를 반환
string mergeStrings(const string &a, const string &b) {
    int maxOverlap = 0;
    int lenA = a.size(), lenB = b.size();
    
    // a의 끝부분과 b의 시작부분이 겹치는 최대 길이를 찾는다.
    for (int i = 1; i <= min(lenA, lenB); ++i) {
        if (a.substr(lenA - i) == b.substr(0, i)) {
            maxOverlap = i;
        }
    }
    
    // a + b의 겹치지 않는 부분을 결합하여 반환
    return a + b.substr(maxOverlap);
}

// 모든 문자열을 포함하는 가장 짧은 결과를 찾는 함수
string shortestCommonSupersequence(vector<string> &planets) {
    int n = planets.size();
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) perm[i] = i;
    
    string result = "";
    bool first = true;
    
    // 모든 순열을 시도
    do {
        string current = planets[perm[0]];
        for (int i = 1; i < n; ++i) {
            current = mergeStrings(current, planets[perm[i]]);
        }
        if (first || current.size() < result.size()) {
            result = current;
            first = false;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<string> planets(N);
    for (int i = 0; i < N; ++i) {
        cin >> planets[i];
    }
    
    string answer = shortestCommonSupersequence(planets);
    cout << answer << endl;
    
    return 0;
}