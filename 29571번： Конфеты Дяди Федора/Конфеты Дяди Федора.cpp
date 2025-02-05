#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // n == 0인 경우, 모든 캔디가 먹혔다고 볼 수 있으므로 YES 출력
    if (n == 0)
    {
        cout << "YES";
        return 0;
    }

    // 테트라헤드럴 수 T(m) = m*(m+1)*(m+2)/6
    // m = 0부터 B_MAX까지 미리 계산합니다.
    const int B_MAX = 2000;
    vector<long long> tetra(B_MAX + 1, 0);
    for (int m = 0; m <= B_MAX; m++)
    {
        tetra[m] = (long long)m * (m + 1) * (m + 2) / 6;
    }

    // a: 먹힌 층의 수 (최소 1 이상), b: 원래 피라미드의 총 층 수 (a보다 커야 함)
    for (int a = 1; a < B_MAX; a++)
    {
        for (int b = a + 1; b <= B_MAX; b++)
        {
            long long diff = tetra[b] - tetra[a];
            if (diff == n)
            {
                cout << "YES";
                return 0;
            }
            if (diff > n)
                break; // 더 이상 b를 늘려도 n을 초과하므로 내부 루프 종료
        }
    }

    cout << "NO";
    return 0;
}