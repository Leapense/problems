#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // n==0인 경우 (즉, 모든 캔디가 먹힌 경우)는 정답으로 YES
    if (n == 0)
    {
        cout << "YES";
        return 0;
    }

    // n의 최댓값(10^9)을 고려하여 충분한 b의 최대값을 설정 (대략 2000면 충분)
    const int B_MAX = 2000;
    vector<long long> tetra(B_MAX + 1, 0);

    // 테트라헤드럴 수 T(m) = m*(m+1)*(m+2)/6 을 0 <= m <= B_MAX까지 계산
    for (int m = 0; m <= B_MAX; m++)
    {
        tetra[m] = (long long)m * (m + 1) * (m + 2) / 6;
    }

    // b: 전체 피라미드 층 수, a: 먹힌 층의 수 (1 <= a < b)
    // T(b) - T(a) = n 이 되는 쌍 (a,b)가 있는지 검사합니다.
    for (int b = 2; b <= B_MAX; b++)
    {
        // candidate = T(b) - n. candidate가 T(a)여야 함.
        long long candidate = tetra[b] - n;

        // candidate가 음수이면 a가 존재할 수 없음
        if (candidate < 0)
            continue;
        // candidate가 0이면 a==0인 경우인데, n>0에서는 먹힌 층이 0이면 안 됨.
        if (candidate == 0)
            continue;

        // a는 1 이상, b-1 이하여야 하므로 tetra[1]부터 tetra[b-1] 범위에서 candidate를 찾습니다.
        if (binary_search(tetra.begin() + 1, tetra.begin() + b, candidate))
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
