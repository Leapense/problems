#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string generate_palindromic_run(int midLen, int groups) {
    string result;
    vector<char> alphabet = {'a', 'b', 'c'};

    int mid = groups / 2;
    vector<char> colors(groups);
    vector<int> lens(groups);

    // 중심 그룹
    char centerChar = rnd.any(alphabet);
    colors[mid] = centerChar;
    lens[mid] = midLen;

    // 좌우 대칭 그룹
    for (int i = 1; i <= mid; ++i) {
        char ch = rnd.any(alphabet);
        int l1 = rnd.next(1, 2);
        int l2 = rnd.next(max(1, 3 - l1), 3); // l1 + l2 >= 3
        colors[mid - i] = colors[mid + i] = ch;
        lens[mid - i] = l1;
        lens[mid + i] = l2;
    }

    // 문자열 조립
    for (int i = 0; i < groups; ++i)
        result += string(lens[i], colors[i]);
    return result;
}

int main(int argc, char* argv[]) {
    // Usage: ./gen <TEST_COUNT> <MAX_LENGTH>
    registerGen(argc, argv, 1);
    int T       = atoi(argv[1]);
    int MAX_LEN = atoi(argv[2]);

    for (int tc = 0; tc < T; ++tc) {
        bool makeValid = rnd.next(0, 1); // 50% 확률로 valid/invalid
        string s;
        if (makeValid) {
            // 3~15사이 홀수 그룹 개수 생성: [1..7]*2+1 → [3,5,7,9,11,13,15]
            int groups = rnd.next(1, 7) * 2 + 1;
            // 각 그룹 최소 1이므로 전체 길이가 groups*1 ≤ MAX_LEN 이려면 midLen 최대 = MAX_LEN/groups
            int centerLen = rnd.next(2, max(2, MAX_LEN / groups));
            s = generate_palindromic_run(centerLen, groups);
        } else {
            // 완전 랜덤 문자열
            int len = rnd.next(1, MAX_LEN);
            s = rnd.next("[abc]{" + to_string(len) + "}");
        }
        cout << s << "\n";
    }
    return 0;
}
