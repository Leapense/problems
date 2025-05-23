#include <bits/stdc++.h>
using namespace std;

class SNUPTI
{
private:
    int N, M;
    vector<string> strings;
    // 각 척도별 사용된 알파벳을 비트마스크로 저장 (A~Z -> 0~25)
    // sets[i] 는 i번째 척도에서 쓰인 알파벳들의 비트마스크
    vector<int> sets;

public:
    SNUPTI()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> N >> M;
        strings.resize(M);
        for (int i = 0; i < M; i++)
        {
            cin >> strings[i];
        }
    }

    void run()
    {
        // 1) 중복 문자열 검사
        {
            unordered_set<string> us;
            us.reserve(M);
            for (const auto &s : strings)
            {
                us.insert(s);
            }
            if ((int)us.size() != M)
            {
                cout << "NO\n";
                return;
            }
        }

        // 2) 각 척도별로 등장한 알파벳을 비트마스크로 저장
        sets.assign(N, 0);
        for (const auto &s : strings)
        {
            for (int i = 0; i < N; i++)
            {
                int bitIndex = s[i] - 'A';
                sets[i] |= (1 << bitIndex);
            }
        }

        // 3) 각 척도별 가능한 알파벳 수의 곱이 M인지 확인
        long long product = 1;
        for (int i = 0; i < N; i++)
        {
            int cnt = __builtin_popcount(sets[i]);
            // 곱이 이미 M 초과 시 더 볼 필요 없음
            if (product > M)
                break;
            product *= cnt;
        }
        if (product != M)
        {
            cout << "NO\n";
            return;
        }

        // 4) 서로 다른 척도에서 쓰이는 알파벳은 겹치면 안 됨
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (sets[i] & sets[j])
                {
                    cout << "NO\n";
                    return;
                }
            }
        }

        // 조건 모두 충족 시 YES 출력 후 집합 출력
        cout << "YES\n";
        for (int i = 0; i < N; i++)
        {
            // sets[i]에 대해 'A'부터 'Z'까지 체크
            for (int c = 0; c < 26; c++)
            {
                if (sets[i] & (1 << c))
                {
                    cout << char('A' + c);
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    SNUPTI snupti;
    snupti.run();
    return 0;
}