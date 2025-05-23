#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // 0-indexed: 초기 조커 위치는 0 (즉, 맨 위)
    int *pos = new int[M + 1];
    pos[0] = 0;

    for (int i = 1; i <= M; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            ll x;
            cin >> x;
            // x번 반복하므로 x mod N만큼 이동
            int delta = (int)(x % N);
            pos[i] = (pos[i - 1] + delta) % N;
        }
        else if (op == 2)
        {
            ll y;
            cin >> y;
            int delta = (int)(y % N);
            // 음수가 되지 않도록 N을 더한 후 모듈러 연산
            pos[i] = ((pos[i - 1] - delta) % N + N) % N;
        }
        else if (op == 3)
        {
            int z;
            cin >> z;
            // z번 셔플 후의 상태로 복원 (z는 0 이상, i 미만)
            pos[i] = pos[z];
        }
    }

    // 최종 상태: pos[M] (0-indexed), 1-indexed로 출력
    cout << pos[M] + 1 << "\n";

    delete[] pos;
    return 0;
}