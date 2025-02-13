#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int m;
    cin >> m;

    // 알파벳별 등장 인덱스 저장
    // pos[c] = 문자열 s 내에서 문자 c가 등장하는 모든 인덱스
    vector<int> pos[26];
    for (int i = 0; i < (int)s.size(); i++)
    {
        pos[s[i] - 'a'].push_back(i);
    }

    int answer = 1; // 최소 1 이상 (문자열 길이가 최소 1일 수도 있으므로)

    // 모든 알파벳에 대해 검사
    for (int c = 0; c < 26; c++)
    {
        // 해당 문자가 문자열에 전혀 없다면 패스
        if (pos[c].empty())
            continue;

        // 투 포인터로, pos[c]에서 최대 연속 구간 찾기
        int left = 0;
        int sumGap = 0; // 인접 인덱스 사이에 있는 "제거해야 할 문자 수"의 합

        // right를 0부터 확장
        for (int right = 0; right < (int)pos[c].size(); right++)
        {
            if (right > 0)
            {
                // 새로 추가되는 구간(직전 ~ 현재)
                sumGap += (pos[c][right] - pos[c][right - 1] - 1);
            }

            // 만약 m 초과하면 left 이동
            while (sumGap > m)
            {
                // left ~ left+1 구간 빼기
                sumGap -= (pos[c][left + 1] - pos[c][left] - 1);
                left++;
            }

            // 현재 [left..right] 구간 길이 갱신
            int length = right - left + 1;
            answer = max(answer, length);
        }
    }

    cout << answer << "\n";
    return 0;
}